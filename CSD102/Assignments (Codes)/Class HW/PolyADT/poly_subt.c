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

poly *subtract_polynomials(poly *p1, poly *p2) {
    poly *result = NULL;
    while (p1 || p2) {
        int coef, exp;
        if (p1 && (!p2 || p1->exp > p2->exp)) {
            coef = p1->coef;
            exp = p1->exp;
            p1 = p1->next;
        } else if (p2 && (!p1 || p1->exp < p2->exp)) {
            coef = -p2->coef;
            exp = p2->exp;
            p2 = p2->next;
        } else { 
            coef = p1->coef - p2->coef;
            exp = p1->exp;
            p1 = p1->next;
            p2 = p2->next;
        }
        if (coef != 0)
            insert_node(&result, coef, exp);
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
    
    poly3 = subtract_polynomials(poly1, poly2);
    printf("Resultant Polynomial after subtraction: ");
    display(poly3);
    return 0;
}