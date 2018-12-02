using System.Collections.Generic;
using TemplatePrograming.Lab2.ClassLibrary;
using TemplatePrograming.Lab4.ClassLibrary;

namespace TemplatePrograming.Lab4.Client
{
    public static class MatrixFactory
    {
        private static Matrix GetSimpleMatrix(int maxSize)
        {
            int rowCount = RandomHelper.GetInt(1, maxSize);
            int columnCount = RandomHelper.GetInt(1, maxSize);
            var matrix = new Matrix(rowCount, columnCount);
            FillMatrix(matrix);
            return matrix;
        }

        private static SparseMatrix GetSparseMatrix(int maxSize)
        {
            int rowCount = RandomHelper.GetInt(1, maxSize);
            int columnCount = RandomHelper.GetInt(1, maxSize);
            var matrix = new SparseMatrix(rowCount, columnCount);
            FillMatrix(matrix);
            return matrix;
        }

        private static void FillMatrix(IMatrix matrix)
        {
            for (int i = 0; i < matrix.RowCount; i++)
            {
                for (int j = 0; j < matrix.ColumnCount; j++)
                {
                    var value = RandomHelper.GetBool()
                        ? RandomHelper.GetDouble(0.0, 9.9)
                        : 0.0;
                    matrix.SetValue(i, j, value);
                }
            }
        }

        private static MatrixBase GetMatrixBase(int maxSize)
        {
            bool isSparse = RandomHelper.GetBool();
            if (isSparse)
                return GetSparseMatrix(maxSize);
            return GetSimpleMatrix(maxSize);
        }

        private static IMatrix GetMatrix(int depth, int maxGroupWidth, int maxSize, bool isHorizontal)
        {
            if (depth == 1)
                return GetMatrixBase(maxSize);

            int groupWidth = RandomHelper.GetInt(1, maxGroupWidth);
            IList<IMatrix> matrixes = new IMatrix[groupWidth];
            for (int i = 0; i < groupWidth; i++)
                matrixes[i] = GetMatrix(depth - 1, maxGroupWidth, maxSize);

            if (isHorizontal)
                return new HorizontalMatrixGroup(matrixes);
            return new VerticalMatrixGroup(matrixes);
        }

        public static IMatrix GetMatrix(int depth, int maxGroupWidth, int maxSize)
        {
            var isHorizontal = RandomHelper.GetBool();
            return GetMatrix(depth, maxGroupWidth, maxSize, isHorizontal);
        }
    }
}
