namespace TemplatePrograming.Lab0
{
    public class Word : IPrintable
    {
        private readonly string _text;

        public Word(string text)
        {
            _text = text;
        }

        void IPrintable.Print(IPrinter printer)
        {
            printer.Print(this);
        }

        public override string ToString()
        {
            return _text;
        }
    }
}
