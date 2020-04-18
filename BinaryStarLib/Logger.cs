using System;
using System.Collections.Concurrent;
using System.Threading;
using System.Threading.Tasks;

namespace BinaryStarLib
{
    public sealed class Logger
    {
        private Type LogType { get; }
        private Thread LogThread { get; }
        private BlockingCollection<LogPackage> PackageQueue { get; } = new BlockingCollection<LogPackage>();

        static Logger()
        {
            Console.BufferWidth = Console.WindowWidth;
        }

        public Logger(Type type)
        {
            if (type == null) throw new ArgumentNullException(nameof(type));
            if (!type.HasMethod("Main")) throw new MissingMethodException(type.Name, "Main");
            LogType = type;
            LogThread = new Thread(() => 
            {
                while (true) 
                {
                    LogPackage pckg = PackageQueue.Take();
                    Console.WriteLine("[" + pckg.PostTime.ToString("yyyy/MM/dd HH:mm:ss.fff")
                        + "][" + pckg.LoggerName + "][" + pckg.Level.ToString() + "]: " + pckg.Message);
                } 
            });
            LogThread.IsBackground = true;
            LogThread.Start();
            ClearBuffer();
        }

        public Task Log(LogLevel level = LogLevel.Info, string msg = null)
        {
            PackageQueue.Add(new LogPackage
            {
                PostTime = DateTime.Now,
                Level = level,
                LoggerName = LogType.Name,
                Message = msg
            });
            return Task.CompletedTask;
        }

        public Task DivideBuffer()
        {
            string s = string.Empty;
            for (int i = 0; i < Console.BufferWidth - 1; i++) s += "-";
            return Task.CompletedTask;
        }

        public Task ClearBuffer()
        {
            Console.Clear();
            return Task.CompletedTask;
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
