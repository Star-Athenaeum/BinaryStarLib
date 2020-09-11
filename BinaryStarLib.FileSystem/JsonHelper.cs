using System;
using System.IO;
using System.Text;
using System.Text.Json;
using System.Threading.Tasks;

namespace BSL.FileSystem
{
	public static class JsonHelper
	{
		public static async Task WriteJSON<T>(T data, FileInfo info)
		{
			if (data == null) throw new ArgumentNullException(nameof(data));
			if (info == null) throw new ArgumentNullException(nameof(info));
			await FileIOHelper.WriteText(info, Encoding.UTF8.GetString(JsonSerializer.SerializeToUtf8Bytes(data)), Encoding.UTF8);
		}

		public static async Task<T> ReadJSON<T>(FileInfo info) where T : new()
		{
			if (info == null) throw new ArgumentNullException(nameof(info));
			return JsonSerializer.DeserializeAsync<T>(await FileIOHelper.OpenStream(info)).Result;
		}

		public static async Task<string> Serialize<T>(T data)
		{
			using (MemoryStream stream = new MemoryStream())
			{
				await JsonSerializer.SerializeAsync(stream, data, data.GetType());
				stream.Position = 0;
				using (StreamReader reader = new StreamReader(stream)) return await reader.ReadToEndAsync();
			}
		}

		public static async Task<T> Deserialize<T>(string jsonString)
		{
			using (MemoryStream stream = new MemoryStream(Encoding.UTF8.GetBytes(jsonString))) return await JsonSerializer.DeserializeAsync<T>(stream);
		}
	}
}
