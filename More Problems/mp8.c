/*Write a recursive function linearSearch that takes an array, its size, the target element
to search for, and the current index. It checks if the target is at the current index and
continues searching in the subsequent indices until it either finds the target or exhausts
the array.*/
#include <stdio.h>

void recursiveLinearSearch(int arr[], int search, int n, int check, int count);
int main() {
    int n;
    printf("Enter length of the array: ");
    scanf("%d",&n);
    int arr[n];
    int count = 0; //only for condition if value not found
    for(int i=0;i<n;i++){
      printf("Enter element[%d]: ",i+1);
      scanf("%d",&arr[i]);
    }//end for
    int search; printf("\nEnter number to search: ");
    scanf("%d",&search);
    recursiveLinearSearch(arr,search,n,0,count);
    
    return 0;
}

void recursiveLinearSearch(int arr[],int search,int n,int check,int count){
    
    if(check>=n){
        if(count==0){
            printf("\nNo value found based on your search. ");
        }
        return;     //base case
    }
    if(arr[check] ==search){
        printf("\nFound at %d at index: %d and element#%d ",arr[check],check,check+1);
        count+=1;
    }
     recursiveLinearSearch(arr, search, n, check + 1,count);
    //recursivve case

}//end recursiveLinearSearch(int arr[],int search)