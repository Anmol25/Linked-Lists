#include<stdlib.h>
#include<stdio.h>
#include <string.h>
#include <malloc.h>
//A WELL FUNCTIONING SINGLE  LINKED LIST EXAMPLE!
//also asks for the last name and the decimal grade (float value)! 
//NODE==========================================================================================
struct node
{
    char name[10];
    char lastname[10];
    float grade;
    struct node *next;
};
struct node *head =  NULL;
struct node *current =  NULL;
struct node *temp;

//MENU============================================================================================
int menu()
{
    int choice;
    puts("\n\n\t1- ENTER A NAME"); // create();
    puts("\t2 - DISPLAY NAMES");// display();
    puts("\t3 - EXIT");
    puts("\n\n\n\tPlease enter your choice:");
    fflush(stdin);
    scanf("\t\t\t%d", &choice);
    fflush(stdin);

    switch(choice)
    {
        case 1: puts("\tYou will now be entering a name......\n");
                create();
                break;
        case 2: puts("\tThe names are now going to be displayed.....\n");
                display();
                break;
        case 3: puts("\tHAVE A NICE DAY!");
                break;
    }

}
//CREATE===============================================================================================
int create()
{
    char n[10];
    char ln[10];
    float g;
    puts("\n\tPlease enter a name to enter to the list:");
    fflush(stdin);




    scanf("\n\n%s", &n);
    puts("\n\tPlease enter the last name:");
    scanf("%s", &ln);
    puts("\n\tPlease enter decimal grade:");
    scanf("%f", &g);

    fflush(stdin);


    temp = (struct node*)malloc(sizeof(struct node));

    if(head == NULL)//meaning the list is empty!
    {

        temp->next = head;
        strcpy(temp->name, n);
        strcpy(temp->lastname, ln);
        temp->grade = g;
        head = temp;

    }
    else if(head != NULL)//meaning the list is not empty!
    {

        current = head;
        while(current->next != NULL)
        {
            current = current->next;
        }

        temp->next = current->next;//current->next == NULL : so temp->next == NULL also!
        strcpy(temp->name, n);
        strcpy(temp->lastname, ln);
        temp->grade = g;
        current->next = temp;

    }
    menu();

}
//DISPLAY======================================================================================================
int display()
{

    current = head;
    int counter = 1;
    while(current != NULL)
    {
        printf("\n\n\tStudent number %d: %s %s, has the grade: %.2f", counter, current->name, current->lastname, current->grade);
        counter++;
        current = current->next;
    }
    menu();
}
//MAIN===========================================================================================================
int main(void)
{

    menu();
}
