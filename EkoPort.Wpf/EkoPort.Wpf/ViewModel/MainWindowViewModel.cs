using System.IO;
using System.Windows;
using System.Windows.Input;
using EkoPort.Wpf.Mvvm;
using Microsoft.Win32;
using Newtonsoft.Json;

namespace EkoPort.Wpf
{
    public class MainWindowViewModel : ViewModelBase
    {
        private readonly DataBase _dataBase = new DataBase();
        private string _openedFilePath;

        private DataBaseEditorControlViewModel _dataBaseEditorControlViewModel;

        public DataBaseEditorControlViewModel DataBaseEditorControlViewModel
        {
            get { return _dataBaseEditorControlViewModel ?? (_dataBaseEditorControlViewModel = new DataBaseEditorControlViewModel(this)); }
        }

        private EnvironmentalEquipmentEditorControlViewModel _transshippingEnvironmentalEquipmentEditorControlViewModel;

        public EnvironmentalEquipmentEditorControlViewModel TransshippingEnvironmentalEquipmentEditorControlViewModel
        {
            get { return _transshippingEnvironmentalEquipmentEditorControlViewModel ?? (_transshippingEnvironmentalEquipmentEditorControlViewModel = new EnvironmentalEquipmentEditorControlViewModel(this, EnvironmentalEquipmentType.Transshipping)); }
        }

        private EnvironmentalEquipmentEditorControlViewModel _storageEnvironmentalEquipmentEditorControlViewModel;

        public EnvironmentalEquipmentEditorControlViewModel StorageEnvironmentalEquipmentEditorControlViewModel
        {
            get { return _storageEnvironmentalEquipmentEditorControlViewModel ?? (_storageEnvironmentalEquipmentEditorControlViewModel = new EnvironmentalEquipmentEditorControlViewModel(this, EnvironmentalEquipmentType.Storage)); }
        }

        private RecommendationControlViewModel _recommendationControlViewModel;

        public RecommendationControlViewModel RecommendationControlViewModel
        {
            get { return _recommendationControlViewModel ?? (_recommendationControlViewModel = new RecommendationControlViewModel(this)); }
        }

        public MainWindowViewModel() 
            : base(null)
        {
        }
        
        #region NewFileCommand

        private ICommand _newFileCommand;

        public ICommand NewFileCommand
        {
            get { return _newFileCommand ?? (_newFileCommand = new DelegateCommand(OnNewFile)); }
        }

        private void OnNewFile()
        {
            if (_dataBase.HasChanges)
            {
                var messageBoxResult = MessageBox.Show("Текущий файл не сохранён. Вы действительно хотите создать новый файл? Все несохранённые данные будут утеряны",
                    "Текущий файл не сохранён!", MessageBoxButton.YesNo, MessageBoxImage.Warning);
                if (messageBoxResult == MessageBoxResult.No)
                    return;
            }
            _dataBase.Clear();
            _openedFilePath = null;
            _dataBase.HasChanges = false;
        }

        #endregion

        #region OpenFileCommand

        private ICommand _openFileCommand;

        public ICommand OpenFileCommand
        {
            get { return _openFileCommand ?? (_openFileCommand = new DelegateCommand(OnOpenFile)); }
        }

        private void OnOpenFile()
        {
            if (_dataBase.HasChanges)
            {
                var messageBoxResult = MessageBox.Show("Текущий файл не сохранён. Вы действительно хотите открыть новый файл? Все несохранённые данные будут утеряны",
                    "Текущий файл не сохранён!", MessageBoxButton.YesNo, MessageBoxImage.Warning);
                if (messageBoxResult == MessageBoxResult.No)
                    return;
            }
            var openFileDialog = new OpenFileDialog
            {
                Filter = "DataBase (*.db)|*.db|All files|*.*",
            };
            if (openFileDialog.ShowDialog() != true) 
                return;
            _dataBase.Clear();
            try
            {
                var text = File.ReadAllText(openFileDialog.FileName);
                var deserializedDataBase = JsonConvert.DeserializeObject<DataBase>(text);
                _dataBase.Merge(deserializedDataBase);
                _openedFilePath = openFileDialog.FileName;
            }
            catch
            {
                MessageBox.Show("Файл не является файлом базы данных",
                    "Ошибка при чтении файла!", MessageBoxButton.OK, MessageBoxImage.Error);
            }
            _dataBase.HasChanges = false;
        }

        #endregion

        #region SaveFileCommand

        private ICommand _saveFileCommand;

        public ICommand SaveFileCommand
        {
            get { return _saveFileCommand ?? (_saveFileCommand = new DelegateCommand(OnSaveFile, CanSaveFile)); }
        }

        private void OnSaveFile()
        {
            var text = JsonConvert.SerializeObject(_dataBase);
            File.WriteAllText(_openedFilePath, text);
            _dataBase.HasChanges = false;
        }

        private bool CanSaveFile()
        {
            return _openedFilePath != null;
        }

        #endregion

        #region SaveFileAsCommand

        private ICommand _saveFileAsCommand;

        public ICommand SaveFileAsCommand
        {
            get { return _saveFileAsCommand ?? (_saveFileAsCommand = new DelegateCommand(OnSaveFileAs)); }
        }

        private void OnSaveFileAs()
        {
            var saveFileDialog = new SaveFileDialog
            {
                Filter = "DataBase (*.db)|*.db|All files|*.*",
            };
            if (saveFileDialog.ShowDialog() != true)
                return;
            _openedFilePath = saveFileDialog.FileName;
            var text = JsonConvert.SerializeObject(_dataBase);
            File.WriteAllText(_openedFilePath, text);
            _dataBase.HasChanges = false;
        }

        #endregion

        public DataBase GetDataBase()
        {
            return _dataBase;
        }
    }
}
