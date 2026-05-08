
#include "MOBA.h"

MOBA::MOBA() :
	Game(),
	MultiplayerGame(),
		numberOfCharacters(0), characters(nullptr) {};

MOBA::MOBA(string name, string dev, int relDay, int relMonth, int relYear, int version, double size, double stars, int charactersNum, const string* characters, int onlinePlayers, int servers) :
	Game(name, dev, relDay, relMonth, relYear, version, size, stars),
	MultiplayerGame(name, dev, relDay, relMonth, relYear, version, size, stars, onlinePlayers, servers),
		numberOfCharacters(charactersNum)
{
	createValuedStringArray(this->characters, characters, this->numberOfCharacters);
}

MOBA::MOBA(string name, string dev, Date& date, Version& version, double size, double stars, int charactersNum, const string* characters, int onlinePlayers, int servers) :
	Game(name, dev, date, version, size, stars),
	MultiplayerGame(name, dev, date, version, size, stars, onlinePlayers, servers),
		numberOfCharacters(charactersNum)
{
	createValuedStringArray(this->characters, characters, this->numberOfCharacters);
}

MOBA::MOBA(MOBA& moba) :
	Game(moba),
	MultiplayerGame(moba),
		numberOfCharacters(moba.numberOfCharacters)
{
	createValuedStringArray(this->characters, characters, this->numberOfCharacters);
}
MOBA::~MOBA()
{
	delete[] this->characters;
}


void MOBA::addCharacter()
{
	cout << "Enter your new character: ";
	string newCharacter;
	cin >> newCharacter;

	string* tempCharacters = this->characters;

	this->characters = new string[++this->numberOfCharacters];

	for (int i = 0; i < this->numberOfCharacters - 1; ++i)
		this->characters[i] = tempCharacters[i];
	this->characters[this->numberOfCharacters - 1] = newCharacter;

	delete[] tempCharacters;
	cout << "New character successfully added!\n";
}

void MOBA::interact()
{
	char intAns = ' ';

	cout << "You opened a game called: " << this->getName() << ".\n";

	while (intAns != 'Q' && intAns != 'q')
	{
		cout << "How do you wish to proceed?\n\n";
		cout << "You can choose what to do next by entering the symbol in the brackets ():\n";
		cout << "(S)tart a level.\n";
		cout << "(A)dd a new character.\n";
		cout << "(P)rint a resume about the game.\n";
		cout << "(Q)uit game.\n";

		cin >> intAns;

		switch (intAns)
		{
		case 'S': case 's':
			cout << "Playing a level........................................\n";
			cout << "You have finished playing the level. Going back to the interaction menu...\n\n";  break;
		case 'A': case 'a':
			this->addCharacter(); break;
		case 'P': case 'p':
			this->printInfo(); break;
		}
	}
}

void MOBA::printInfo() const
{
	MultiplayerGame::printInfo();
	cout << "Currently it has " << this->numberOfCharacters << " different characters to choose from being: " << this->characters[0];
	for (int i = 1; i < this->numberOfCharacters; ++i)
		cout << ", " << this->characters[i];
	cout << endl;
}