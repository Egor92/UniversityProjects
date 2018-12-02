namespace EkoPort.Wpf.Mvvm
{
    public abstract class ViewModelBase : NotificationObject
    {
        public ViewModelBase Parent { get; protected internal set; }

        protected DataBase DataBase
        {
            get { return GetAncestor<MainWindowViewModel>().GetDataBase(); }
        }

        protected ViewModelBase(ViewModelBase parent)
        {
            Parent = parent;
        }

        protected TViewModel GetAncestor<TViewModel>()
            where TViewModel : ViewModelBase
        {
            if (Parent == null)
                return null;
            if (Parent is TViewModel)
                return (TViewModel)Parent;
            return Parent.GetAncestor<TViewModel>();
        }
    }
}
