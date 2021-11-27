#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "headers/linkedList.h"
#include "headers/readFile.h"
#include "headers/gamePlay.h"

struct LinkedList *head = NULL;

LinkedListPointer getEneimes(char *filename)
{
    FILE *input_fp;
    input_fp = fopen(filename, "r");
    int hp, atk, def;
    char monster_name[50];

    if (input_fp == NULL)
    {

        printf("\nUnable to open Eneimes file.\n");
        printf("Please check whether file exists and you have read privilege.\n");
        return NULL;
    }

    while (!feof(input_fp))
    {
        fscanf(input_fp, "%d,%d,%d,%49[^\n]", &hp, &atk, &def, &monster_name);
        MayhemPointer newm = newMonster(hp, atk, def, monster_name);
        createLinkedList(&head, newm);
    }

    fclose(input_fp);
    return head;
}

MayhemPointer newMonster(int hp, int atk, int def, char monster_name[50])
{
    MayhemPointer newm = malloc(sizeof(MayhemType));

    if (newm != NULL)
    {
        newm->hp = hp;
        newm->atk = atk;
        newm->def = def;
        strcpy(newm->hm_name, monster_name);
    }

    return newm;
}

MayhemPointer getHero(char *filename)
{
    FILE *input_fp;
    input_fp = fopen(filename, "r");
    int hp, atk, def, med;
    char hero_name[50];
    MayhemPointer newh = malloc(sizeof(MayhemType));

    if (input_fp == NULL)
    {

        printf("\nUnable to open Hero file.\n");
        printf("Please check whether file exists and you have read privilege.\n");
        return NULL;
    }

    fscanf(input_fp, "%d,%d,%d,%d,%[^\n]", &hp, &atk, &def, &med, &hero_name);
    newh->hp = hp;
    newh->atk = atk;
    newh->def = def;
    newh->med = med;
    strcpy(newh->hm_name, hero_name);
    return newh;
}