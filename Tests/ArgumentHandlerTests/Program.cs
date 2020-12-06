using System;
using System.Collections.Generic;
using System.Threading.Tasks;

using Stryxus.Lib;

namespace ArgumentHandlerTests
{
    class Program
    {
        static void Main() => MainAsync().GetAwaiter().GetResult();

        static async Task MainAsync()
        {
            await ArgumentHandler.ParseArgumentsFromArray(new string[]
            {
                "-projectPath",
                "D:/Projects",
                "-deleteEverything",
                "true"
            }, 
            out List<ParsedArgument> parsedArgs);

            foreach (ParsedArgument arg in parsedArgs) Console.WriteLine(arg.Command + " : " + arg.Value);
            Console.ReadKey();
        }
    }
}
