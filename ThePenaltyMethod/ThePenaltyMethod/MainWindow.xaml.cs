using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;
using System.Reflection;
using System.Runtime.InteropServices;
using System.Text;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

using C1.WPF.C1Chart3D;
using ThePenaltyMethod.Functions;
using ThePenaltyMethod.Functions.ObjectiveFunctions;

namespace ThePenaltyMethod
{
	/// <summary>
	/// Логика взаимодействия для MainWindow.xaml
	/// </summary>
	public partial class MainWindow : Window
	{
		public MainWindow()
		{
			InitializeComponent();
		}

		const double CanvasPointSize = 20;

		private void AddInequalityLimitationButton_Click(object sender, RoutedEventArgs e)
		{
			this.ConditionFunctionsListView.Items.Add(new ConditionFunction());
		}

		private void DeleteInequalityLimitationButton_Click(object sender, RoutedEventArgs e)
		{
			object obj = this.ConditionFunctionsListView.SelectedItem;
			if (obj != null)
				this.ConditionFunctionsListView.Items.Remove(obj);
		}
		
		private bool AllExpressionsAreCorrect()
		{
			if (this.ToUseOwnFunctionCheckBox.IsChecked == true 
			    && !(this.OwnFunctionExpression_TextBox.DataContext as OwnFunction).Value_Expression_IsCorrect)
			{
				MessageBox.Show("Целевая функция задана неверным выражением");
				return false;
			}
			
			List<ConditionFunction> funcList = this.ConditionFunctionsListView.Items.OfType<ConditionFunction>().ToList();
			for (int I=0; I<funcList.Count; I++) 
			{
				if (!funcList[I].Value_Expression_IsCorrect)
				{
					MessageBox.Show(string.Format("Ограничение №{0}, задано неверным выражением", I+1));
					return false;
				}
				if (!funcList[I].Derivative_dX_Expression_IsCorrect)
				{
					MessageBox.Show(string.Format("Производная по переменной X ограничения №{0}, задана неверным выражением", I+1));
					return false;
				}
				if (!funcList[I].Derivative_dX_Expression_IsCorrect)
				{
					MessageBox.Show(string.Format("Производная по переменной Y ограничения №{0}, задана неверным выражением", I+1));
					return false;
				}
			}
			
			return true;					
		}

		private void ExecuteButton_Click(object sender, RoutedEventArgs e)
		{
			if (!this.AllExpressionsAreCorrect())
				return;
			
			ObjectiveFunction objectiveFunction;
			if (this.ToUseOwnFunctionCheckBox.IsChecked == true)
				objectiveFunction = this.OwnFunctionExpression_TextBox.DataContext as OwnFunction;
			else
				objectiveFunction = this.FunctionSelectionComboBox.SelectedItem as ObjectiveFunction;

			List<ConditionFunction> conditionFunctions = this.ConditionFunctionsListView.Items.OfType<ConditionFunction>().ToList();
			GeneralFunction generalFunction = new GeneralFunction(objectiveFunction, 2.0, conditionFunctions);
			PenaltyMethod penaltyMethod = new PenaltyMethod(generalFunction);
			Point startPoint = new Point(this.StartPointX_DoubleUpDown.Value.Value, this.StartPointY_DoubleUpDown.Value.Value);
			double Sigma_Discrepancy = this.SigmaDiscrepancy_Slider.Value;
			double Sigma_HookJeevs = this.SigmaHookJeevs_Slider.Value;
			double h0 = this.H0_Slider.Value;
			double Gamma_0 = 1000;
			Tuple<List<Point>, int> Results_HookeJeevs = penaltyMethod.Perform(startPoint, Sigma_Discrepancy, Sigma_HookJeevs, h0, Gamma_0);
			this.BuildChart(generalFunction, Results_HookeJeevs.Item1, Math.Pow(Gamma_0, Results_HookeJeevs.Item2));
		}

		private void BuildChart(GeneralFunction function, List<Point> points, double Gamma_k)
		{
			this.PointsDataGrid.ItemsSource = null;
			this.Chart3D.Children.Clear();
			this.Chart2D.Children.Clear();

			Point minPoint = points.Last();
			// Частота сетки
			int netFrequency = (int)this.NetFrequency_Slider.Value;
			var zData = new double[netFrequency, netFrequency];
			// Масштаб
			double scale = Math.Max(points.Max(p => p.X) - points.Min(p => p.X), points.Max(p => p.Y) - points.Min(p => p.Y)) + 4;
			double step = (2*scale) / (netFrequency - 1);
			// calculate function for all points in the range  
			for (int I = 0; I < netFrequency; I++)
				for (int J = 0; J < netFrequency; J++)
				{
					double x = minPoint.X - scale + I * step;
					double y = minPoint.Y - scale + J * step;
					zData[I, netFrequency-J-1] = function.Value(new Point(x, y), Gamma_k);
				}
			// create data series
			var ds = new GridDataSeries();
			ds.Start = new Point(minPoint.X - scale, minPoint.Y - scale); ; // start for x,y
			ds.Step = new Point(step, step); // step for x,y
			ds.ZData = zData; // z-values 
			// add series to the chart
			try
			{
				this.Chart3D.Children.Add(ds);
				this.Chart2D.Children.Add(ds);
				this.PaintPoints(points, new Point(minPoint.X - scale, minPoint.Y - scale), new Point(minPoint.X + scale, minPoint.Y + scale));
				this.PointsDataGrid.ItemsSource = points;
			}
			catch (Exception ex)
			{
				MessageBox.Show("Нет точки минимума.");
			}
		}
		
		private void PaintPoints(List<Point> points, Point min, Point max)
		{
			this.PointsCanvas.Children.Clear();
			for (int I=0; I<points.Count; I++)
			{
				Ellipse ellipse = this.GetEllipse(points[I], I, (I == points.Count-1), min, max);
				ellipse.Fill = new SolidColorBrush(new Color(){A=255, R=0, B=0, G=(byte)(255*(double)I/points.Count)});
				this.PointsCanvas.Children.Add(ellipse);
				if (I != 0)
				{
					this.PointsCanvas.Children.Add(this.GetLine(points[I-1], points[I], min, max));
				}
			}
		}
		
		private Ellipse GetEllipse(Point point, int number, bool isMinimum, Point min, Point max)
		{
			Ellipse Result = new Ellipse()
			{
				Width = CanvasPointSize,
				Height = CanvasPointSize,
				ToolTip = new ToolTip()
				{
					Content = isMinimum ?
						string.Format("ТОЧКА МИНИМУМА!\n ({1}; {2})", number, point.X.ToString("f4"), point.Y.ToString("f4"))
						: string.Format("Точка №{0}:\n ({1}; {2})", number, point.X.ToString("f4"), point.Y.ToString("f4"))
				}
			};
			Point coordinates = this.GetPointCanvasCoordinates(point, min, max);
			Canvas.SetLeft(Result, coordinates.X);
			Canvas.SetBottom(Result, coordinates.Y);
			return Result;
		}

		private Line GetLine(Point point1, Point point2, Point min, Point max)
		{
			Point reformedPoint1 = this.GetPointCanvasCoordinates(point1, min, max);
			Point reformedPoint2 = this.GetPointCanvasCoordinates(point2, min, max);
			Line Result = new Line()
			{
				X1 = reformedPoint1.X,
				X2 = reformedPoint2.X,
				Y1 = reformedPoint1.Y,
				Y2 = reformedPoint2.Y,
				StrokeThickness = 15,
				Fill = Brushes.Yellow
			};
			Canvas.SetLeft(Result, 0.0);
			Canvas.SetBottom(Result, 0.0);
			return Result;
		}
		
		private Point GetPointCanvasCoordinates(Point point, Point min, Point max)
		{
			return new Point()
			{
				X = (point.X - min.X)/(max.X - min.X)*1000 - CanvasPointSize/2,
				Y = (point.Y - min.Y)/(max.Y - min.Y)*1000 - CanvasPointSize/2
			};
		}

		private void Chart3DTypeSelectionComboBox_SelectionChanged(object sender, SelectionChangedEventArgs e)
		{
			switch (this.Chart3DTypeSelectionComboBox.SelectedIndex)
			{
				case (0):
					this.Chart3D.ChartType = Chart3DType.SurfaceWireframe;
					break;
				case (1):
					this.Chart3D.ChartType = Chart3DType.SurfaceWireframeContour;
					break;
				case (2):
					this.Chart3D.ChartType = Chart3DType.Surface;
					break;
				case (3):
					this.Chart3D.ChartType = Chart3DType.SurfaceContour;
					break;
				case (4):
					this.Chart3D.ChartType = Chart3DType.SurfaceZone;
					break;
				case (5):
					this.Chart3D.ChartType = Chart3DType.SurfaceZoneContour;
					break;
				default:
					break;
			}
		}
		
		void NetFrequency_Slider_ValueChanged(object sender, RoutedPropertyChangedEventArgs<double> e)
		{
			this.NetFrequency_Slider.Value = (int) this.NetFrequency_Slider.Value;
		}

	}
}
