using System.Windows.Media;

namespace TemplatePrograming.Lab2.Client
{
    public interface IMatrixVisualizationScheme
    {
        double ItemSize { get; }
        Brush MatrixBorderBrush { get; }
        Brush MatrixBackground { get; }
        Brush ItemBorderBrush { get; }
        Brush ValueItemBackground { get; }
        Brush EmptyItemBackground { get; }
        bool IsShadowVisible { get; }
    }
}
