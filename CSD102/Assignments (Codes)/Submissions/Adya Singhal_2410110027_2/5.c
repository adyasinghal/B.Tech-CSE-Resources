#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct library {
    int accession_number;
    char title[100];
    char author[100];
    float price;
    int is_issued;  // 0 for issued, 1 for not issued
};

struct library books[100];
int book_count = 0;

void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Function to add test data
void add_test_data() {
    struct library test_books[] = {
        {1, "The C Programming Language", "Dennis Ritchie", 599.99, 1},
        {2, "Digital Design", "Morris Mano", 799.50, 0},
        {3, "Data Structures in C", "Dennis Ritchie", 450.00, 1},
        {4, "Computer Networks", "Andrew Tanenbaum", 899.99, 1}
    };
    
    for(int i = 0; i < 4; i++) {
        books[i] = test_books[i];
        book_count++;
    }
    printf("Test data loaded successfully!\n");
}

void add_book() {
    if (book_count >= 100) {
        printf("Library is full. Cannot add more books.\n");
        return;
    }
    
    struct library new_book;
    new_book.accession_number = book_count + 1;
    
    clear_input_buffer();
    printf("Enter book title: ");
    scanf("%[^\n]s", new_book.title);
    
    clear_input_buffer();
    printf("Enter author name: ");
    scanf("%[^\n]s", new_book.author);
    
    clear_input_buffer();
    printf("Enter book price: ");
    scanf("%f", &new_book.price);
    
    new_book.is_issued = 1;
    
    books[book_count] = new_book;
    book_count++;
    
    printf("Book added successfully with accession number %d\n", new_book.accession_number);
}

void list_books_by_author() {
    char search_author[100];
    int found = 0;
    
    clear_input_buffer();
    printf("Enter author name: ");
    scanf("%[^\n]s", search_author);
    
    printf("\nBooks by %s:\n", search_author);
    for (int i = 0; i < book_count; i++) {
        if (strcmp(books[i].author, search_author) == 0) {
            printf("Accession Number: %d\n", books[i].accession_number);
            printf("Title: %s\n", books[i].title);
            printf("Price: %.2f\n\n", books[i].price);
            found = 1;
        }
    }
    
    if (!found) {
        printf("No books found by this author.\n");
    }
}

void list_book_count() {
    printf("Total number of books in the library: %d\n", book_count);
}

void list_books_by_accession() {
    printf("\nBooks in order of accession number:\n");
    for (int i = 0; i < book_count; i++) {
        printf("\nAccession Number: %d\n", books[i].accession_number);
        printf("Title: %s\n", books[i].title);
        printf("Author: %s\n", books[i].author);
        printf("Price: %.2f\n", books[i].price);
        printf("Status: %s\n", books[i].is_issued ? "Available" : "Issued");
    }
}

int main() {
    int choice;
    
    // Load test data at program start
    add_test_data();
    
    while (1) {
        printf("\nLibrary Management System\n");
        printf("1. Add book information\n");
        printf("2. List all books of given author\n");
        printf("3. List the count of books in the library\n");
        printf("4. List the books in order of accession number\n");
        printf("5. Exit\n");
        
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                add_book();
                break;
            case 2:
                list_books_by_author();
                break;
            case 3:
                list_book_count();
                break;
            case 4:
                list_books_by_accession();
                break;
            case 5:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    
    return 0;
}
