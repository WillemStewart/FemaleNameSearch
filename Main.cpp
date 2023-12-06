#include <iostream>
#include <string>
#include <fstream>
#include <chrono>
#include <cctype>
#include "Name.h"
using namespace std;

int main()
{
	ifstream nameFile;
	string name;
	string newName, nameCounter;
	int newNameSize;
	int ord;
	Name nameList;

	//Import file that contains common female names
	nameFile.open("CommonFemaleNames.txt");
	while (nameFile >> ord)
	{
		nameFile >> name;
		nameList.addName(new CommonName(ord, name));
	}
	
	cout << "The names have been read" << endl;

	//Sort names based on number
	nameList.sortNames();

	//User enters a name
	cout << "Enter a female name, enter stop to end" << endl;
	cin >> newName;

	//Search for names on the list while timing each algorithm
	while (newName != "stop")
	{
		nameCounter = "";
		newNameSize = newName.length();
		for (int i = 0; i < newNameSize; i++)
		{
			nameCounter += toupper(newName.at(i));
		}
		newName = nameCounter;

		auto start_time = chrono::high_resolution_clock::now();
		ord = nameList.findLinear(newName);
		auto end_time = chrono::high_resolution_clock::now();
		cout << "Linear search took " << chrono::duration_cast<chrono::microseconds>(end_time - start_time).count() << " microseconds." << endl;

		start_time = chrono::high_resolution_clock::now();
		nameList.findBinary(newName);
		end_time = chrono::high_resolution_clock::now();
		cout << "Binary search took " << chrono::duration_cast<chrono::microseconds>(end_time - start_time).count() << " microseconds." << endl;
		
		if (ord <= 0 || ord == 69)
		{
			cout << newName << " is not on the list" << endl;
		}
		else
		{
			cout << newName << " is the number " << ord << " most popular female name" << endl;
		}

		cout << "Enter a female name, enter stop to end" << endl;
		cin >> newName;
	}
	return 0;
}
