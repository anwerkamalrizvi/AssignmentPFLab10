/*Create a C program that defines a constant for the conversion factor of meters to
kilometers. Use a static variable in a function to count how many times the function is
called.*/
#include <stdio.h>
static int function_counter = 0;
float meterToKm(float m){
    function_counter+=1;
    printf("\nCounter of the function: %d ",function_counter);
    float p = (m/1000);
    return p;
}
int main() {
    float m;   
    int choose;
    do{
        printf("\nEnter value of meter:  ");  scanf("%f",&m);
       printf("\nThe meter to kilometres is: %.2f ",meterToKm(m));

        printf("\nDo you want to repeat for another value?? (1 for yes, 0 for NO):  "); scanf("%d",&choose);    
    }while(choose==1);
    return 0;
}