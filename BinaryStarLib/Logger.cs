using System;
using System.Linq;
using System.Collections.Concurrent;
using System.Threading;
using System.Threading.Tasks;
using System.Runtime.InteropServices;

public static class Logger
{
    private static BlockingCollection<LogPackage> PackageQueue { get; } = new BlockingCollection<LogPackage>();
    private static Thread LogThread { get; }
    private static bool IsWebPlatform { get; }

    static Logger()
    {
        IsWebPlatform = RuntimeInformation.FrameworkDescription.Contains("Mono") && RuntimeInformation.FrameworkDescription.Contains("wasm");
        if (IsWebPlatform)
        {
            if (RuntimeInformation.IsOSPlatform(OSPlatform.Windows))
            {

            }
            else if (RuntimeInformation.IsOSPlatform(OSPlatform.Linux))
            {

            }

        }
        else
        {
            if (RuntimeInformation.IsOSPlatform(OSPlatform.Windows))
            {
                Console.BufferWidth = Console.WindowWidth;
            }
            else if (RuntimeInformation.IsOSPlatform(OSPlatform.Linux))
            {

            }
            LogThread = new Thread(() =>
            {
                while (true) PushLog();
            })
            {
                IsBackground = true
            };
            LogThread.Start();
        }
        ClearBuffer();
    }

    private static Task PushLog()
    {
        LogPackage pckg = PackageQueue.Take();
        if (pckg.Level == LogLevel.Warn) Console.ForegroundColor = ConsoleColor.Yellow;
        else if (pckg.Level == LogLevel.Error) Console.ForegroundColor = ConsoleColor.Red;
        else Console.ForegroundColor = ConsoleColor.White;
        if (pckg.ClearMode == ClearMode.None) Console.WriteLine("[" + pckg.PostTime.ToString("yyyy/MM/dd HH:mm:ss.fff") + "][" + pckg.Level.ToString() + "]: " + pckg.Message);
        else if (pckg.ClearMode == ClearMode.ClearBuffer) Console.Clear();
        else if (pckg.ClearMode == ClearMode.EmptyLine) Console.WriteLine();
        else if (pckg.ClearMode == ClearMode.NoFormatting) Console.WriteLine(pckg.Message);
        Console.ForegroundColor = ConsoleColor.White;
        return Task.CompletedTask;
    }

    public static Task Log(LogLevel level, object msg)
    {
        PackageQueue.Add(new LogPackage
        {
            PostTime = DateTime.Now,
            Level = level,
            Message = msg.ToString()
        });
        if (IsWebPlatform) return PushLog();
        else return Task.CompletedTask;
    }

    public static Task NewLine()
    {
        PackageQueue.Add(new LogPackage
        {
            ClearMode = ClearMode.EmptyLine
        });
        if (IsWebPlatform) return PushLog();
        else return Task.CompletedTask;
    }

    public static Task DivideBuffer()
    {
        string s = string.Empty;
        for (int i = 0; i < (IsWebPlatform ? 100 : Console.BufferWidth) - 1; i++) s += "-";
        PackageQueue.Add(new LogPackage
        {
            ClearMode = ClearMode.NoFormatting,
            Message = s
        });
        if (IsWebPlatform) return PushLog();
        else return Task.CompletedTask;
    }

    public static Task ClearBuffer()
    {
        if (IsWebPlatform) return DivideBuffer();
        else
        {
            PackageQueue.Add(new LogPackage
            {
                ClearMode = ClearMode.ClearBuffer
            });
            return Task.CompletedTask;
        }
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