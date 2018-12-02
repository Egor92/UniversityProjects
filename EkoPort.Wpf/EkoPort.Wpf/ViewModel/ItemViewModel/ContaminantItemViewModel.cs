using System.Collections.Generic;
using System.Linq;
using EkoPort.Wpf.Mvvm;

namespace EkoPort.Wpf
{
    public class ContaminantItemViewModel : DataItemViewModel
    {
        private readonly Contaminant _model;

        public IEnumerable<TransshippingArea> AvailableTransshippingAreas
        {
            get { return DataBase.TransshippingAreas; }
        }

        public TransshippingArea SelectedTransshippingArea
        {
            get { return DataBase.TransshippingAreas.FirstOrDefault(x => x.Id == _model.TransshippingAreaId); }
            set
            {
                if (value == null)
                {
                    _model.TransshippingAreaId = 0;
                    RaisePropertyChanged(() => SelectedTransshippingArea);
                    RaisePropertyChanged(() => CargoName);
                }
                else if (_model.TransshippingAreaId != value.Id)
                {
                    _model.TransshippingAreaId = value.Id;
                    RaisePropertyChanged(() => SelectedTransshippingArea);
                    RaisePropertyChanged(() => CargoName);
                }
            }
        }

        public string CargoName
        {
            get { return SelectedTransshippingArea != null
                ? SelectedTransshippingArea.CargoName
                : null; }
        }

        public double AllowableConcentration
        {
            get { return _model.AllowableConcentration; }
            set
            {
                if (_model.AllowableConcentration == value)
                    return;
                _model.AllowableConcentration = value;
                RaisePropertyChanged(() => AllowableConcentration);
            }
        }

        public ContaminantItemViewModel(ViewModelBase parent, Contaminant model) 
            : base(parent, model)
        {
            _model = model;
        }
    }
}
