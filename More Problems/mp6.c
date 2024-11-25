/*Design a structure to store information about travel packages, including package name,
destination, duration, cost, and number of seats available. Write a program that allows
users to book a travel package and display available packages.*/
#include <stdio.h>
#define n 100
struct Packages{
    int seats, cost, booking_code;      //code for booking seats 
    char duration[20], dest[20], package_name[20];
};

void availablePackages(int choice, struct Packages Info[n],int count){
    if(choice == 1){
        printf("\nPackage Name: %s\nDestination of the package: %s\nTotal Duration DD:HH:MM: %s\nNet cost in $: %d\nTotal Seats available in the package: %d\nBooking code: %d",Info[count].package_name,Info[count].dest,Info[count].duration,Info[count].cost,Info[count].seats,Info[count].booking_code);
    }
    else if(choice == 2){
        int search;
        printf("\nEnter booking code to book the seat. "); scanf("%d",&search);
        for (int j = 0; j < count; j++)       {
            if(Info[j].booking_code == search){
                if(Info[j].seats>0){

                Info[j].seats-=1;
                printf("\nSeat Booked ");
                }else{
                    printf("\nSorry no Seat left in the package! ");
                }
            }
        }
                }//end else iff
    else if(choice==3){
        for (int j = 0; j < count; j++)
            {
                availablePackages(1,Info,j);
            }//end for
    }
}
int main() {
    struct Packages Info[n];
    int choice, i = 0, count=0;
    while(choice!=4){

    printf("\n\t\tWelcome To Travel Packages Services Info Corp (TPSIC)\n\nEnter:\n1. Add new package detail.\n2. Book seat in the current packages\n3. Display available packages\n4. Exit\nYour choice:  ");
    scanf("%d",&choice); 
    switch(choice){
        case 1:
            printf("\nEnter Package Name: "); scanf("%s",Info[i].package_name);
            printf("\nEnter Destination of the package: "); scanf("%s",Info[i].dest);
            printf("\nEnter Total Duration in format(Days:Hours:Minutes) DD:HH:MM : "); scanf("%s",Info[i].duration);
            printf("\nEnter Total expense of the package in $: "); scanf("%d",&Info[i].cost);
            printf("\nEnter Total seats available of the package: "); scanf("%d",&Info[i].seats);
            Info[i].booking_code = count+1;
            availablePackages(1,Info,count);
            i+=1;
            count+=1;
            break;
        case 2:
            availablePackages(2,Info,count);
            break;    
        case 3: 
            availablePackages(3,Info,count);
            break;
        case 4:
            printf("\nBye have a nice day! Thanks for using Travel Packages Service Info Corp. (TPSIC)");
            
    }//end switch statment
    }//end while loop
    return 0;
}//end main no way bro