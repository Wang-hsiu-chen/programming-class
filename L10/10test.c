#include <stdio.h>
#include <stdlib.h>

int determine(char *arr, int i, int maxsize, int stop){
    if ( arr[i] == arr[maxsize - i] && i < maxsize) {
        stop = 1;
        determine(arr, i + 1, maxsize, stop);
    }
    else if(arr[i] != arr[maxsize - i]){
        stop = 0;
    }
    if(i == maxsize && stop == 1){
        printf("a pelin\n");
    }
    else if(stop == 0){
        printf("not\n");
    }
}

int main(){
    int size = 5, i = -1;
    char *arr = (char*)malloc(size * sizeof(char));
    do {
        i++;
        scanf("%c", &*(arr + i));
        if (i == size - 1){
            char *temp = (char*)malloc(size * sizeof(char));
            for (int j = 0; j < size; j++) {
                *(temp + j) = *(arr + j);
            }
            free(arr);
            size += 5;
            char *arr = (char*)malloc(size * sizeof(char));
            for (int j = 0; j < size - 5; j++) {
                *(arr + j) = *(temp + j);
            }
        }
    }while(*(arr + i) != '\n');
    for (int j = 0; j < i; j++) {
        printf("%c ", *(arr + j));
    }
    determine(arr, 0, i - 1, 0);
}
