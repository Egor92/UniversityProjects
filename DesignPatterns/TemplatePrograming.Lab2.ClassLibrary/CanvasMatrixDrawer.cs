using System;
using System.Globalization;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Media.Effects;

namespace TemplatePrograming.Lab2.ClassLibrary
{
    public class CanvasMatrixDrawer : IMatrixDrawer
    {
        private static readonly DropShadowEffect DropShadowEffect = new DropShadowEffect();
        private readonly Canvas _canvas;

        public IMatrixVisualizationScheme Scheme { get; set; }

        public CanvasMatrixDrawer(Canvas canvas, IMatrixVisualizationScheme scheme)
        {
            if (canvas == null)
                throw new ArgumentNullException("canvas");
            _canvas = canvas;
            Scheme = scheme;
        }

        public void Clear()
        {
            _canvas.Children.Clear();
        }

        public void DrawCell(IMatrix matrix, int rowIndex, int columnIndex, int startRowIndex, int startColumnIndex)
        {
            var border = new Border
            {
                Height = Scheme.ItemSize,
                Width = Scheme.ItemSize,
                BorderThickness = new Thickness(2),
                BorderBrush = Scheme.ItemBorderBrush,
                Background = Scheme.ValueItemBackground
            };
            Canvas.SetTop(border, (startRowIndex + rowIndex) * Scheme.ItemSize);
            Canvas.SetLeft(border, (startColumnIndex + columnIndex) * Scheme.ItemSize);
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
            if (Scheme.IsShadowVisible)
            {
                border.Effect = DropShadowEffect;
                textBlock.Effect = DropShadowEffect;
            }
            _canvas.Children.Add(border);
        }
    }
}
