using EkoPort.Wpf.Mvvm;

namespace EkoPort.Wpf
{
    public abstract class DataItemViewModel : Mvvm.DataItemViewModel
    {
        private readonly DataItem _model;

        public int Number
        {
            get { return _model.Number; }
            set
            {
                if (_model.Number == value)
                    return;
                _model.Number = value;
                RaisePropertyChanged(() => Number);
            }
        }

        public string Name
        {
            get { return _model.Name; }
            set
            {
                if (_model.Name == value)
                    return;
                _model.Name = value;
                RaisePropertyChanged(() => Name);
            }
        }

        protected DataItemViewModel(ViewModelBase parent, DataItem model) 
            : base(parent, model)
        {
            _model = model;
        }
    }
}
