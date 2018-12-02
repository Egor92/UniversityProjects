using EkoPort.Wpf.Mvvm;

namespace EkoPort.Wpf
{
    public class TransshippingAreaItemViewModel : DataItemViewModel
    {
        private readonly TransshippingArea _model;

        public string CargoName
        {
            get { return _model.CargoName; }
            set
            {
                if (_model.CargoName == value)
                    return;
                _model.CargoName = value;
                RaisePropertyChanged(() => CargoName);
            }
        }

        public TransshippingAreaItemViewModel(ViewModelBase parent, TransshippingArea model) 
            : base(parent, model)
        {
            _model = model;
        }
    }
}