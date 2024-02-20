#include <stdio.h>
#include <limits.h>

//Data Structure to store number of times a number appears in the array
typedef struct pair{
    int number;
    int ocurrences;
} Pair;

// Function to print an array
void printArray(int A[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}

//DO THE DIVIDE AND CONQUER WAY

/* Function to give the majority number of an array (n/2)
Using the classic way.*/
int* classicAlgorithm(int arr[], int SIZE){

    Pair repNumbers[SIZE];
    for (int i = 0; i < SIZE; i++){
        repNumbers[i].number = INT_MAX;
        repNumbers[i].ocurrences = 0;
    }

    for (int i = 0; i < SIZE; i++){
        int j = 0;
        int found = 0;
        while (repNumbers[j].number != INT_MAX && j < SIZE){
            if (repNumbers[j].number == arr[i]){
                repNumbers[j].ocurrences++;
                found = 1;
                break;
            }
            j++;
        }
        if (!found){
            Pair add;
            add.number = arr[i];
            add.ocurrences = 1;
            repNumbers[j] = add;
        }
    }

    Pair *max = &repNumbers[0];
    for (int i = 1; i < SIZE; i++){
        if (max->ocurrences < repNumbers[i].ocurrences){
            max = &repNumbers[i];
        }
    }
    if(max->ocurrences > SIZE/2)
        return &max->number;
    return NULL;
}

int main(){

    int arr[16] = {1,2,3,4,4,5,1,3,2,3,5,4,3,4,3,4};
    
    printf("The given array is:\n");
    printArray(arr,15);

    int* found = classicAlgorithm(arr, 15);

    if(found)
        printf("The data found as majority number in the array is:\n%d\n",*found);
    else
        printf("There's not majority number in the given array\n");
    return 0;
}