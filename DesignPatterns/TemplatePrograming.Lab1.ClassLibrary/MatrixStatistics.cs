namespace TemplatePrograming.Lab1.ClassLibrary
{
    public class MatrixStatistics
    {
        private readonly IMatrix _matrix;

        public double ValuesSumma
        {
            get
            {
                double result = 0.0;
                for (int i = 0; i < _matrix.RowCount; i++)
                {
                    for (int j = 0; j < _matrix.ColumnCount; j++)
                    {
                        result += _matrix.GetValue(i, j);
                    }
                }
                return result;
            }
        }

        public double AverageValue
        {
            get { return ValuesSumma / (_matrix.RowCount * _matrix.ColumnCount); }
        }

        public int NotNullValuesCount
        {
            get
            {
                int result = 0;
                for (int i = 0; i < _matrix.RowCount; i++)
                {
                    for (int j = 0; j < _matrix.ColumnCount; j++)
                    {
                        if (_matrix.GetValue(i, j) == 0.0)
                            result++;
                    }
                }
                return result;
            }
        }

        public MatrixStatistics(IMatrix matrix)
        {
            _matrix = matrix;
        }
    }
}