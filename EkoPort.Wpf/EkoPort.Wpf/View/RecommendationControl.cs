using System.Windows;
using System.Windows.Controls;

namespace EkoPort.Wpf
{
    public class RecommendationControl : Control
    {
        static RecommendationControl()
        {
            DefaultStyleKeyProperty.OverrideMetadata(typeof (RecommendationControl), 
                new FrameworkPropertyMetadata(typeof (RecommendationControl)));
        }
    }
}
