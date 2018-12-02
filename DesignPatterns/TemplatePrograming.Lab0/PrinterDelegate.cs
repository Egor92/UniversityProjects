namespace TemplatePrograming.Lab0
{
    public class PrinterDelegate : PrinterDefault, IPrinterDelegate
    {
        public void PrintDelegate(IPrintable printable)
        {
            printable.Print(this);
        }
    }
}