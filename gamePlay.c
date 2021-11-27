#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "headers/linkedList.h"
#include "headers/readFile.h"
#include "headers/gamePlay.h"
#include "headers/newSleep.h"

int gamePlay(MayhemPointer Hero, LinkedListPointer Eneimes, int seconds)
{
    MayhemPointer Eneime;
    LinkedListPointer *topE = &Eneimes;
    int hpretore = Hero->hp;
    int hitType;
    char *attack;
    int EffectiveAttack;
    printf("Hello Mortals\n");
    printf("Welcome to auto RPG!\n");
    printf("\nHero:");
    printHero(Hero);
    printf("\n\nEneimes:");
    printEneimes(Eneimes);

    while (Eneimes != NULL)
    {
        newSleep(seconds);
        system("cls");
        Eneime = ((MayhemPointer)Eneimes->data);

        hitType = BattleTurnRandomness();
        EffectiveAttack = Fight(&Hero, &Eneime, hitType);
        attack = attacktype(hitType);
        DisplayStatsHero(Hero);
        if ((Hero->hp) <= (hpretore * 0.3))
        {
            printf("\n%s is badly injured, eating 1 medicine. HP is restored!", Hero->hm_name);
            if (Hero->med > 0)
            {
                Hero->hp = hpretore;
            }
            Hero->med--;
        }
        printf("\n%s attacks %s, %sdealing %d damage!\n", Hero->hm_name, Eneime->hm_name, attack, EffectiveAttack);
        DisplayStatsEneime((MayhemPointer)Eneimes->data);

        if (Hero->atk <= (((MayhemPointer)Eneimes->data)->def) / 2)
        {
            system("cls");
            printf("\nEnd of the Game.\n%s is defeated!\n", Hero->hm_name);
            printf("Hero attack is less powerful then Eneime Defence");
            printf("World is Doomed!");
            FreeAllocatedMemory(topE);
            return (0);
        }
        if (Eneime->hp == 0)
        {
            printf("\n%s is defeated!", Eneime->hm_name);
            free(Eneimes->data);
            newSleep(seconds);
            system("cls");
            if (Eneimes->next != NULL)
            {
                battleReward(&Hero);
            }
            newSleep(seconds);
            Eneimes = Eneimes->next;
            continue;
        }

        newSleep(seconds);
        system("cls");
        hitType = BattleTurnRandomness();
        EffectiveAttack = Fight(&Eneime, &Hero, hitType);
        attack = attacktype(hitType);
        DisplayStatsHero(Hero);
        printf("\n\t%s attacks %s, %sdealing %d damage!\n", Eneime->hm_name, Hero->hm_name, attack, EffectiveAttack);
        DisplayStatsEneime((MayhemPointer)Eneimes->data);

        if (Hero->hp == 0)
        {
            system("cls");
            printf("End of the Game.\n%s is defeated!\n", Hero->hm_name);
            printf("World is Doomed!\n");
            FreeAllocatedMemory(topE);
            free(topE);
            return (0);
        }
    }
    system("cls");
    printf("%s defeated all Eneimes! The world is saved!", Hero->hm_name);
    free(Hero);
    return (0);
}

char *attacktype(int hitType)
{
    char *attack;

    switch (hitType)
    {
    case 1:

        attack = "";
        break;
    case 2:
        attack = "Critical Hit!! ";
        // strcpy(attack, "Critical Hit!! ");
        break;
    case 3:
        attack = "Missed! ";
        // strcpy(attack, "Missed! ");
        break;

    default:
        printf("Error");
        break;
    }

    return attack;
}

int Fight(MayhemPointer *attacker, MayhemPointer *defencer, int hitType)
{
    int EffectiveAttack = 0;
    //char attackType[20] = attacktype(hitType);

    switch (hitType)
    {
    case 1:
        EffectiveAttack = (*attacker)->atk - (*defencer)->def;
        break;
    case 2:
        EffectiveAttack = (((*attacker)->atk) << 1) - (*defencer)->def;
        break;
    case 3:
        EffectiveAttack = 0;
        break;
    default:
        printf("Error");
        break;
    }
    // EffectiveAttack = (*attacker)->atk - (*defencer)->def;
    (*defencer)->hp = (*defencer)->hp - EffectiveAttack;
    if ((*defencer)->hp <= 0)
    {
        (*defencer)->hp = 0;
    }
    //printf("%s attacks %s, %sdealing %d damage!\n", (*attacker)->hm_name, (*defencer)->hm_name, attackType, EffectiveAttack);

    return EffectiveAttack;
}

void battleReward(MayhemPointer *Hero)
{
    int rewardType = BattleRewardRandomness();
    switch (rewardType)
    {
    case 1:
        (*Hero)->atk = (*Hero)->atk + (*Hero)->atk * 0.5;
        printf("%s recevies a Better Sword! ATK is now %d!", (*Hero)->hm_name, (*Hero)->atk);
        break;
    case 2:
        (*Hero)->def = (*Hero)->def + (*Hero)->def * 0.5;
        printf("%s recevies a Better Shield! DEF is now %d!", (*Hero)->hm_name, (*Hero)->def);
        break;

    case 3:
        (*Hero)->med++;
        printf("%s recevies a MED! MED is now %d!", (*Hero)->hm_name, (*Hero)->med);
        break;
    default:
        printf("Error");
        break;
    }
}

/*
Damage = 1;
Critical Hit = 2;
Miss = 3;
*/
int BattleTurnRandomness()
{
    srand(time(NULL));
    int attack = rand() % 100, decider = 0;
    if (attack < 70)
    {
        decider = 1;
    }
    else if (attack > 70 && attack < 90)
    {
        decider = 2;
    }
    else if (attack > 90)
    {
        decider = 3;
    }

    return decider;
}
/*
Better Sword = 1;
Better Shield = 2;
1 Medicine = 3;
*/
int BattleRewardRandomness()
{
    srand(time(NULL));
    int defence = rand() % 100, decider = 0;
    if (defence < 40)
    {
        decider = 1;
    }
    else if (defence > 40 && defence < 70)
    {
        decider = 2;
    }
    else if (defence > 70)
    {
        decider = 3;
    }

    return decider;
}

void printEneimes(LinkedListPointer print)
{
    //Clear the screen
    while (print != NULL)
    {
        printf("\n%s \n", ((MayhemPointer)print->data)->hm_name);
        printf("\t\tHP:%d ", ((MayhemPointer)print->data)->hp);
        printf("\tATK:%d ", ((MayhemPointer)print->data)->atk);
        printf("\tDEF:%d ", ((MayhemPointer)print->data)->def);
        print = print->next;
    }
}

void printHero(MayhemPointer print)
{
    printf("\n%s \n", print->hm_name);
    printf("\t\tHP:%d ", print->hp);
    printf("\tATK:%d ", print->atk);
    printf("\tDEF:%d ", print->def);
    printf("\tMED:%d ", print->med);
    printf("\n");
}

void DisplayStatsHero(MayhemPointer Hero)
{
    printf("%s \n", Hero->hm_name);
    printf("HP:%d \n", Hero->hp);
    printf("ATK:%d \n", Hero->atk);
    printf("DEF:%d \n", Hero->def);
    printf("MED:%d \n", Hero->med);
}
void DisplayStatsEneime(MayhemPointer Eneime)
{
    printf("\n");
    printf("\t%s \n", Eneime->hm_name);
    printf("\tHP:%d \n", Eneime->hp);
    printf("\tATK:%d \n", Eneime->atk);
    printf("\tDEF:%d \n", Eneime->def);
}