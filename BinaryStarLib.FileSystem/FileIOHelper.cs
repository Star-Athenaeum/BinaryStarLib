using System;
using System.IO;
using System.Text;
using System.Threading.Tasks;
using System.Collections.Concurrent;

namespace BSL.FileSystem
{
    public static class FileIOHelper
    {
        private static ConcurrentDictionary<FileInfo, FileStream> ConcurrentOpenStreams { get; } = new ConcurrentDictionary<FileInfo, FileStream>();

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
                using StreamReader reader = new StreamReader(ConcurrentOpenStreams[info]);
                data = await reader.ReadToEndAsync();
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

        public static async Task NullifyFile(FileInfo info)
        {
            if (info == null) throw new ArgumentNullException(nameof(info));
            await File.WriteAllTextAsync(info.FullName, string.Empty);
        }
    }
}
