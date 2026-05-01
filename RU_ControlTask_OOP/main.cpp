#include <time.h>
#include <string>
#include <iostream>
using namespace std;

#include "Player.h"

int main()
{
    srand(time(0));

    Player player;
    player.bootUp();

    return 0;
}