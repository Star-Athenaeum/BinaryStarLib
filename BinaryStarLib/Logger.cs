using System;
using System.Linq;
using System.Collections.Concurrent;
using System.Threading;
using System.Threading.Tasks;

public sealed class Logger
{
    private static Logger LoggerInstance;
    private BlockingCollection<LogPackage> PackageQueue { get; } = new BlockingCollection<LogPackage>();
    private Thread LogThread { get; }

    static Logger()
    {
        Console.BufferWidth = Console.WindowWidth;
        LoggerInstance = new Logger();
    }

    public Logger()
    {
        LogThread = new Thread(() =>
        {
            while (true)
            {
                LogPackage pckg = PackageQueue.Take();
                if (pckg.PostTime != null)
                {
                    Console.WriteLine("[" + pckg.PostTime.ToString("yyyy/MM/dd HH:mm:ss.fff")
                        + "][" + pckg.Level.ToString() + "]: " + pckg.Message);
                }
                else if (pckg.Message.All(c => c == '-')) Console.WriteLine(pckg.Message);
                else Console.WriteLine();
            }
        });
        LogThread.IsBackground = true;
        LogThread.Start();
        ClearBuffer();
    }

    public static Task Log(LogLevel level = LogLevel.Info, string msg = null)
    {
        LoggerInstance.PackageQueue.Add(new LogPackage
        {
            PostTime = DateTime.Now,
            Level = level,
            Message = msg
        });
        return Task.CompletedTask;
    }

    public static Task NewLine()
    {
        LoggerInstance.PackageQueue.Add(new LogPackage());
        return Task.CompletedTask;
    }

    public static Task DivideBuffer()
    {
        string s = string.Empty;
        for (int i = 0; i < Console.BufferWidth - 1; i++) s += "-";
        LoggerInstance.PackageQueue.Add(new LogPackage
        {
            Message = s
        });
        return Task.CompletedTask;
    }

    public static Task ClearBuffer()
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
    internal string Message { get; set; }
}