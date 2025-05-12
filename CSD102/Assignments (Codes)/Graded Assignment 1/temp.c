//NAME : RISHIT KAMBOJ
// ROLL NO. : 2410110598
//this program is completely my own work and that no part of it has been copied from anybody else or downloaded from the net.


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node structure
typedef struct Node {
    char first_name[50];
    char last_name[50];
    int regis_day;
    struct Node* next;
} Node;

// New node creation function
Node* createNode(char* first_name, char* last_name, int regis_day) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed");
        exit(1);
    }
    strcpy(newNode->first_name, first_name);
    strcpy(newNode->last_name, last_name);
    newNode->regis_day = regis_day;
    newNode->next = NULL;
    return newNode;
}

// Insert node function (in order)
void insertInOrder(Node** head, Node* newNode) {
    if (*head == NULL || (*head)->regis_day >= newNode->regis_day) {
        newNode->next = *head;
        *head = newNode;
        return;
    }
    
    Node* current = *head;
    while (current->next != NULL && current->next->regis_day < newNode->regis_day) {
        current = current->next;
    }
    
    newNode->next = current->next;
    current->next = newNode;
}

// List deleting function
int deleteNode(Node** head, char* first_name, char* last_name) {
    if (*head == NULL) {
        return 0;
    }
    
    Node* temp = *head;
    if (strcmp(temp->first_name, first_name) == 0 && strcmp(temp->last_name, last_name) == 0) {
        *head = temp->next;
        free(temp);
        return 1;
    }
    
    Node* prev = NULL;
    Node* current = *head;
    
    while (current != NULL) {
        if (strcmp(current->first_name, first_name) == 0 && strcmp(current->last_name, last_name) == 0) {
            prev->next = current->next;
            free(current);
            return 1;
        }
        prev = current;
        current = current->next;
    }
    
    return 0;
}

// TRIP PRINTING 
void printTripList(Node* head, int N) {
    printf("TRIP");
    Node* current = head;
    int count = 0;
    while (current != NULL && count < N) {
        printf(" %d %s %s", current->regis_day, current->first_name, current->last_name);
        current = current->next;
        count++;
    }
    printf("\n");
}

// WAITLIST PRINTING
void printWaitList(Node* head, int N) {
    printf("WAITLIST");
    int count = 0;
    Node* current = head;
    while (count < N && current != NULL) {
        current = current->next;
        count++;
    }
    while (current != NULL) {
        printf(" %d %s %s", current->regis_day, current->first_name, current->last_name);
        current = current->next;
    }
    printf("\n");
}

int main() {
    
    FILE* file = fopen("EASYTRIP.txt", "r");
    if (file == NULL) {
        printf("Failed to open the file.");
        return 1;
    }
    
    int N;
    fscanf(file, "%d", &N);
    
    Node* BOOKING = NULL;
    
    int op_code;
    char first_name[50], last_name[50];
    int regis_day;
    
    while (fscanf(file, "%d", &op_code) != EOF) {
        switch (op_code) {
            case 1: // Add a tourist (NewNode)
                fscanf(file, "%s %s %d", first_name, last_name, &regis_day);
                Node* newNode = createNode(first_name, last_name, regis_day);
                insertInOrder(&BOOKING, newNode);
                break;
                
            case 2: // Cancel BOOKING
                fscanf(file, "%s %s", first_name, last_name);
                deleteNode(&BOOKING, first_name, last_name);
                break;
                
            case 3: // Print BOOKING
                printf("BOOKING");
                Node* current = BOOKING;
                while (current != NULL) {
                    printf(" %d %s %s", current->regis_day, current->first_name, current->last_name);
                    current = current->next;
                }
                printf("\n");
                break;
                
            case 4: // Print TRIP
                printTripList(BOOKING, N);
                break;
                
            case 8: // Print WAITLIST
                printWaitList(BOOKING, N);
                break;
                
            default:
                printf("Invalid operation code: %d\n", op_code);
                break;
        }
    }
    
    fclose(file);
    
    // Free the memory which was allocated
    Node *current = BOOKING;
    while (current != NULL) {
        Node* next = current->next;
        free(current);
        current = next;
    }
    
    return 0;
}