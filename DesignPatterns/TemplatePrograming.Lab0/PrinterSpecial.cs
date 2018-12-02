namespace TemplatePrograming.Lab0
{
    public class PrinterSpecial : PrinterDefault
    {
        public override void Print(object obj)
        {
            string format = obj is Word
            ? "({0})"
            : "{0}";
            System.Console.WriteLine(format, obj);
        }
    }
}
