using System;
using System.IO;
using System.Threading.Tasks;
using System.Runtime.InteropServices;

namespace BSL.FileSystem
{
	public static class FileSystemIO
	{
		public static DirectoryInfo ApplicationDirectory { get; } = new DirectoryInfo(AppDomain.CurrentDomain.BaseDirectory);
		public static DirectoryInfo AppDataDirectory { get; }

		static FileSystemIO()
		{
			if (RuntimeInformation.IsOSPlatform(OSPlatform.Windows))
			{
				AppDataDirectory = new DirectoryInfo(Environment.GetFolderPath(Environment.SpecialFolder.ApplicationData));
			}
			else if (RuntimeInformation.IsOSPlatform(OSPlatform.Linux))
			{

			}
		}

		public static Task Create(FileInfo info)
		{
			if (info == null) throw new ArgumentNullException(nameof(info));
			File.Create(info.FullName).Dispose();
			return Task.CompletedTask;
		}

		public static Task Create(DirectoryInfo info)
		{
			if (info == null) throw new ArgumentNullException(nameof(info));
			Directory.CreateDirectory(info.FullName);
			return Task.CompletedTask;
		}

		public static Task Delete(FileInfo info)
		{
			if (info == null) throw new ArgumentNullException(nameof(info));
			File.Delete(info.FullName);
			return Task.CompletedTask;
		}

		public static Task Delete(DirectoryInfo info)
		{
			if (info == null) throw new ArgumentNullException(nameof(info));
			Directory.Delete(info.FullName);
			return Task.CompletedTask;
		}
		/*
		public static Task RecycleFile(FileInfo info)
		{
			if (info == null) throw new ArgumentNullException(nameof(info));
			Microsoft.VisualBasic.FileIO.FileSystem.DeleteFile(info.FullName, 
				Microsoft.VisualBasic.FileIO.UIOption.AllDialogs, 
				Microsoft.VisualBasic.FileIO.RecycleOption.SendToRecycleBin);
			return Task.CompletedTask;
		}

		public static Task RecylceDirectory(DirectoryInfo info)
		{
			if (info == null) throw new ArgumentNullException(nameof(info));
			Microsoft.VisualBasic.FileIO.FileSystem.DeleteDirectory(info.FullName,
				Microsoft.VisualBasic.FileIO.UIOption.AllDialogs, 
				Microsoft.VisualBasic.FileIO.RecycleOption.SendToRecycleBin);
			return Task.CompletedTask;
		}*/

		public static Task Move(FileInfo from, FileInfo to)
		{
			if (from == null) throw new ArgumentNullException(nameof(from));
			if (to == null) throw new ArgumentNullException(nameof(to));
			File.Move(from.FullName, to.FullName);
			return Task.CompletedTask;
		}

		public static Task Move(DirectoryInfo from, DirectoryInfo to)
		{
			if (from == null) throw new ArgumentNullException(nameof(from));
			if (to == null) throw new ArgumentNullException(nameof(to));
			Directory.Move(from.FullName, to.FullName);
			return Task.CompletedTask;
		}

		public static Task Copy(FileInfo from, FileInfo to, bool overwrite = false)
		{
			if (from == null) throw new ArgumentNullException(nameof(from));
			if (to == null) throw new ArgumentNullException(nameof(to));
			File.Copy(from.FullName, to.FullName, overwrite);
			return Task.CompletedTask;
		}

		public static Task Copy(DirectoryInfo from, DirectoryInfo to, bool overwrite = false)
		{
			if (from == null) throw new ArgumentNullException(nameof(from));
			if (to == null) throw new ArgumentNullException(nameof(to));
			foreach (string newPath in Directory.GetDirectories(from.FullName, "*.*", SearchOption.AllDirectories)) Directory.CreateDirectory(newPath.Replace(from.FullName, to.FullName));
			foreach (string newPath in Directory.GetFiles(from.FullName, "*.*", SearchOption.AllDirectories)) File.Copy(newPath, newPath.Replace(from.FullName, to.FullName), overwrite);
			return Task.CompletedTask;
		}

		public static Task Cut(FileInfo from, FileInfo to, bool overwrite = false)
		{
			if (from == null) throw new ArgumentNullException(nameof(from));
			if (to == null) throw new ArgumentNullException(nameof(to));
			File.Copy(from.FullName, to.FullName, overwrite);
			File.Delete(from.FullName);
			return Task.CompletedTask;
		}

		public static Task Cut(DirectoryInfo from, DirectoryInfo to, bool overwrite = false)
		{
			if (from == null) throw new ArgumentNullException(nameof(from));
			if (to == null) throw new ArgumentNullException(nameof(to));
			foreach (string newPath in Directory.GetDirectories(from.FullName, "*.*", SearchOption.AllDirectories)) Directory.CreateDirectory(newPath.Replace(from.FullName, to.FullName));
			foreach (string newPath in Directory.GetFiles(from.FullName, "*.*", SearchOption.AllDirectories)) File.Copy(newPath, newPath.Replace(from.FullName, to.FullName), overwrite);
			foreach (string newPath in Directory.GetFiles(from.FullName, "*.*", SearchOption.AllDirectories)) File.Delete(newPath);
			foreach (string newPath in Directory.GetDirectories(from.FullName, "*.*", SearchOption.AllDirectories)) Directory.Delete(newPath);
			return Task.CompletedTask;
		}

		public static Task<bool> Exists(FileInfo info)
		{
			if (info == null) throw new ArgumentNullException(nameof(info));
			return Task.FromResult(File.Exists(info.FullName));
		}

		public static Task<bool> Exists(DirectoryInfo info)
		{
			if (info == null) throw new ArgumentNullException(nameof(info));
			return Task.FromResult(Directory.Exists(info.FullName));
		}
	}
}
