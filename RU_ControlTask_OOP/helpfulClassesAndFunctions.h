#pragma once
#include <iostream>
using namespace std;

//additional classes and fucnctions
void createValuedStringArray(string* arr1, const string* arr2, int arr2_size);

//class Date - storing a given date
class Date
{
    short day;
    short month;
    short year;

    //checks if a date is valid (eg. 31.04.2020, 11.15.2000, 07.08.2300)
    bool checkValidDate(short day, short month, short year);

public:
    Date();
    Date(short year, short month = 1, short day = 1);
    Date(Date& date);
    Date(Date&& date) noexcept;
    ~Date();
    void printDate() const;
};

//class Version - storing a given version as a number AABBCCDD
class Version
{
    int version;

public:
    Version();
    Version(int version);
    Version(Version& version);
    Version(Version&& version) noexcept;
    ~Version();

    //changing the version (setter)
    void changeVersion(int newVersion);
    int getVersion() const;

    //printing is in format AA.BB.CC.DD
    void printVersion() const;
};