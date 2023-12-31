
// middle elemnt from linked list
#include<stdio.h>
#include<stdlib.h>

#pragma pack(1)
struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

void InsertFirst(PPNODE First, int no)
{
    PNODE newn = (PNODE)malloc(sizeof(NODE));      

    newn->data = no;
    newn->next = NULL;

    if(*First == NULL) 
    {
        *First = newn;
    }
    else                
    {
        newn->next = *First;
        *First = newn;
    }
}

void Display(PNODE First)
{
    printf("Elements from the Linked List are : \n");

    while(First != NULL)
    {
        printf("| %d |-> ",First->data);
        First = First -> next;
    }
    printf("NULL \n");
}
int MiddleElement(PNODE First)
{
    PNODE Student = First;
    PNODE Teacher=First;

    while(Teacher !=NULL) // Even only oe seg false
    // for odd (teacher ->next!=NUll)
    {
        Teacher=Teacher->next->next;
        Student=Student->next;

    }
    return (Student->data);
}



int main()
{
    PNODE Head = NULL;
    int iRet = 0;

    InsertFirst(&Head, 151);
    InsertFirst(&Head, 121);
    InsertFirst(&Head, 111);
    InsertFirst(&Head, 101);
    InsertFirst(&Head, 51);
    InsertFirst(&Head, 101);
    InsertFirst(&Head, 11);
    
    Display(Head);
    iRet=MiddleElement(Head);
    printf("Middle element is %d",iRet);
    

    return 0;
}
