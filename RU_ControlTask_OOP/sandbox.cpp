
#include "Sandbox.h"

Sandbox::Sandbox() : 
    Game(),
    SingleplayerGame(), 
        numberOfMaterials(0), materials(nullptr), numberOfShapes(0), shapes(nullptr) {};

Sandbox::Sandbox(string name, string dev, int relDay, int relMonth, int relYear, int version, double size, double stars, string objective, int materialsNum, const string* materials, int shapesNum, const string* shapes, int downloads, int levels) :
    Game(name, dev, relDay, relMonth, relYear, version, size, stars),
    SingleplayerGame(name, dev, relDay, relMonth, relYear, version, size, stars, objective, downloads, levels),
        numberOfMaterials(materialsNum), numberOfShapes(shapesNum)
{
    createValuedStringArray(this->materials, materials, this->numberOfMaterials);
    createValuedStringArray(this->shapes, shapes, this->numberOfShapes);
}

Sandbox::Sandbox(string name, string dev, Date& date, Version& version, double size, double stars, string objective, int materialsNum, const string* materials, int shapesNum, const string* shapes, int downloads, int levels) :
    Game(name, dev, date, version, size, stars),
    SingleplayerGame(name, dev, date, version, size, stars, objective, downloads, levels),
        numberOfMaterials(materialsNum), numberOfShapes(shapesNum)
{
    createValuedStringArray(this->materials, materials, this->numberOfMaterials);
    createValuedStringArray(this->shapes, shapes, this->numberOfShapes);
}

Sandbox::Sandbox(Sandbox& sndbox) :
    Game(sndbox),
    SingleplayerGame(sndbox),
        numberOfMaterials(sndbox.numberOfMaterials), numberOfShapes(sndbox.numberOfShapes)
{
    createValuedStringArray(this->materials, sndbox.materials, this->numberOfMaterials);
    createValuedStringArray(this->shapes, sndbox.shapes, this->numberOfShapes);
};

Sandbox::~Sandbox()
{
    delete[] materials;
    delete[] shapes;
}


void Sandbox::addMaterial(string newMaterial)
{
    string* tempMat = this->materials;

    this->materials = new string[++this->numberOfMaterials];
    for (int i = 0; i < this->numberOfMaterials - 1; ++i)
        this->materials[i] = tempMat[i];
    this->materials[this->numberOfMaterials - 1] = newMaterial;

    delete[] tempMat;
}

void Sandbox::printInfo() const
{
    SingleplayerGame::printInfo();
    cout << "Currently it has " << this->numberOfMaterials << " different materials to choose from being: " << this->materials[0];
    for (int i = 1; i < this->numberOfMaterials; ++i)
        cout << ", " << this->materials[i];
    cout << " and " << this->numberOfShapes << " different shapes to choose from being: " << this->shapes[0];
    for (int i = 1; i < this->numberOfShapes; ++i)
        cout << ", " << this->shapes[i];
    cout << endl;
}