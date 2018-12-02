using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ThePenaltyMethod.Functions
{
	/// <summary> Класс для представления целевой функции со штрафом </summary>
	public class GeneralFunction : Function
	{
		/// <summary> Целевая функция </summary>
		private ObjectiveFunction ObjectiveFunction;

		/// <summary> Функция штрафа </summary>
		private PenaltyFunction PenaltyFunction;

		public GeneralFunction(ObjectiveFunction ObjectiveFunction, double r, List<ConditionFunction> ConditionFunctions)
		{
			this.ObjectiveFunction = ObjectiveFunction;
			this.PenaltyFunction = new PenaltyFunction(r, ConditionFunctions);
		}

		public double Value(System.Windows.Point p, double gamma)
		{
			double Result = this.ObjectiveFunction.Value(p) + gamma * this.PenaltyFunction.Value(p);
			return Result;
		}

		public double Derivative_dX(System.Windows.Point p, double gamma)
		{
			double Result = this.ObjectiveFunction.Derivative_dX(p) + gamma * this.PenaltyFunction.Derivative_dX(p);
			return Result;
		}

		public double Derivative_dY(System.Windows.Point p, double gamma)
		{
			double Result = this.ObjectiveFunction.Derivative_dY(p) + gamma * this.PenaltyFunction.Derivative_dY(p);
			return Result;
		}

		public List<ConditionFunction> GetConditionFunction()
		{
			return this.PenaltyFunction.ConditionFunctions;
		}


		public override double Value(System.Windows.Point p)
		{
			return this.Value(p, 0.0);
		}

		public override double Derivative_dX(System.Windows.Point p)
		{
			return this.Derivative_dX(p, 0.0);
		}

		public override double Derivative_dY(System.Windows.Point p)
		{
			return this.Derivative_dX(p, 0.0);
		}
	}
}
