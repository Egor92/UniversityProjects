class drob{
	public:
		int chisl;
		int znam;
	public:
		drob();
		drob(drob &A);
		drob(int chis);
		drob(int chis, int znam);
		void sokratit();
		void initialize(int a, int b);
};

drob minus(drob A, drob B);
drob delit(drob A, int B);
drob delit(drob A, drob B);
drob umnozhit(drob A, int B);
drob umnozhit(drob A, drob B);
drob plus(drob A, drob B, drob C);
