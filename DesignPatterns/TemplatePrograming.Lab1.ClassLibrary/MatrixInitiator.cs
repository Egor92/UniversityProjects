using System;

namespace TemplatePrograming.Lab1.ClassLibrary
{
    public static class MatrixInitiator
    {
        private static readonly Random Random = new Random();

        public static void Fill(IMatrix matrix, int notNullValuesCount, int maxValue)
        {
            int cellCount = matrix.RowCount*matrix.ColumnCount;
            if (notNullValuesCount > cellCount)
                notNullValuesCount = cellCount;

            while (notNullValuesCount > 0)
            {
                double newValue = 0.0;
                while (newValue == 0.0)
                    newValue = maxValue * Random.NextDouble();

                while (true)
                {
                    int rowNumber = Random.Next(matrix.RowCount);
                    int columnNumber = Random.Next(matrix.ColumnCount);
                    double currentValue = matrix.GetValue(rowNumber, columnNumber);
                    if (currentValue == 0.0)
                    {
                        matrix.SetValue(rowNumber, columnNumber, newValue);
                        break;
                    }
                }
                notNullValuesCount--;
            }
        }
    }
}