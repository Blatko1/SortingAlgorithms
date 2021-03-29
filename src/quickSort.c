#include <stdio.h>

#define N 15

void quicksort(int list[], int low, int high);
int sort(int list[], int low, int high);
void swap(int list[], int a, int b);

int steps = 0;

int main(void){

    int sort[] = {3,44,38,5,47,15,36,26,27,2,46,4,19,50,48};
    quicksort(sort, 0, N);

    printf("\nSorted List Result:\n");
    for(int i = 0; i < N; i++){
        printf("%i ",sort[i]);
    }
    printf("\nSteps: %i", steps);
    return 0;
}

void quicksort(int list[], int low, int high){
    if(low >= high) return;
    int middle = sort(list, low, high);
    //printf("Low: %i, High: %i, Middle: %i", low, high, middle);
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