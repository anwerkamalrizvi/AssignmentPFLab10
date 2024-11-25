/*Write a recursive function that takes an array and its size as input and prints all the
elements.*/
#include <stdio.h>

int arrPrintRecursion(int arr[],int i, int n){
    if (i==n)
    {return 0 ;}
    printf("%d ",arr[i]);
    return arrPrintRecursion(arr, i + 1, n);
}
int main() {
    int n;
    printf("Enter length of the array: ");
    scanf("%d",&n);
    int arr[n],i=-1;
    for(int j=0;j<n;j++){
      printf("Enter element[%d]: ",j+1);
      scanf("%d",&arr[j]); 
    }//end for
    arrPrintRecursion(arr,0,n);
        return 0;
}