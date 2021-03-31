#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Defining the lenght of the input list.
#define N 100000

// Declaring functions.

void quicksort(int list[], int low, int high);
int sort(int list[], int low, int high);
void swap(int list[], int a, int b);
void generateRandomList(int list[], int lenght);

// Declaring & initializing step/loop counter.
int steps = 0;

int main(void){

    time_t t;

    srand((unsigned) time(&t));
    // Initializing the randomized list and starting the algorithm.
    int sort[N];
    generateRandomList(sort,N);

    printf("\nRandom list before sorting:\n");
    /*for(int i = 0; i < N; i++){
        printf("%i ",sort[i]);
    }*/

    quicksort(sort, 0, N);

    // Printing the results.
    printf("\nSorted List Result:\n");
    /*for(int i = 0; i < N; i++){
        printf("%i ",sort[i]);
    }*/
    printf("\nSteps: %i", steps);
    return 0;
}

// Main algorithm function.
void quicksort(int list[], int low, int high){

    // Checking if the function should end.
    if(low >= high) return;

    // Starting a sort between given values (borders) and returning the position of the sorted number.
    int middle = sort(list, low, high);

    // These lines are commented out because they are used for debugging.
    //printf("Low: %i, High: %i, Middle: %i", low, high, middle);

    // Using recursion to sort the left side of the sorted number position.
    quicksort(list, low, middle-1);

    // Using recursion to sort the right side of the sorted number position.
    quicksort(list, middle, high);
}

// Algorithm for sorting numbers between given values
int sort(int list[], int low, int high){
    // Findng the value of lowest value.
    int a = list[low];
    int cur = high;

    // Loop trough list, sort the value a to its position and return the position.
    for(int i = low+1; i < high; i++){
        if(a<list[i]){
            if(cur == high){
                cur = i;
            }
        }
        else if(a>list[i]){
            if(cur != high){
                swap(list, i, cur);
                cur++;
            }
        }
        steps++;
    }
    swap(list, low, cur-1);
    // These lines are commented out because they are used for debugging.
    /*printf("\nnext:\n");
    for(int i = 0; i < N; i++){
        printf("%i ",list[i]);
    }
    printf("\n");*/
    return cur;
}

// Function for swaping two elements in the list.
void swap(int list[], int a, int b){
    int c = list[a];
    list[a] = list[b];
    list[b] = c;
}

void generateRandomList(int list[], int lenght){
    for(int i = 0; i < lenght; i++){
        list[i] = rand() % lenght + 1;
    }
}