/*
Description: 

Sample: 
    sample input 1
    123456789098765432112345678909876543211234567890987654321
    sample output 1
    123456789098765432112345678909876543211234567890987654321
    a palindrome

*/

#include <stdio.h>
#include <stdlib.h>

int size = 10;
char AddSize(char[]), Judge(char[], int);

int main(){
    char *array1 = (char*) malloc(size * sizeof(char));
    int i = 0;

    do{
        scanf("%c", &array1[i]);
        i ++;
    }while(i < size && array1[i-1] != '\n');

    if(i == size && array1[i-1] != '\n'){
        AddSize(array1);
    }
    else if(array1[i-1] == '\n'){
        Judge(array1, i-1);
    }
}

char AddSize(char A[size]){
    char *array2 = (char*) malloc(size * sizeof(char));
    for(int i = 0; i < size; i ++){
        array2[i] = A[i];
    }
    free(A);

    size += 10;
    A = (char*) malloc(size * sizeof(char));
    for(int i = 0; i < size-10; i ++){
        A[i] = array2[i];
    }
    free(array2);

    int i = 0;
    do{
        scanf("%c", &A[i + (size - 10)]);
        i ++;
    }while(i < 10 && A[(i+size-10)-1] != '\n');
    if(i == 10 && A[(i+size-10)-1] != '\n'){
        AddSize(A);
    }
    else if(A[(i+size-10)-1] == '\n'){
        Judge(A, (i+size-10)-1);
    }
}

char Judge(char A[], int S){
    int count = 0;
    for(int j = 0; j < S; j ++){
        printf("%c", A[j]);
        if(A[j] == A[S -j -1]){
            count++;
        }
    }
    if(count == S){
        printf("\na palindrome\n");
    }
    else{
        printf("\nnot a palindrome\n");
    }
}
