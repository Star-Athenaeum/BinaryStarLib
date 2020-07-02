using System;
using System.Linq;
using System.Collections.Concurrent;
using System.Threading;
using System.Threading.Tasks;
using System.Runtime.InteropServices;

public static class Logger
{
    private static ConcurrentQueue<LogPackage> PackageQueue { get; } = new ConcurrentQueue<LogPackage>();
    private static Thread LogThread { get; }
    private static bool IsWebPlatform { get; }

    static Logger()
    {
        IsWebPlatform = RuntimeInformation.FrameworkDescription.Contains("Mono") && RuntimeInformation.FrameworkDescription.Contains("wasm");
        if (!IsWebPlatform)
        {
            if (RuntimeInformation.IsOSPlatform(OSPlatform.Windows)) Console.BufferWidth = Console.WindowWidth;
            else if (RuntimeInformation.IsOSPlatform(OSPlatform.Linux)) { /* Is it supported yet? */ }
            LogThread = new Thread(() =>
            {
                while (true) PushLog();
            })
            { IsBackground = true };
            LogThread.Start();
        }
        ClearBuffer();
    }

    private static Task PushLog()
    {
        if (PackageQueue.TryDequeue(out LogPackage pckg))
        {
            if (pckg.Level == 1) Console.ForegroundColor = ConsoleColor.Yellow;
            else if (pckg.Level == 2) Console.ForegroundColor = ConsoleColor.Red;
            else Console.ForegroundColor = ConsoleColor.White;
            if (pckg.ClearMode == 0)
            {
                if (pckg.Level == 0) Console.WriteLine("[" + pckg.PostTime.ToString("yyyy/MM/dd HH:mm:ss.fff") + "][INFO]: " + pckg.Message);
                else if (pckg.Level == 1) Console.WriteLine("[" + pckg.PostTime.ToString("yyyy/MM/dd HH:mm:ss.fff") + "][WARN]: " + pckg.Message);
                else if (pckg.Level == 2) Console.WriteLine("[" + pckg.PostTime.ToString("yyyy/MM/dd HH:mm:ss.fff") + "][ERROR]: " + pckg.Message);
                else if (pckg.Level == 3) Console.WriteLine("[" + pckg.PostTime.ToString("yyyy/MM/dd HH:mm:ss.fff") + "][DEBUG]: " + pckg.Message);
                else Console.WriteLine("[" + pckg.PostTime.ToString("yyyy/MM/dd HH:mm:ss.fff") + "][INFO]: " + pckg.Message);
            }
            else if (pckg.ClearMode == 3) Console.Clear();
            else if (pckg.ClearMode == 2) Console.WriteLine();
            else if (pckg.ClearMode == 1) Console.WriteLine(pckg.Message);
            Console.ForegroundColor = ConsoleColor.White;
        }
        return Task.CompletedTask;
    }

    public static Task LogInfo(object msg)
    {
        PackageQueue.Enqueue(new LogPackage
        {
            PostTime = DateTime.Now,
            Level = 0,
            Message = msg != null ? msg.ToString() : "null"
        });
        if (IsWebPlatform) return PushLog();
        else return Task.CompletedTask;
    }

    public static Task LogWarn(object msg)
    {
        PackageQueue.Enqueue(new LogPackage
        {
            PostTime = DateTime.Now,
            Level = 1,
            Message = msg != null ? msg.ToString() : "null"
        });
        if (IsWebPlatform) return PushLog();
        else return Task.CompletedTask;
    }

    public static Task LogError(object msg)
    {
        PackageQueue.Enqueue(new LogPackage
        {
            PostTime = DateTime.Now,
            Level = 2,
            Message = msg != null ? msg.ToString() : "null"
        });
        if (IsWebPlatform) return PushLog();
        else return Task.CompletedTask;
    }

    public static Task LogDebug(object msg)
    {
#if DEBUG
        PackageQueue.Enqueue(new LogPackage
        {
            PostTime = DateTime.Now,
            Level = 3,
            Message = msg != null ? msg.ToString() : "null"
        });
        if (IsWebPlatform) return PushLog();
        else return Task.CompletedTask;
#else
        return Task.CompletedTask;
#endif
    }

    public static Task NewLine()
    {
        PackageQueue.Enqueue(new LogPackage { ClearMode = 2 });
        if (IsWebPlatform) return PushLog();
        else return Task.CompletedTask;
    }

    public static Task DivideBuffer()
    {
        string s = string.Empty;
        if (IsWebPlatform) s = "----------------------------------------------------------------------------------------------------";
        else for (int i = 0; i < Console.BufferWidth - 1; i++) s += "-";
        PackageQueue.Enqueue(new LogPackage
        {
            ClearMode = 1,
            Message = s
        });
        if (IsWebPlatform) return PushLog();
        else return Task.CompletedTask;
    }

    public static Task ClearBuffer()
    {
        if (IsWebPlatform) return DivideBuffer();
        else PackageQueue.Enqueue(new LogPackage { ClearMode = 3 });
        return Task.CompletedTask;
    }
}

internal struct LogPackage
{
    internal DateTime PostTime { get; set; }
    /*
     * 0 = None
     * 1 = No Formatting
     * 2 = Empty Line
     * 3 = Clear Buffer
     */
    internal int ClearMode { get; set; }
    /*
     * 0 = Info
     * 1 = Warn
     * 2 = Error
     */
    internal int Level { get; set; }
    internal string Message { get; set; }
}