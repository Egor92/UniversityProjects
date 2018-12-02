using System.Windows;
using System.Windows.Controls;

namespace EkoPort.Wpf
{
    public class DataBaseEditorControl : Control
    {
        static DataBaseEditorControl()
        {
            DefaultStyleKeyProperty.OverrideMetadata(typeof (DataBaseEditorControl), 
                new FrameworkPropertyMetadata(typeof (DataBaseEditorControl)));
        }
    }
}
