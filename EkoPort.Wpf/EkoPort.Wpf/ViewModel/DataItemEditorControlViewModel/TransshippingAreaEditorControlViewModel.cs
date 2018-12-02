using EkoPort.Wpf.Mvvm;

namespace EkoPort.Wpf
{
    public class TransshippingAreaEditorControlViewModel 
        : DataItemEditorControlViewModel<TransshippingArea, TransshippingAreaItemViewModel>
    {
        protected override DataItemCollection<TransshippingArea> ModelCollection
        {
            get { return DataBase.TransshippingAreas; }
        }

        public TransshippingAreaEditorControlViewModel(ViewModelBase parent)
            : base(parent)
        {
        }

        protected override TransshippingAreaItemViewModel GetViewModel(TransshippingArea model)
        {
            return new TransshippingAreaItemViewModel(this, model);
        }

        protected override TransshippingArea GetModel(TransshippingAreaItemViewModel viewModel)
        {
            return (TransshippingArea) viewModel.Model;
        }
    }
}