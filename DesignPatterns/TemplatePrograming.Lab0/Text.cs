namespace TemplatePrograming.Lab0
{
    public class Text : IPrintable
    {
        private readonly IPrintable[] _printableCollection;

        public Text(IPrintable[] printableCollection)
        {
            _printableCollection = printableCollection;
        }

        void IPrintable.Print(IPrinter printer)
        {
            foreach (var printable in _printableCollection)
                printable.Print(printer);
        }
    }
}
