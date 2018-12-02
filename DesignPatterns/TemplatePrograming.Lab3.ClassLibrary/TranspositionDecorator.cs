using TemplatePrograming.Lab2.ClassLibrary;

namespace TemplatePrograming.Lab3.ClassLibrary
{
    public class TranspositionDecorator : MatrixDecorator, IMatrix
    {
        public TranspositionDecorator(IMatrix matrix)
            : base(matrix)
        {
        }

        double IMatrix.GetValue(int rowNumber, int columnNumber)
        {
            return SourceMatrix.GetValue(columnNumber, rowNumber);
        }

        void IMatrix.SetValue(int rowNumber, int columnNumber, double value)
        {
            SourceMatrix.SetValue(columnNumber, rowNumber, value);
        }
    }
}