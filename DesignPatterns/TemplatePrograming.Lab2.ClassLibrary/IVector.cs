namespace TemplatePrograming.Lab2.ClassLibrary
{
    public interface IVector
    {
        double GetValue(int index);
        void SetValue(int index, double value);
        int Dimension { get; }
    }
}