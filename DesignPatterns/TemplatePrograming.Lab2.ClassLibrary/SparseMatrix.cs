namespace TemplatePrograming.Lab2.ClassLibrary
{
    public class SparseMatrix : MatrixBase
    {
        public SparseMatrix(int rowCount, int columnCount)
            : base(rowCount, columnCount)
        {
        }

        public override void Draw(IMatrixDrawer matrixDrawer, int startRowIndex = 0, int startColumnIndex = 0, bool toClear = true)
        {
            if (toClear)
                matrixDrawer.Clear();
            for (int i = 0; i < RowCount; i++)
            {
                for (int j = 0; j < ColumnCount; j++)
                {
                    double value = GetValue(i, j);
                    if (value != 0.0)
                        matrixDrawer.DrawCell(this, i, j, startRowIndex, startColumnIndex);
                }
            }
        }

        protected override IVector GetVector(int dimension)
        {
            return new SparseVector(dimension);
        }
    }
}