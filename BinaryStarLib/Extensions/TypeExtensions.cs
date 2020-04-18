namespace System
{
    public static class TypeExtensions
    {
        public static bool HasMethod(this Type type, string methodnName)
        {
            if (type == null) throw new ArgumentNullException(nameof(type));
            if (methodnName == null) throw new ArgumentNullException(nameof(methodnName));
            try
            {
                return type.GetMethod(methodnName) != null;
            }
            catch (ArgumentNullException)
            {
                throw;
            }
        }
    }
}
