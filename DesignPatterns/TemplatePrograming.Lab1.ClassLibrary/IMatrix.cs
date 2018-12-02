namespace TemplatePrograming.Lab1.ClassLibrary
{
    public interface IMatrix
    {
        int RowCount { get; }
        int ColumnCount { get; }
        double GetValue(int rowNumber, int columnNumber);
        void SetValue(int rowNumber, int columnNumber, double value);
    }
}