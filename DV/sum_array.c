#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
// Function to print an array
void printArray(int A[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}


int classicAlgorithm(int arr[], int SIZE){
    if (SIZE <= 0){
        printf("\nThe array is empty or not properly initialized\n");
        exit(1);
    }
    
    int min = INT_MAX;
    int max = INT_MIN;
    int sum = 0;
    for(int i = 0; i < SIZE; i++){
        if (min > arr[i])
            min = arr[i];
        else if (max < arr[i])
            max = arr[i];
        
        sum += arr[i];
    }
    sum -= (min + max);
    return sum;
}

int main(){
    
    int arr[8] = {4,1,8,7,2,6,9,3};
    
    printf("The given array is:\n");
    printArray(arr,8);

    printf("The result of the sum except MIN and MAX element is:\n%d\n", classicAlgorithm(arr,8));
}