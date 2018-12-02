namespace TemplatePrograming.Lab1.ClassLibrary
{
    public class Matrix : MatrixBase
    {
        public Matrix(int rowCount, int columnCount) 
            : base(rowCount, columnCount)
        {
        }

        protected override IVector GetVector(int dimension)
        {
            return new Vector(dimension);
        }
    }
}