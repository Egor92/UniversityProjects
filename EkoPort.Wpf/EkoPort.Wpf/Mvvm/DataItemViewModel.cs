using System;
using System.ComponentModel;

namespace EkoPort.Wpf.Mvvm
{
    public abstract class DataItemViewModel : ViewModelBase
    {
        public DataItem Model { get; private set; }

        public int Id
        {
            get { return Model.Id; }
            set
            {
                if (Model.Id == value)
                    return;
                Model.Id = value;
                RaisePropertyChanged(() => Id);
            }
        }

        protected DataItemViewModel(ViewModelBase parent, DataItem model)
            : base(parent)
        {
            if (model == null)
                throw new ArgumentNullException("model");
            Model = model;
            Model.PropertyChanged += OnModelPropertyChanged;
        }

        private void OnModelPropertyChanged(object sender, PropertyChangedEventArgs e)
        {
            RaisePropertyChanged(e.PropertyName);
            if (e.PropertyName.EndsWith("Id"))
            {
                var selectedPopertyName = string.Format("Selected{0}", e.PropertyName.Substring(0, e.PropertyName.Length - 2));
                RaisePropertyChanged(selectedPopertyName);
            }
        }
    }
}
