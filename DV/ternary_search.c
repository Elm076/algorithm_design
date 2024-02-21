#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "../data_structures_C/ivector/ivector.c"


#define SIZE 7

// Function to print an array
void printArray(int A[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		printf("%d ", A[i]);
	printf("\n");
}


int ternary_search(int v[], int l, int r, int data){
        if (l <= r)
        {
            int mid1 = l + (r - l) / 3;
            int mid2 = r - (r - l) / 3;

            if (data == v[mid1])
            {
                return v[mid1];
            }
            if (data == v[mid2])
            {
                return v[mid2];
            }


            if (data < v[mid1])
            {
                ternary_search(v, l, mid1-1, data);
            }
            else if (data < v[mid2])
            {
                ternary_search(v, mid1+1, mid2-1, data);
            }
            else if (data > v[mid2])
            {
                ternary_search(v, mid2+1, r, data);
            }
        }
        
        //Data not found
        else{
            return INT_MIN;
        }

}

int main(){

    ivector arr;
    arr = icreavector(SIZE);

    for (int i = 0; i < SIZE; i++)
    {
        arr[i] = i*2;
    }

	printf("Given array is \n");
    printArray(arr,SIZE);

    printf("The found data in the array is: \n%d \n", ternary_search(arr, 0, SIZE-1, 10));

    ifreevector(&arr);
}