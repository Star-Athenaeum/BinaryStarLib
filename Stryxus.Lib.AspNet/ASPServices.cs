using System;

namespace Stryxus.Lib.AspNet
{
    public static class ASPServices
    {
        public static bool IsDevelopmentMode { get; internal set; }
        public static IServiceProvider Provider { get; internal set; }

        public static void Get<T>(out T service) => service = (T)Provider.GetService(typeof(T));
        public static T Get<T>() => (T)Provider.GetService(typeof(T));
    }
}
