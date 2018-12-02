namespace TemplatePrograming.Lab1.ClassLibrary
{
    public class SparseMatrix : MatrixBase
    {
        public SparseMatrix(int rowCount, int columnCount) 
            : base(rowCount, columnCount)
        {
        }

        protected override IVector GetVector(int dimension)
        {
            return new SparseVector(dimension);
        }
    }
}