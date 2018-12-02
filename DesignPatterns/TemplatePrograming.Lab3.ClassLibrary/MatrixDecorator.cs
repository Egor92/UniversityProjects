using System;
using TemplatePrograming.Lab2.ClassLibrary;

namespace TemplatePrograming.Lab3.ClassLibrary
{
    public abstract class MatrixDecorator : IMatrix
    {
        public IMatrix SourceMatrix { get; private set; }

        protected MatrixDecorator(IMatrix matrix)
        {
            if (matrix == null)
                throw new ArgumentNullException("matrix");
            SourceMatrix = matrix;
        }

        public IMatrix GetOriginalMatrix()
        {
            var matrixDecorator = SourceMatrix as MatrixDecorator;
            if (matrixDecorator != null)
                return matrixDecorator.GetOriginalMatrix();
            return SourceMatrix;
        }

        int IMatrix.RowCount
        {
            get { return SourceMatrix.RowCount; }
        }

        int IMatrix.ColumnCount
        {
            get { return SourceMatrix.ColumnCount; }
        }

        double IMatrix.GetValue(int rowNumber, int columnNumber)
        {
            return SourceMatrix.GetValue(rowNumber, columnNumber);
        }

        void IMatrix.SetValue(int rowNumber, int columnNumber, double value)
        {
            SourceMatrix.SetValue(rowNumber, columnNumber, value);
        }

        void IMatrix.Draw(IMatrixDrawer matrixDrawer, int startRowIndex, int startColumnIndex, bool toClear)
        {
            if (toClear)
                matrixDrawer.Clear();
            var thisMatrix = (IMatrix) this;
            for (int i = 0; i < thisMatrix.RowCount; i++)
            {
                for (int j = 0; j < thisMatrix.ColumnCount; j++)
                {
                    matrixDrawer.DrawCell(this, i, j);
                }
            }
        }
    }
}