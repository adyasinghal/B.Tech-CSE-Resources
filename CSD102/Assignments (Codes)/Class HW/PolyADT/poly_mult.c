#include <stdio.h>
#include <stdlib.h>

struct polynode {
    int coef;
    int exp;
    struct polynode *next;
};
typedef struct polynode poly;

poly *create_node(int coef, int exp) {
    poly *new_node = (poly *)malloc(sizeof(poly));
    new_node->coef = coef;
    new_node->exp = exp;
    new_node->next = NULL;
    return new_node;
}

void insert_node(poly **head, int coef, int exp) {
    poly *new_node = create_node(coef, exp);
    if (*head == NULL) {
        *head = new_node;
        return;
    }
    poly *temp = *head;
    while (temp->next)
        temp = temp->next;
    temp->next = new_node;
}

void display(poly *head) {
    while (head) {
        printf("%dx^%d", head->coef, head->exp);
        if (head->next)
            printf(" + ");
        head = head->next;
    }
    printf("\n");
}

poly *multiply_polynomials(poly *p1, poly *p2) {
    if (!p1 || !p2)
        return NULL;

    poly *result = NULL;
    for (poly *a = p1; a; a = a->next) {
        for (poly *b = p2; b; b = b->next) {
            insert_node(&result, a->coef * b->coef, a->exp + b->exp);
        }
    }

    poly *ptr1 = result, *ptr2, *prev;
    while (ptr1 && ptr1->next) {
        prev = ptr1;
        ptr2 = ptr1->next;
        while (ptr2) {
            if (ptr1->exp == ptr2->exp) {
                ptr1->coef += ptr2->coef;
                prev->next = ptr2->next;
                free(ptr2);
                ptr2 = prev->next;
            } else {
                prev = ptr2;
                ptr2 = ptr2->next;
            }
        }
        ptr1 = ptr1->next;
    }
    return result;
}

int main() {
    poly *poly1 = NULL, *poly2 = NULL, *poly3;
    int n, coef, exp;
    
    printf("Enter number of terms in first polynomial: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter coefficient and exponent: ");
        scanf("%d %d", &coef, &exp);
        insert_node(&poly1, coef, exp);
    }

    printf("Enter number of terms in second polynomial: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter coefficient and exponent: ");
        scanf("%d %d", &coef, &exp);
        insert_node(&poly2, coef, exp);
    }

    printf("First Polynomial: ");
    display(poly1);
    printf("Second Polynomial: ");
    display(poly2);
    
    poly3 = multiply_polynomials(poly1, poly2);
    printf("Resultant Polynomial after multiplication: ");
    display(poly3);
    return 0;
}
