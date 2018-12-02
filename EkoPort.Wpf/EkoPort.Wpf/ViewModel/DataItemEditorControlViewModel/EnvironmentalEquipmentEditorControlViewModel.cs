using EkoPort.Wpf.Mvvm;

namespace EkoPort.Wpf
{
    public class EnvironmentalEquipmentEditorControlViewModel 
        : DataItemEditorControlViewModel<EnvironmentalEquipment, EnvironmentalEquipmentItemViewModel>
    {
        private readonly EnvironmentalEquipmentType _environmentalEquipmentType;

        protected override DataItemCollection<EnvironmentalEquipment> ModelCollection
        {
            get { return DataBase.EnvironmentalEquipments; }
        }

        public EnvironmentalEquipmentEditorControlViewModel(ViewModelBase parent, EnvironmentalEquipmentType environmentalEquipmentType) 
            : base(parent)
        {
            _environmentalEquipmentType = environmentalEquipmentType;
        }

        protected override sealed void PrepearNewItem(EnvironmentalEquipment item)
        {
            item.Type = _environmentalEquipmentType;
        }

        protected override EnvironmentalEquipmentItemViewModel GetViewModel(EnvironmentalEquipment model)
        {
            return new EnvironmentalEquipmentItemViewModel(this, model);
        }

        protected override EnvironmentalEquipment GetModel(EnvironmentalEquipmentItemViewModel viewModel)
        {
            return (EnvironmentalEquipment)viewModel.Model;
        }

        protected override bool GetModelFilter(EnvironmentalEquipment model)
        {
            return model.Type == _environmentalEquipmentType;
        }
    }
}
