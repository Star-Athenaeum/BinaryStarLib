using System;
using System.IO;
using System.Text;
using System.Threading.Tasks;
using System.Collections.Concurrent;

namespace BSL.FileSystem
{
    public static class FileIO
    {
        public static DirectoryInfo ApplicationDirectory { get; } = new DirectoryInfo(AppDomain.CurrentDomain.BaseDirectory);
        public static DirectoryInfo AppDataDirectory { get; } = new DirectoryInfo(Environment.GetFolderPath(Environment.SpecialFolder.ApplicationData));

        private static ConcurrentDictionary<FileInfo, FileStream> ConcurrentOpenStreams { get; } = new ConcurrentDictionary<FileInfo, FileStream>();

        public static async Task Write(FileInfo info, object data, FileMode mode = FileMode.Open, FileAccess access = FileAccess.ReadWrite, FileShare share = FileShare.ReadWrite)
        {
            if (info == null) throw new ArgumentNullException(nameof(info));
            if (data == null) throw new ArgumentNullException(nameof(data));
            byte[] bytes = await data.CastToByteArray();
            if (ConcurrentOpenStreams.ContainsKey(info)) await ConcurrentOpenStreams[info].WriteAsync(bytes, 0, bytes.Length);
            else using (FileStream fs = info.Open(mode, access, share)) await fs.WriteAsync(bytes);
        }

        public static async Task<T> Read<T>(FileInfo info, FileMode mode = FileMode.Open, FileAccess access = FileAccess.ReadWrite, FileShare share = FileShare.ReadWrite)
        {
            if (info == null) throw new ArgumentNullException(nameof(info));
            byte[] data = new byte[info.Length];
            if (ConcurrentOpenStreams.ContainsKey(info)) await ConcurrentOpenStreams[info].ReadAsync(data, 0, data.Length);
            else using (FileStream fs = info.Open(mode, access, share)) await fs.ReadAsync(data, 0, data.Length);
            return await data.CastFromByteArray<T>();
        }

        public static async Task WriteText(FileInfo info, object data, Encoding encoding, FileMode mode = FileMode.Open, FileAccess access = FileAccess.ReadWrite, FileShare share = FileShare.ReadWrite)
        {
            if (info == null) throw new ArgumentNullException(nameof(info));
            if (data == null) throw new ArgumentNullException(nameof(data));
            if (encoding == null) throw new ArgumentNullException(nameof(encoding));
            if (ConcurrentOpenStreams.ContainsKey(info))
            {
                byte[] d = encoding.GetBytes(data.ToString());
                await ConcurrentOpenStreams[info].WriteAsync(d, 0, d.Length);
            }
            else using (FileStream fs = info.Open(mode, access, share)) await fs.WriteAsync(encoding.GetBytes(data.ToString()));
        }

        public static async Task<string> ReadText(FileInfo info, FileMode mode = FileMode.Open, FileAccess access = FileAccess.ReadWrite, FileShare share = FileShare.ReadWrite)
        {
            if (info == null) throw new ArgumentNullException(nameof(info));
            string data = null;
            if (ConcurrentOpenStreams.ContainsKey(info))
            {
                using (StreamReader reader = new StreamReader(ConcurrentOpenStreams[info])) data = await reader.ReadToEndAsync();
            }
            else using (StreamReader reader = new StreamReader(new FileStream(info.FullName, mode, access, share))) data = await reader.ReadToEndAsync();
            return data;
        }

        public static Task<FileStream> OpenStream(FileInfo info, FileMode mode = FileMode.Open, FileAccess access = FileAccess.ReadWrite, FileShare share = FileShare.ReadWrite)
        {
            if (info == null) throw new ArgumentNullException(nameof(info));
            FileStream stream = new FileStream(info.FullName, mode, access, share);
            bool success = ConcurrentOpenStreams.TryAdd(info, stream);
            return Task.FromResult(success ? stream : null);
        }

        public static async Task CloseStream(FileStream stream)
        {
            if (stream == null) throw new ArgumentNullException(nameof(stream));
            await stream.DisposeAsync();
        }

        public static async Task CloseAllStreams()
        {
            foreach (FileStream stream in ConcurrentOpenStreams.Values) await stream.DisposeAsync();
        }

        public static async Task NullifyFileAsync(FileInfo info)
        {
            if (info == null) throw new ArgumentNullException(nameof(info));
            await File.WriteAllTextAsync(info.FullName, string.Empty);
        }
    }
}
