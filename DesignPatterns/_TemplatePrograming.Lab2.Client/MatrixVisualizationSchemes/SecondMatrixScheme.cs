using System.Windows.Media;

namespace TemplatePrograming.Lab2.Client
{
    public class SecondMatrixScheme : IMatrixVisualizationScheme
    {
        public double ItemSize
        {
            get { return 30; }
        }

        public Brush MatrixBorderBrush
        {
            get { return Brushes.Green; }
        }

        public Brush MatrixBackground
        {
            get { return Brushes.HotPink; }
        }

        public Brush ItemBorderBrush
        {
            get { return Brushes.LightBlue; }
        }

        public Brush ValueItemBackground
        {
            get { return Brushes.Chocolate; }
        }

        public Brush EmptyItemBackground
        {
            get { return Brushes.CornflowerBlue; }
        }

        public bool IsShadowVisible
        {
            get { return true; }
        }
    }
}
