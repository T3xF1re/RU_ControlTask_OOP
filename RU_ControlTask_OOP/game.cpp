#include <iostream>
using namespace std;

#include "Game.h"

Game::Game() :
    name("Unknown"), developer("Unknown"), releaseDate(), currentVersion(), size(0.0), ratingStars(3) {};

Game::Game(string name, string dev, int relDay, int relMonth, int relYear, int version, double size, double stars) :
    name(name), developer(dev), releaseDate(relYear, relMonth, relDay), currentVersion(version), size(size)
{
    if (stars < 0) stars = 0;
    else if (stars > 5) stars = 5;
    this->ratingStars = stars;
};

Game::Game(string name, string dev, Date& date, Version& version, double size, double stars) :
    name(name), developer(dev), releaseDate(date), currentVersion(version), size(size)
{
    if (stars < 0) stars = 0;
    else if (stars > 5) stars = 5;
    this->ratingStars = stars;
};

Game::Game(Game& game) :
    name(game.name), developer(game.developer), releaseDate(game.releaseDate), currentVersion(game.currentVersion), size(game.size), ratingStars(game.ratingStars) {};

void Game::printInfo() const
{
    cout << "Game: " << this->name << " is made by " << this->developer << " on "; this->releaseDate.printDate();
    cout << "." << endl << "The current version: "; this->currentVersion.printVersion();
    cout << " is " << this->size << "GB and has " << ceil(this->ratingStars * 10) / 10.0 << " stars rating.\n";
}