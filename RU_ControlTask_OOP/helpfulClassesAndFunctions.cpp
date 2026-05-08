#include <string>
#include <iostream>
#include "helpfulClassesAndFunctions.h"
using namespace std;

//additional classes and fucnctions
void createValuedStringArray(string* arr1, const string* arr2, int arr2_size)
{
    arr1 = new string[arr2_size];
    for (int i = 0; i < arr2_size; ++i)
        arr1[i] = arr2[i];
};

//class Date
Date::Date() :day(0), month(0), year(0) {};
Date::Date(short year, short month, short day)
{
    if (checkValidDate(day, month, year))
    {
        this->day = day;
        this->month = month;
        this->year = year;
    }
    else
    {
        this->day = 0;
        this->month = 0;
        this->year = 0;
    }
};
Date::Date(const string date)
{
    this->day = (date[0] - '0') * 10 + date[1] - '0';
    this->month = (date[3] - '0') * 10 + date[4] - '0';
    this->year = (date[6] - '0') * 1000 + (date[7] - '0') * 100 + (date[8] - '0') * 10 + date[9] - '0';

    if (checkValidDate(this->day, this->month, this->year))
    {
        this->day = day;
        this->month = month;
        this->year = year;
    }
    else
    {
        this->day = 0;
        this->month = 0;
        this->year = 0;
    }
};
Date::Date(Date& date)
{
    if (checkValidDate(date.day, date.month, date.year))
    {
        this->day = date.day;
        this->month = date.month;
        this->year = date.year;
    }
    else
    {
        this->day = 0;
        this->month = 0;
        this->year = 0;
    }
}
Date::Date(Date&& date) noexcept
{
    if (checkValidDate(date.day, date.month, date.year))
    {
        this->day = date.day;
        this->month = date.month;
        this->year = date.year;
    }
    else
    {
        this->day = 0;
        this->month = 0;
        this->year = 0;
    }
    date.day = 0;
    date.month = 0;
    date.year = 0;
}
//Date::~Date() {};

bool Date::checkValidDate(short day, short month, short year)
{
    if (year < 1900 || year > 2026 || day < 1 || month < 1)
        return false;
    else
    {
        switch (month)
        {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            if (day > 31)
                return false; break;
        case 4: case 6: case 9: case 11:
            if (day > 30)
                return false; break;
        case 2:
            if (year % 4 == 0 || (year % 100 != 0 && year % 400 == 0)) {
                if (day > 29)
                    return false;
            }
            else {
                if (day > 28)
                    return false;
            }
            break;
        default:
            return false;
        }
    }
    return true;
};
void Date::printDate() const
{
    if (this->day == 0 || this->month == 0 || this->year == 0)
        cout << "Invalid Date";
    else
        printf("%02d.%02d.%d", this->day, this->month, this->year);
}

//class Version
Version::Version() : version(1000000) {};
Version::Version(int version) : version(0)
{
    changeVersion(version);
};
Version::Version(Version& version) : version(0)
{
    changeVersion(version.version);
};
Version::Version(Version&& version) noexcept
{
    changeVersion(version.version);
    version.version = 0;
};
//Version::~Version() {};

//changing the version (setter)
void Version::changeVersion(int newVersion)
{
    if (newVersion < 1000000)
        newVersion += 1000000;
    this->version = newVersion;
}
int Version::getVersion() const
{
    return this->version;
}

//printing is in format AA.BB.CC.DD
void Version::printVersion() const
{
    int ver = 0;
    for (int i = 3; i >= 0; --i)
    {
        ver = this->version / (int)pow(100, i); ver %= 100;
        if (ver > 0)
        {
            cout << ver;
            if (i > 0 && this->version % (int)pow(100, i) != 0)
                cout << '.';
        }
    }
}