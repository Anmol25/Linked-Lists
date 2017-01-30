#include <stdio.h>
#include <stdlib.h>

//declare all functions this program will use
int menu(void);
int insert();
int front();
int back();
int modify();
int removee();
void remove_head(int x);
void remove_tail(int x);

struct node
{
    struct node *prev;
    int data;
    struct node *next;
}*head = NULL,*current = NULL, *tail =  NULL, *temp = NULL;
//===================================================================================

//MENU
int menu(void)
{
    int choice;
    puts("\n\n1 - Insert a Number into the Doubly Linked List");
    puts("2 - Display Numbers from the FRONT");
    puts("3 - Display Numbers from the BACK");
    puts("4 - Modify Values in the Doubly Linked List");
    puts("5 - Delete a Number from the Doubly Linked List");
    puts("6 - Exit");
    printf("\nEnter your option:-> ");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1: insert(); break;
        case 2: front(); break;
        case 3: back(); break;
        case 4: modify(); break;
        case 5: removee(); break;
        case 6: puts("Have a nice day!"); break;
    }

}//=====================================================================================
int insert()
{
    int num;
    printf("\n\nEnter the number to insert:->");
    scanf("%d", &num);
    temp = (struct node*)malloc(sizeof(struct node));
    temp->data = num;
    temp->prev = temp->next = NULL;

    if(head == NULL)
    {
        head = temp;
        tail = temp;

    }
    else if(head != NULL)
    {
        current = head;
        while(current->next != NULL) current = current->next;
        current->next = temp;
        temp->next = NULL;
        temp->prev = current;
        tail = temp;

    }
    menu();
}//=======================================================================================
//FRONT
int front()
{
    current = head;
    printf("\n\nThe elements displayed from the front are: ");
    while(current != NULL)
    {
        printf("\t%d",current->data);
        current = current->next;

    }
    menu();
}//======================================================================================
int back()
{
    current = tail;
    printf("\n\nThe elements displayed from the back are: ");
    while(current != NULL)
    {
        printf("\t%d",current->data);
        current = current->prev;
    }
    menu();
}//=======================================================================================
int modify()
{
    int original;
    int changed;
    printf("\n\nEnter the number that will be changed:->");
    scanf("%d", &original);
    printf("\nEnter the number to replace the original value:->");
    scanf("%d", &changed);
    current = head;
    while(current != NULL)
    {
        if(current->data == original)
        {
            current->data = changed;
            printf("\n%d was successfully changed to %d",original,changed);
            break;
        }
        if(current == NULL)
        {
            printf("%d does not exist in the list.",original);

        }
        current = current->next;
    }
    menu();
}//=====================================================================================
int removee()
{
    int target;
    printf("\nEnter the number to remove from the list:->");
    scanf("%d", &target);


    remove_head(target);
    remove_tail(target);
    //make the tail point to the last node!
    menu();

}//=====================================================================================
void remove_head(int x)
{
    struct node *current_head;
    struct node *desired_head;
    current_head = head;
    while(current_head->next != NULL)
    {
        if((current_head->next)->data == x)
        {
            desired_head = (current_head->next)->next;
            current_head ->next = NULL;
            current_head->next = desired_head;
            break;
        }
        current_head = current_head->next;
    }
    return;


}//============================================================================================
void remove_tail(int x)
{
    struct node *current_tail = tail;
    struct node *desired_tail;

    while(current_tail -> prev != NULL)
    {
        if((current_tail->prev)->data == x)
        {
            desired_tail = (current_tail->prev)->prev;
            current_tail->prev = NULL;
            current_tail ->prev = desired_tail;
            break;
        }
        current_tail = current_tail->prev;
    }
    return;
}//=============================================================================================
int main()
{
    menu();
}
