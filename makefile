game: GameCharacter.o driver.o
	c++ GameCharacter.o driver.o -o game


GameCharacter.o: GameCharacter.cpp
	c++ -c GameCharacter.cpp

driver.o: driver.cpp
	c++ -c driver.cpp

clean:
	rm *.o game
