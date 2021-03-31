#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LENGHT 10000

void bubbleSort(int list[], int lenght);
void swap(int list[], int posA, int posB);
void generateRandomList(int list[], int lenght);

int steps = 0;

int main(void){

    time_t t;

    srand((unsigned) time(&t));
    int list[LENGHT];
    generateRandomList(list, LENGHT);

    printf("\nRandom list before sorting:\n");
    /*for(int i = 0; i < LENGHT; i++){
        printf("%i ",list[i]);
    }*/

    bubbleSort(list, LENGHT);

    printf("\nFINAL:\n");
    /*for(int i = 0; i < LENGHT; i++){
        printf("%i ", list[i]);
    }*/
    printf("\nSteps: %i", steps);

    return 0;
}

void bubbleSort(int list[], int lenght){
    int a;
    for(int i = lenght; i > 1; i--){
        for(int n = 0; n < i-1; n++){
            a = list[n];
            if(a > list[n+1]){
                list[n] = list[n+1];
                list[n+1] = a;
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

void generateRandomList(int list[], int lenght){
    for(int i = 0; i < lenght; i++){
        list[i] = rand() % lenght + 1;
    }
}
