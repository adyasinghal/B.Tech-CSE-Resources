// Name: ADYA SINGHAL
// Roll No.: 2410110027

// The program is completely my own and no part of it has been copied from anybody or downloaded from the net


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definition of a reservation structure
typedef struct Reservation {
    char firstName[50];
    char lastName[50];
    int reservationDate;
    struct Reservation *next;
} Reservation;

Reservation *BOOKING = NULL, *TRIP = NULL, *WAITLIST = NULL;
int maxCapacity;

// Function to create a new reservation node
Reservation* createReservation(char firstName[], char lastName[], int reservationDate) {
    Reservation* newEntry = (Reservation*)malloc(sizeof(Reservation));
    strcpy(newEntry->firstName, firstName);
    strcpy(newEntry->lastName, lastName);
    newEntry->reservationDate = reservationDate;
    newEntry->next = NULL;
    return newEntry;
}

// Function to insert a reservation into a sorted list based on date
void addSorted(Reservation **listHead, Reservation *newEntry) {
    if (*listHead == NULL || (*listHead)->reservationDate > newEntry->reservationDate) {
        newEntry->next = *listHead;
        *listHead = newEntry;
        return;
    }

    Reservation *current = *listHead;
    while (current->next != NULL && current->next->reservationDate < newEntry->reservationDate) {
        current = current->next;
    }
    newEntry->next = current->next;
    current->next = newEntry;
}

// Function to remove a reservation from a list by name
void removeByName(Reservation **listHead, char firstName[], char lastName[]) {
    Reservation *current = *listHead, *previous = NULL;

    while (current != NULL) {
        if (strcmp(current->firstName, firstName) == 0 && strcmp(current->lastName, lastName) == 0) {
            if (previous == NULL) {
                *listHead = current->next;
            } else {
                previous->next = current->next;
            }
            free(current);
            return;
        }
        previous = current;
        current = current->next;
    }
}

// Function to display all reservations in a list with a title
void showList(char title[], Reservation *listHead) {
    printf("%s:\n", title);

    if (!listHead) {
        printf("EMPTY\n");
        return;
    }

    Reservation *current = listHead;
    while (current != NULL) {
        printf("%d %s %s ", current->reservationDate, current->firstName, current->lastName);        
        current = current->next;
    }
    printf("\n");
}

// Function to update TRIP and WAITLIST based on the BOOKING list
void refreshLists() {
    TRIP = NULL;
    WAITLIST = NULL;

    Reservation *currentBooking = BOOKING;
    int count = 0;

    while (currentBooking != NULL) {
        Reservation* clonedNode = createReservation(currentBooking->firstName, currentBooking->lastName, currentBooking->reservationDate);
        
        if (count < maxCapacity) {
            addSorted(&TRIP, clonedNode);
        } else {
            addSorted(&WAITLIST, clonedNode);
        }

        count++;
        currentBooking = currentBooking->next;
    }
}

// Function to count the number of reservations in a list
int getCount(Reservation* listHead) {
    int count = 0;

    while (listHead != NULL) {
        count++;
        listHead = listHead->next;
    }

    return count;
}

// Function to delete a reservation from BOOKING and refresh TRIP and WAITLIST
void cancelReservation(char firstName[], char lastName[]) {
    removeByName(&BOOKING, firstName, lastName);
    refreshLists();
}

int main() {
    FILE* filePointer = fopen("EASYTRIP.txt", "r");

    if (!filePointer) {
        printf("Error: Unable to open file.\n");
        return -1;
    }

    fscanf(filePointer, "%d", &maxCapacity);

    int operationCode, bookingDate;
    char firstName[50], lastName[50];

    while (fscanf(filePointer, "%d", &operationCode) != EOF) {
        switch (operationCode) {
            case 1:
                fscanf(filePointer, "%s %s %d", firstName, lastName, &bookingDate);
                addSorted(&BOOKING, createReservation(firstName, lastName, bookingDate));
                refreshLists();
                break;

            case 2:
                fscanf(filePointer, "%s %s", firstName, lastName);
                cancelReservation(firstName, lastName);
                break;

            case 3:
                showList("BOOKING", BOOKING);
                break;

            case 4:
                showList("TRIP", TRIP);
                break;

            case 8:
                showList("WAITLIST", WAITLIST);
                break;

            default:
                break;
        }
    }

    fclose(filePointer);

    return 0;
}
