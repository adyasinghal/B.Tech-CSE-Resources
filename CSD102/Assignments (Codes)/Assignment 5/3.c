#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;


Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}


void append(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}


void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}


void deleteFirstAndLast(Node** head) {
    if (*head == NULL) return; 

    
    Node* temp = *head;
    *head = temp->next;
    free(temp);

    
    if (*head == NULL) return; 

    Node* prev = NULL;
    Node* curr = *head;
    while (curr->next != NULL) {
        prev = curr;
        curr = curr->next;
    }
    prev->next = NULL;
    free(curr);
}


void printSecondLast(Node* head) {
    if (head == NULL || head->next == NULL) {
        printf("No second last node.\n");
        return;
    }
    Node* temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    printf("Second last node: %d\n", temp->data);
}

int isSorted(Node* head) {
    while (head != NULL && head->next != NULL) {
        if (head->data > head->next->data) {
            return 0; 
        }
        head = head->next;
    }
    return 1; 
}
int main() {
    Node* A = NULL;
    for (int i = 1; i <= 10; i++) {
        append(&A, i);
    }
    printf("Original List:\n");
    printList(A);


    deleteFirstAndLast(&A);
    printf("After deleting first and last node:\n");
    printList(A);
    printSecondLast(A);
    if (isSorted(A)) {
        printf("The list is sorted in increasing order.\n");
    } else {
        printf("The list is not sorted.\n");
    }

    return 0;
}
