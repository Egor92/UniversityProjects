using EkoPort.Wpf.Mvvm;

namespace EkoPort.Wpf
{
    public class ContaminantEditorControlViewModel
        : DataItemEditorControlViewModel<Contaminant, ContaminantItemViewModel>
    {
        protected override DataItemCollection<Contaminant> ModelCollection
        {
            get { return DataBase.Contaminants; }
        }

        public ContaminantEditorControlViewModel(DataBaseEditorControlViewModel parent)
            : base(parent)
        {
        }

        protected override ContaminantItemViewModel GetViewModel(Contaminant model)
        {
            return new ContaminantItemViewModel(this, model);
        }

        protected override Contaminant GetModel(ContaminantItemViewModel viewModel)
        {
            return (Contaminant)viewModel.Model;
        }
    }
}