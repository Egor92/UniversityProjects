using System;
using System.Collections.Generic;
using System.Linq;
using TemplatePrograming.Lab2.ClassLibrary;

namespace TemplatePrograming.Lab4.ClassLibrary
{
    public class HorizontalMatrixGroup : IMatrix
    {
        private readonly IList<IMatrix> _matrixes;
        private int? _rowCount;
        private int? _columnCount;

        public int RowCount
        {
            get
            {
                if (_rowCount == null)
                    _rowCount = _matrixes.Sum(x => x.RowCount);
                return _rowCount.Value;
            }
        }

        public int ColumnCount
        {
            get
            {
                if (_columnCount == null)
                    _columnCount = _matrixes.Max(x => x.ColumnCount);
                return _columnCount.Value;
            }
        }


        public HorizontalMatrixGroup(IList<IMatrix> matrixes)
        {
            _matrixes = matrixes;
        }

        public void AddMatrix(IMatrix matrix)
        {
            _matrixes.Add(matrix);
            _rowCount = null;
            _columnCount = null;
        }

        public double GetValue(int rowNumber, int columnNumber)
        {
            if (!AreIndexesInMatrixBounds(rowNumber, columnNumber))
                throw new IndexOutOfRangeException();
            var submatrix = GetSubmatrix(rowNumber, columnNumber);
            if (submatrix == null)
                return 0.0;
            var columnNumberInSubmatrix = GetColumnNumberInSubmatrix(columnNumber, submatrix);
            return submatrix.GetValue(rowNumber, columnNumberInSubmatrix);
        }

        public void SetValue(int rowNumber, int columnNumber, double value)
        {
            if (!AreIndexesInMatrixBounds(rowNumber, columnNumber))
                throw new IndexOutOfRangeException();
            var submatrix = GetSubmatrix(rowNumber, columnNumber);
            if (submatrix == null)
                return;
            var columnNumberInSubmatrix = GetColumnNumberInSubmatrix(columnNumber, submatrix);
            submatrix.SetValue(rowNumber, columnNumberInSubmatrix, value);
        }

        public void Draw(IMatrixDrawer matrixDrawer, int startRowIndex, int startColumnIndex, bool toClear)
        {
            if (toClear)
                matrixDrawer.Clear();
            foreach (var matrix in _matrixes)
            {
                matrix.Draw(matrixDrawer, startRowIndex, startColumnIndex, false);
                startColumnIndex += matrix.ColumnCount;
            }
        }

        private int GetColumnNumberInSubmatrix(int columnNumber, IMatrix submatrix)
        {
            int columnNumberInSubmatrix = columnNumber;
            var submatrixIndex = _matrixes.IndexOf(submatrix);
            for (int i = 0; i < submatrixIndex; i++)
                columnNumberInSubmatrix -= _matrixes[i].ColumnCount;
            return columnNumberInSubmatrix;
        }

        private IMatrix GetSubmatrix(int rowNumber, int columnNumber)
        {
            if (!AreIndexesInMatrixBounds(rowNumber, columnNumber))
                throw new IndexOutOfRangeException();
            int currentLimit = 0;
            int submatrixIndex = -1;
            while (columnNumber > currentLimit)
            {
                submatrixIndex++;
                currentLimit += _matrixes[submatrixIndex].ColumnCount;
            }
            var subMatrix = _matrixes[submatrixIndex];
            if (rowNumber < subMatrix.RowCount)
                return null;
            return subMatrix;
        }

        private bool AreIndexesInMatrixBounds(int rowNumber, int columnNumber)
        {
            return rowNumber >= 0 && rowNumber < RowCount
                   && columnNumber >= 0 && columnNumber < ColumnCount;
        }
    }
}