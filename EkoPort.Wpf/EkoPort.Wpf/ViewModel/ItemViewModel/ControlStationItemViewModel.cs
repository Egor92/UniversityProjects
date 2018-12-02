using EkoPort.Wpf.Mvvm;

namespace EkoPort.Wpf
{
    public class ControlStationItemViewModel : DataItemViewModel
    {
        private readonly ControlStation _model;

        public ControlStationItemViewModel(ViewModelBase parent, ControlStation model) 
            : base(parent, model)
        {
            _model = model;
        }
    }
}
