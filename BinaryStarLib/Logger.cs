using System;
using System.Linq;
using System.Collections.Concurrent;
using System.Threading;
using System.Threading.Tasks;

public static class Logger
{
    private static BlockingCollection<LogPackage> PackageQueue { get; } = new BlockingCollection<LogPackage>();
    private static Thread LogThread { get; }

    static Logger()
    {
        Console.BufferWidth = Console.WindowWidth;
        LogThread = new Thread(() =>
        {
            while (true)
            {
                LogPackage pckg = PackageQueue.Take();
                if (pckg.ClearMode == ClearMode.None) Console.WriteLine("[" + pckg.PostTime.ToString("yyyy/MM/dd HH:mm:ss.fff") + "][" + pckg.Level.ToString() + "]: " + pckg.Message);
                else if (pckg.ClearMode == ClearMode.ClearBuffer) Console.Clear();
                else if (pckg.ClearMode == ClearMode.EmptyLine) Console.WriteLine();
                else if (pckg.ClearMode == ClearMode.NoFormatting) Console.WriteLine(pckg.Message);
            }
        })
        {
            IsBackground = true
        };
        LogThread.Start();
        ClearBuffer();
    }

    public static Task Log(LogLevel level, object msg)
    {
        PackageQueue.Add(new LogPackage
        {
            PostTime = DateTime.Now,
            Level = level,
            Message = msg.ToString()
        });
        return Task.CompletedTask;
    }

    public static Task NewLine()
    {
        PackageQueue.Add(new LogPackage
        {
            ClearMode = ClearMode.EmptyLine
        });
        return Task.CompletedTask;
    }

    public static Task DivideBuffer()
    {
        string s = string.Empty;
        for (int i = 0; i < Console.BufferWidth - 1; i++) s += "-";
        PackageQueue.Add(new LogPackage
        {
            ClearMode = ClearMode.NoFormatting,
            Message = s
        });
        return Task.CompletedTask;
    }

    public static Task ClearBuffer()
    {
        PackageQueue.Add(new LogPackage
        {
            ClearMode = ClearMode.ClearBuffer
        });
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

public enum ClearMode
{
    None = 0b_0000_0000,
    NoFormatting = 0b_0000_0001,
    EmptyLine = 0b_0000_0010,
    ClearBuffer = 0b_000_0011
}

internal struct LogPackage
{
    internal DateTime PostTime { get; set; }
    internal ClearMode ClearMode { get; set; }
    internal LogLevel Level { get; set; }
    internal string Message { get; set; }
}