using System.Windows.Input;
using EkoPort.Wpf.Mvvm;

namespace EkoPort.Wpf
{
    public abstract class DataItemEditorControlViewModel<TModel, TViewModel> : ViewModelBase
        where TModel : DataItem, new() 
        where TViewModel : DataItemViewModel
    {
        protected abstract DataItemCollection<TModel> ModelCollection { get; }

        #region Items

        private ViewModelObservableCollection<TModel, TViewModel> _items;

        public ViewModelObservableCollection<TModel, TViewModel> Items
        {
            get { return _items ?? (_items = GetItems()); }
        }

        private ViewModelObservableCollection<TModel, TViewModel> GetItems()
        {
            return new ViewModelObservableCollection<TModel, TViewModel>(ModelCollection, GetViewModel, GetModel, GetModelFilter);
        }

        #endregion

        #region SelectedItem

        public TViewModel SelectedItem { get; set; }

        #endregion

        protected DataItemEditorControlViewModel(ViewModelBase parent)
            : base(parent)
        {
        }

        #region AddItemCommand

        private ICommand _addItemCommand;

        public ICommand AddItemCommand
        {
            get { return _addItemCommand ?? (_addItemCommand = new DelegateCommand(OnAddItem)); }
        }

        private void OnAddItem()
        {
            var model = new TModel();
            PrepearNewItem(model);
            ModelCollection.Add(model);
        }

        #endregion

        #region RemoveSelectedItemCommand

        private ICommand _removeSelectedItemCommand;

        public ICommand RemoveSelectedItemCommand
        {
            get { return _removeSelectedItemCommand ?? (_removeSelectedItemCommand = new DelegateCommand(OnRemoveSelectedItem, CanRemoveSelectedItem)); }
        }

        private void OnRemoveSelectedItem()
        {
            Items.Remove(SelectedItem);
        }

        private bool CanRemoveSelectedItem()
        {
            return SelectedItem != null;
        }

        #endregion

        protected abstract TViewModel GetViewModel(TModel model);

        protected abstract TModel GetModel(TViewModel viewModel);

        protected virtual bool GetModelFilter(TModel model)
        {
            return true;
        }

        protected virtual void PrepearNewItem(TModel item)
        {
        }
    }
}
