using EkoPort.Wpf.Mvvm;

namespace EkoPort.Wpf
{
    public class PortItemViewModel : DataItemViewModel
    {
        private readonly Port _model;

        public string Location
        {
            get { return _model.Location; }
            set
            {
                if (_model.Location == value)
                    return;
                _model.Location = value;
                RaisePropertyChanged(() => Location);
            }
        }

        public int AreaSize
        {
            get { return _model.AreaSize; }
            set
            {
                if (_model.AreaSize == value)
                    return;
                _model.AreaSize = value;
                RaisePropertyChanged(() => AreaSize);
            }
        }

        public int RecipientCount
        {
            get { return _model.RecipientCount; }
            set
            {
                if (_model.RecipientCount == value)
                    return;
                _model.RecipientCount = value;
                RaisePropertyChanged(() => RecipientCount);
            }
        }

        public PortItemViewModel(ViewModelBase parent, Port model)
            : base(parent, model)
        {
            _model = model;
        }
    }
}
