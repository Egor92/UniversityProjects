using System.Windows;
using System.Windows.Controls;

namespace TemplatePrograming.Lab2.Client
{
    public class MatrixControl : Control
    {
        static MatrixControl()
        {
            DefaultStyleKeyProperty.OverrideMetadata(typeof (MatrixControl),
                new FrameworkPropertyMetadata(typeof (MatrixControl)));
        }
    }
}
