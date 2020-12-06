using System;
using System.Runtime.InteropServices;

namespace Stryxus.Lib
{
    public static class Runtime
    {
        static Runtime()
        {

        }

        public static bool IsMono { get { return RuntimeInformation.FrameworkDescription.Contains("Mono"); } }
        public static bool IsWASM { get { return RuntimeInformation.OSDescription.Contains("Browser"); } }
    }
}
