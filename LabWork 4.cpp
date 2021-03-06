#include <iostream>
#include <vector>
#include <string>
#include <conio.h>
#include <ctime>
using namespace std;

class Dot
{
	static int n;
public:
	double x, y;
	int ID;
	int adjacencyList[3];
	Dot()
	{
		x = 0;
		y = 0;
		ID = ++n;
	}
	Dot(double a, double b)
	{
		x = a;
		y = b;
		ID = ++n;
	}
	static int getN()
	{
		return n;
	}
};

int Dot::n;
double calcAngle(int x0, int x1, int x2);
int findVertex(vector<Dot> dotVector, int vertex);
// X0 is number of dot, relatively to which R is found
int getR(vector<Dot>& a, int x0, int x1);

int getL(vector<Dot>& a, int x0, int x1);

double tan(Dot& X);

int main()
{
	srand(time(0));
	cout << "Please type in coordinates of all dots of graph.\n"
		"The last two must be zeroes. \n";

	vector<Dot> dotVector;

	double tempX = 1, tempY = 1;
	for (int i = 0/*, n = 2 * (rand() % 6) + 2*/; tempY || tempX /*i < n*/; ++i)
	{
		cout << "Point " << i + 1 << ": ";
		cin >> tempX >> tempY;
		//tempX = rand() % 20;
		//tempY = rand() % 20;
		dotVector.push_back(Dot(tempX, tempY));
	}
	dotVector.pop_back();
	cout << "\nThere are " << dotVector.size()
		<< " vertices int the graph now\n";

	cout << "\nPlease type in adjacency lists\n"
		"Every list must be concluded by zero\n";


	for (int i = 0, n = dotVector.size(); i < n; ++i)
	{
		/*int i = findVertex(dotVector, vertex);

		if (!~i)
		{
			cout << "Incorrect vertex. Please try again\n";
			cin >> vertex;
			continue;
		}
		*/
		
		cout << "\n" << i + 1 << ": \n";
		for (int j = 0; j < 3; ++j)
			cin >> dotVector[i].adjacencyList[j];
	}

	cout << "\nThe graph has been formed.\n"
		<< "\nPlease input two vertices and consiquence of \"L\"s \"R\"s\n"
		"See the task, p.2\n";
	int x0, x1;
	cin >> x0 >> x1;
	--x0;
	--x1;

	string consiquence, result = "";
	result += static_cast<char>(x0 + '0');
	result += static_cast<char>(x1 + '0');
	cin >> consiquence;

	for (int i = 0; consiquence[i]; ++i)
	{
		int temp;
		if (consiquence[i] == 'L')
			temp = getL(dotVector, x0, x1);
		else if (consiquence[i] == 'R')
			temp = getR(dotVector, x0, x1);

		x0 = x1;
		x1 = temp;
		result += static_cast<char>(x1 + '0');
	}
	cout << "\nThe way is: " << result;



	_getch();
	return 0;
}
// Calculate the angle (in parrots) between lines (x0, x1) and (x1, x2)
double calcAngle(vector<Dot>& a, int ix0, int ix1, int ix2)
{
	// Change the centre of coordinates to x1
	Dot x0(a[ix0].x - a[ix1].x, a[ix0].y - a[ix1].y);
	Dot x1(0, 0);
	Dot x2(a[ix2].x - a[ix1].x, a[ix2].y - a[ix1].y);

	// TOFIX: 
	bool moreThanPi = (x2.y < tan(x0) * x2.x);

	// The formula for cos(alpha)
	double angle = (x0.x * x2.x + x0.y * x2.y) /
		(sqrt(x0.x * x0.x + x0.y * x0.y) * sqrt(x2.x * x2.x + x2.y * x2.y));

	// convert to parrots
	angle = 1 - angle + 2 * moreThanPi;

	return angle;
}
// tan((X,0), Ox)
double tan(Dot& X)
{
	return (X.x ? X.y / X.x : 0);
}
// X0 is number of dot, relatively to which L is found
int getL(vector<Dot>& a, int x0, int x1)
{
	double maxAngle = 0, t = 0;
	int iMax = 0;
	for (int i = 0; i < 3; ++i)
	{
		if (a[x1].adjacencyList[i] == x0)
			continue;
		double angle = calcAngle(a, x0, x1, a[x1].adjacencyList[i]);
		if (maxAngle < angle)
		{
			maxAngle = angle;
			iMax = i;
		}
	}

	return iMax;
	
}

// X0 is number of dot, relatively to which R is found
int getR(vector<Dot>& a, int x0, int x1)
{
	double minAngle = 4, t = 0;
	int iMin = 0;
	for (int i = 0; i < 3; ++i)
	{
		if (a[x1].adjacencyList[i] == x0)
			continue;

		double angle = calcAngle(a, x0, x1, a[x1].adjacencyList[i]);
		if (minAngle > angle)
		{
			minAngle = angle;
			iMin = i;
		}
	}

	return iMin;

}
//Returns index of dot which has ID == vertex
int findVertex(vector<Dot> dotVector, int vertex)
{
	if (dotVector[vertex - 1].ID == vertex)
		return vertex;

	
	for (int i = 0, n = dotVector.size(); i < n; ++i)
	{
		if (dotVector[i].ID == vertex)
			return i;
	}
	
	return -1;
}
