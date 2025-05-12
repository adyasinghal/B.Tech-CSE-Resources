#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void append(Node** head, int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    
    if (*head == NULL) {
        *head = new_node;
        return;
    }
    
    Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new_node;
}

void PRINTPRINT(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void ADDADD(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        temp->data += 6;
        temp = temp->next;
    }
    PRINTPRINT(head);
}

void SKIP(Node* head) {
    Node* temp = head;
    int count = 0;
    while (temp != NULL) {
        if (count % 2 == 0) {
            printf("%d ", temp->data);
        }
        temp = temp->next;
        count++;
    }
    printf("\n");
}

int main() {
    Node* A = NULL;
    int values[] = {12, 24, 33, 40, 57, 68, 77};
    int n = sizeof(values) / sizeof(values[0]);
    
    for (int i = 0; i < n; i++) {
        append(&A, values[i]);
    }
    
    PRINTPRINT(A);
    ADDADD(A);
    SKIP(A);
    
    return 0;
}
