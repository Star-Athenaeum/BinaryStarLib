using System;
using System.IO;
using System.Text;
using System.Threading.Tasks;

using Newtonsoft.Json;

namespace Stryxus.Lib.FileSystem
{
	public static class JsonHelper
	{
		public static async Task WriteJSON<T>(T data, FileInfo info)
		{
			if (data == null) throw new ArgumentNullException(nameof(data));
			if (info == null) throw new ArgumentNullException(nameof(info));
			await FileIOHelper.WriteText(info, JsonConvert.SerializeObject(data), Encoding.UTF8);
		}

		public static async Task<T> ReadJSON<T>(FileInfo info) where T : new()
		{
			if (info == null) throw new ArgumentNullException(nameof(info));
			return JsonConvert.DeserializeObject<T>(await FileIOHelper.ReadText(info));
		}
	}
}
