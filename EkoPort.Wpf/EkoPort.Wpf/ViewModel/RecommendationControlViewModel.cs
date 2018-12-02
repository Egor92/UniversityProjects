using System;
using System.Windows.Input;
using EkoPort.Wpf.Mvvm;

namespace EkoPort.Wpf
{
    public class RecommendationControlViewModel : ViewModelBase
    {
        private DataItemCollection<TransshippingArea> _transshippingAreas;

        public DataItemCollection<TransshippingArea> TransshippingAreas
        {
            get { return _transshippingAreas ?? (_transshippingAreas = DataBase.TransshippingAreas); }
        }

        private EnvironmentalEquipmentType[] _environmentalEquipmentTypes;

        public EnvironmentalEquipmentType[] EnvironmentalEquipmentTypes
        {
            get { return _environmentalEquipmentTypes ?? (_environmentalEquipmentTypes = GetEnvironmentalEquipmentTypes()); }
        }

        private static EnvironmentalEquipmentType[] GetEnvironmentalEquipmentTypes()
        {
            return (EnvironmentalEquipmentType[])Enum.GetValues(typeof(EnvironmentalEquipmentType));
        }
        private DataItemCollection<Contaminant> _contaminants;

        public DataItemCollection<Contaminant> Contaminants
        {
            get { return _contaminants ?? (_contaminants = DataBase.Contaminants); }
        }

        public TransshippingArea SelectedTransshippingArea { get; set; }

        private EnvironmentalEquipmentType? _selectedEnvironmentalEquipmentType;
        public EnvironmentalEquipmentType? SelectedEnvironmentalEquipmentType
        {
            get { return _selectedEnvironmentalEquipmentType; }
            set
            {
                if (_selectedEnvironmentalEquipmentType == value)
                    return;
                _selectedEnvironmentalEquipmentType = value;
                UpdateEnvironmentalEquipmentRecomendationItemVMs();
                RaisePropertyChanged(() => EnvironmentalEquipmentRecomendationItemVMs);
            }
        }

        public Contaminant SelectedContaminant { get; set; }

        public double PredictedConcentration { get; set; }

        public int InflationFactor { get; set; }

        private double _damage;

        public double Damage
        {
            get { return _damage; }
            set
            {
                if (_damage == value)
                    return;
                _damage = value;
                RaisePropertyChanged(() => Damage);
            }
        }

        private ViewModelObservableCollection<EnvironmentalEquipment, EnvironmentalEquipmentRecomendationItemViewModel> _environmentalEquipmentRecomendationItemVMs;

        public ViewModelObservableCollection<EnvironmentalEquipment, EnvironmentalEquipmentRecomendationItemViewModel> EnvironmentalEquipmentRecomendationItemVMs
        {
            get { return _environmentalEquipmentRecomendationItemVMs ?? (_environmentalEquipmentRecomendationItemVMs = GetEnvironmentalEquipmentRecomendationItemVMs()); }
        }

        private ViewModelObservableCollection<EnvironmentalEquipment, EnvironmentalEquipmentRecomendationItemViewModel> GetEnvironmentalEquipmentRecomendationItemVMs()
        {
            return new ViewModelObservableCollection<EnvironmentalEquipment, EnvironmentalEquipmentRecomendationItemViewModel>(
                DataBase.EnvironmentalEquipments,
                x => new EnvironmentalEquipmentRecomendationItemViewModel(this, x),
                x => (EnvironmentalEquipment)x.Model,
                x => x.Type == SelectedEnvironmentalEquipmentType);
        }

        private void UpdateEnvironmentalEquipmentRecomendationItemVMs()
        {
            _environmentalEquipmentRecomendationItemVMs = GetEnvironmentalEquipmentRecomendationItemVMs();
        }

        #region GetRecommendationCommand

        private ICommand _getRecommendationCommand;

        public ICommand GetRecommendationCommand
        {
            get { return _getRecommendationCommand ?? (_getRecommendationCommand = new DelegateCommand(OnGetRecommendation, CanGetRecommendation)); }
        }

        private void OnGetRecommendation()
        {
            //Здесь создаём рекомендацию
        }

        private bool CanGetRecommendation()
        {
            return true;
        }

        #endregion

        public RecommendationControlViewModel(ViewModelBase parent)
            : base(parent)
        {
        }
    }
}
