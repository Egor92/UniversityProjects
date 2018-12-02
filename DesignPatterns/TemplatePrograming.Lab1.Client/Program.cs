using System;
using TemplatePrograming.Lab1.ClassLibrary;

namespace TemplatePrograming.Lab1.Client
{
    static class Program
    {
        static void Main(string[] args)
        {
            const int rowCount = 5;
            const int columnCount = 5;
            const int notNullValuesCount = 16;
            const int maxValue = 9;

            IMatrix matrix = new Matrix(rowCount, columnCount);
            IMatrix sparseMatrix = new SparseMatrix(rowCount, columnCount);

            MatrixInitiator.Fill(matrix, notNullValuesCount, maxValue);
            Console.WriteLine("Matrix:");
            WriteMatrixToConsole(matrix);
            WriteMatrixInfo(matrix);

            Console.WriteLine("SparseMatrix:");
            MatrixInitiator.Fill(sparseMatrix, notNullValuesCount, maxValue);
            WriteMatrixToConsole(sparseMatrix);
            WriteMatrixInfo(sparseMatrix);

            Console.Read();
        }

        private static void WriteMatrixToConsole(IMatrix matrix)
        {
            for (int i = 0; i < matrix.RowCount; i++)
            {
                for (int j = 0; j < matrix.ColumnCount; j++)
                {
                    double value = matrix.GetValue(i, j);
                    Console.Write("{0} ", value.ToString(@"F1"));
                }
                Console.WriteLine();
            }
        }

        private static void WriteMatrixInfo(IMatrix matrix)
        {
            var matrixStatistics = new MatrixStatistics(matrix);
            Console.WriteLine("ValuesSumma = {0}", matrixStatistics.ValuesSumma);
            Console.WriteLine("AverageValue = {0}", matrixStatistics.AverageValue);
            Console.WriteLine("NotNullValuesCount = {0}", matrixStatistics.NotNullValuesCount);
        }
    }
}
