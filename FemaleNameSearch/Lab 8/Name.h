#ifndef NAME_H
#define NAME_H
#include <string>
using namespace std;

class CommonName 
{
protected:
	int ordinal;
	string name;
public:
	CommonName();
	CommonName(int ord, string aName);
	int getOrdinal();
	string getName();
};

class Name : public CommonName
{
private:
	CommonName* namePair[1000];
	int nextname;
public:
	Name();
	void addName(CommonName* pair);
	void sortNames();
	void nextSort(CommonName* pair, int high, int low);
	int findLinear(string name);
	int findBinary(string name);
	int findRecursive(CommonName* pair, int low, int high);
};

#endif