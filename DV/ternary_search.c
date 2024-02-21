#include <stdio.h>
#include <stdlib.h>
#include "../data_structures/ivector/ivector.h"

// Function to print an array
void printArray(int A[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		printf("%d ", A[i]);
	printf("\n");
}


//REVISAR ESTO HAY UN ERROR AQUÍ
int* ternary_search(int v[], int lower, int SIZE, int data){
    if (SIZE >= 1){
        int new_size = SIZE/3;

        int mid1 = lower + ((lower + SIZE) - lower) / 3;
        int mid2 = lower + 2 * ((lower + SIZE) - lower) / 3;

        if (v[lower] < data && data <= v[mid1]){
            return ternary_search(v, lower, new_size, data);
        }
        else if (v[mid1] < data && data <= v[mid2]){
            return ternary_search(v, mid1, new_size, data);
        }
        return ternary_search(v, mid2, new_size, data);
    }

    return &v[lower];
        
}

int main(){
    const int SIZE = 20;
    int v[SIZE];
    
    for (int i = 0; i < SIZE; i++){
        v[i] = 2*i;
    }

	printf("Given array is \n");
    printArray(v,SIZE);

    printf("The found data in the array is: \n%d \n", *ternary_search(v, v[0], SIZE, 20));
}