using System;
using System.Windows.Controls;
using System.Windows.Media;
using TemplatePrograming.Lab1.ClassLibrary;
using TrumpSoftware.Mvvm;

namespace TemplatePrograming.Lab2.Client
{
    public abstract class MatrixControlViewModel : NotificationObject
    {
        private readonly IMatrix _matrix;
        private IMatrixVisualizationScheme _scheme;

        public ValueItemViewModel[][] Values
        {
            get { return GetValues(); }
        }

        public IMatrixVisualizationScheme Scheme
        {
            get { return _scheme; }
            set
            {
                if (_scheme == value)
                    return;
                _scheme = value;
                RaisePropertyChanged(() => Values);
            }
        }

        public Brush MatrixBorderBrush
        {
            get { return Scheme.MatrixBorderBrush; }
        }

        public Brush MatrixBackground
        {
            get { return Scheme.MatrixBackground; }
        }

        public abstract DataTemplateSelector ItemTemplateSelector { get; }

        protected MatrixControlViewModel(IMatrix matrix, IMatrixVisualizationScheme scheme)
        {
            if (matrix == null)
                throw new ArgumentNullException("matrix");
            if (scheme == null)
                throw new ArgumentNullException("scheme");
            _matrix = matrix;
            _scheme = scheme;
        }

        private ValueItemViewModel[][] GetValues()
        {
            var rowCount = _matrix.RowCount;
            var columnCount = _matrix.ColumnCount;
            var result = new ValueItemViewModel[rowCount][];
            for (int i = 0; i < rowCount; i++)
            {
                result[i] = new ValueItemViewModel[columnCount];
                for (int j = 0; j < columnCount; j++)
                {
                    var value = _matrix.GetValue(i, j);
                    result[i][j] = new ValueItemViewModel(Scheme, value); 
                }
            }
            return result;
        }
    }
}
