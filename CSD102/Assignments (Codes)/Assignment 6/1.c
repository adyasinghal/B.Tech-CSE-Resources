#include<stdio.h>
#include<stdlib.h>

typedef struct lifo{
   int value;
   struct lifo *next;
}stack;
  
stack *top;

void create (stack **top){
   *top = NULL; // empty stack
}

void push (stack **top, int element){

    stack *new;
    new = (stack *) malloc(sizeof(stack));

    if (new == NULL)    {
       printf ("\n Stack is full");
       exit(-1);
    }

    new->value = element; 
    new->next = *top;
    *top = new;
} 

int pop (stack **top){
   int t;  
   stack *p;

   if (*top == NULL){
      printf ("\n Stack is empty");
      exit(-1);
   }

   else{
      t = (*top)->value;
      p = *top;
      *top = (*top)->next;
      free (p);
      return t;
   }
}

void display(stack *top) {
    if (top == NULL) {
        printf("\nStack is empty.\n");
        return;
    }

    stack *current = top;
    while (current != NULL) {
        printf("%d\n", current->value);
        current = current->next;
    }
}


int main(){
    stack *a;
    create(&a);

    push(&a,9);
    push(&a,5);
    push(&a,20);
    pop(&a);
    push(&a,6);
    pop(&a);
    push(&a,10);
    display(a);
}





