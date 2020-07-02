using System;
using System.Collections.Generic;
using System.Threading.Tasks;

namespace LoggerTests
{
    internal static class Program
    {
        internal static void Main()
        {
            Logger.ClearBuffer();
            Logger.LogDebug("SYNC LOGGER");
            Logger.DivideBuffer();
            Logger.LogInfo(1);
            Logger.LogWarn(455534456.CastToByteArray());
            Logger.LogError("Houston, we dont have a problem.");
            Logger.LogDebug(new List<string>());
            Logger.NewLine(3);
            MainAsync().GetAwaiter().GetResult();
            Console.ReadKey();
        }

        private static async Task MainAsync()
        {
            await Logger.LogDebug("ASYNC LOGGER");
            await Logger.DivideBuffer();
            await Logger.LogInfo(1);
            await Logger.LogWarn(455534456.CastToByteArray());
            await Logger.LogError("Houston, we dont have a problem.");
            await Logger.LogDebug(new List<string>());
            await Logger.DivideBuffer();
        }
    }
}
