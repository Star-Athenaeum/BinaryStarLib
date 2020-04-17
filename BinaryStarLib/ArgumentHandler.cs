using System;
using System.Collections.Generic;

namespace BinaryStarLib
{
    public static class ArgumentHandler
    {
        internal static char CommandChar = '-';
        internal static char CommandArgumentBorderChar = '"';

        public static bool ParseArgumentsFromArray(string[] args, out List<ParsedArgument> parsedArgs)
        {
            bool formattingError = false;
            parsedArgs = new List<ParsedArgument>();
            ParsedArgument currentParsed = default;
            foreach (string a in args)
            {
                if (a.StartsWith(CommandChar)) currentParsed.Command = a[1..];
                else ResetParsedArgumentInstance(currentParsed);
                if (a.StartsWith(CommandArgumentBorderChar) && a.EndsWith(CommandArgumentBorderChar)) currentParsed.Value = a[1..];
                else ResetParsedArgumentInstance(currentParsed);

                void ResetParsedArgumentInstance(ParsedArgument instance)
                {
                    instance = default;
                    formattingError = true;
                }

                if (currentParsed.Command != null && currentParsed.Value != null)
                {
                    parsedArgs.Add(currentParsed);
                    currentParsed = default;
                }
            }
            return formattingError;
        }

        public struct ParsedArgument
        {
            public string Command { get; internal set; }
            public string Value { get; internal set; }
        }
    }
}
