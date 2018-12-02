using EkoPort.Wpf.Mvvm;

namespace EkoPort.Wpf
{
    public class EnvironmentalEquipmentRecomendationItemViewModel : EnvironmentalEquipmentItemViewModel
    {
        private string _preference;

        public string Preference
        {
            get { return _preference; }
            set
            {
                if (_preference == value)
                    return;
                _preference = value;
                RaisePropertyChanged(() => Preference);
            }
        }

        public EnvironmentalEquipmentRecomendationItemViewModel(ViewModelBase parent, EnvironmentalEquipment model) 
            : base(parent, model)
        {
        }
    }
}
