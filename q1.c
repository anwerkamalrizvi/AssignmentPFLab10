/*Write a recursive function that calculates the sum of digits of a number. For example, if
the input is 123, the output should be 6.*/
#include <stdio.h>

int sumOfDigits(int n);
int main() {
    int num; printf("\nEnter any number: "); scanf("%d",&num);
    printf("\nSum of digits is: %d",sumOfDigits(num));
    return 0;
}

int sumOfDigits(int n){
    if(n==0){
        return 0;
    }else{
        return (n%10 + sumOfDigits(n/10));
    }
}//end sumOfDigits