#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "headers/linkedList.h"
#include "headers/readFile.h"
#include "headers/gamePlay.h"

int createLinkedList(LinkedListPointer *head_ref, void *new_data)
{
    int returnValue = -1;
    int i = 0;
    LinkedListPointer new_node = NULL;

    if ((*head_ref) == NULL)
    {
        /*Call malloc to allocate memory in heap for the first node*/
        new_node = malloc(sizeof(LinkedListType));
        if (new_node != NULL) /*Check allocated memory*/
        {
            new_node->data = new_data; /*put the desire Data*/
            new_node->next = NULL;     /*Give the Address of first Node*/

            *head_ref = new_node; /*Assign the address of the first node to the head pointer*/
            returnValue = 0;      /*Update the return value*/
        }
    }
    else
    {
        /*Add the Node at the Front*/
        returnValue = insertNodeAtFront(head_ref, new_data);
    }

    return returnValue;
}

int insertNodeAtFront(LinkedListPointer *head_ref, void *new_data)
{
    int returnValue = -1, i = 0;
    LinkedListPointer head = NULL;

    head = *head_ref;

    LinkedListPointer new_node = (LinkedListPointer)malloc(sizeof(LinkedListType));

    if (new_node != NULL) /*Check allocated memory*/
    {
        new_node->data = new_data; //put the desire Data
        new_node->next = NULL;     //Give the Address of first Node
        returnValue = 0;           // Update the return value
    }
    // If there is no node in beginning
    if (head == NULL)
    {
        *head_ref = new_node;
    }
    else
    {
        new_node->next = (*head_ref);
        (*head_ref) = new_node;
    }

    return returnValue;
}

void FreeAllocatedMemory(LinkedListPointer *list)
{
    LinkedListPointer temp = NULL;
    LinkedListPointer fn = NULL;
    //Assign  the Address of first node
    fn = *list;
    /*check if fn is NULL, then now list is empty,
    so assign NULL to head and return.*/
    while (fn != NULL)
    {
        /*Save the fn in a temp node pointer*/
        temp = fn;
        /*Assign the address of next on your list*/
        fn = fn->next;
        //Free the data
        free(temp->data);
        //Free the allocated memory
        free(temp);
    }
    //Assign NULL to the head pointer
    *list = NULL;
    free(fn);
}