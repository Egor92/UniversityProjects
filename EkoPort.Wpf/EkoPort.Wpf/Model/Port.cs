namespace EkoPort.Wpf
{
    public class Port : DataItem
    {
        private string _location;
        private int _areaSize;
        private int _recipientCount;

        public string Location
        {
            get { return _location; }
            set
            {
                if (_location == value)
                    return;
                _location = value;
                RaisePropertyChanged(() => Location);
            }
        }

        public int AreaSize
        {
            get { return _areaSize; }
            set
            {
                if (_areaSize == value)
                    return;
                _areaSize = value;
                RaisePropertyChanged(() => AreaSize);
            }
        }

        public int RecipientCount
        {
            get { return _recipientCount; }
            set
            {
                if (_recipientCount == value)
                    return;
                _recipientCount = value;
                RaisePropertyChanged(() => RecipientCount);
            }
        }
    }
}
