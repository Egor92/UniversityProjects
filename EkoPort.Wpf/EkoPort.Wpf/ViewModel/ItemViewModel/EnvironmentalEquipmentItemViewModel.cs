using EkoPort.Wpf.Mvvm;

namespace EkoPort.Wpf
{
    public class EnvironmentalEquipmentItemViewModel : DataItemViewModel
    {
        private readonly EnvironmentalEquipment _model;

        public int Cost
        {
            get { return _model.Cost; }
            set
            {
                if (_model.Cost == value)
                    return;
                _model.Cost = value;
                RaisePropertyChanged(() => Cost);
            }
        }

        public double CleaningDegree
        {
            get { return _model.CleaningDegree; }
            set
            {
                if (_model.CleaningDegree == value)
                    return;
                _model.CleaningDegree = value;
                RaisePropertyChanged(() => CleaningDegree);
            }
        }

        public EnvironmentalEquipmentItemViewModel(ViewModelBase parent, EnvironmentalEquipment model) 
            : base(parent, model)
        {
            _model = model;
        }
    }
}
