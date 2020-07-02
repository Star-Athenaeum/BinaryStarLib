using System;
using System.Collections.Generic;

namespace LoggerTests
{
    class Program
    {
        static void Main(string[] args)
        {
            Logger.ClearBuffer();
            Logger.LogInfo(1);
            Logger.LogWarn(455534456.CastToByteArray());
            Logger.LogError("Houston, we dont have a problem.");
            Logger.DivideBuffer();
            Logger.LogDebug(new List<string>());
            Console.ReadKey();
        }
    }
}
