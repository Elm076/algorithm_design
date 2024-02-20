#include <stdio.h>
#include "../data_structures_C/vdin/vdin.c"

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

//PEDIR Q ME EXPLIQUE ESTO
// Function to compare int numbers
int intComp(const Pair *a, const int *b) {
    return (a->number - *b);
}

//int* classicAlgorithm(int arr[], int SIZE){
int classicAlgorithm(int arr[], int SIZE){

    vdin numbers = vdin_nuev(sizeof(Pair));
    vdin_aumd(numbers, &arr[0]);
    for (int i = 1; i < SIZE; i++){
        int found = vdin_bbin(numbers, &arr[i], intComp);
        if (found == -1){
            Pair add = {arr[i],1};
            vdin_aumd(numbers, &add);
        }
        else{
            Pair* modi;
            vdin_obti(numbers,found,modi);
            modi->ocurrences++;
        }
    }
    //Pair *max;
    Pair max = {0,0};
    //max->number = 0; max->ocurrences = 0;
    Pair data;
    for (int i = 0; i < vdin_tamal(numbers); i++){
        vdin_obti(numbers,i,&data);
        // //AQUÍ CORREGIR Q MAX EN VEZ DE APUNTAR A DATA QUE APUNTE AL ELEMENTO DEL VECTOR DINÁMICO Y YA ESTARÍA
        // if (max->ocurrences < data.ocurrences){
        //     max = &data;
        // }
        //if (max->ocurrences < data.ocurrences){
        if (max.ocurrences < data.ocurrences){
            max = data;
        }
    }
    //return &max->number;
    return max.number;
}

int main(){

    int arr[15] = {1,2,3,4,4,5,1,2,3,5,4,4,3,4};

    printf("The given array is:\n");
    printArray(arr,15);

    int found = classicAlgorithm(arr, 15);

    //printf("The data found as majority number in the array is\n %d",*found);
    printf("The data found as majority number in the array is\n %d",found);
    return 0;
}