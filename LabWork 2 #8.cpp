/*Задано семейство множеств букв.Найти такое k, для которого можно построить
множество, состоящее из k букв, причем каждая из них принадлежит ровно k
множествам заданного семейства.
*/

#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <ctime>
#include <vector>
#include <conio.h>

using namespace std;

int fillVector(char* fileName, std::vector<std::string> &retVector);
int renewFile(char* fileName);
void bubbleSort(int*);
int findK(int*);

void main()
{
	if (!renewFile("SourceTextFile.txt") )
		cerr << "Error: file can't be opened";
	
	vector<string> stringVect;
	if (!fillVector("SourceTextFile.txt", stringVect))
		cerr << "Error: file can't be opened";
	
	int* a = new int[26];
	
	//Figure out every letter entity number;
	for (int i = 0; i < 26; ++i)
		a[i] = 0;
		
	vector<string>::iterator it;
	for (it = stringVect.begin(); it != stringVect.end(); ++it)
	{
		for (int i = 0; (*it)[i]; ++i)
			++a[(*it)[i] - 'a'];
	}
	
	//Sort the entity numbers to simplify searching of 'k';
	bubbleSort(a);
	
	cout << "k = " << findK(a);
	
	_getch();
}

void bubbleSort(int* a)
{
	for (int i = 0, sorted = 0; !sorted && i < 26; i++)
	{
		sorted = 1;
		for (int j = 0; j < 26 - i - 1; j++)
		{
			if (a[j] > a[j + 1])
			{
				swap(a[j], a[j + 1]);
				sorted = 0;
			}
		}
	}
}
//Find a number which is equal to its repetition number;
int findK(int* a)
{
	short i = 0, k = 0, currentEntryAmount = 1;
	while (!a[i++]);
	while (i < 26)
	{
		if (a[i] == a[i - 1])
			++currentEntryAmount;
		else
		{
			k = currentEntryAmount;
			if (k == a[i - 1])
				return k;
			currentEntryAmount = 1;
		}
		++i;
	}
	return 0;
}
/*Fill the file with set by user number of rows,
every of which contains random number of random characters;*/
int renewFile(char* fileName)
{
	std::cout << "How many sets of characters whould you prefer?\n";
	int rowNum;
	std::cin >> rowNum;

	srand(time(0));

	std::ofstream sourceFileOut(fileName);
	if (!sourceFileOut.is_open())
		return 0;

	std::set<char> temp; // To avoid repetitions in rows

	for (int i = 0; i < rowNum; i++)
	{
		for (short j = 0; j < rand() % 26 + 1; j++)
			temp.insert(char(rand() % 26 + 'a')); // 26 - number of english letters

		while (!temp.empty())
		{
			sourceFileOut << *temp.begin();
			temp.erase(temp.begin());
		}
		sourceFileOut << std::endl;
	}

	sourceFileOut.close();
	return 1;
}
// Copy rows from file to the vector of strings;
int fillVector(char* fileName, std::vector<std::string> &retVector)
{
	std::ifstream sourceFileIn(fileName);
	if (!sourceFileIn.is_open())
		return 0;
	std::string temp;
	while (!sourceFileIn.eof())
	{
		getline(sourceFileIn, temp);
		retVector.push_back(temp);
	}
	return 1;
}
