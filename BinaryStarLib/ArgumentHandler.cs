using System;
using System.Collections.Generic;

namespace BSL
{
    public static class ArgumentHandler
    {
        internal static char CommandChar = '-';
        internal static char CommandArgumentBorderChar = '"';

        public static bool ParseArgumentsFromArray(string[] args, out List<ParsedArgument> parsedArgs)
        {
            parsedArgs = new List<ParsedArgument>();
            if (args == null || args.Length == 0) return true;

            bool formattingError = false;
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
            unchecked
            {
                return Command.GetHashCode() ^ Value.GetHashCode();
            }
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
