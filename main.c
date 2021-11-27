#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "headers/linkedList.h"
#include "headers/readFile.h"
#include "headers/gamePlay.h"
#include "headers/newSleep.h"

int main(int argc, char *argv[])
{
    system("cls");
    char filename[50];
    char *Hero = "hero.txt";
    char *Eneimes = "enemies.txt";
    float seconds;

    if (argc > 4) /*if arguments is more than four*/
    {
        printf("Enter only 3 arguments\n");
        exit(1);
    }
    else if (argc < 4) /*if arguments is less than four*/
    {
        printf("Enter only 3 arguments\n");
        exit(1);
    }
    Hero = argv[1];
    Eneimes = argv[2];
    seconds = atof(argv[3]);
    LinkedListPointer eneimes = getEneimes(Eneimes);
    MayhemPointer hero = getHero(Hero);
    gamePlay(hero, eneimes, seconds);
    return 0;
}