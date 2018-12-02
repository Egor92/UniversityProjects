using EkoPort.Wpf.Mvvm;

namespace EkoPort.Wpf
{
    public class DataBaseEditorControlViewModel : ViewModelBase
    {
        private ContaminantEditorControlViewModel _contaminantEditorControlViewModel;
        private ControlStationEditorControlViewModel _controlStationEditorControlViewModel;
        private PortEditorControlViewModel _portEditorControlViewModel;
        private TransshippingAreaEditorControlViewModel _transshippingAreaEditorControlViewModell;

        public ContaminantEditorControlViewModel ContaminantEditorControlViewModel
        {
            get { return _contaminantEditorControlViewModel ?? (_contaminantEditorControlViewModel = new ContaminantEditorControlViewModel(this)); }
        }

        public ControlStationEditorControlViewModel ControlStationEditorControlViewModel
        {
            get { return _controlStationEditorControlViewModel ?? (_controlStationEditorControlViewModel = new ControlStationEditorControlViewModel(this)); }
        }

        public PortEditorControlViewModel PortEditorControlViewModel
        {
            get { return _portEditorControlViewModel ?? (_portEditorControlViewModel = new PortEditorControlViewModel(this)); }
        }

        public TransshippingAreaEditorControlViewModel TransshippingAreaEditorControlViewModel
        {
            get { return _transshippingAreaEditorControlViewModell ?? (_transshippingAreaEditorControlViewModell = new TransshippingAreaEditorControlViewModel(this)); }
        }

        public DataBaseEditorControlViewModel(ViewModelBase parent)
            : base(parent)
        {
        }
    }
}
