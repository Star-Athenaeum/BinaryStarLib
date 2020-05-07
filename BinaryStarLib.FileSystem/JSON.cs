using System;
using System.IO;
using System.Text;
using System.Threading.Tasks;

using Newtonsoft.Json;

namespace BSL.FileSystem
{
	public static class JSON
	{
		public static async Task WriteJSON<T>(T data, FileInfo info)
		{
			if (data == null) throw new ArgumentNullException(nameof(data));
			if (info == null) throw new ArgumentNullException(nameof(info));
			await FileIO.WriteText(info, JsonConvert.SerializeObject(data), Encoding.UTF8);
		}

		public static async Task<T> ReadJSON<T>(FileInfo info) where T : new()
		{
			if (info == null) throw new ArgumentNullException(nameof(info));
			return (T)JsonConvert.DeserializeObject(await FileIO.ReadText(info));
		}
	}
}
