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
            if (RuntimeInformation.IsOSPlatform(OSPlatform.Windows))        Console.BufferWidth = Console.WindowWidth;
            else if (RuntimeInformation.IsOSPlatform(OSPlatform.Linux))     { /* Is it supported yet? */ }
            LogThread = new Thread(() =>
            {
                while (true) PushLog();
            })
            { IsBackground = true };
            LogThread.Start();
        }
        ClearBuffer();
    }

    private static bool     InitialMessage =        false;
    private static string   PreviousMessage =       null;
    private static int      PreviousMessageCount =  0;

    private static Task PushLog()
    {
        if (PackageQueue.TryDequeue(out LogPackage pckg))
        {
            if (PreviousMessage == pckg.Message) PreviousMessageCount++;
            else
            {
                if (PreviousMessage == null) InitialMessage = true;
                PreviousMessage = !string.IsNullOrEmpty(pckg.Message) ? pckg.Message : string.Empty;
                PreviousMessageCount = 0;
            }

            if      (pckg.Level == 1)                                       Console.ForegroundColor = ConsoleColor.Yellow;
            else if (pckg.Level == 2)                                       Console.ForegroundColor = ConsoleColor.Red;
            else                                                            Console.ForegroundColor = ConsoleColor.White;
            if (pckg.ClearMode == 0)
            {
                if      (!InitialMessage && PreviousMessageCount == 0)      Console.Write("\n");
                if      (pckg.Level == 0 && PreviousMessageCount == 0)      Console.Write("[" + pckg.PostTime.ToString("yyyy/MM/dd HH:mm:ss.fff") 
                                                                                + "][INFO]:  " + pckg.Message);

                else if (pckg.Level == 0)                                   ClearLine("[" + pckg.PostTime.ToString("yyyy/MM/dd HH:mm:ss.fff") 
                                                                                + "][INFO]:  [" + PreviousMessageCount + " Duplicates] " + pckg.Message);

                else if (pckg.Level == 1 && PreviousMessageCount == 0)      Console.Write("[" + pckg.PostTime.ToString("yyyy/MM/dd HH:mm:ss.fff") 
                                                                                + "][WARN]:  " + pckg.Message);

                else if (pckg.Level == 1)                                   ClearLine("[" + pckg.PostTime.ToString("yyyy/MM/dd HH:mm:ss.fff") 
                                                                                + "][WARN]:  [" + PreviousMessageCount + " Duplicates] " + pckg.Message);

                else if (pckg.Level == 2 && PreviousMessageCount == 0)      Console.Write("[" + pckg.PostTime.ToString("yyyy/MM/dd HH:mm:ss.fff") 
                                                                                + "][ERROR]: " + pckg.Message);

                else if (pckg.Level == 2)                                   ClearLine("[" + pckg.PostTime.ToString("yyyy/MM/dd HH:mm:ss.fff") 
                                                                                + "][ERROR]:  [" + PreviousMessageCount + " Duplicates] " + pckg.Message);

                else if (pckg.Level == 3 && PreviousMessageCount == 0)      Console.Write("[" + pckg.PostTime.ToString("yyyy/MM/dd HH:mm:ss.fff") 
                                                                                + "][DEBUG]: " + pckg.Message);

                else if (pckg.Level == 3)                                   ClearLine("[" + pckg.PostTime.ToString("yyyy/MM/dd HH:mm:ss.fff") 
                                                                                + "][DEBUG]:  [" + PreviousMessageCount + " Duplicates] " + pckg.Message);

                else                                                        Console.Write("[" + pckg.PostTime.ToString("yyyy/MM/dd HH:mm:ss.fff") 
                                                                                + "][INFO]: " + pckg.Message);
            }
            else if (pckg.ClearMode == 3)                                   Console.Clear();
            else if (pckg.ClearMode == 2)                                   Console.Write("\n");
            else if (pckg.ClearMode == 1)                                   Console.Write((!InitialMessage ? "\n" : string.Empty) + pckg.Message);
            Console.ForegroundColor = ConsoleColor.White;
            InitialMessage = false;
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

    public static Task NewLine(int lines = 1)
    {
        if (lines < 1) lines = 1;
        for (int i = 0; i < lines; i++)
        {
            PackageQueue.Enqueue(new LogPackage { ClearMode = 2 });
            if (IsWebPlatform) return PushLog();
        }
        return Task.CompletedTask;
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

    public static Task ClearLine(string content = null)
    {
        if (!IsWebPlatform)
        {
            if (string.IsNullOrEmpty(content))
            {
                content = string.Empty;
                for (int i = 0; i < Console.BufferWidth - 1; i++) content += " ";
            }
            Console.Write("\r{0}", content);
        }
        return Task.CompletedTask;
    }

    public static Task ClearBuffer()
    {
        if (!IsWebPlatform) PackageQueue.Enqueue(new LogPackage { ClearMode = 3 });
        return Task.CompletedTask;
    }
}

internal struct LogPackage
{
    internal DateTime   PostTime    { get; set; }
    /*
     * 0 = None
     * 1 = No Formatting
     * 2 = Empty Line
     * 3 = Clear Buffer
     */
    internal int        ClearMode   { get; set; }
    /*
     * 0 = Info
     * 1 = Warn
     * 2 = Error
     */
    internal int        Level       { get; set; }
    internal string     Message     { get; set; }
}