using System;
using BSL.OS.Hardware;

namespace BSL.OS
{
    public static class OperatingSystem
    {
        static OperatingSystem()
        {
            Type = Environment.OSVersion.Platform == PlatformID.Win32NT ? OSType.Windows :
               Environment.OSVersion.Platform == PlatformID.Unix ? OSType.Linux :
               Environment.OSVersion.Platform == PlatformID.MacOSX ? OSType.MacOSX : OSType.Windows;
        }

        public static OSType Type { get; private set; }

        public static CentralProcessingUnit CPU { get; private set; }
        public static GraphicalProcessingUnit GPU { get; private set; }
        public static AudioProcessingUnit APU { get; private set; }

        public static bool IsWindows { get { return Type == OSType.Windows; } }
        public static bool IsLinux { get { return Type == OSType.Linux; } }
        public static bool IsAndroid { get { return Type == OSType.Android; } }
        public static bool IsMacOSX { get { return Type == OSType.MacOSX; } }
        public static bool IsiPhone { get { return Type == OSType.iPhone; } }
    }

    public enum OSType
    {
        Windows,
        Linux,
        Android,
        MacOSX,
        iPhone
    }
}
