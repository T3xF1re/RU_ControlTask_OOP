
#include "RPG.h"

RPG::RPG() :
    Game(),
    SingleplayerGame(),
    MultiplayerGame(),
        numberOfClasses(0), classes(nullptr), numberOfOptions(0), customisationOptions(nullptr) {};

RPG::RPG(string name, string dev, int relDay, int relMonth, int relYear, int version, double size, double stars, string objective, int classesNum, const string* classes, int optionsNum, const string* options, int onlinePlayers, int servers, int downloads, int levels) :
    Game(name, dev, relDay, relMonth, relYear, version, size, stars),
    SingleplayerGame(name, dev, relDay, relMonth, relYear, version, size, stars, objective, downloads, levels),
    MultiplayerGame(name, dev, relDay, relMonth, relYear, version, size, stars, onlinePlayers, servers),
        numberOfClasses(classesNum), numberOfOptions(optionsNum)
{
    createValuedStringArray(this->classes, classes, this->numberOfClasses);
    createValuedStringArray(this->customisationOptions, options, this->numberOfOptions);
}

RPG::RPG(string name, string dev, Date& date, Version& version, double size, double stars, string objective, int classesNum, const string* classes, int optionsNum, const string* options, int onlinePlayers, int servers, int downloads, int levels) :
    Game(name, dev, date, version, size, stars),
    SingleplayerGame(name, dev, date, version, size, stars, objective, downloads, levels),
    MultiplayerGame(name, dev, date, version, size, stars, onlinePlayers, servers),
        numberOfClasses(classesNum), numberOfOptions(optionsNum)
{
    createValuedStringArray(this->classes, classes, this->numberOfClasses);
    createValuedStringArray(this->customisationOptions, options, this->numberOfOptions);
}

RPG::RPG(RPG& rpg) :
    Game(rpg), 
    SingleplayerGame(rpg),
    MultiplayerGame(rpg), 
        numberOfClasses(rpg.numberOfClasses), numberOfOptions(rpg.numberOfOptions)
{
    createValuedStringArray(this->classes, rpg.classes, this->numberOfClasses);
    createValuedStringArray(this->customisationOptions, rpg.customisationOptions, this->numberOfOptions);
};

RPG::~RPG()
{
    delete[] classes;
    delete[] customisationOptions;
}


void RPG::addClass()
{
    cout << "Enter your new class: ";
    string newClass;
    cin >> newClass;

    string* tempClasses = this->classes;

    this->classes = new string[++this->numberOfClasses];

    for (int i = 0; i < this->numberOfClasses - 1; ++i)
        this->classes[i] = tempClasses[i];
    this->classes[this->numberOfClasses - 1] = newClass;

    delete[] tempClasses;
    cout << "New class successfully added!\n";
}

void RPG::interact()
{
    char intAns = ' ';

    cout << "You opened a game called: " << this->getName() << ".\n";

    while (intAns != 'Q' && intAns != 'q')
    {
        cout << "How do you wish to proceed?\n\n";
        cout << "You can choose what to do next by entering the symbol in the brackets ():\n";
        cout << "(S)tart a level.\n";
        cout << "(A)dd a new class.\n";
        cout << "(P)rint a resume about the game.\n";
        cout << "(Q)uit game.\n";

        cin >> intAns;

        switch (intAns)
        {
        case 'S': case 's':
            cout << "Playing a level........................................\n";
            cout << "You have finished playing the level. Going back to the interaction menu...\n\n";  break;
        case 'A': case 'a':
            this->addClass(); break;
        case 'P': case 'p':
            this->printInfo(); break;
        }
    }
}

void RPG::update()
{
    MultiplayerGame::update();
}

void RPG::printInfo() const
{
    SingleplayerGame::printInfo();
    cout << "Currently it has " << this->onlinePlayers << " players online and " << this->availableServers << " available servers with average ping of " << ceil(this->averagePing * 10) / 10.0 << ".\n";

    cout << "Currently it has " << this->numberOfOptions << " different customization options to choose from being: " << this->customisationOptions[0];
    for (int i = 1; i < this->numberOfOptions; ++i)
        cout << ", " << this->customisationOptions[i];
    cout << endl;
    cout << "and " << this->numberOfClasses << " different classes to choose from being: " << this->classes[0];
    for (int i = 1; i < this->numberOfClasses; ++i)
        cout << ", " << this->classes[i];
    cout << endl;
}