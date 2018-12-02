using TemplatePrograming.Lab2.ClassLibrary;
using TemplatePrograming.Lab5.ClassLibrary;

namespace TemplatePrograming.Lab5.Client
{
    public class InitializeAppCommand : Command
    {
        private readonly Ref<IMatrix> _matrixRef;
        private readonly int _rowCount;
        private readonly int _columnCount;
        private readonly double[,] _values;

        public InitializeAppCommand(Ref<IMatrix> matrixRef)
        {
            _matrixRef = matrixRef;
            _rowCount = RandomHelper.GetInteger(2, 4);
            _columnCount = RandomHelper.GetInteger(2, 4);
            _values = new double[_rowCount, _columnCount];
            for (int i = 0; i < _rowCount; i++)
            {
                for (int j = 0; j < _columnCount; j++)
                {
                    _values[i, j] = RandomHelper.GetDouble(0, 1) > 0.5
                            ? 10 * RandomHelper.GetDouble(0, 1)
                            : 0.0;
                }
            }
        }

        public override void Execute()
        {
            _matrixRef.Value = new Matrix(_rowCount, _columnCount);
            for (int i = 0; i < _rowCount; i++)
            {
                for (int j = 0; j < _columnCount; j++)
                {
                    _matrixRef.Value.SetValue(i, j, _values[i, j]);
                }
            }
        }
    }
}