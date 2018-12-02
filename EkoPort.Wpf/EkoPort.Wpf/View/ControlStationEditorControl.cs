using System.Windows;

namespace EkoPort.Wpf
{
    public class ControlStationEditorControl : DataItemEditorControl
    {
        static ControlStationEditorControl()
        {
            DefaultStyleKeyProperty.OverrideMetadata(typeof (ControlStationEditorControl),
                new FrameworkPropertyMetadata(typeof (ControlStationEditorControl)));
        }
    }
}
