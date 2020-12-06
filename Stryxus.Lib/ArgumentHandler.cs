using System;
using System.Collections.Generic;
using System.Threading.Tasks;

namespace Stryxus.Lib
{
    public static class ArgumentHandler
    {
        public static char CommandChar { get; set; } = '-';

        public static Task ParseArgumentsFromArray(string[] args, out List<ParsedArgument> parsedArgs)
        {
            List<ParsedArgument> parsedArgsList = new List<ParsedArgument>();
            ParsedArgument currentParsed = default;
            for (int i = 0; i < args.Length; i++)
            {
                if (args[i].StartsWith(CommandChar) && currentParsed.Command == null && currentParsed.Value == null)
                {
                    currentParsed.Command = args[i][1..];
                    if (i + 1 < args.Length && !args[i + 1].StartsWith("-"))
                    {
                        currentParsed.Value = args[i + 1];
                        parsedArgsList.Add(currentParsed);
                        currentParsed = default;
                    }
                    else if (i + 1 < args.Length && args[i + 1].StartsWith("-"))
                    {
                        parsedArgsList.Add(currentParsed);
                        currentParsed = default;
                    }
                }
            }
            parsedArgs = parsedArgsList;
            return Task.CompletedTask;
        }
    }

    public struct ParsedArgument : IEquatable<ParsedArgument>
    {
        public string Command { get; internal set; }
        public string Value { get; internal set; }

        public override bool Equals(object obj)
        {
            try
            {
                ParsedArgument other = (ParsedArgument)obj;
                return other.Command == Command && other.Value == Value;
            }
            catch (InvalidCastException) { return false; }
        }

        public bool Equals(ParsedArgument other)
        {
            return other.Command == Command && other.Value == Value;
        }

        public override int GetHashCode()
        {
            return Command.GetHashCode() ^ Value.GetHashCode();
        }

        public static bool operator ==(ParsedArgument left, ParsedArgument right)
        {
            return left == right;
        }

        public static bool operator !=(ParsedArgument left, ParsedArgument right)
        {
            return !(left == right);
        }
    }
}
