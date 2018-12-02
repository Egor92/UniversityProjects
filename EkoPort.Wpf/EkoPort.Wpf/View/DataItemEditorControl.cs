using System.Windows;
using System.Windows.Controls;

namespace EkoPort.Wpf
{
    [TemplatePart(Name = DataGridContentControlName, Type = typeof(ControlTemplate))]
    public class DataItemEditorControl : Control
    {
        private const string DataGridContentControlName = @"PART_DataGridContentControl";
        private ContentControl _dataGridContentControl;

        public static readonly DependencyProperty DataGridTemplateProperty = 
            DependencyProperty.Register("DataGridTemplate", typeof (ControlTemplate), typeof (DataItemEditorControl), new FrameworkPropertyMetadata(OnDataGridTemplatePropertyChanged));

        private static void OnDataGridTemplatePropertyChanged(DependencyObject dependencyObject, DependencyPropertyChangedEventArgs e)
        {
            var dataItemEditorControl = (DataItemEditorControl) dependencyObject;
            dataItemEditorControl.OnDataGridTemplatePropertyChanged((ControlTemplate) e.NewValue);
        }

        private void OnDataGridTemplatePropertyChanged(ControlTemplate controlTemplate)
        {
            if (controlTemplate == null)
                return;
            if (_dataGridContentControl == null)
                return;
            UpdateDataGrid(controlTemplate);
        }

        public ControlTemplate DataGridTemplate
        {
            get { return (ControlTemplate) GetValue(DataGridTemplateProperty); }
            set { SetValue(DataGridTemplateProperty, value); }
        }

        static DataItemEditorControl()
        {
            DefaultStyleKeyProperty.OverrideMetadata(typeof (DataItemEditorControl), 
                new FrameworkPropertyMetadata(typeof (DataItemEditorControl)));
        }

        public override void OnApplyTemplate()
        {
            _dataGridContentControl = GetTemplateChild(DataGridContentControlName) as ContentControl;
            if (_dataGridContentControl != null)
                UpdateDataGrid(DataGridTemplate);
        }

        private void UpdateDataGrid(ControlTemplate controlTemplate)
        {
            if (controlTemplate == null)
                return;
            var dataGrid = controlTemplate.LoadContent() as DataGrid;
            _dataGridContentControl.Content = dataGrid;
        }
    }
}
