/* Implementation of Singly Linked List using C 
    
    Includes functions such as insert, search and delete the entire list
    
*/

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <cs50.h>

typedef struct sll
{
    int n;
    struct sll* next;
}sll;

sll* insert(int n, sll* head);
bool search(int n, sll* head);
bool delete(sll* head);
sll* create(int n);

int main(void)
{
   
    sll* head = malloc(sizeof(sll));
    if(head == NULL)
    {
        printf("Something went wrong\n");
        return -1;
    }
    
    
    while(true)
    {
        char* s = NULL;
        printf("Please enter what do you want to do with the linged list\n a) insert\n b) search\n c) delete \n ENTER 'quit' to quit the program\n");
        do
        {
            s = GetString();
        }while(strncmp(s, "", sizeof(s) + 1) == 0);    
        
         int x;
        
        if(strncmp(s, "insert", sizeof(s) + 1) == 0)
        {
            printf("Please enter the number you want to add to the list: \n");
            scanf("%i", &x);
            head = insert(x, head); 
            if(head != NULL)
            {
                printf("The list was sucessfully updated\n");
            }
        }
        
        else if(strncmp(s, "search", sizeof(s) + 1) == 0)
        {
            printf("Please enter the number you want to search:\n");
            scanf("%i", &x);
            if(search(x, head) == true)
                printf("The number has been found\n");
            else
                printf("The number could not be found\n");
        }
        
        else if(strncmp(s, "delete", sizeof(s) + 1) == 0)
        {
            if(delete(head) == true)
            {
                printf("The list was sucessfully deleted\n");
                return 0; 
            }
           
        }
        
        else if((strncmp(s, "quit", sizeof(s) + 1) == 0))
            return 0;
        else
            printf("Not an option, Please try again\n");
           
        
    }
    
    return 0;
    
}

/* search for a number in the linked list */
bool search(int n, sll* head)
{
    if ( head == NULL)
        return false;
   
    sll* ptr = head;
    do
    {
        if( ptr->n == n )
            return true;
        ptr = ptr->next;    
    }while(ptr->next != NULL); 
    
    // check the last node
    if(ptr->n == n)
        return true;
    return false; 
}


// inserts elemts to sll
sll* insert(int n, sll* head)
{
    if(head == NULL)
        return head;
    if(!(head->n))
    {
        head->n = n;
        head->next = NULL;
        return head;
    }    
    sll* ptr = malloc(sizeof(sll));
    ptr->n = n;
    ptr->next = head;
    head = ptr;
    return head;
    
}

bool delete(sll* head)
{
    sll* ptr = head;
    ptr = head->next;
    free(head);
    if(ptr->next == NULL)
    {
        free(ptr);
        return true;
    }    
    else    
        delete(ptr);
    return true;    
}
