using EkoPort.Wpf.Mvvm;

namespace EkoPort.Wpf
{
    public class ControlStationEditorControlViewModel
        : DataItemEditorControlViewModel<ControlStation, ControlStationItemViewModel>
    {
        protected override DataItemCollection<ControlStation> ModelCollection
        {
            get { return DataBase.ControlStations; }
        }

        public ControlStationEditorControlViewModel(ViewModelBase parent)
            : base(parent)
        {
        }

        protected override ControlStationItemViewModel GetViewModel(ControlStation model)
        {
            return new ControlStationItemViewModel(this, model);
        }

        protected override ControlStation GetModel(ControlStationItemViewModel viewModel)
        {
            return (ControlStation) viewModel.Model;
        }
    }
}