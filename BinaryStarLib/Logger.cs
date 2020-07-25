﻿using System;
using System.Linq;
using System.Threading.Tasks;

using BSL;

using OperatingSystem = BSL.OS.OperatingSystem;

public static class Logger
{
    private static bool IsWebPlatform { get; }

    static Logger()
    {
        IsWebPlatform = Runtime.IsWASM;
        if (!IsWebPlatform)
        {
            if (OperatingSystem.IsWindows)        Console.BufferWidth = Console.WindowWidth;
        }
        ClearBuffer().GetAwaiter().GetResult();
    }

    private static bool     InitialMessage =        false;
    private static string   PreviousMessage =       null;
    private static int      PreviousMessageCount =  0;

    private static async Task PushLog(LogPackage pckg)
    {
        if (PreviousMessage == pckg.Message) PreviousMessageCount++;
        else
        {
            if (PreviousMessage == null) InitialMessage = true;
            PreviousMessage = !string.IsNullOrEmpty(pckg.Message) ? pckg.Message : string.Empty;
            PreviousMessageCount = 0;
        }

        if (pckg.Level == 1 && !IsWebPlatform) Console.ForegroundColor = ConsoleColor.Yellow;
        else if (pckg.Level == 2 && !IsWebPlatform) Console.ForegroundColor = ConsoleColor.Red;
        else if (!IsWebPlatform) Console.ForegroundColor = ConsoleColor.White;
        if (pckg.ClearMode == 0)
        {
            if (!InitialMessage && PreviousMessageCount == 0) Console.Write("\n");
            if (pckg.Level == 0 && PreviousMessageCount == 0) Console.Write("[" + pckg.PostTime.ToString("yyyy/MM/dd HH:mm:ss.fff")
                                                                  + "][INFO]:  " + pckg.Message);

            else if (pckg.Level == 0) await ClearLine("[" + pckg.PostTime.ToString("yyyy/MM/dd HH:mm:ss.fff")
                                          + "][INFO]:  [" + PreviousMessageCount + " Duplicates] " + pckg.Message);

            else if (pckg.Level == 1 && PreviousMessageCount == 0) Console.Write("[" + pckg.PostTime.ToString("yyyy/MM/dd HH:mm:ss.fff")
                                                                       + "][WARN]:  " + pckg.Message);

            else if (pckg.Level == 1) await ClearLine("[" + pckg.PostTime.ToString("yyyy/MM/dd HH:mm:ss.fff")
                                          + "][WARN]:  [" + PreviousMessageCount + " Duplicates] " + pckg.Message);

            else if (pckg.Level == 2 && PreviousMessageCount == 0) Console.Write("[" + pckg.PostTime.ToString("yyyy/MM/dd HH:mm:ss.fff")
                                                                       + "][ERROR]: " + pckg.Message);

            else if (pckg.Level == 2) await ClearLine("[" + pckg.PostTime.ToString("yyyy/MM/dd HH:mm:ss.fff")
                                          + "][ERROR]:  [" + PreviousMessageCount + " Duplicates] " + pckg.Message);

            else if (pckg.Level == 3 && PreviousMessageCount == 0) Console.Write("[" + pckg.PostTime.ToString("yyyy/MM/dd HH:mm:ss.fff")
                                                                       + "][DEBUG]: " + pckg.Message);

            else if (pckg.Level == 3) await ClearLine("[" + pckg.PostTime.ToString("yyyy/MM/dd HH:mm:ss.fff")
                                          + "][DEBUG]:  [" + PreviousMessageCount + " Duplicates] " + pckg.Message);

            else Console.Write("[" + pckg.PostTime.ToString("yyyy/MM/dd HH:mm:ss.fff")
                     + "][INFO]: " + pckg.Message);
        }
        else if (pckg.ClearMode == 3 && !IsWebPlatform) Console.Clear();
        else if (pckg.ClearMode == 2 && !IsWebPlatform) Console.Write("\n");
        else if (pckg.ClearMode == 1 && !IsWebPlatform) Console.Write((!InitialMessage ? "\n" : string.Empty) + pckg.Message);
        if (!IsWebPlatform) Console.ForegroundColor = ConsoleColor.White;
        InitialMessage = false;
    }

    public static async Task LogInfo(object msg)
    {
        await PushLog(new LogPackage
        {
            PostTime = DateTime.Now,
            Level = 0,
            Message = msg != null ? msg.ToString() : "null"
        });
    }

    public static async Task LogWarn(object msg)
    {
        await PushLog(new LogPackage
        {
            PostTime = DateTime.Now,
            Level = 1,
            Message = msg != null ? msg.ToString() : "null"
        });
    }

    public static async Task LogError(object msg)
    {
        await PushLog(new LogPackage
        {
            PostTime = DateTime.Now,
            Level = 2,
            Message = msg != null ? msg.ToString() : "null"
        });
    }

    public static async Task LogDebug(object msg)
    {
#if DEBUG
        await PushLog(new LogPackage
        {
            PostTime = DateTime.Now,
            Level = 3,
            Message = msg != null ? msg.ToString() : "null"
        });
#endif
    }

    public static async Task NewLine(int lines = 1)
    {
        if (lines < 1) lines = 1;
        for (int i = 0; i < lines; i++)
        {
            await PushLog(new LogPackage { ClearMode = 2 });
        }
    }

    public static async Task DivideBuffer()
    {
        string s = string.Empty;
        if (IsWebPlatform) s = "----------------------------------------------------------------------------------------------------";
        else for (int i = 0; i < Console.BufferWidth - 1; i++) s += "-";
        await PushLog(new LogPackage
        {
            ClearMode = 1,
            Message = s
        });
    }

    public static async Task ClearLine(string content = null)
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

    public static async Task ClearBuffer()
    {
        await PushLog(new LogPackage { ClearMode = 3 });
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