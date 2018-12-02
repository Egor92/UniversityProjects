using System.Globalization;

namespace TemplatePrograming.Lab0
{
    public class Sign : IPrintable
    {
        private readonly char _sign;

        public Sign(char sign)
        {
            _sign = sign;
        }

        void IPrintable.Print(IPrinter printer)
        {
            printer.Print(this);
        }

        public override string ToString()
        {
            return _sign.ToString(CultureInfo.InvariantCulture);
        }
    }
}
