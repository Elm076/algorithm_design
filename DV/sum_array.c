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


int divConqAlgorithm(int arr[], int l, int r, int *min, int *max)
{
    if (r - l < 2)
    {
        int sum = 0;
        for (int i = l; i <= r; i++)
        {
            if (arr[i] < *min)
                *min = arr[i];
            else if (arr[i] > *max)
                *max = arr[i];

            sum += arr[i];
        }

        return sum;
    }

    int mid = l + (r - l) / 2;
    
    int leftSum = divConqAlgorithm(arr, l, mid, min, max);
    int rightSum = divConqAlgorithm(arr, mid+1, r, min, max);
    
    return leftSum + rightSum;
}

// Function Divide and Conquer Way
int divConq(int arr[], int l, int r)
{
    int min = INT_MAX;
    int max = INT_MIN;

    return divConqAlgorithm(arr, l, r, &min, &max) - (min + max);
}




int classicAlgorithm(int arr[], int SIZE){
    if (SIZE <= 0){
        printf("\nThe array is empty or not properly initialized\n");
        exit(1);
    }
    
    int min = INT_MAX;
    int max = INT_MIN;
    int sum = 0;
    for(int i = 0; i < SIZE; i++)
    {
        if (arr[i] < min)
            min = arr[i];
        else if (arr[i] > max)
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

    //printf("The result of the sum except MIN and MAX element is:\n%d\n", classicAlgorithm(arr,8));

    printf("The result of the sum except MIN and MAX element is:\n%d\n", divConq(arr,0,8-1));
}