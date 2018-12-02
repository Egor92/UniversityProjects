using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.CodeDom.Compiler;
using Microsoft.CSharp;
using System.Reflection;

namespace ThePenaltyMethod
{
	public static class FunctionCompiler
	{
		public static MethodInfo Compile(string Expression)
		{
			CompilerResults CResults = null;
			try
			{
				CSharpCodeProvider CodeProvider = new CSharpCodeProvider();
				CResults = CodeProvider.CompileAssemblyFromSource(new CompilerParameters(),
					@"using System; namespace Space " + '\n' + " { public class FormulaCreator { " + '\n' + " public static double F(double x, double y) { return " + Expression + @"; } } }");

				MethodInfo method = CResults.CompiledAssembly.CreateInstance("Space.FormulaCreator").GetType().GetMethod("F");
				return method;
			}
			catch
			{
				return null;
			}
		}
	}
}
