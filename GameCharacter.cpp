#include "GameCharacter.h"
#include <iostream>
#include <fstream>
using namespace std;


// Constructor: No return type 
// Parametric constructor with parameters: name, maxHealth, attackPoints and defensePoints
// The Parametric constructor allocates space in memory for all members & initializes values  
GameCharacter::GameCharacter(const string& characterName, const int& charMaxHealth, int charAttackPts, int charDefensePts)
	{	
		name = characterName;
		healthPoints = maxHealth = charMaxHealth;
		attackPoints = charAttackPts;
		defensePoints = charDefensePts;
		isAlive = true;

	}


// Constructor: No return type 
// Parametric constructor with parameters: Filename
// The Parametric constructor allocates space in memory for all members & initializes values  
// This one uses the loadFromFile funciton to create an instance from a file.
GameCharacter::GameCharacter(const string& filename) 
	{
		loadFromFile(filename);
	}	


// Name: getName()
// Getter Function:  Simply returns the name of the character. 
// It's const because it only needs to access the values not modify them 
string GameCharacter::getName() const
{
	return name;
}

// Name: getMaxHealth()
// Getter Function:  Simply returns the maximum Health of the character.
// It's const because it only needs to access the values not modify them
int GameCharacter::getMaxHealth() const
{
	return maxHealth;
}

// Name: getHealthPts()
// Getter Function:  Simply returns the health points of the character.
// It's const because it only needs to access the values not modify them
int GameCharacter::getHealthPts() const
{
	return healthPoints;
}

// Name: getAttackPts()
// Getter Function:  Simply returns the Attack points of the character.
// It's const because it only needs to access the values not modify them
int GameCharacter::getAttackPts() const
{
	return attackPoints;
}

// Name: getDefensePts()
// Getter Function:  Simply returns the defense points of the character.
// It's const because it only needs to access the values not modify them
int GameCharacter::getDefensePts() const
{
	return defensePoints;
}

// Name: getStatus()  
// Getter Function:  Simply returns if the character is alive or dead.
// It's const because it only needs to access the values not modify them
bool GameCharacter::getStatus() const
{
	return isAlive;
}

// Name: takeDamage()
// Return Type: void
// Parametrs: An integer, representing the damage infliceted on the character
// Description: This function checks to make sure the damage is valid, if it is, then it updates 
// the health points of the character receiving damage
void GameCharacter::takeDamage(int damage) 
{
	if (damage > 0)
	{	
		healthPoints -= damage;
		if(healthPoints <= 0) {
			isAlive = false;
			cout << name << " is dead." << endl;
			healthPoints = 0;
		}
	}
}
// Name: attack(GameCharacter& target)
// Return Type: void
// Paramerts: An object of type GameCharacter
// Description:  Computes the damage inflicted and makes sure the damage is not -ve or 0, 
// Then makes use of the take damage function to reflect the changes
void GameCharacter::attack(GameCharacter& target)
{	
	cout << name << " attacking " << target.name << "!!!" << endl;
	int damage = attackPoints - target.defensePoints;
	if (damage <= 0) // Don't update the health values if damage = 0 || -ve
	{	
		cout << "No Damage Occured" << endl;
	}
	else {
		cout << target.name << "'s Health is reduced by " << damage << " points!!" << endl; 
		target.takeDamage(damage);
		
	}
}


// Name: operator+
// Return Type: An instance of type GameCharacter
// Paramerts: A constant object of type GameCharacter
// Description:  Overloads the + operator to take an instance of GameCharacter class as input 
// and compute the average of the current instance calling the operator / lhs and the parameter instance's attributes to 
// return an instance of GameCharacter with the averaged values 
GameCharacter GameCharacter::operator+(const GameCharacter& other)
{
	string tempName = getName() + " " + other.getName();
	int tempMaxHealth = getMaxHealth() + other.getMaxHealth();
	int tempHealthPoints = (getHealthPts() + other.getHealthPts()) / 2;
	int tempAttackPoints = (getAttackPts() + other.getAttackPts()) / 2;
	int tempDefensePoints = (getDefensePts() + other.getDefensePts()) / 2;
	
	GameCharacter temp(tempName, tempMaxHealth, tempAttackPoints, tempDefensePoints);
	temp.healthPoints = tempHealthPoints;
	if(temp.healthPoints <= 0)
		temp.isAlive = false;
	else 	
		temp.isAlive = true;

	return temp;
}

// Name: operator <<
// Return Type: Returns an instance of the ostream type 
// Paramerts: An instance of type ostream, A constant object of type GameCharacter
// Description:  Overloads the << operator to output the attributes of an instance of GameCharacter
ostream& operator << (ostream& os, const GameCharacter& character)
{
	os << "-----------------------------------------" << endl;
	os << character.getName() << "'s Details:" << endl;
	os << "Status: " << character.getStatus() << endl;
	os << "Max Health: " << character.getMaxHealth() << endl;
	os << "Health left: " << character.getHealthPts() << endl;
	os << "Attack Points: " << character.getAttackPts() << endl;
	os << "Defense Points: " << character.getDefensePts() << endl;
	os << "------------------------------------------" << endl << endl;
	return os;
	
	
}	

// Name: operator <
// Return Type: A boolean value 
// Paramerts: A constant object of type GameCharacter
// Description:  Overloads the < operator to compare the instance of GameCharacter class / rhs passed to it and the  
// instance calling the operator <, / lhs. Returns true of rhs > lsh.

bool GameCharacter::operator < (const GameCharacter& other)
{
	if(getHealthPts() < other.getHealthPts())
		return true;
	else
		return false;
}

// Name: operator >
// Return Type: A boolean value
// Paramerts: A constant object of type GameCharacter
// Description:  Overloads the > operator to compare the instance of GameCharacter class / rhs passed to it and the
// instance calling the operator >, / lhs. Returns true of rhs < lsh.

bool GameCharacter::operator > (const GameCharacter& other)
{
	if(getHealthPts() > other.getHealthPts())
		return true;
	else
		return false;
}

// Name: saveToFile
// Return Type: Void
// Paramerts: A constant string representing the file it's going save the data in. 
// Description:  This function makes use of ofstream class, to write to a file. 
// It checks to see if opening the file was successful. if not it exits from the code

void GameCharacter::saveToFile(const string& filename) const
{
	ofstream outFile(filename);
       	if (outFile.fail()) {
		cout << "Falied to open file for writing. " << endl;
		exit(1);
	}

	outFile << "Name: " << name << endl;
	outFile << "Max Health: " << maxHealth << endl;
	outFile << "Health Points: " << healthPoints << endl;
	outFile << "Attack Points: " << attackPoints << endl;
	outFile << "Defense Points: " << defensePoints << endl;
	outFile << "Status: " << isAlive << endl;
	
}
// Name: saveToFile
// Return Type: Void
// Paramerts: A constant string representing the file it's going save the data in.
// Description:  This function makes use of ifstream class, to input from a file.
// It checks to see if opening the file was successful. If it was it modifies the characters attributes 

void GameCharacter::loadFromFile(const string& filename) 
{
	ifstream inFile(filename);
	if (inFile.fail()) {
		cout << "Failed to open the file for writing. " << endl;
		
	}

	getline(inFile, name);
	inFile >> maxHealth;
	inFile >> healthPoints;
	inFile >> attackPoints;
	inFile >> defensePoints;
	inFile >> isAlive;
	
	
}

