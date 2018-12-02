using System;

namespace TemplatePrograming.Lab1.ClassLibrary
{
    public abstract class MatrixBase : IMatrix
    {
        private readonly IVector[] _vectors;

        public int RowCount { get; private set; }

        public int ColumnCount { get; private set; }

        protected MatrixBase(int rowCount, int columnCount)
        {
            _vectors = new IVector[rowCount];
            RowCount = rowCount;
            ColumnCount = columnCount;
            for (int i = 0; i < rowCount; i++)
                _vectors[i] = GetVector(columnCount);
        }

        public double GetValue(int rowNumber, int columnNumber)
        {
            if (rowNumber < 0 || rowNumber > RowCount - 1)
                throw new ArgumentOutOfRangeException("rowNumber");
            if (columnNumber < 0 || columnNumber > ColumnCount - 1)
                throw new ArgumentOutOfRangeException("columnNumber");
            return _vectors[rowNumber].GetValue(columnNumber);
        }

        public void SetValue(int rowNumber, int columnNumber, double value)
        {
            if (rowNumber < 0 || rowNumber > RowCount - 1)
                throw new ArgumentOutOfRangeException("rowNumber");
            if (columnNumber < 0 || columnNumber > ColumnCount - 1)
                throw new ArgumentOutOfRangeException("columnNumber");
            _vectors[rowNumber].SetValue(columnNumber, value);
        }

        protected abstract IVector GetVector(int dimension);
    }
}