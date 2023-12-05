#include "Name.h"
#include <iostream>
#include <chrono>
#include <string>
using namespace std;

CommonName::CommonName()
{
	ordinal = 0;
	name = "";
}

CommonName::CommonName(int ord, string aName)
{
	ordinal = ord;
	name = aName;
}

int CommonName::getOrdinal()
{
	return ordinal;
}

string CommonName::getName()
{
	return name;
}

Name::Name()
{
	namePair[0] = nullptr;
	nextname = 0;
}

void Name::addName(CommonName* pair)
{
	namePair[nextname] = pair;
	cout << namePair[nextname]->getOrdinal() << " " << namePair[nextname]->getName() << endl;
	nextname++;
}

void Name::sortNames()
{
	int low = 0;
	int high = 999;
	if (low < high)
	{
		nextSort(namePair[ordinal], low, high);
	}
}

void Name::nextSort(CommonName* pair, int low, int high)
{
	if (low < high)
	{
		int pi = findRecursive(pair, low, high);
		nextSort(pair, low, pi - 1);
		nextSort(pair, pi + 1, high);
	}
}

int Name::findLinear(string name)
{
	string nameSearch;
	for (int i = 0; i < 1000; i++)
	{
		nameSearch = namePair[i]->getName();
		if (nameSearch == name)
		{
			return namePair[i]->getOrdinal();
		}
	}
}

int Name::findBinary(string name)
{
	bool valid = false;
	int l = 0;
	int h = ordinal;
	while (l <= h)
	{
		int mid = l + (h - 1) / 2;
		if (namePair[mid]->getName() == name)
		{
			valid = true;
			return namePair[mid]->getOrdinal();
		}
		if (namePair[mid]->getName() > name)
		{
			l = mid + 1;
		}
		if (namePair[mid]->getName() < name)
		{
			h = mid - 1;
		}
	}
}

int Name::findRecursive(CommonName* pair, int low, int high)
{
	string temp;
	string pivot = namePair[high]->getName();
	int i = (low - 1);

	for (int j = low; j <= high - 1; j++)
	{
		if (namePair[j]->getName() < pivot)
		{
			i++;
			temp = namePair[i]->getName();
			namePair[i]->getName() = namePair[j]->getName();
			namePair[j]->getName() = temp;
		}
	}
	temp = namePair[i + 1]->getName();
	namePair[i + 1]->getName() = namePair[high]->getName();
	namePair[high] ->getName() = temp;
	return (i + 1);
}