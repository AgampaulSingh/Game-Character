#include "GameCharacter.h"
#include <iostream>
using namespace std;

int main()
{
	string inputFile;
	string outputFile;

	GameCharacter c1("Mark", 100, 100, 100); 
	GameCharacter c2("Benjamin", 100, 100, 100);
        GameCharacter c3("Morgan", 1, 2, 3);	
	
	cout << "Enter the file you want to input data from: ";
	getline(cin, inputFile);
	GameCharacter c4(inputFile);
	
	cout << "Here are the game's Profiles: " << endl;
	cout << c1;
	cout << c2;
	cout << c3;
	cout << c4;

	cout << "Here's " << c3.getName() << " VS " << c1.getName() << endl;
	c1.attack(c3);
	c3.attack(c1);
	
	cout << endl << endl << "Enter " << c2.getName() << endl;
	GameCharacter c5 = c3 + c2; 

	cout << c2.getName() << " combines with " << c3.getName() << endl;
	cout << c5;

	if (c5 > c1)
		c5.attack(c1);
	else 
		c1.attack(c5);

	cout << "---------- Game End ----------" << endl;
	cout << "Enter file to save data into: " ;
	getline(cin, outputFile);
	c5.saveToFile(outputFile);	
	
	
	return 0;
}


