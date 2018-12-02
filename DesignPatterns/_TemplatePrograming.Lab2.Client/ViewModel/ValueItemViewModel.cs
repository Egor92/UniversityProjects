using System.Windows.Media;
using TrumpSoftware.Mvvm;

namespace TemplatePrograming.Lab2.Client
{
    public class ValueItemViewModel : NotificationObject
    {
        private readonly IMatrixVisualizationScheme _scheme;
        public double Value { get; private set; }

        public double ItemSize
        {
            get { return _scheme.ItemSize; }
        }

        public Brush ItemBorderBrush
        {
            get { return _scheme.ItemBorderBrush; }
        }

        public Brush ValueItemBackground
        {
            get { return _scheme.ValueItemBackground; }
        }

        public Brush EmptyItemBackground
        {
            get { return _scheme.EmptyItemBackground; }
        }

        public bool IsShadowVisible
        {
            get { return _scheme.IsShadowVisible; }
        }

        public ValueItemViewModel(IMatrixVisualizationScheme scheme, double value)
        {
            _scheme = scheme;
            Value = value;
        }
    }
}
