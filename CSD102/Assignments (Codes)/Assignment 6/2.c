#include<stdio.h>
#include<stdlib.h>
#include<math.h>

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
        printf("%d", current->value);
        current = current->next;
    }
    printf("\n");
}

int isempty (stack *top){
   if (top == NULL)
        return (1);
    else
        return (0);
}

int main(){
    stack *a;
    create(&a);

    stack *b;
    create(&b);

    stack *c;
    create(&c);

    int num1;
    printf("Enter first number: ");
    scanf("%d", &num1);

    int num2;
    printf("Enter second number: ");
    scanf("%d", &num2);

    int digits1 = (int)log10(num1);
    while (digits1>=0){
        int divisor = (int)pow(10, digits1);
        int digit = num1 / divisor;
        push(&a,digit);
        num1 = num1 % divisor;
        digits1--;
        
    }

    int digits2= (int)log10(num2);
    while (digits2>=0){
        int divisor2 = (int)pow(10, digits2);
        int digit2 = num2 / divisor2;
        push(&b,digit2);
        num2 = num2 % divisor2;
        digits2--;
        
    }

    /*
    display(a);
    display(b);
    */

    while (!isempty(a) || !isempty(b)) {
        int digitA = 0, digitB = 0;

        if (!isempty(a))
            digitA = pop(&a);

        if (!isempty(b))
            digitB = pop(&b);

        push(&c, digitA + digitB); // No carry handling 
    }

    printf("Resultant Sum: ");
    display(c);

}
