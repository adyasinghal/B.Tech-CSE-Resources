#include <stdio.h>

struct Customer {
    int accountNumber;
    char name[50];
    float balance;
};

void printLowBalance(struct Customer customers[], int n) {
    for(int i = 0; i < n; i++) {
        if(customers[i].balance < 100) {
            printf("Account: %d, Name: %s\n", 
                customers[i].accountNumber, customers[i].name);
        }
    }
}

void processTransaction(struct Customer *customer, float amount, int code) {
    
    if(code == 1) {  // deposit
        customer->balance += amount;
    } 
    else if(code == 0) {  // withdrawal
        if(customer->balance < amount) {
            printf("The balance is insufficient for the specified withdrawal\n");
            return;
        }
        customer->balance -= amount;
    }
}

int main() {
    int ans;
    float money;
    struct Customer customers[3];
    
    // Test data
    customers[0] = (struct Customer){1001, "Alice", 50.0};
    customers[1] = (struct Customer){1002, "Bob", 500.0};
    customers[2] = (struct Customer){1003, "Charlie", 75.0};
    
    printf("Customers with balance below 100:\n");
    printLowBalance(customers, 3);
    
    printf("Enter code(1 for deposit, 0 for withdrawal): ");
    scanf("%d", &ans);
    printf("Enter money you want to deposit or withdraw: ");
    scanf("%f", &money);
    printf("\nProcessing deposit for Alice Brown:\n");
    processTransaction(&customers[0], money, ans);
    printf("New balance: %.2f\n", customers[0].balance);
    
    return 0;
}
