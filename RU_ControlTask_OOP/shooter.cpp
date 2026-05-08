
#include "Shooter.h"

Shooter::Shooter() :
	Game(),
	MultiplayerGame(),
	numberOfGear(0), gear(nullptr) { };

Shooter::Shooter(string name, string dev, int relDay, int relMonth, int relYear, int version, double size, double stars, int gearNum, const string* gear, int onlinePlayers, int servers) :
	Game(name, dev, relDay, relMonth, relYear, version, size, stars),
	MultiplayerGame(name, dev, relDay, relMonth, relYear, version, size, stars, onlinePlayers, servers),
	numberOfGear(gearNum)
{
	createValuedStringArray(this->gear, gear, this->numberOfGear);
}

Shooter::Shooter(string name, string dev, Date& date, Version& version, double size, double stars, int gearNum, const string* gear, int onlinePlayers, int servers) :
	Game(name, dev, date, version, size, stars),
	MultiplayerGame(name, dev, date, version, size, stars, onlinePlayers, servers),
	numberOfGear(gearNum)
{
	createValuedStringArray(this->gear, gear, this->numberOfGear);
}

Shooter::Shooter(Shooter& shotr) :
	Game(shotr),
	MultiplayerGame(shotr),
	numberOfGear(shotr.numberOfGear)
{
	createValuedStringArray(this->gear, gear, this->numberOfGear);
}

Shooter::~Shooter()
{
	delete[] this->gear;
}


void Shooter::addGear()
{
    cout << "Enter your new gear (equipment/tools/weapons): ";
    string newGear;
    cin >> newGear;

    string* tempGear = this->gear;

    this->gear = new string[++this->numberOfGear];

    for (int i = 0; i < this->numberOfGear - 1; ++i)
        this->gear[i] = tempGear[i];
    this->gear[this->numberOfGear - 1] = newGear;

    delete[] tempGear;
    cout << "New gear successfully added!\n";
}

void Shooter::interact()
{
    char intAns = ' ';

    cout << "You opened a game called: " << this->getName() << ".\n";

    while (intAns != 'Q' && intAns != 'q')
    {
        cout << "How do you wish to proceed?\n\n";
        cout << "You can choose what to do next by entering the symbol in the brackets ():\n";
        cout << "(S)tart a level.\n";
        cout << "(A)dd a new gear option (equipment/tools/weapons).\n";
        cout << "(P)rint a resume about the game.\n";
        cout << "(Q)uit game.\n";

        cin >> intAns;

        switch (intAns)
        {
        case 'S': case 's':
            cout << "Playing a level........................................\n";
            cout << "You have finished playing the level. Going back to the interaction menu...\n\n";  break;
        case 'A': case 'a':
            this->addGear(); break;
        case 'P': case 'p':
            this->printInfo(); break;
        }
    }
}

void Shooter::printInfo() const
{
    MultiplayerGame::printInfo();
    cout << "Currently it has " << this->numberOfGear << " different gear options to choose from being: " << this->gear[0];
    for (int i = 1; i < this->numberOfGear; ++i)
        cout << ", " << this->gear[i];
    cout << endl;
}