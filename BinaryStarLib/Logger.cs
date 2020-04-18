using System;
using System.Collections.Concurrent;
using System.Threading;

namespace BinaryStarLib
{
    public sealed class Logger
    {
        private Type LogType { get; }
        private Thread LogThread { get; }
        private BlockingCollection<LogPackage> PackageQueue { get; } = new BlockingCollection<LogPackage>();

        public Logger(Type type)
        {
            if (type == null) throw new ArgumentNullException(nameof(type));
            if (!type.HasMethod("Main")) throw new MissingMethodException(type.Name, "Main");
            LogType = type;
            LogThread = new Thread(() => { while (true) { Console.WriteLine(PackageQueue.Take()); } });
            LogThread.IsBackground = true;
            LogThread.Start();
        }

        public void Log(LogLevel level = LogLevel.Info, string msg = null)
        {
            PackageQueue.Add(new LogPackage
            {
                PostTime = DateTime.Now,
                Level = level,
                LoggerName = LogType.Name,
                Message = msg
            });
        }
    }

    public enum LogLevel
    {
        Info = 0b_0000_0000,
        Warn = 0b_0000_0001,
        Error = 0b_0000_0010,
        Debug = 0b_1111_1111
    }

    internal struct LogPackage
    {
        internal DateTime PostTime { get; set; }
        internal LogLevel Level { get; set; }
        internal string LoggerName { get; set; }
        internal string Message { get; set; }
    }
}
