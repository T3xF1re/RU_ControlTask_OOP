
#include "Platformer.h"

Platformer::Platformer() :
    Game(),
    SingleplayerGame(),
        numberOfObstacles(0), obstacles(nullptr) {};

Platformer::Platformer(string name, string dev, int relDay, int relMonth, int relYear, int version, double size, double stars, int obstaclesNum, const string* obstacles, string objective, int downloads, int levels) :
    Game(name, dev, relDay, relMonth, relYear, version, size, stars),
    SingleplayerGame(name, dev, relDay, relMonth, relYear, version, size, stars, objective, downloads, levels),
        numberOfObstacles(obstaclesNum)
{
    this->obstacles = new string[this->numberOfObstacles];

    for (int i = 0; i < this->numberOfObstacles; ++i)
        this->obstacles[i] = obstacles[i];
}
Platformer::Platformer(string name, string dev, Date& date, Version& version, double size, double stars, int obstaclesNum, const string* obstacles, string objective, int downloads, int levels) :
    Game(name, dev, date, version, size, stars),
    SingleplayerGame(name, dev, date, version, size, stars, objective, downloads, levels),
        numberOfObstacles(obstaclesNum)
{
    this->obstacles = new string[this->numberOfObstacles];

    for (int i = 0; i < this->numberOfObstacles; ++i)
        this->obstacles[i] = obstacles[i];
}

Platformer::Platformer(Platformer& platformer) :
    Game(platformer),
    SingleplayerGame(platformer),
        numberOfObstacles(platformer.numberOfLevels)
{
    createValuedStringArray(this->obstacles, obstacles, this->numberOfObstacles);
};

Platformer::~Platformer()
{
    delete[] obstacles;
}


void Platformer::addObstacle()
{
    cout << "Enter your new obstacle: ";
    string newObstacle;
    cin >> newObstacle;

    string* tempObst = this->obstacles;

    this->obstacles = new string[++this->numberOfObstacles];
    for (int i = 0; i < this->numberOfObstacles - 1; ++i)
        this->obstacles[i] = tempObst[i];
    this->obstacles[this->numberOfObstacles - 1] = newObstacle;

    delete[] tempObst;
    cout << "New obstacle successfully added!\n";
}
/*void Platformer::removeObstacle(string wasteObstacle, int wastePos)
{
    string* tempObst = this->obstacles;

    this->obstacles = new string[--this->numberOfObstacles];
    for (int i = 0, j = 0; i < this->numberOfObstacles && j < this->numberOfObstacles + 1; ++j)
    {
        if ((wastePos > 0 && wastePos - 1 != j) || (wasteObstacle != "" && tempObst[j] != wasteObstacle))
            this->obstacles[i++] = tempObst[j];
    }

    delete[] tempObst;
}*/

void Platformer::interact()
{
    char intAns = ' ';

    cout << "You opened a game called: " << this->getName() << ".\n";

    while (intAns != 'Q' && intAns != 'q')
    {
        cout << "How do you wish to proceed?\n\n";
        cout << "You can choose what to do next by entering the symbol in the brackets ():\n";
        cout << "(S)tart a level.\n";
        cout << "(A)dd a new obstacle.\n";
        cout << "(P)rint a resume about the game.\n";
        cout << "(Q)uit game.\n";

        cin >> intAns;
        int posAns;

        switch (intAns)
        {
        case 'S': case 's':
            cout << "Playing a level........................................\n";
            cout << "You have finished playing the level. Going back to the interaction menu...\n\n";  break;
        case 'A': case 'a':
            this->addObstacle(); break;
        case 'P': case 'p':
            this->printInfo(); break;
        }
    }
}

void Platformer::printInfo() const
{
    SingleplayerGame::printInfo();
    cout << "Currently it has " << this->numberOfObstacles << " different obstacles being: " << this->obstacles[0];
    for (int i = 1; i < this->numberOfObstacles; ++i)
        cout << ", " << this->obstacles[i];
    cout << endl;
}