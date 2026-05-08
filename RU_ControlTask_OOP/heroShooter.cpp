
#include "HeroShooter.h"

HeroShooter::HeroShooter() :
    Game(),
    MultiplayerGame(),
    MOBA(),
    Shooter(),
    numberOfMonsters(0), monsters(nullptr) {
};

HeroShooter::HeroShooter(string name, string dev, int relDay, int relMonth, int relYear, int version, double size, double stars, int charactersNum, const string* characters, int gearNum, const string* gear, int monstersNum, const string* monsters, int onlinePlayers, int servers, int downloads, int levels) :
    Game(name, dev, relDay, relMonth, relYear, version, size, stars),
    MultiplayerGame(name, dev, relDay, relMonth, relYear, version, size, stars, onlinePlayers, servers),
    MOBA(name, dev, relDay, relMonth, relYear, version, size, stars, charactersNum, characters, onlinePlayers, servers),
    Shooter(name, dev, relDay, relMonth, relYear, version, size, stars, gearNum, gear, onlinePlayers, servers),
    numberOfMonsters(monstersNum)
{
    createValuedStringArray(this->monsters, monsters, this->numberOfMonsters);
}

HeroShooter::HeroShooter(string name, string dev, Date& date, Version& version, double size, double stars, int charactersNum, const string* characters, int gearNum, const string* gear, int monstersNum, const string* monsters, int onlinePlayers, int servers, int downloads, int levels) :
    Game(name, dev, date, version, size, stars),
    MultiplayerGame(name, dev, date, version, size, stars, onlinePlayers, servers),
    MOBA(name, dev, date, version, size, stars, charactersNum, characters, onlinePlayers, servers),
    Shooter(name, dev, date, version, size, stars, gearNum, gear, onlinePlayers, servers),
    numberOfMonsters(monstersNum)
{
    createValuedStringArray(this->monsters, monsters, this->numberOfMonsters);
}

HeroShooter::HeroShooter(HeroShooter& heroShotr) :
    Game(heroShotr),
    MultiplayerGame(heroShotr),
    MOBA(heroShotr),
    Shooter(heroShotr),
    numberOfMonsters(heroShotr.numberOfMonsters)
{
    createValuedStringArray(this->monsters, heroShotr.monsters, this->numberOfMonsters);
};

HeroShooter::~HeroShooter()
{
    delete[] monsters;
}


void HeroShooter::addMonster()
{
    cout << "Enter your new monster: ";
    string newMonster;
    cin >> newMonster;

    string* tempMonsters = this->monsters;

    this->monsters = new string[++this->numberOfMonsters];

    for (int i = 0; i < this->numberOfMonsters - 1; ++i)
        this->monsters[i] = tempMonsters[i];
    this->monsters[this->numberOfMonsters - 1] = newMonster;

    delete[] tempMonsters;
    cout << "New monster successfully added!\n";
}

void HeroShooter::interact()
{
    char intAns = ' ';

    cout << "You opened a game called: " << this->getName() << ".\n";

    while (intAns != 'Q' && intAns != 'q')
    {
        cout << "How do you wish to proceed?\n\n";
        cout << "You can choose what to do next by entering the symbol in the brackets ():\n";
        cout << "(S)tart a level.\n";
        cout << "(A)dd a new monster.\n";
        cout << "(P)rint a resume about the game.\n";
        cout << "(Q)uit game.\n";

        cin >> intAns;

        switch (intAns)
        {
        case 'S': case 's':
            cout << "Playing a level........................................\n";
            cout << "You have finished playing the level. Going back to the interaction menu...\n\n";  break;
        case 'A': case 'a':
            this->addMonster(); break;
        case 'P': case 'p':
            this->printInfo(); break;
        }
    }
}

//void HeroShooter::update()
//{
//    MultiplayerGame::update();
//}

void HeroShooter::printInfo() const
{
    MOBA::printInfo();
    cout << "Currently it has " << this->numberOfGear << " different gear options to choose from being: " << this->gear[0];
    for (int i = 1; i < this->numberOfGear; ++i)
        cout << ", " << this->gear[i];
    cout << endl;

    cout << "Currently it has " << this->numberOfMonsters << " different obstacles being: " << this->monsters[0];
    for (int i = 1; i < this->numberOfMonsters; ++i)
        cout << ", " << this->monsters[i];
    cout << endl;
}
