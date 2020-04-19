﻿using System;
using System.IO;
using System.Threading.Tasks;
using System.Runtime.Serialization.Formatters.Binary;

namespace System
{
    public static class ObjectExtensions
    {
        public static Task<byte[]> CastToByteArray(this object data)
        {
            if (data == null) throw new ArgumentNullException(nameof(data));
            using (MemoryStream ms = new MemoryStream())
            {
                BinaryFormatter bf = new BinaryFormatter();
                bf.Serialize(ms, data);
                return Task.FromResult(ms.ToArray());
            }
        }
    }
}
