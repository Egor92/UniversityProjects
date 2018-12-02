namespace TemplatePrograming.Lab0
{
    public interface IPrinterDelegate : IPrinter
    {
        void PrintDelegate(IPrintable printable);
    }
}
