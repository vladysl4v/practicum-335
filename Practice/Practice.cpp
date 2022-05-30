#include <iostream>
#include <fstream>
#include "header.h"

using namespace std;

void ReadFile(char*);
void WriteFile(char*);

int main()
{
	char filename[22];
	int n;
	do {
		cout << "Menu:\n"
			<< "1 - Write to file\n"
			<< "2 - Read File\n"
			<< "0 - Quit\n\n=>";
		cin >> n;
		cin.ignore();
		switch (n)
		{
		case 1:
			cout << "Input a file name, please\n";
			cin.getline(filename, 20);
			WriteFile(filename);
			break;
		case 2:
			cout << "Input a file name, please\n";
			cin.getline(filename, 20);
			ReadFile(filename);
			break;
		default: n = 0;
		}
	} while (n);
}

