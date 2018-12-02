namespace EkoPort.Wpf
{
    public class Contaminant : DataItem
    {
        private int _transshippingAreaId;
        private double _allowableConcentration;

        public int TransshippingAreaId
        {
            get { return _transshippingAreaId; }
            set
            {
                if (_transshippingAreaId == value)
                    return;
                _transshippingAreaId = value;
                RaisePropertyChanged(() => TransshippingAreaId);
            }
        }

        public double AllowableConcentration
        {
            get { return _allowableConcentration; }
            set
            {
                if (_allowableConcentration == value)
                    return;
                _allowableConcentration = value;
                RaisePropertyChanged(() => AllowableConcentration);
            }
        }
    }
}
