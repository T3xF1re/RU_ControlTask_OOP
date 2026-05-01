#pragma once
#include "SingleplayerGame.h"

class Sandbox : public SingleplayerGame
{
protected:
    int numberOfMaterials;
    string* materials;
    int numberOfShapes;
    string* shapes;

public:
    Sandbox();
    Sandbox(string name, string dev, int relDay, int relMonth, int relYear, int version, double size, double stars, string objective, int obstaclesNum, const string* obstacles, int materialsNum, const string* materials, int shapesNum, const string* shapes, int downloads = 0, int levels = 1);
    Sandbox(string name, string dev, Date& date, Version& version, double size, double stars, string objective, int obstaclesNum, const string* obstacles, int materialsNum, const string* materials, int shapesNum, const string* shapes, int downloads = 0, int levels = 1);
    Sandbox(Sandbox& sndbox);
    ~Sandbox();


};