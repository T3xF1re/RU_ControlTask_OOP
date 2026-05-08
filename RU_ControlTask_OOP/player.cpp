
#include "Player.h"

gameGenres Player::chooseGenre()
{
	cout << "Choose a game genre (Platformer | Sandbox | MOBA | Shooter | RPG | MMORPG | Hero Shooter): ";
	string genre = "";
	cin >> genre;

	if (genre == "Platformer")
		return _Platformer;
	if (genre == "Sandbox")
		return _Sandbox;
	if (genre == "MOBA")
		return _MOBA;
	if (genre == "Shooter")
		return _Shooter;
	if (genre == "RPG")
		return _RPG;
	if (genre == "MMORPG")
		return _MMORPG;
	if (genre == "Hero Shooter")
		return _HeroShooter;
}

void Player::bootUp()
{
	char ans = ' ';
	
	while (ans != 'S' && ans != 's')
	{
		cout << "Your PC has been boot up. You currently have " << this->numberOfGames << " games downloaded on it.\n\n";
		cout << "You can choose what to do next by entering the symbol in the brackets ():\n";
		cout << "(D)ownload new game.\n";
		cout << "(U)ninstall an existing game.\n";
		cout << "(O)pen a game to play.\n";
		cout << "(P)rint a resume about every game.\n";
		cout << "(S)hut down your PC.\n";

		cin >> ans;
		int posAns;

		switch (ans)
		{
		case 'D': case 'd':
			this->downloadGame(); break;
		case 'U': case 'u':
			cout << "Which game (number 1 - " << this->numberOfGames << "): ";
			cin >> posAns;
			this->deleteGame(posAns); break;
		case 'O': case 'o':
			cout << "Which game (number 1 - " << this->numberOfGames << "): ";
			cin >> posAns;
			this->openGame(posAns); break;
		case 'P': case 'p':
			this->printAllGamesInfo(); break;
		}
	}
}

const Game* Player::downloadGame()
{
	gameGenres newGenre = chooseGenre();

	while (newGenre < _Platformer || newGenre > _HeroShooter)
	{
		cout << "This is unvalid game genre! Please try again.\n";
		newGenre = chooseGenre();
	}

	++this->numberOfGames;

	string newName;
	cout << "What is the name of the new game: "; cin >> newName;
	string newDeveloper;
	cout << "Who developed this new game: "; cin >> newDeveloper;
	string newRelDate;
	cout << "What date was this game released (format: dd.mm.yyyy): ";  cin >> newRelDate;
	Date newReleaseDate(newRelDate);
	int newVer;
	cout << "What is the current version of the game (number AABBCCDD for version AA.BB.CC.DD): "; cin >> newVer;
	Version newCurrentVersion(newVer);
	double newSize;
	cout << "How big is this game (in GB): "; cin >> newSize;
	double newRatingStars = 0.0;
	cout << "What rating does it currently have (from 1.0 to 5.0 stars): "; cin >> newSize;

	string newObjective;
	int newTotalDownloads;
	int newNumberOfLevels;
	if (newGenre == _Platformer || newGenre == _Sandbox || newGenre == _RPG || newGenre == _MMORPG) // means it's from the Singleplayer Game class
	{
		cout << "What is main objective of the game: ";
		cin >> newObjective;
		cout << "How many downloads does the game have: ";
		cin >> newTotalDownloads;
		cout << "How many levels does the game currently have: ";
		cin >> newNumberOfLevels;
	}
	int newOnlinePlayers;
	int newAvailableServers;
	if (newGenre == _MOBA || newGenre == _Shooter || newGenre == _RPG || newGenre == _MMORPG || newGenre == _HeroShooter) // means it's from the Multiplayer Game class
	{
		cout << "How many online players does the game currently have: ";
		cin >> newOnlinePlayers;
		cout << "How many available servers does the game have: ";
		cin >> newAvailableServers;
	}

	int strArr1Length = 0;
	string* strArr1 = nullptr;
	int strArr2Length = 0;
	string* strArr2 = nullptr;
	int strArr3Length = 0;
	string* strArr3 = nullptr;
	switch (newGenre)
	{
	case _Platformer:
		cout << "How many obstacles does the game have: "; cin >> strArr1Length;
		strArr1 = new string[strArr1Length];
		for (int i = 0; i < strArr1Length; ++i)
		{
			cout << "Obstacle " << i + 1 << ": ";
			cin >> strArr1[i];
		}
		return new Platformer(newName, newDeveloper, newReleaseDate, newCurrentVersion, newSize, newRatingStars, strArr1Length, strArr1, newObjective, newTotalDownloads, newNumberOfLevels);

	case _Sandbox:
		cout << "How many materials does the game have: "; cin >> strArr1Length;
		strArr1 = new string[strArr1Length];
		for (int i = 0; i < strArr1Length; ++i)
		{
			cout << "Material " << i + 1 << ": ";
			cin >> strArr1[i];
		}
		cout << "How many building shapes does the game have: "; cin >> strArr2Length;
		strArr2 = new string[strArr2Length];
		for (int i = 0; i < strArr2Length; ++i)
		{
			cout << "Building Shape " << i + 1 << ": ";
			cin >> strArr2[i];
		}
		return new Sandbox(newName, newDeveloper, newReleaseDate, newCurrentVersion, newSize, newRatingStars, newObjective, strArr1Length, strArr1, strArr2Length, strArr2, newTotalDownloads, newNumberOfLevels);

	case _MOBA:
		cout << "How many characters does the game have: "; cin >> strArr1Length;
		strArr1 = new string[strArr1Length];
		for (int i = 0; i < strArr1Length; ++i)
		{
			cout << "Character " << i + 1 << ": ";
			cin >> strArr1[i];
		}
		return new MOBA(newName, newDeveloper, newReleaseDate, newCurrentVersion, newSize, newRatingStars, strArr1Length, strArr1, newOnlinePlayers, newAvailableServers);

	case _Shooter:
		cout << "How much different gear does the game have: "; cin >> strArr1Length;
		strArr1 = new string[strArr1Length];
		for (int i = 0; i < strArr1Length; ++i)
		{
			cout << "Piece of gear " << i + 1 << ": ";
			cin >> strArr1[i];
		}
		return new Shooter(newName, newDeveloper, newReleaseDate, newCurrentVersion, newSize, newRatingStars, strArr1Length, strArr1, newOnlinePlayers, newAvailableServers);

	case _RPG:
		cout << "How many classes does the game have: "; cin >> strArr1Length;
		strArr1 = new string[strArr1Length];
		for (int i = 0; i < strArr1Length; ++i)
		{
			cout << "Class " << i + 1 << ": ";
			cin >> strArr1[i];
		}
		cout << "How many customization options does the game have: "; cin >> strArr1Length;
		strArr2 = new string[strArr2Length];
		for (int i = 0; i < strArr2Length; ++i)
		{
			cout << "Option " << i + 1 << ": ";
			cin >> strArr2[i];
		}
		return new RPG(newName, newDeveloper, newReleaseDate, newCurrentVersion, newSize, newRatingStars, newObjective, strArr1Length, strArr1, strArr2Length, strArr2, newOnlinePlayers, newAvailableServers, newTotalDownloads, newNumberOfLevels);
	
	case _MMORPG:
		cout << "How many classes does the game have: "; cin >> strArr1Length;
		strArr1 = new string[strArr1Length];
		for (int i = 0; i < strArr1Length; ++i)
		{
			cout << "Class " << i + 1 << ": ";
			cin >> strArr1[i];
		}
		cout << "How many customization options does the game have: "; cin >> strArr1Length;
		strArr2 = new string[strArr2Length];
		for (int i = 0; i < strArr2Length; ++i)
		{
			cout << "Option " << i + 1 << ": ";
			cin >> strArr2[i];
		}
		cout << "How much different npcs does the game have: "; cin >> strArr1Length;
		strArr3 = new string[strArr3Length];
		for (int i = 0; i < strArr3Length; ++i)
		{
			cout << "NPC " << i + 1 << ": ";
			cin >> strArr3[i];
		}
		return new MMORPG(newName, newDeveloper, newReleaseDate, newCurrentVersion, newSize, newRatingStars, newObjective, strArr1Length, strArr1, strArr2Length, strArr2, strArr3Length, strArr3, newOnlinePlayers, newAvailableServers);


	case _HeroShooter:
		cout << "How many characters does the game have: "; cin >> strArr1Length;
		strArr1 = new string[strArr1Length];
		for (int i = 0; i < strArr1Length; ++i)
		{
			cout << "Character " << i + 1 << ": ";
			cin >> strArr1[i];
		}
		cout << "How much different gear does the game have: "; cin >> strArr1Length;
		strArr2 = new string[strArr2Length];
		for (int i = 0; i < strArr2Length; ++i)
		{
			cout << "Piece of gear " << i + 1 << ": ";
			cin >> strArr2[i];
		}
		cout << "How much different monsters does the game have: "; cin >> strArr1Length;
		strArr3 = new string[strArr3Length];
		for (int i = 0; i < strArr3Length; ++i)
		{
			cout << "Monster " << i + 1 << ": ";
			cin >> strArr3[i];
		}
		return new HeroShooter(newName, newDeveloper, newReleaseDate, newCurrentVersion, newSize, newRatingStars, strArr1Length, strArr1, strArr2Length, strArr2, strArr3Length, strArr3, newOnlinePlayers, newAvailableServers);

	}
}

void Player::deleteGame(int pos)
{
	while (pos <= 0 || pos > this->numberOfGames)
		cout << "You can't go below 1 game or don't have that much downloaded games!" << endl << "Try with a different number." << endl;

	string deleteName = this->games[pos - 1]->getName();

	char answer = ' ';
	cout << "Do you wish to continue uninstalling " << deleteName << "? (y/n): ";
	cin >> answer;
	if (answer != 'Y' && answer != 'y')
		return;
	cout << "Do you REALLY wish to uninstall " << deleteName << "? (y/n): ";
	if (answer != 'Y' && answer != 'y')
		return;
	cin >> answer;
	cout << "You won't be able to play " << deleteName << "! Continue? (y/n): ";
	if (answer != 'Y' && answer != 'y')
		return;
	cin >> answer;

	this->games[pos - 1] = this->games[this->numberOfGames - 1];
	this->games[this->numberOfGames - 1] = nullptr;

	--this->numberOfGames;
	cout << "Game " << deleteName << " has been successfully uninstalled!\n";
}

void Player::openGame(int pos)
{
	while (pos <= 0 || pos > this->numberOfGames)
		cout << "You can't go below 1 game or don't have that much downloaded games!" << endl << "Try with a different number." << endl;

	this->games[pos - 1]->interact();
}

void Player::printAllGamesInfo()
{
	cout << "Printing the info of all downloaded games...\n";
	cout << "-------------------------------------------------\n";
	for (int i = 0; i < this->numberOfGames; ++i)
	{
		this->games[i]->printInfo();
		cout << "-------------------------------------------------\n";
	}
}