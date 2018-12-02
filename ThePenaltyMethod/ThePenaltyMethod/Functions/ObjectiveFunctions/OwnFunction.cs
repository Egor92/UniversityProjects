using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Reflection;

namespace ThePenaltyMethod.Functions.ObjectiveFunctions
{
	/// <summary> Своя целевая функция </summary>
	public class OwnFunction : ObjectiveFunction
	{
		public OwnFunction()
		{
			this.Name = "Своя функция";
		}

		/// <summary> Метод, вычисляющий значение функцию </summary>
		public MethodInfo Value_Method { get; set; }

		/// <summary> Выражение, задающее функцию </summary>
		public string Value_Expression
		{
			set
			{
				this.Value_Method = FunctionCompiler.Compile(value);
			}
		}

		/// <summary> Показывает, верно ли задано выражение, задающее функцию </summary>
		public bool Value_Expression_IsCorrect
		{
			get
			{
				return this.Value_Method != null;
			}
			set { }
		}

		public override double Value(System.Windows.Point p)
		{
			if (this.Value_Method != null)
				return (double)this.Value_Method.Invoke(this, new object[2] { p.X, p.Y });
			else
				throw new NullReferenceException("Value_Method == null!!!");
		}

		public override double Derivative_dX(System.Windows.Point p)
		{
			return 0.0;
		}

		public override double Derivative_dY(System.Windows.Point p)
		{
			return 0.0;
		}
	}
}
