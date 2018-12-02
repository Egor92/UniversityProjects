using System;
using System.Globalization;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Media;
using System.Windows.Media.Effects;
using TemplatePrograming.Lab2.ClassLibrary;

namespace TemplatePrograming.Lab4.Client
{
    public class BrightCanvasMatrixDrawer : IMatrixDrawer
    {
        private static readonly DropShadowEffect DropShadowEffect = new DropShadowEffect();
        private readonly Canvas _canvas;
        private IMatrix _lastMatrix;
        private SolidColorBrush _borderBrush;
        private SolidColorBrush _background;
        private bool _isShadowVisible;

        public BrightCanvasMatrixDrawer(Canvas canvas)
        {
            if (canvas == null)
                throw new ArgumentNullException("canvas");
            _canvas = canvas;
        }

        public void Clear()
        {
            _canvas.Children.Clear();
        }

        public void DrawCell(IMatrix matrix, int rowIndex, int columnIndex, int startRowIndex, int startColumnIndex)
        {
            if (_lastMatrix != matrix)
                ChangeScheme(matrix);
            const double cellSize = 30.0;
            var border = new Border
            {
                Height = cellSize,
                Width = cellSize,
                BorderThickness = new Thickness(2),
                BorderBrush = _borderBrush,
                Background = _background
            };
            Canvas.SetTop(border, (startRowIndex + rowIndex) * cellSize);
            Canvas.SetLeft(border, (startColumnIndex + columnIndex) * cellSize);
            double value = matrix != null
                ? matrix.GetValue(rowIndex, columnIndex)
                : 0.0;
            var textBlock = new TextBlock
            {
                Text = value.ToString("F1", CultureInfo.InvariantCulture),
                VerticalAlignment = VerticalAlignment.Center,
                HorizontalAlignment = HorizontalAlignment.Center
            };
            border.Child = textBlock;
            if (_isShadowVisible)
            {
                border.Effect = DropShadowEffect;
                textBlock.Effect = DropShadowEffect;
            }
            _canvas.Children.Add(border);
        }

        private void ChangeScheme(IMatrix matrix)
        {
            _lastMatrix = matrix;
            _borderBrush = RandomHelper.GetSolidColorBrush();
            _background = RandomHelper.GetSolidColorBrush();
            _isShadowVisible = RandomHelper.GetBool();
        }
    }
}