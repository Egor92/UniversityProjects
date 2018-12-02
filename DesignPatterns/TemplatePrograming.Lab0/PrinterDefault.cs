namespace TemplatePrograming.Lab0
{
    public class PrinterDefault : IPrinter
    {
        public virtual void Print(object obj)
        {
            System.Console.WriteLine(obj);
        }
    }
}
