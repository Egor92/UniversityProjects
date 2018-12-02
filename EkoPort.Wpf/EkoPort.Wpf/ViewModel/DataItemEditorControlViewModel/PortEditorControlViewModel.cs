using EkoPort.Wpf.Mvvm;

namespace EkoPort.Wpf
{
    public class PortEditorControlViewModel
        : DataItemEditorControlViewModel<Port, PortItemViewModel>
    {
        protected override DataItemCollection<Port> ModelCollection
        {
            get { return DataBase.Ports; }
        }

        public PortEditorControlViewModel(DataBaseEditorControlViewModel parent)
            : base(parent)
        {
        }

        protected override PortItemViewModel GetViewModel(Port model)
        {
            return new PortItemViewModel(this, model);
        }

        protected override Port GetModel(PortItemViewModel viewModel)
        {
            return (Port) viewModel.Model;
        }
    }
}