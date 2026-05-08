
#include "MMORPG.h"

MMORPG::MMORPG() :
    Game(),
    RPG(),
    numberOfNPCs(0), npcs(nullptr) {
};

MMORPG::MMORPG(string name, string dev, int relDay, int relMonth, int relYear, int version, double size, double stars, string objective, int classesNum, const string* classes, int optionsNum, const string* options, int npcsNum, const string* npcs, int onlinePlayers, int servers, int downloads, int levels) :
    Game(name, dev, relDay, relMonth, relYear, version, size, stars),
    RPG(name, dev, relDay, relMonth, relYear, version, size, stars, objective, classesNum, classes, optionsNum, options, downloads, levels),
    numberOfNPCs(npcsNum)
{
    createValuedStringArray(this->npcs, npcs, this->numberOfNPCs);
}

MMORPG::MMORPG(string name, string dev, Date& date, Version& version, double size, double stars, string objective, int classesNum, const string* classes, int optionsNum, const string* options, int npcsNum, const string* npcs, int onlinePlayers, int servers, int downloads, int levels) :
    Game(name, dev, date, version, size, stars),
    RPG(name, dev, date, version, size, stars, objective, classesNum, classes, optionsNum, options, downloads, levels),
    numberOfNPCs(npcsNum)
{
    createValuedStringArray(this->npcs, npcs, this->numberOfNPCs);
}

MMORPG::MMORPG(MMORPG& mmorpg) :
    Game(mmorpg),
    RPG(mmorpg),
    numberOfNPCs(mmorpg.numberOfNPCs)
{
    createValuedStringArray(this->npcs, mmorpg.npcs, this->numberOfNPCs);
};

MMORPG::~MMORPG()
{
    delete[] npcs;
}


void MMORPG::addNPC()
{
    cout << "Enter your new NPC: ";
    string newNPC;
    cin >> newNPC;

    string* tempNPC = this->npcs;

    this->npcs = new string[++this->numberOfNPCs];

    for (int i = 0; i < this->numberOfNPCs - 1; ++i)
        this->npcs[i] = tempNPC[i];
    this->npcs[this->numberOfNPCs - 1] = newNPC;

    delete[] tempNPC;
    cout << "New NPC successfully added!\n";
}

void MMORPG::interact()
{
    char intAns = ' ';

    cout << "You opened a game called: " << this->getName() << ".\n";

    while (intAns != 'Q' && intAns != 'q')
    {
        cout << "How do you wish to proceed?\n\n";
        cout << "You can choose what to do next by entering the symbol in the brackets ():\n";
        cout << "(S)tart a level.\n";
        cout << "(A)dd a new NPC.\n";
        cout << "(P)rint a resume about the game.\n";
        cout << "(Q)uit game.\n";

        cin >> intAns;

        switch (intAns)
        {
        case 'S': case 's':
            cout << "Playing a level........................................\n";
            cout << "You have finished playing the level. Going back to the interaction menu...\n\n";  break;
        case 'A': case 'a':
            this->addNPC(); break;
        case 'P': case 'p':
            this->printInfo(); break;
        }
    }
}

//void MMORPG::update() override
//{
//  RPG::update();
//}

void MMORPG::printInfo() const
{
    RPG::printInfo();
    cout << "Currently it has " << this->numberOfNPCs << " different customization options to choose from being: " << this->npcs[0];
    for (int i = 1; i < this->numberOfNPCs; ++i)
        cout << ", " << this->npcs[i];
    cout << endl;
}
