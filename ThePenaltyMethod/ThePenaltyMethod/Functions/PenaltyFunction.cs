using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ThePenaltyMethod.Functions
{
	/// <summary> Класс для представления функции штрафа </summary>
	public class PenaltyFunction : Function
	{
		/// <summary> Степень штрафа </summary>
		private double R;
		
		/// <summary> Ограничения-неравенства </summary>
		public List<ConditionFunction> ConditionFunctions { get; set; }

		public PenaltyFunction(double r, List<ConditionFunction> ConditionFunctions)
		{
			if (r <= 0.0)
				throw new ArgumentOutOfRangeException("Paramert 'p' must be more than 0.0!");
			this.R = r;
			this.ConditionFunctions = ConditionFunctions;
		}

		public override double Value(System.Windows.Point p)
		{
			double Result = 0.0;
			foreach (ConditionFunction cond in this.ConditionFunctions)
				Result += Math.Pow(Math.Max(cond.Value(p), 0), this.R);
			return Result;
		}

		public override double Derivative_dX(System.Windows.Point p)
		{
			double Result = 0.0;
			foreach (ConditionFunction cond in this.ConditionFunctions)
				if (cond.Value(p) > 0.0)
					Result += this.R * (Math.Pow(cond.Value(p), this.R-1) * cond.Derivative_dX(p));
			return Result;
		}

		public override double Derivative_dY(System.Windows.Point p)
		{
			double Result = 0.0;
			foreach (ConditionFunction cond in this.ConditionFunctions)
				if (cond.Value(p) > 0.0)
					Result += this.R * (Math.Pow(cond.Value(p), this.R-1) * cond.Derivative_dY(p));
			return Result;
		}
	}
}
