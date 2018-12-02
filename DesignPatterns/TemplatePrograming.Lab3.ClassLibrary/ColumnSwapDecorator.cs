using System;
using TemplatePrograming.Lab2.ClassLibrary;

namespace TemplatePrograming.Lab3.ClassLibrary
{
    public class ColumnSwapDecorator : MatrixDecorator, IMatrix
    {
        private readonly int _i;
        private readonly int _j;

        public ColumnSwapDecorator(IMatrix matrix, int i, int j)
            : base(matrix)
        {
            if (i < 0 || j < 0 || i > SourceMatrix.ColumnCount - 1 || j > SourceMatrix.ColumnCount - 1)
                throw new Exception();
            _i = i;
            _j = j;
        }

        double IMatrix.GetValue(int rowNumber, int columnNumber)
        {
            int actualColumnNumber = GetActualColumnNumber(columnNumber);
            return SourceMatrix.GetValue(rowNumber, actualColumnNumber);
        }

        void IMatrix.SetValue(int rowNumber, int columnNumber, double value)
        {
            int actualColumnNumber = GetActualColumnNumber(rowNumber);
            SourceMatrix.SetValue(rowNumber, actualColumnNumber, value);
        }

        private int GetActualColumnNumber(int columnNumber)
        {
            if (columnNumber == _i)
                return _j;
            if (columnNumber == _j)
                return _i;
            return columnNumber;
        }
    }
}