using System;
using System.IO;

namespace System
{
	public static class DirectoryInfoExtensions
	{
		public static DirectoryInfo Combine(this DirectoryInfo dir, params string[] extensions)
		{
			if (dir == null) throw new ArgumentNullException(nameof(dir));
			string path = dir.FullName;
			foreach (string d in extensions) path = Path.Combine(path, d);
			return new DirectoryInfo(path);
		}

		public static DirectoryInfo Combine(this DirectoryInfo dir, params DirectoryInfo[] extensions)
		{
			if (dir == null) throw new ArgumentNullException(nameof(dir));
			string path = dir.FullName;
			foreach (DirectoryInfo d in extensions) path = Path.Combine(path, d.FullName);
			return new DirectoryInfo(path);
		}

		public static FileInfo CombineToFile(this DirectoryInfo dir, string filename)
		{
			if (dir == null) throw new ArgumentNullException(nameof(dir));
			if (filename == null) throw new ArgumentNullException(nameof(filename));
			return new FileInfo(dir.FullName + Path.DirectorySeparatorChar + filename);
		}

		public static FileInfo CombineToFile(this DirectoryInfo dir, string filename, params string[] extensions)
		{
			if (dir == null) throw new ArgumentNullException(nameof(dir));
			if (filename == null) throw new ArgumentNullException(nameof(filename));
			string path = dir.FullName;
			foreach (string d in extensions) path = Path.Combine(path, d);
			return new FileInfo(path + Path.DirectorySeparatorChar + filename);
		}

		public static FileInfo CombineToFile(this DirectoryInfo dir, string filename, params DirectoryInfo[] extensions)
		{
			if (dir == null) throw new ArgumentNullException(nameof(dir));
			if (filename == null) throw new ArgumentNullException(nameof(filename));
			string path = dir.FullName;
			foreach (DirectoryInfo d in extensions) path = Path.Combine(path, d.FullName);
			return new FileInfo(path + Path.DirectorySeparatorChar + filename);
		}

		public static bool ContainsDirectory(this DirectoryInfo dir, string lookup)
		{
			if (dir == null) throw new ArgumentNullException(nameof(dir));
			if (lookup == null) throw new ArgumentNullException(nameof(lookup));
			return dir.FullName.Contains(Path.DirectorySeparatorChar + lookup);
		}

		public static bool ContainsAnyDirectory(this DirectoryInfo dir, params string[] lookup)
		{
			if (dir == null) throw new ArgumentNullException(nameof(dir));
			if (lookup == null) throw new ArgumentNullException(nameof(lookup));
			foreach (string i in lookup)
			{
				if (dir.FullName.Contains(Path.DirectorySeparatorChar + i)) return true;
			}
			return false;
		}

		public static bool ContainsAllDirectories(this DirectoryInfo dir, params string[] lookup)
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
