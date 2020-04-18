using System;
using System.Collections.Generic;
using System.Linq;

namespace System
{
    public static class StringExtensions
    {
        public static bool IsEmpty(this string haystack)
        {
            if (haystack == null) throw new ArgumentNullException(nameof(haystack));
            return haystack.Length == 0;
        }

        public static bool IsWhitespace(this string haystack)
        {
            if (haystack == null) throw new ArgumentNullException(nameof(haystack));
            if (haystack.Length == 0) return false;
            foreach (char c in haystack)
            {
                if (c != " ".ToCharArray()[0]) return false;
            }
            return true;
        }

        public static bool ContainsAny(this string haystack, params string[] needles)
        {
            if (haystack == null) throw new ArgumentNullException(nameof(haystack));
            foreach (string needle in needles)
            {
                if (haystack.Contains(needle)) return true;
            }
            return false;
        }

        public static bool ContainsAll(this string haystack, params string[] needles)
        {
            if (haystack == null) throw new ArgumentNullException(nameof(haystack));
            foreach (string i in needles)
            {
                if (!haystack.Contains(i)) return false;
            }
            return true;
        }

        public static int NthIndexOf(this string str, string lookup, int nth = 1)
        {
            if (str == null) throw new ArgumentNullException(nameof(str));
            List<int> locs = GetLocationsOfString(str, lookup);
            if (locs.Count < nth)
            {
                ArgumentOutOfRangeException e = new ArgumentOutOfRangeException(nameof(str));
                throw e;
            }
            return locs[nth];
        }

        public static int NthLastIndexOf(this string str, string lookup, int nth = 1)
        {
            if (str == null) throw new ArgumentNullException(nameof(str));
            List<int> locs = GetLocationsOfString(str, lookup);
            if (locs.Count < nth)
            {
                ArgumentOutOfRangeException e = new ArgumentOutOfRangeException(nameof(str));
                throw e;
            }
            return locs[locs.Count - nth];
        }

        public static List<int> GetLocationsOfString(string str, string lookup)
        {
            if (str == null) throw new ArgumentNullException(nameof(str));
            List<int> locations = new List<int>();
            while (str.Any())
            {
                if (str.IndexOf(lookup) == -1) break;
                locations.Add(str.LastIndexOf(lookup));
                str = str.Substring(0, str.LastIndexOf(lookup));
            }
            return locations;
        }
    }
}
