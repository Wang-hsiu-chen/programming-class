/*
Description: 
    Redo Lecture #6 using malloc() as explained in the class. 
    DO NOT USE STATIC ARRAYS (or any variable-length arrays) as you will not only get NO POINTS for this lab but also lose PENALTY POINTS of 1 extra Lab!
    用malloc()重做 lecture #6，不可用靜態陣列寫法，否則不但此次Lab 0分，且要倒扣一次Lab分數！

Sample: 
    sample input 1
    5 6
    101010
    100010
    110000
    110001
    110000
    sample output 1
    #3#3#2
    #523#2
    ##2122
    ##3.1#
    ##2.11
    
*/

#include <stdio.h>
#include <stdlib.h>

void input(char **, int, int);
void count(char **, char **, int , int);
void output(char **, int, int);

int main(){
   int  h, w;
   scanf("%d %d", &h, &w);

   char **a = (char**) malloc(h*sizeof(char*));
   char **b = (char**) malloc(h*sizeof(char*));
   for(int i = 0; i < h; i++){
        *(a + i) = (char*) malloc(w*sizeof(char));
        *(b + i) = (char*) malloc(w*sizeof(char));
   }

   input(a,h,w);
   count(a,b,h,w);

   return 0;
}

void input(char **a, int H, int W) {
   int i, j;
   char temp;

    for (i = 0; i < H; i++){
       scanf("\n");

       for (j = 0; j < W; j++){
           scanf("%c", &temp);
           if('1' == temp){
               *(*(a+i)+j) = (char)1;
           }
           if('0'== temp){
               *(*(a+i)+j) = (char)0;
           }
       }
    }
}

void count(char **a, char **b, int H, int W){
    /*
    int **c = (int**) malloc(H*sizeof(int*));
    for(int i = 0; i < H; i++){
        *(c + i) = (int*) malloc(W*sizeof(int));
    }
    */
    int BombNum = 0;

    for(int i=0; i<H; i++){
        for(int j=0; j<W; j++){
            if (*(*(a+i)+j) == (char)1) {
                *(*(b+i)+j) = '#';
            } else if (*(*(a+i)+j) == (char)0) {
                for (int ii = -1; ii < 2; ii++) {
                    for (int jj = -1; jj < 2; jj++) {
                        if (i + ii >= 0 && i + ii < H && j + jj >= 0 && j + jj < W)
                            BombNum += (int)*(*(a+i+ii)+j+jj);
                        else 
                            BombNum += 0;
                    }
                }
                if (BombNum > 0)
                    *(*(b+i)+j) =  (char)BombNum + 48;
                else if (BombNum == 0)
                    *(*(b+i)+j) = '.' ;
            }
            BombNum = 0;
        }
    }
    output(b, H, W);
}

void output(char **b, int H, int W){
    for(int i=0; i<H; i++){
        for(int j=0; j<W; j++){
            printf("%c",   *(*(b+i)+j));
        }
        printf("\n");
    }
}

