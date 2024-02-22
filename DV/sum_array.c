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

//Function to merge
void merge (int arr[], int l, int r, int *sum, int *min, int *max)
{
    //if (r - l > 2)
    //{
        for (int i = l; i < r; i++)
        {
            if (*min > arr[i])
            {
                *min = arr[i];
            }
            if (*max < arr[i])
            {
                *max = arr[i];
            }
            *sum += arr[i];
        }
    //}
    //else
    //{
    //    for (int i = l; i <= r; i++)
    //    {
    //        *sum += arr[i];
    //    }  
    //}
}

// Function to divide in two subArrays
void Divide(int arr[], int l, int r, int *sum, int *min, int *max)
{
    int mid = l + (r - l) / 2;

    if (r - l > 2)
    {
        Divide(arr, l, mid, sum, min, max);
        Divide(arr, mid+1, r, sum, min, max);

        merge(arr, l, r, sum, min, max);
    }
    else
    {
        //TERMINAR ESTO
        for (int i = 0;)
    }
}

// Function Divide and Conquer Way
int DivConq(int arr[], int l, int r)
{
    int min = 0;
    int max = 0;
    int sum = 0;

    Divide(arr, l, r, &sum, &min, &max);

    return (sum -= (min + max));
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

    //printf("The result of the sum except MIN and MAX element is:\n%d\n", classicAlgorithm(arr,8));

    printf("The result of the sum except MIN and MAX element is:\n%d\n", DivConq(arr,0,8-1));
}