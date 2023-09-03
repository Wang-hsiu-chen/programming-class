/*
Description: 
    Redo the palindrome problem (Lec 4-2 ) using recursion.
    You cannot use the old version, otherwise not only will you get no credits for this lecture, we will take PENALTY points.
    重做 Lec 4-2 palindrome 那一題，請用“遞迴函式”的方法，否則不但不算分還會被倒扣分數！

Sample: 
    sample input 1
    abcba
    sample output 1
    a palindrome

    sample input 2
    abc
    sample output 2
    not a palindrome
*/

#include <stdio.h>
#include <stdlib.h>

int size = 10;
char AddSize(char[]);
void Judge(char[], int, int, int);

int main(){
    char *array1 = (char*) malloc(size * sizeof(char));
    int i = 0;

    do{
        scanf("%c", &array1[i]);
        i ++;
    }while(i < size && array1[i-1] != '\n');

    Judge(array1, 0, i-1, 0);
}

void Judge(char A[], int j, int S, int e){
    if(A[j] == A[S -j -1] && j < S){
        e = 1;
        Judge(A, j+1, S, e);
    }
    else if(A[j] != A[S - j - 1]){
        e = 0;
    }
    if(j == S && e == 1){
        printf("a palindrome\n");
    }
    else if(e == 0){
        printf("not a palindrome\n");
    }
}
