using System.Windows.Media;

namespace TemplatePrograming.Lab2.Client
{
    public class ThirdMatrixScheme : IMatrixVisualizationScheme
    {
        public double ItemSize
        {
            get { return 45; }
        }

        public Brush MatrixBorderBrush
        {
            get { return Brushes.Black; }
        }

        public Brush MatrixBackground
        {
            get { return null; }
        }

        public Brush ItemBorderBrush
        {
            get { return Brushes.Black; }
        }

        public Brush ValueItemBackground
        {
            get { return null; }
        }

        public Brush EmptyItemBackground
        {
            get { return null; }
        }

        public bool IsShadowVisible
        {
            get { return false; }
        }
    }
}
