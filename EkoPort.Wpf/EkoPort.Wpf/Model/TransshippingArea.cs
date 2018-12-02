namespace EkoPort.Wpf
{
    public class TransshippingArea : DataItem
    {
        private string _cargoName;

        public string CargoName
        {
            get { return _cargoName; }
            set
            {
                if (_cargoName == value)
                    return;
                _cargoName = value;
                RaisePropertyChanged(() => CargoName);
            }
        }
    }
}
