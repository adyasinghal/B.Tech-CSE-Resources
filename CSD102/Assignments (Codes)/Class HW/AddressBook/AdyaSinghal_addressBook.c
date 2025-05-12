#include<stdio.h>
#include<stdlib.h>
typedef struct node{
char name[20];
long int ph_nbr;
char email[20];
struct node *next;
}node;
node *start_ptr = NULL;

void new_data() {
    node *temp, *ptr;
    temp = (node*)malloc(sizeof(node));
    
    if(temp == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    
    printf("Enter name: ");
    scanf("%s", temp->name);
    
    printf("Enter phone number: ");
    scanf("%ld", &temp->ph_nbr);
    
    printf("Enter email: ");
    scanf("%s", temp->email);
    
    temp->next = NULL;
    
    if(start_ptr == NULL) {
        // First entry in the address book
        start_ptr = temp;
    } else {
        // Add to the end of the list
        ptr = start_ptr;
        while(ptr->next != NULL) {
            ptr = ptr->next;
        }
        ptr->next = temp;
    }
    
    printf("Contact added successfully!\n");
}

void output_data() {
    node *ptr;
    
    if(start_ptr == NULL) {
        printf("Address book is empty!\n");
        return;
    }
    
    printf("\n--- Address Book Contents ---\n");
    printf("Name\t\tPhone Number\t\tEmail\n");
    printf("\n");
    
    ptr = start_ptr;
    while(ptr != NULL) {
        printf("%s\t\t%ld\t\t%s\n", ptr->name, ptr->ph_nbr, ptr->email);
        ptr = ptr->next;
    }
    printf("\n");
}




int main()
{
    int choice;
    do
    {
        printf("Enter your choice\n");
        printf("1. New Address data\n");
        printf("2. Display Address Book\n");
        printf("3. Exit\n");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1: new_data();
                    break;
            case 2: output_data();
                    break;
            case 3: exit(0);
                    break;
        }
    } while(choice != 3);
    
    return 0;
}