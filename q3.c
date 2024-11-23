/*Write a program that uses structures to manage flight information, including flight number, 
departure city, destination city, date, and available seats. 
Create functionalities to book a seat and display flight details.*/
#include <stdio.h>
#include <string.h>

typedef struct flight{
    int flightNumber, seats;
    char departureCity[50], destinationCity[50], date[15]; 
} Flight;

void displayFlightDetails(Flight flight) {
    printf("\nFlight Number: %d",flight.flightNumber); 
    printf("\nDeparture City: %s",flight.departureCity);
    printf("\nDestination City: %s",flight.destinationCity);
    printf("\nDate: %s",flight.date);
    printf("\nAvailable Seats: %d\n",flight.seats);
}//end displayFlightDetails()

void bookSeat(Flight *flight) {
    if (flight->seats > 0) {
        flight->seats--;
        printf("\nSeat booked successfully! Remaining seats: %d\n", flight->seats);
    } else {
        printf("\nNo seats available for booking.\n");
    }
}//end bookSeat()

int main() {
    Flight flight;

    printf("Enter flight number: ");
    scanf("%d", &flight.flightNumber);
    getchar();
    printf("Enter departure city: ");
    fgets(flight.departureCity, sizeof(flight.departureCity), stdin);
    flight.departureCity[strcspn(flight.departureCity, "\n")] = '\0';
    printf("Enter destination city: ");
    fgets(flight.destinationCity, sizeof(flight.destinationCity), stdin);
    flight.destinationCity[strcspn(flight.destinationCity, "\n")] = '\0';
    printf("Enter date (DD/MM/YYYY): ");
    fgets(flight.date, sizeof(flight.date), stdin);
    flight.date[strcspn(flight.date, "\n")] = '\0';
    printf("Enter available seats: ");
    scanf("%d", &flight.seats);

    int choice;
    do {
        printf("\nMenu:\n");
        printf("1. Display Flight Details\n2. Book a Seat\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch (choice) {
            case 1:
                 displayFlightDetails(flight);
                break;
            case 2:
            bookSeat(&flight);
                break;
            case 3:
               printf("\nExiting program.\n");
                break;
            default:
                 printf("\nInvalid choice. Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}//end main no way