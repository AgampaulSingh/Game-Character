
#ifndef GAMECHARACTER_H
#define GAMECHARACTER_H
#include <string>
#include <ctime>
using namespace std;

class GameCharacter{

public:
	GameCharacter(const string& characterName, const int& charMaxHealth, int charAttackPts, int charDefensePts);	
	GameCharacter(const string& filename);	// Additional constructor, to create an object, from a file. 

	string getName() const;
	int getMaxHealth() const;
	int getHealthPts() const;
	int getAttackPts() const;
	int getDefensePts() const;
	bool getStatus() const;

	void takeDamage(int damage);
	void attack(GameCharacter& target);
        void saveToFile(const string& filename) const;
	void loadFromFile(const string& filename);
	void displayDateTimeOfLastSave();
        	
	GameCharacter operator+(const GameCharacter& other);
	bool operator<(const GameCharacter& other);
	bool operator>(const GameCharacter& other);
	friend ostream& operator << (ostream& os, const GameCharacter& character);

			
private:
	string name;
	int maxHealth; // Needs to be looked at, MAX_HEALTH?  
	int healthPoints;
	int attackPoints;
	int defensePoints;
	bool isAlive;	
	time_t lastSaveTime;	
};



#endif
