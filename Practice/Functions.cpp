#include <iostream>
#include <iomanip>
#include <fstream>
#include "header.h"

using namespace std;

void ReadFile(char* filename)
{

	double excellent = 0;
	Students s;
	int size = sizeof(Students);
	int realsize = 0;
	ifstream fin(filename);
	if (!fin)
	{
		cout << "ERROR" << endl;
		return;
	}
	fin.read((char*)&s, size);

	while (!fin.eof())
	{
		realsize++;
		cout << setw(12) << s.surname
			<< setw(3) << s.group
			<< setw(8) << s.mark1
			<< setw(4) << s.mark2
			<< setw(4) << s.mark3
			<< endl;

		if (s.mark1 > 3 && s.mark2 > 3 && s.mark3 > 3)
			excellent++;

		fin.read((char*)&s, size);
	}
	int success = (excellent / realsize) * 100;
	cout << "Quality of student success: " << success << "%" << endl;
	fin.close();
}

void WriteFile(char* filename)
{
	Students s;
	ofstream fout(filename);
	int size = sizeof(Students);
	char surname[12];
	if (!fout)
	{
		cout << "ERROR" << endl;
		return;
	}
	do {
		cout << "Surname -> ";
		cin.getline(surname, 12);

		if (strcmp(surname, "*"))
		{
			strcpy_s(s.surname, surname);
			cout << "group -> ";			cin >> s.group;
			cout << "mark1 -> ";			cin >> s.mark1;
			cout << "mark2 -> ";			cin >> s.mark2;
			cout << "mark3 -> ";			cin >> s.mark3;
			cin.ignore();
			fout.write((char*)&s, size);

		}
	} while (strcmp(surname, "*"));
	fout.close();
}