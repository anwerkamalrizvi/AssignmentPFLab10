/*Create a program with a constant that defines the maximum allowable temperature (in
Celsius). Write a function to compare input temperatures and use a static variable to
count how many times temperatures exceeded the limit.*/

#include <stdio.h>
#define max_celcius 50

void maxTempInCelcius(int temp){ 
    static int count = 0;
    if(temp>max_celcius){
        count++;   
    }
    printf("\nCounter of exceeded limit: %d ",count);
}

int main() {
    int temp;
    while(temp!=100){
        printf("\nEnter temperature in Celcius max limit is 50 degress(Enter 100 to exit): "); scanf("%d",&temp);
    }
        maxTempInCelcius(temp);
    return 0;
}