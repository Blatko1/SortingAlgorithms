#include <stdio.h>

#define LENGHT 15

void bubbleSort(int list[], int lenght);
void swap(int list[], int posA, int posB);

int steps = 0;

int main(void){

    int list[] = {3,44,38,5,47,15,36,26,27,2,46,4,19,50,48};
    bubbleSort(list, LENGHT);

    printf("\nFINAL:\n");
    for(int i = 0; i < LENGHT; i++){
        printf("%i ", list[i]);
    }
    printf("\nSteps: %i", steps);

    return 0;
}

void bubbleSort(int list[], int lenght){
    int a;
    for(int i = lenght; i > 1; i--){
        for(int n = 0; n < i-1; n++){
            a = list[n];
            if(a > list[n+1]){
                swap(list, n, n+1);
            }
            steps++;      
        }
    }
}

void swap(int list[], int posA, int posB){
    int temp = list[posA];
    list[posA] = list[posB];
    list[posB] = temp;
}


