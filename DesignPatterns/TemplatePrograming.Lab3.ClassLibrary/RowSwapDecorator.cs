using System;
using TemplatePrograming.Lab2.ClassLibrary;

namespace TemplatePrograming.Lab3.ClassLibrary
{
    public class RowSwapDecorator : MatrixDecorator, IMatrix
    {
        private readonly int _i;
        private readonly int _j;

        public RowSwapDecorator(IMatrix matrix, int i, int j)
            : base(matrix)
        {
            if (i < 0 || j < 0 || i > SourceMatrix.RowCount - 1 || j > SourceMatrix.RowCount - 1)
                throw new Exception();
            _i = i;
            _j = j;
        }

        double IMatrix.GetValue(int rowNumber, int columnNumber)
        {
            int actualRowNumber = GetActualRowNumber(rowNumber);
            return SourceMatrix.GetValue(actualRowNumber, columnNumber);
        }

        void IMatrix.SetValue(int rowNumber, int columnNumber, double value)
        {
            int actualRowNumber = GetActualRowNumber(rowNumber);
            SourceMatrix.SetValue(actualRowNumber, columnNumber, value);
        }

        private int GetActualRowNumber(int rowNumber)
        {
            if (rowNumber == _i)
                return _j;
            if (rowNumber == _j)
                return _i;
            return rowNumber;
        }
    }
}