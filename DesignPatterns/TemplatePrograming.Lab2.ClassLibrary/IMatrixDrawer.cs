namespace TemplatePrograming.Lab2.ClassLibrary
{
    public interface IMatrixDrawer
    {
        void Clear();
        void DrawCell(IMatrix matrix, int rowIndex, int columnIndex, int startRowIndex = 0, int startColumnIndex = 0);
    }
}