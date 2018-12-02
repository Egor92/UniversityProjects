using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Windows;
using System.Reflection;

namespace ThePenaltyMethod.Functions
{
	/// <summary> Класс для представления ограничений </summary>
	public class ConditionFunction : Function
	{
		/// <summary> Метод, вычисляющий значение функцию </summary>
		public MethodInfo Value_Method { get; set; }

		/// <summary> Метод, вычисляющий первую производную функции по переменной "x" </summary>
		public MethodInfo Derivative_dX_Method { get; set; }

		/// <summary> Метод, вычисляющий первую производную функции по переменной "y" </summary>
		public MethodInfo Derivative_dY_Method { get; set; }


		/// <summary> Выражение, задающее функцию </summary>
		public string Value_Expression
		{
			set
			{ 
				this.Value_Method = FunctionCompiler.Compile(value);
				this.NotifyPropertyChanged("Value_Expression_IsCorrect");
			}
		}

		/// <summary> Выражение, задающее первую производную функции по переменной "x" </summary>
		public string Derivative_dX_Expression
		{
			set
			{
				this.Derivative_dX_Method = FunctionCompiler.Compile(value);
				this.NotifyPropertyChanged("Derivative_dX_Expression_IsCorrect");
			}
		}

		/// <summary> Выражение, задающее первую производную функции по переменной "y" </summary>
		public string Derivative_dY_Expression
		{
			set
			{
				this.Derivative_dY_Method = FunctionCompiler.Compile(value);
				this.NotifyPropertyChanged("Derivative_dY_Expression_IsCorrect");
			}
		}


		/// <summary> Показывает, верно ли задано выражение, задающее функцию </summary>
		public bool Value_Expression_IsCorrect
		{
			get
			{
				return this.Value_Method != null;
			}
		}

		/// <summary> Показывает, верно ли задано выражение, задающее первую производную функции по переменной "x" </summary>
		public bool Derivative_dX_Expression_IsCorrect
		{
			get
			{
				return this.Derivative_dX_Method != null;
			}
		}

		/// <summary> Показывает, верно ли задано выражение, задающее первую производную функции по переменной "y" </summary>
		public bool Derivative_dY_Expression_IsCorrect
		{
			get
			{
				return this.Derivative_dY_Method != null;
			}
		}


		public override double Value(Point p)
		{
			if (this.Value_Expression_IsCorrect)
				return (double)this.Value_Method.Invoke(this, new object[2] { p.X, p.Y });
			else
				throw new NullReferenceException("Value_Method == null!!!");
		}

		public override double Derivative_dX(Point p)
		{
			if (this.Derivative_dX_Expression_IsCorrect)
				return (double)this.Derivative_dX_Method.Invoke(this, new object[2] { p.X, p.Y });
			else
				throw new NullReferenceException("Derivative_dX_Method == null!!!");
		}

		public override double Derivative_dY(Point p)
		{
			if (this.Derivative_dY_Expression_IsCorrect)
				return (double)this.Derivative_dY_Method.Invoke(this, new object[2] { p.X, p.Y });
			else
				throw new NullReferenceException("Derivative_dY_Method == null!!!");
		}
	}
}
