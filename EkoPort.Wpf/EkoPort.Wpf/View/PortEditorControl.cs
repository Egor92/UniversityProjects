using System.Windows;

namespace EkoPort.Wpf
{
    public class PortEditorControl : DataItemEditorControl
    {
        static PortEditorControl()
        {
            DefaultStyleKeyProperty.OverrideMetadata(typeof (PortEditorControl), 
                new FrameworkPropertyMetadata(typeof (PortEditorControl)));
        }
    }
}
