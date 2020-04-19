using System;
using System.Linq;
using System.IO;
using System.Threading.Tasks;
using System.Runtime.Serialization.Formatters.Binary;

namespace System
{
    public static class ObjectExtensions
    {
        public static Task<byte[]> CastToByteArray(object data)
        {
            if (data == null) throw new ArgumentNullException(nameof(data));
            using (MemoryStream ms = new MemoryStream())
            {
                BinaryFormatter bf = new BinaryFormatter();
                bf.Serialize(ms, data);
                return Task.FromResult(ms.ToArray());
            }
        }

        public static Task<T> CastFromByteArray<T>(byte[] data)
        {
            if (data == null) throw new ArgumentNullException(nameof(data));
            using (MemoryStream ms = new MemoryStream())
            {
                BinaryFormatter bf = new BinaryFormatter();
                ms.Write(data, 0, data.Length);
                ms.Seek(0, SeekOrigin.Begin);
                try
                {
                    return Task.FromResult((T)bf.Deserialize(ms));
                }
                catch (InvalidCastException)
                {
                    throw;
                }
            }
        }
    }
}
