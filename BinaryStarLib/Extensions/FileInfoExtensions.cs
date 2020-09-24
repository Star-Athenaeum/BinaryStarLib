using System;
using System.IO;

namespace System
{
	public static class FileInfoExtensions
	{
		public static FileInfo Combine(this FileInfo dir, string filename, params string[] extensions)
		{
			if (dir == null) throw new ArgumentNullException(nameof(dir));
			if (filename == null) throw new ArgumentNullException(nameof(filename));
			if (extensions == null) throw new ArgumentNullException(nameof(extensions));
			string path = dir.FullName;
			foreach (string d in extensions) path = Path.Combine(path, d);
			return new FileInfo(path + Path.DirectorySeparatorChar + filename);
		}

		public static FileInfo Combine(this FileInfo dir, string filename, params DirectoryInfo[] extensions)
		{
			if (dir == null) throw new ArgumentNullException(nameof(dir));
			if (filename == null) throw new ArgumentNullException(nameof(filename));
			if (extensions == null) throw new ArgumentNullException(nameof(extensions));
			string path = dir.FullName;
			foreach (DirectoryInfo d in extensions) path = Path.Combine(path, d.FullName);
			return new FileInfo(path + Path.DirectorySeparatorChar + filename);
		}

		public static bool ContainsDirectory(this FileInfo dir, string lookup)
		{
			if (dir == null) throw new ArgumentNullException(nameof(dir));
			if (lookup == null) throw new ArgumentNullException(nameof(lookup));
			return dir.FullName.Contains(Path.DirectorySeparatorChar + lookup);
		}

		public static bool ContainsAnyDirectory(this FileInfo dir, params string[] lookup)
		{
			if (dir == null) throw new ArgumentNullException(nameof(dir));
			if (lookup == null) throw new ArgumentNullException(nameof(lookup));
			foreach (string i in lookup)
			{
				if (dir.FullName.Contains(Path.DirectorySeparatorChar + i)) return true;
			}
			return false;
		}

		public static bool ContainsAllDirectories(this FileInfo dir, params string[] lookup)
		{
			if (dir == null) throw new ArgumentNullException(nameof(dir));
			if (lookup == null) throw new ArgumentNullException(nameof(lookup));
			foreach (string i in lookup)
			{
				if (!dir.FullName.Contains(Path.DirectorySeparatorChar + i)) return false;
			}
			return true;
		}
	}
}
