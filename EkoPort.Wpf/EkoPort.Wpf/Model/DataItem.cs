using EkoPort.Wpf.Mvvm;

namespace EkoPort.Wpf
{
    public abstract class DataItem : NotificationObject
    {
        private int _id;
        private int _number;
        private string _name;

        public int Id
        {
            get { return _id; }
            set
            {
                if (_id == value)
                    return;
                _id = value;
                RaisePropertyChanged(() => Id);
            }
        }

        public int Number
        {
            get { return _number; }
            set
            {
                if (_number == value)
                    return;
                _number = value;
                RaisePropertyChanged(() => Number);
            }
        }

        public string Name
        {
            get { return _name; }
            set
            {
                if (_name == value)
                    return;
                _name = value;
                RaisePropertyChanged(() => Name);
            }
        }
    }
}
