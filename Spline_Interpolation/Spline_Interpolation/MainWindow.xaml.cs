using System;
using System.Collections.Generic;
using System.Linq;
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
using System.Threading.Tasks;
using Microsoft.CSharp;
using System.CodeDom.Compiler;
using System.Reflection;

namespace Spline_Interpolation
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

		const double STEP = 0.05;
		double LowerLimit;
		double UpperLimit;
		int IntervalsCount;
		double Delta 
		{ 
			get 
			{
				return (UpperLimit - LowerLimit) / IntervalsCount;
			}
		}
		Polynom[] Polynoms;
		List<Point> OriginalFunctionValues;
		List<Point> SplineFunctionValues;
		List<Point> MaxErrorFunctionValues;
		double GlobalMinValue, GlobalMaxValue;
		double MaxSquareDeviation;
		double PointOfMaxSquareDeviation;
		double Epsilon;
		MethodInfo FormulaCreator;

		private void Calculate_Click(object sender, RoutedEventArgs e)
		{
			if (!CompileFunction()) return;

			GlobalMinValue = double.MaxValue;
			GlobalMaxValue = double.MinValue;

			if (this.TypeOfExperiment.SelectedIndex == 0)
			{
				IntervalsCount = IntervalsUpDown.Value.Value + 1;

				UpperLimit = UpperFunctionLimit.Value.Value;
				LowerLimit = LowerFunctionLimit.Value.Value - (UpperLimit - LowerFunctionLimit.Value.Value) / (IntervalsCount - 1);

				InitializeOriginalFunctionPoints();

				MaxSquareDeviation = 0.0;

				Polynoms = new Polynom[IntervalsCount];
				for (int I = 0; I < IntervalsCount; I++)
				{
					Polynoms[I] = new Polynom();
					Polynoms[I].LeftLimit = GetNode(I - 1);
					Polynoms[I].RightLimit = GetNode(I);
				}

				InitializeCoefficients();

				InitializeSplineFunctionPoints();
			}
			else
			{
				IntervalsCount = 1;

				UpperLimit = UpperFunctionLimit.Value.Value;
				Epsilon = EpsilonUpDown.Value.Value;

				InitializeOriginalFunctionPoints();

				do
				{
					IntervalsCount++;

					LowerLimit = LowerFunctionLimit.Value.Value - (UpperLimit - LowerFunctionLimit.Value.Value) / (IntervalsCount - 1);

					MaxSquareDeviation = 0.0;

					Polynoms = new Polynom[IntervalsCount];
					for (int I = 0; I < IntervalsCount; I++)
					{
						Polynoms[I] = new Polynom();
						Polynoms[I].LeftLimit = GetNode(I - 1);
						Polynoms[I].RightLimit = GetNode(I);
					}

					InitializeCoefficients();

					InitializeSplineFunctionPoints();
				} while (MaxSquareDeviation > Epsilon);
			}

			InitializeMaxErrorFunctionPoints();
			FillCoefsDataGrid();

			this.ResultTextBlock.Foreground = Brushes.Black;
			ResultTextBlock.Text = string.Format("Сделано {0} разбиений интервала. Максимальная погрешность: {1} в точке x={2}",
													 IntervalsCount - 1,
													 MaxSquareDeviation.ToString("F8"),
													 PointOfMaxSquareDeviation);

		}

		private double GetNode(int I)
		{
			return LowerLimit + (I + 1) * Delta;
		}

		private double Y(int I)
		{
			return F(GetNode(I));
		}

		private double F(double X)
		{
			//return X * X * X;
			//return X*X*X - 3*X*X + 2*X - 3;
			//return (5*X*X - 3*X + 1) / (2*X*X*X + X*X*X - 3*X + 4) + Math.Sin(2*X);
			//return Math.Exp(-X);
			//return Math.Sin(X);
			return (double) FormulaCreator.Invoke(null, new object[] { X });
		}

		private double S(int I, double X)
		{
			return Polynoms[I].S(X);
		}

		private void InitializeOriginalFunctionPoints()
		{
			OriginalFunctionValues = new List<Point>();

			for (double X = LowerFunctionLimit.Value.Value; X <= UpperLimit; X += STEP)
			{
				double F = this.F(X);
				OriginalFunctionValues.Add(new Point(X, F));
				if (F < GlobalMinValue) { GlobalMinValue = F; }
				if (F > GlobalMaxValue) { GlobalMaxValue = F; }
			}

			OriginalFunctionTable.ItemsSource = OriginalFunctionValues;
		}

		private void InitializeSplineFunctionPoints()
		{
			SplineFunctionValues = new List<Point>();

			for (int I = 1; I < IntervalsCount; I++)
			{
				Polynoms[I].Xi = GetNode(I);
				for (double X = GetNode(I-1); X < GetNode(I); X += STEP)
				{
					double S = this.S(I, X);
					SplineFunctionValues.Add(new Point(X, S));

					double Difference  = Math.Abs(S - F(X));
					if (Difference > MaxSquareDeviation)
					{
						MaxSquareDeviation = Difference;
						PointOfMaxSquareDeviation = X;
					}

					if (S < GlobalMinValue) { GlobalMinValue = S; }
					if (S > GlobalMaxValue) { GlobalMaxValue = S; }
				}
			}

			SplineFunctionTable.ItemsSource = SplineFunctionValues;
		}

		private void InitializeMaxErrorFunctionPoints()
		{
			MaxErrorFunctionValues = new List<Point>();
			MaxErrorFunctionValues.Add(new Point(PointOfMaxSquareDeviation, GlobalMinValue));
			MaxErrorFunctionValues.Add(new Point(PointOfMaxSquareDeviation, GlobalMaxValue));

			MaxErrorFunctionTable.ItemsSource = MaxErrorFunctionValues;
		}

		private void FillCoefsDataGrid()
		{
			this.Polynoms[1].C = 0.0;
			this.CoefsDataGrid.ItemsSource = this.Polynoms.Skip(1);
		}

		private bool CompileFunction()
		{
			CompilerResults CResults = null;
			try
			{
				CSharpCodeProvider CodeProvider = new CSharpCodeProvider();
				CResults = CodeProvider.CompileAssemblyFromSource(new CompilerParameters(),
					@"using System; namespace Space " + '\n' + " { public class FormulaCreator { " + '\n' + " public static double F(double x) { return " + this.Formula.Text + @"; } } }");

				FormulaCreator = CResults.CompiledAssembly.CreateInstance("Space.FormulaCreator").GetType().GetMethod("F");
				return true;
			}
			catch 
			{
				this.ResultTextBlock.Text = string.Format("Ошибка: {0}", CResults.Errors[0].ErrorText);
				this.ResultTextBlock.Foreground = Brushes.Red;
				return false;
			}
		}

		private double[] GetSolutionOfMatrix()
		{
			// диагональ, лежащая под главной
			double[] A = new double[IntervalsCount];
			// диагональ, лежащая над главной
			double[] B = new double[IntervalsCount];
			// главная диагональ матрицы
			double[] C = new double[IntervalsCount];
			// правая часть (столбец)
			double[] E = new double[IntervalsCount];

			A[0] = 0.0;
			B[0] = 0.0;
			C[0] = Delta;
			E[0] = 0.0;
			Parallel.For(1, IntervalsCount, I =>
			{
				A[I] = Delta;
				B[I] = Delta;
				C[I] = 4.0 * Delta;
				E[I] = 6.0 * (Y(I + 1) - 2 * Y(I) + Y(I - 1)) / Delta;
			});
			A[A.Length - 1] = 0.0;
			B[B.Length - 1] = 0.0;
			C[C.Length - 1] = Delta;
			E[E.Length - 1] = 0.0;

			return Progonka(A, B, C, E);
		}

		private double[] Progonka(double[] A, double[] B, double[] C, double[] E)
		{
			double[] Result = new double[IntervalsCount];

			for (int I = 1; I < IntervalsCount; I++)
			{
				double M = A[I] / C[I - 1];
				C[I] = C[I] - M * B[I - 1];
				E[I] = E[I] - M * E[I - 1];
			}

			Result[IntervalsCount - 1] = E[IntervalsCount - 1] 
										/ C[IntervalsCount - 1];

			for (int I = IntervalsCount - 2; I >= 0; I--)
				Result[I] = (E[I] - B[I] * Result[I + 1]) / C[I];

			return Result;
		}

		private double[] Gauss()
		{
			double[,] A = new double[IntervalsCount, IntervalsCount];
			double[ ] B = new double[IntervalsCount];

			A[0, 0] = Delta;
			B[0] = 0.0;
			Parallel.For(1, IntervalsCount - 1, I =>
			{
				A[I, I - 1] = Delta;
				A[I, I] = 4.0 * Delta;
				A[I, I + 1] = Delta;
				B[I] = 6.0 * (Y(I + 1) - Y(I - 1));
			});
			A[IntervalsCount - 1, IntervalsCount - 1] = Delta;
			B[IntervalsCount - 1] = 0.0;

			LinearSystem linearSystem = new LinearSystem(A, B);
			return linearSystem.XVector;
		}

		private void InitializeCoefficients()
		{
			InitializeCoefsC();

			InitializeCoefsA();

			InitializeCoefsD();

			InitializeCoefsB();
		}

		private void InitializeCoefsA()
		{
			Parallel.For(1, IntervalsCount, I =>
			{
				Polynoms[I].A = Y(I);
			});
		}

		private void InitializeCoefsB()
		{
			Parallel.For(1, IntervalsCount, I =>
			{
				Polynoms[I].B = (Delta / 2) * Polynoms[I].C
									- (Delta * Delta / 6) * Polynoms[I].D
									+ (Y(I) - Y(I-1)) / Delta;
			});
		}

		private void InitializeCoefsC()
		{
			double[] C = GetSolutionOfMatrix();
			//double[] C = Gauss();
			Parallel.For(1, IntervalsCount, I =>
			{
				Polynoms[I].C = C[I];
			});
		}

		private void InitializeCoefsD()
		{
			Parallel.For(1, IntervalsCount, I =>
			{
				Polynoms[I].D = (Polynoms[I].C - Polynoms[I - 1].C) / Delta;
			});
		}

		private void TypeOfExperiment_SelectionChanged(object sender, SelectionChangedEventArgs e)
		{
			if (this.FirstExperimentProperties != null)
			{
				if (this.TypeOfExperiment.SelectedIndex == 0)
				{
					this.FirstExperimentProperties.Visibility = System.Windows.Visibility.Visible;
					this.SecondExperimentProperties.Visibility = System.Windows.Visibility.Collapsed;
				}
				else
				{
					this.FirstExperimentProperties.Visibility = System.Windows.Visibility.Collapsed;
					this.SecondExperimentProperties.Visibility = System.Windows.Visibility.Visible;
				}
			} 
		}
	}
}
