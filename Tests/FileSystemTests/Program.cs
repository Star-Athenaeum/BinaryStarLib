﻿using System;
using System.IO;
using System.Threading.Tasks;

using BSL;
using BSL.FileSystem;

namespace FileSystemTests
{
    class Program
    {
        static void Main() => MainAsync().GetAwaiter().GetResult();

        static async Task MainAsync()
        {
            await Logger.LogInfo(await FileIOHelper.ReadText(FileSystemHelper.ApplicationDirectory.CombineToFile("TestingReadFile.txt"), FileMode.Open, FileAccess.Read, FileShare.Read));
            Console.ReadKey();
        }
    }
}