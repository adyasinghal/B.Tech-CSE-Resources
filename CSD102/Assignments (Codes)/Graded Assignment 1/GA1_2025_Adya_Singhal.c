// Name: ADYA SINGHAL
// Roll No.: 2410110027

// The program is completely my own and no part of it has been copied from anybody or downloaded from the net

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Node definition
typedef struct node{
    char fname[50];
    char lname[50];
    int date;
    struct node *next;
}node;

node *BOOKING = NULL, *TRIP = NULL, *WAITLIST = NULL;
int N; 

// Create new node
node* createNode(char fname[], char lname[], int date) {
    node* newNode = (node*)malloc(sizeof(node));
    strcpy(newNode->fname, fname);
    strcpy(newNode->lname, lname);
    newNode->date = date;
    newNode->next = NULL;
    return newNode;
}

// Insert node in sorted order based on date
void insertSorted(node **head, node *newNode) {
    if (*head == NULL || (*head)->date > newNode->date) {
        newNode->next = *head;
        *head = newNode;
        return;
    }
    node *temp = *head;
    while (temp->next != NULL && temp->next->date < newNode->date)
        temp = temp->next;
    
    newNode->next = temp->next;
    temp->next = newNode;
}

// Delete node by name from list
void deleteByName(node **head, char fname[], char lname[]) {

    node *temp = *head, *prev = NULL;
    while (temp != NULL) {
        if (strcmp(temp->fname, fname) == 0 && strcmp(temp->lname, lname) == 0) {
            if (prev == NULL)
                *head = temp->next;
            else
                prev->next = temp->next;
            free(temp);
            return;
        }
        prev = temp;
        temp = temp->next;
    }
}

// Print list with given title
void printList(char title[], node *head) {
    printf("%s ", title);
    if (!head) { 
        printf("EMPTY\n"); 
        return; 
    }

    node *temp = head;
    while (temp != NULL) {
        printf("%d %s %s ", temp->date, temp->fname, temp->lname);
        temp = temp->next;
    }
    printf("\n");
}

// Update TRIP and WAITLIST based on BOOKING list
void updateLists() {
    
    TRIP = NULL;
    WAITLIST = NULL;

    node *temp = BOOKING;
    int count = 0;

    // Traverse BOOKING list (already sorted), copy first N nodes to TRIP and rest to WAITLIST
    while (temp != NULL) {
        node* newnode = createNode(temp->fname, temp->lname, temp->date);
        if (count < N)
            insertSorted(&TRIP, newnode);
        else
            insertSorted(&WAITLIST, newnode);
        count++;
        temp = temp->next;
    }
}

// Count nodes in a list
int countNodes(node* head){
    int count=0;
    while(head){
        count++;
        head=head->next;
    }
    return count;
}

// Delete by name from BOOKING and then update lists
void deleteBooking(char fname[], char lname[]) {

    deleteByName(&BOOKING,fname,lname);
    updateLists();
}

int main() {
    FILE* fp=fopen("EASYTRIP.txt","r");
    
    if(!fp){
        printf("File not found.\n");
        return -1;
    }

    fscanf(fp,"%d",&N);

    int opCode,date;
    char fname[50],lname[50];

    while(fscanf(fp,"%d",&opCode)!=EOF){

        switch(opCode){

            case 1:
                fscanf(fp,"%s %s %d",fname,lname,&date);
                insertSorted(&BOOKING,createNode(fname,lname,date));
                updateLists();
                break;

            case 2:
                fscanf(fp,"%s %s",fname,lname);
                deleteByName(&BOOKING,fname,lname);
                updateLists();
                break;

            case 3:
                printList("BOOKING",BOOKING);
                break;

            case 4:
                printList("TRIP",TRIP);
                break;

            case 8:
                printList("WAITLIST",WAITLIST);
                break;

            default:
                break; // Ignore invalid opcodes or EOF cases
        }
    }

fclose(fp);

}





