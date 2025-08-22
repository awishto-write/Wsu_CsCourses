
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h> // malloc (), calloc (), free ()
#include <stdbool.h>

typedef enum boolean
{
    FALSE, TRUE

} Boolean;


typedef struct contact
{
    char name[50];
    char phone[12]; // 18005557577
    char email[50];
    char title[20];

} Contact;


typedef struct node
{
    Contact data;
    struct node* pNext;
    struct node* pPrev;

} Node;

Node* makeNode(Contact newData);
Boolean insertContactAtFront(Node** pList, Contact newData);
Boolean insertContactInOrder(Node** pList, Contact newData);

Boolean deleteContact(Node** pList, Contact searchContact);
void printList(Node* pList);