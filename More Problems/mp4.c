/*Create a structure to store details about cars in a dealership, including make, model,
year, price, and mileage. Write a program that allows users to add new cars, display a
list of available cars, and search for cars by make or model.*/
#include <stdio.h>
#include <string.h>
#define n 10
typedef struct Dealership
{
    int year, price, mileage;
    char make[20], car[20], model[20], search[20];
}Ds;

void carDealership(int choice, Ds Car_Details[n],int i){
    if(choice ==1){
        printf("\nCar Name: %s\nCar Manufacturer: %s\nCar Model: %s\nYear of Car Manufactoring: %d\nPrice of the Car in $: %d\nTotal Mileage covered by Car in km: %d",Car_Details[i].car,Car_Details[i].make,Car_Details[i].model,Car_Details[i].year,Car_Details[i].price,Car_Details[i].mileage);
        choice = 1;
    }else if(choice == 2){
        int k=0;
        for (k = 0; k < i+1; k++)
        {
            printf("\nCar %d:\n",k+1);
            printf("\nCar Name: %s\nCar Manufacturer: %s\nCar Model: %s\nYear of Car Manufactoring: %d\nPrice of the Car in $: %d\nTotal Mileage covered by Car in km: %d",Car_Details[k].car,Car_Details[k].make,Car_Details[k].model,Car_Details[k].year,Car_Details[k].price,Car_Details[k].mileage);    
            printf("\n");
        }
        k=0;
    }else if(choice ==3){
        Ds Search;
        printf("\nEnter make or model of the car to search: ");
        scanf("%s",Search.search);
        for (int j = 0; j < i+1; j++)
        {
            if(strcmp(Search.search,Car_Details[j].make)==0){
                carDealership(1,Car_Details,j);
            }else if(strcmp(Search.search,Car_Details[j].model)==0){
                carDealership(1,Car_Details,j);
            }
        }
        
    }
    
}//end carDealership
int main() {
    Ds Car_Details[n];
    int choice = 0, i=-1;
    while(choice!=4){
        printf("\n\t\tWELCOME TO CAR DEALERSHIP\nEnter:\n1. Add New Car details.\n2. List of saved cars\n3. Search for a car \n4. Exit\nYour choice(1-4):  ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            i+=1;
            printf("\nEnter car name: "); scanf("%s",Car_Details[i].car);
            printf("\nEnter manufactorar of the car: "); scanf("%s",Car_Details[i].make);
            printf("\nEnter model of the car: "); scanf("%s",Car_Details[i].model);
            printf("\nEnter model's year in format 20XX: "); scanf(" %d",&Car_Details[i].year);
            printf("\nEnter model's price in $: "); scanf(" %d",&Car_Details[i].price);
            printf("\nEnter total mileage of the car in km: "); scanf(" %d",&Car_Details[i].mileage);
            carDealership(choice,Car_Details, i);
            break;
            case 2:
            carDealership(2,Car_Details,i);
            break;
            case 3:
            carDealership(3,Car_Details,i);
            break;

            case 4:
            printf("\nExiting.. Success "); 
            break;

            default:
            printf("\nPlease provide a valid input! ");
            break;
        }
    }
    
    return 0;
}
