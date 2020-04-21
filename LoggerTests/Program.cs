using System;
using System.Collections.Generic;

namespace LoggerTests
{
    class Program
    {
        static void Main(string[] args)
        {
            Logger.ClearBuffer();
            Logger.Log(LogLevel.Info, 1);
            Logger.Log(LogLevel.Warn, 455534456.CastToByteArray());
            Logger.Log(LogLevel.Error, "Houston, we have a problem.");
            Logger.DivideBuffer();
            Logger.Log(LogLevel.Debug, new List<string>());
            Console.ReadKey();
        }
    }
}
