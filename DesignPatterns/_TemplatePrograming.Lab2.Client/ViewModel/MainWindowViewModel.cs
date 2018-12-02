using System;
using System.Windows.Input;
using TemplatePrograming.Lab1.ClassLibrary;
using TrumpSoftware.Mvvm;
using DelegateCommand = TrumpSoftware.Wpf.DelegateCommand;

namespace TemplatePrograming.Lab2.Client
{
    public class MainWindowViewModel : NotificationObject
    {
        private bool _isFirstSchemeSelected = true;
        private bool _isSecondSchemeSelected;
        private bool _isThirdSchemeSelected;
        private bool _isFourthSchemeSelected;
        private Matrix _simpleMatrix;
        private SparseMatrix _sparseMatrix;

        public bool IsFirstSchemeSelected
        {
            get { return _isFirstSchemeSelected; }
            set
            {
                if (_isFirstSchemeSelected == value)
                    return;
                _isFirstSchemeSelected = value;
                RaisePropertyChanged(() => IsFirstSchemeSelected);
                DisplayMatrixes();
            }
        }

        public bool IsSecondSchemeSelected
        {
            get { return _isSecondSchemeSelected; }
            set
            {
                if (_isSecondSchemeSelected == value)
                    return;
                _isSecondSchemeSelected = value;
                RaisePropertyChanged(() => IsSecondSchemeSelected);
                DisplayMatrixes();
            }
        }

        public bool IsThirdSchemeSelected
        {
            get { return _isThirdSchemeSelected; }
            set
            {
                if (_isThirdSchemeSelected == value)
                    return;
                _isThirdSchemeSelected = value;
                RaisePropertyChanged(() => IsThirdSchemeSelected);
                DisplayMatrixes();
            }
        }

        public bool IsFourthSchemeSelected
        {
            get { return _isFourthSchemeSelected; }
            set
            {
                if (_isFourthSchemeSelected == value)
                    return;
                _isFourthSchemeSelected = value;
                RaisePropertyChanged(() => IsFourthSchemeSelected);
                DisplayMatrixes();
            }
        }

        public SimpleMatrixControlViewModel SimpleMatrixControlViewModel
        {
            get
            {
                var selectedScheme = GetSelectedScheme();
                if (_simpleMatrix == null || selectedScheme == null)
                    return null;
                return new SimpleMatrixControlViewModel(_simpleMatrix, GetSelectedScheme());
            }
        }

        public SparseMatrixControlViewModel SparseMatrixControlViewModel
        {
            get
            {
                var selectedScheme = GetSelectedScheme();
                if (_sparseMatrix == null || selectedScheme == null)
                    return null;
                return new SparseMatrixControlViewModel(_sparseMatrix, GetSelectedScheme());
            }
        }

        #region GenerateMatrixCommand

        private ICommand _generateMatrixCommand;

        public ICommand GenerateMatrixCommand
        {
            get { return _generateMatrixCommand ?? (_generateMatrixCommand = new DelegateCommand(OnGenerateMatrix)); }
        }

        private void OnGenerateMatrix()
        {
            var random = new Random(DateTime.Now.Millisecond);
            var rowCount = random.Next(3, 7);
            var columnCount = random.Next(3, 7);
            _simpleMatrix = new Matrix(rowCount, columnCount);
            _sparseMatrix = new SparseMatrix(rowCount, columnCount);
            for (int i = 0; i < rowCount; i++)
            {
                for (int j = 0; j < columnCount; j++)
                {
                    double value = random.NextDouble() > 0.5
                        ? 10 * random.NextDouble()
                        : 0.0;
                    _simpleMatrix.SetValue(i, j, value);
                    _sparseMatrix.SetValue(i, j, value);
                }
            }
            DisplayMatrixes();
        }

        #endregion

        private IMatrixVisualizationScheme GetSelectedScheme()
        {
            if (IsFirstSchemeSelected)
                return MatrixVisualizationSchemes.First;
            if (IsSecondSchemeSelected)
                return MatrixVisualizationSchemes.Second;
            if (IsThirdSchemeSelected)
                return MatrixVisualizationSchemes.Third;
            if (IsFourthSchemeSelected)
                return MatrixVisualizationSchemes.Fourth;
            return null;
        }

        private void DisplayMatrixes()
        {
            RaisePropertyChanged(() => SimpleMatrixControlViewModel);
            RaisePropertyChanged(() => SparseMatrixControlViewModel);
        }
    }
}
