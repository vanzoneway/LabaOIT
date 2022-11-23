#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "goodinputs.h"
#include <time.h>
void give_memory_matrix(int*** table, int N, int M){
    *table = (int**)malloc(N*sizeof(int*));
    for(int i = 0;i<N;i++){
        (*table)[i] = (int*)calloc(M,sizeof(int));
    }
}
void randomised_init_matrix(int*** table, int N, int M){
    srand(time(NULL));
    for(int i = 0; i<N;i++){
        for(int j = 0;j<M;j++){
            (*table)[i][j] = rand()%(100-50+1);
        }
    }
}
void input_array_by_keyboard(int*** table, int N, int M){
    for(int i = 0;i<N;i++){
        printf("Enter [%d] row of matrix:\n ",i+1);
        for(int j = 0; j<M;j++){
            printf("Element [%d][%d] = ", i+1,j+1);
            (*table)[i][j] = goodScanfInt();
            printf("\n");
        }
    }
}

void createMatrix(int*** table, int N, int M){

    printf("Enter [1] if you wanna randomised matrix\nEnter [2] if you wanna matrix by keyboard\n>");
    int var = goodScanfInt();
    int flag = 1;

    while(flag){

        switch (var) {
            case 1:
                give_memory_matrix(table,N,M);
                randomised_init_matrix(table,N,M);
                flag = 0;
                break;
            case 2:
                give_memory_matrix(table,N,M);
                input_array_by_keyboard(table,N,M);
                flag = 0;
                break;


            default:
                printf("You wrote an incorrect variant, try again!\n>");
                var = goodScanfInt();

        }
    }
}

int sum_of_row(const int* row, int M){
    int sum = 0;
    for(int i = 0;i<M;i++){
        sum += row[i];
    }
    return sum;
}

void print_matrix_t2(int** table, int N, int M){
    for(int i = 0;i<N;i++){
        for(int j = 0;j<M;j++){
            printf("%d ",table[i][j]);
            if(j == M-1){
                printf("   (sum of array = %d)", sum_of_row(table[i],M));
            }
        }
        printf("\n");
    }
}

void free_matrix(int** table, int N){
    for(int i = 0;i<N;i++){
        free(table[i]);
    }
    free(table);
}

/*functions for arrays, NOT FOR TABLES!*/
void randomised_init_array(int* arr, int size){
    srand(time(NULL));
    for(int i = 0;i<size;i++){
        arr[i] = rand()%(100-50+1);
    }
}
void init_array_from_keyboard(int* arr,int size){
    for(int i = 0;i<size;i++){
        printf("Enter a [%d] element: \n",i+1);
        arr[i] = goodScanfInt();
    }
}

void createArray(int** arr, int size){
    *arr = (int*)malloc(sizeof(int)*size);
    printf("Enter [1] if you wanna randomised array\n Enter [2] if you wanna keyboard array\n>");
    int var = goodScanfInt();
    int flag = 1;
    while(flag){
        switch (var) {
            case 1:
                randomised_init_array(*arr, size);
                flag = 0;
                break;
            case 2:
                init_array_from_keyboard(*arr,size);
                flag = 0;
                break;
            default:
                printf("You wrote and incorrect variant! Try again!\n>");
        }
    }
}
void print_array(int* arr, int size){
    for(int i = 0;i<size;i++){
        printf("[%d] ",arr[i]);
    }
}

int index_of_max_element(const int* arr, int size){
    int max = arr[0];
    int index_of_max = 0;
    for(int i = 0;i<size;i++){
        if(arr[i]>max){
            max = arr[i];
            index_of_max = i;
        }
    }
    return index_of_max;
}