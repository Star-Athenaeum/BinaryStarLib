using System;
using System.Collections.Generic;
using System.Threading.Tasks;

namespace BSL
{
    public static class ArgumentHandler
    {
        public static char CommandChar { get; set; } = '-';

        public static Task ParseArgumentsFromArray(string[] args, out List<ParsedArgument> parsedArgs)
        {
            List<ParsedArgument> parsedArgsList = new List<ParsedArgument>();
            ParsedArgument currentParsed = default;
            foreach (string a in args)
            {
                if (currentParsed.Command != null && currentParsed.Value != null)
                {
                    parsedArgsList.Add(currentParsed);
                    currentParsed = default;
                }
                else if (a.StartsWith(CommandChar) && currentParsed.Command != null && currentParsed.Value == null)
                {
                    throw new ArgumentException("Argument order is wrong or a command value is missing!", nameof(args));
                }
                else if (a.StartsWith(CommandChar) && currentParsed.Command == null) currentParsed.Command = a[1..];
                else if (!a.StartsWith(CommandChar) && currentParsed.Command != null && currentParsed.Value == null) currentParsed.Value = a;

                if (currentParsed.Command != null && currentParsed.Value != null)
                {
                    parsedArgsList.Add(currentParsed);
                    currentParsed = default;
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
