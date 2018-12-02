using System;
using System.Collections;
using System.Collections.Generic;

namespace TemplatePrograming.Lab2.ClassLibrary
{
    public class Vector : IVector
    {
        private readonly double[] _values;

        public int Dimension
        {
            get { return _values.Length; }
        }

        public Vector(int dimension)
        {
            _values = new double[dimension];
        }

        public double GetValue(int index)
        {
            if (index < 0 || index > Dimension - 1)
                throw new ArgumentOutOfRangeException("index");
            return _values[index];
        }

        public void SetValue(int index, double value)
        {
            if (index < 0 || index > Dimension - 1)
                throw new ArgumentOutOfRangeException("index");
            _values[index] = value;
        }
    }
}