#include <iostream>
#include <fstream>
#include <string>
#include <iterator>
#include <vector>
#include <algorithm>
#include <locale>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

using namespace std;

#define max_size 10
#define max_value 100

int main()
{
	srand(static_cast<unsigned>(time(NULL)));
	setlocale(LC_ALL, "Russian");
	cout << "Введите имя файла" << endl;
	string filePath;
	cin >> filePath;

	// открытие файла на запись;
	ofstream file_o(filePath.c_str(), ios::trunc);
	
	// создадим массив целый чисел;
	vector<size_t> v(max_size);
	for_each(v.begin(), v.end(),
		[](size_t& buffer)->void
		{
			buffer = rand() % max_value;
	});

	// запишем полученный массив в файл;
	copy(v.begin(), v.end(), ostream_iterator<size_t>(file_o, " "));

	// закроем файл;
	file_o.close();

	ifstream file_i(filePath.c_str());
	if (file_i.fail())
	{
		cout << "Невозможно открыть файл" << endl;
		_getch();
		return EXIT_FAILURE;
	}

	// считаем данные из файла;
	while(file_i)
	{
		size_t d;
		file_i >> d;
		cout << d << " ";
	}

	_getch();
	return EXIT_SUCCESS;
}