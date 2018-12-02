namespace TemplatePrograming.Lab2.Client
{
    public static class MatrixVisualizationSchemes
    {
        public static readonly FirstMatrixScheme First = new FirstMatrixScheme();
        public static readonly SecondMatrixScheme Second = new SecondMatrixScheme();
        public static readonly ThirdMatrixScheme Third = new ThirdMatrixScheme();
        public static readonly FourthMatrixScheme Fourth = new FourthMatrixScheme();

        public static readonly IMatrixVisualizationScheme[] All =
        {
            First,
            Second,
            Third,
            Fourth
        };
    }
}
