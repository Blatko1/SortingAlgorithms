#include <stdio.h>

// Defining the lenght of the input list.
#define N 15

// Declaring functions.
void quicksort(int list[], int low, int high);
int sort(int list[], int low, int high);
void swap(int list[], int a, int b);

// Declaring & initializing step/loop counter.
int steps = 0;

int main(void){

    // Initializing the randomized list and starting the algorithm.
    int sort[] = {3,44,38,5,47,15,36,26,27,2,46,4,19,50,48};
    quicksort(sort, 0, N);

    // Printing the results.
    printf("\nSorted List Result:\n");
    for(int i = 0; i < N; i++){
        printf("%i ",sort[i]);
    }
    printf("\nSteps: %i", steps);
    return 0;
}

// Main algorithm function
void quicksort(int list[], int low, int high){

    // Checking if the function should end.
    if(low >= high) return;

    // Starting a sort between given values (borders).
    int middle = sort(list, low, high);
    // These lines are commented out because they are used for debugging.
    //printf("Low: %i, High: %i, Middle: %i", low, high, middle);

    // Using recursion.
    quicksort(list, low, middle-1);
    quicksort(list, middle, high);
}

int sort(int list[], int low, int high){
    int a = list[low];
    int cur = high;

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

void swap(int list[], int a, int b){
    int c = list[a];
    list[a] = list[b];
    list[b] = c;
}