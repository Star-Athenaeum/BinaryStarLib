using System;
using System.Collections.Generic;
using System.Linq;
using System.IO;

namespace System
{
    public static class IEnumerableExtensions
    {
        public static bool Contains(this IEnumerable<FileInfo> enumerable, string lookingFor)
        {
            if (enumerable == null) throw new ArgumentNullException(nameof(enumerable));
            if (lookingFor == null) throw new ArgumentNullException(nameof(lookingFor));
            foreach (FileInfo item in enumerable)
            {
                if (item.Name == lookingFor) return true;
            }
            return false;
        }

        public static IEnumerable<T> Append<T>(this IEnumerable<T> enumerable, IEnumerable<T> appending)
        {
            if (enumerable == null) throw new ArgumentNullException(nameof(enumerable));
            if (appending == null) throw new ArgumentNullException(nameof(appending));
            IEnumerable<T> appended = enumerable;
            foreach (T obj in appending) appending.Append(obj);
            return appended.Distinct();
        }
    }
}
