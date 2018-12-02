namespace TemplatePrograming.Lab2.ClassLibrary
{
    public interface IMatrix
    {
        int RowCount { get; }
        int ColumnCount { get; }
        double GetValue(int rowNumber, int columnNumber);
        void SetValue(int rowNumber, int columnNumber, double value);
        void Draw(IMatrixDrawer matrixDrawer, int startRowIndex = 0, int startColumnIndex = 0, bool toClear = true);
    }
}