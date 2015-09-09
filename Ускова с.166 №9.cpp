/* Ускова с.166 №9
Карту, определяющую прямоугольную область моря, представили матрицей с
логическими элементами (false - море, true - суша). Островом будем называть
совокупность соприкасающихся (вертикальной или горизонтальной стороной) клеток
матрицы со значениями true. Рассчитайте число островов на матрице-карте.
*/
#include <iostream>
#include <conio.h>
#include <time.h>

using namespace std;

void showMatr(bool**, int, int);
bool** initMatr(int, int);
bool** initMatr(int, int, bool);
bool isIsland(bool**, bool**, int, int, int, int);
int countIslands(bool** map, int n, int m);

void main()
{
	int n, m;
	cout << "Input matrix dimensions\n";
	cin >> n >> m;
	bool** map = initMatr(n, m);

	showMatr(map, n, m);

	cout << endl << countIslands(map, n, m);
	_getch();
}

void showMatr(bool** a, int nstr, int ncol)
{
	for (int i = 0; i < nstr; i++)
	{
		for (int j = 0; j < ncol; j++)
		{
			cout << a[i][j] << ' ';
		}
		cout << endl;
	}
	cout << endl;
}

bool** initMatr(int nstr, int ncol)
{
	srand(time(0));
	bool** a = new bool*[nstr];
	for (int i = 0; i < nstr; ++i)
	{
		a[i] = new bool[ncol];
	}

	for (int i = 0; i < nstr; i++)
	{
		for (int j = 0; j < ncol; j++)
		{
			a[i][j] = bool(rand()%2);
		}
	}
	return a;
}

bool** initMatr(int nstr, int ncol, bool value)
{
	bool** a = new bool*[nstr];
	for (int i = 0; i < nstr; ++i)
		a[i] = new bool[ncol];

	for (int i = 0; i < nstr; i++){
		for (int j = 0; j < ncol; j++){
			a[i][j] = value;
		}
	}
	return a;
}

bool isIsland(bool** map, bool** checkMap, int n, int m, int i, int j)
{
	if (checkMap[i][j])
		return 0;
	
	checkMap[i][j] = 1;

	if (!map[i][j])
		return 0;
	
	//Если есть непроверенная "суша", то рекурсивно проверяем всех её соседей
	if (j < m - 1)
		isIsland(map, checkMap, n, m, i, j + 1);
	if (i > 0)
		isIsland(map, checkMap, n, m, i - 1, j);
	if (j > 0)
		isIsland(map, checkMap, n, m, i, j - 1);
	if (i < n - 1)
		isIsland(map, checkMap, n, m, i + 1, j);

	return 1;
}

int countIslands(bool** map, int n, int m)
{	
	//checkMap[i][j] будет хранить данные о том, проверяли ли мы уже эту ячейку
	bool** checkMap = initMatr(n, m, 0);

	int amountOfIslands = 0;
	
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (!checkMap[i][j] && isIsland(map, checkMap, n, m, i, j))
				amountOfIslands++;
		}
	}
	return amountOfIslands;
}
