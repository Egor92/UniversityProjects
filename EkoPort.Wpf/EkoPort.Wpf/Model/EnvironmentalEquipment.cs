using System.ComponentModel;

namespace EkoPort.Wpf
{
    public class EnvironmentalEquipment : DataItem
    {
        private int _cost;
        private double _cleaningDegree;
        private EnvironmentalEquipmentType _type;

        public int Cost
        {
            get { return _cost; }
            set
            {
                if (_cost == value)
                    return;
                _cost = value;
                RaisePropertyChanged(() => Cost);
            }
        }
        public double CleaningDegree
        {
            get { return _cleaningDegree; }
            set
            {
                if (_cleaningDegree == value)
                    return;
                _cleaningDegree = value;
                RaisePropertyChanged(() => CleaningDegree);
            }
        }

        public EnvironmentalEquipmentType Type
        {
            get { return _type; }
            set
            {
                if (_type == value)
                    return;
                _type = value;
                RaisePropertyChanged(() => Type);
            }
        }
    }

    public enum EnvironmentalEquipmentType
    {
        [Description("Перегрузка")]
        Transshipping,
        [Description("Склад")]
        Storage
    }
}