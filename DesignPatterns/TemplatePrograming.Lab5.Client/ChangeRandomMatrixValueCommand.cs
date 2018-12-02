using TemplatePrograming.Lab2.ClassLibrary;
using TemplatePrograming.Lab5.ClassLibrary;

namespace TemplatePrograming.Lab5.Client
{
    public class ChangeRandomMatrixValueCommand : Command
    {
        private readonly Ref<IMatrix> _matrixRef;
        private readonly int _rowNumber;
        private readonly int _columnNumber;
        private readonly double _value;

        public ChangeRandomMatrixValueCommand(Ref<IMatrix> matrixRef)
        {
            _matrixRef = matrixRef;
            _rowNumber = RandomHelper.GetInteger(0, _matrixRef.Value.RowCount - 1);
            _columnNumber = RandomHelper.GetInteger(0, _matrixRef.Value.ColumnCount - 1);
            _value = RandomHelper.GetDouble(0.0, 10.0);
        }

        public override void Execute()
        {
            _matrixRef.Value.SetValue(_rowNumber, _columnNumber, _value);
        }
    }
}
