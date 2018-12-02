using System;

namespace TemplatePrograming.Lab0
{
    static class Program
    {
        static void Main(string[] args)
        {
            var printableCollection = new IPrintable[]
                {
                    new Word("Irish blood"),
                    new Sign(','),
                    new Word("English hart"),
                    new Sign(','),
                    new Word("This I'm made of"),
                    new Sign('.'),
                };
            IPrintable text = new Text(printableCollection);

            var printer = new PrinterDelegate();

            text.Print(printer);

            printer.PrintDelegate(text);

            Console.Read();
        }
    }
}
