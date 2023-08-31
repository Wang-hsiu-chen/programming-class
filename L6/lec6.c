/*
Description: 

Sample: 
    sample input 1
    5 5
    10101
    10001
    11110
    11001
    11001
    sample output 1
    #3#3#
    #645#
    ####3
    ##54#
    ##22#
    
*/

#include <stdio.h>

void input(char [][10], int, int);
void count(char [][10], int [][10], int , int);
void output(int [][10], int, int);

int main(){
   int  h, w;
   char a[10][10];
   char b[10][10];
   int c[10][10]={};

   scanf("%d %d", &h, &w);

   input(a,h,w);
   count(a,c,h,w);
   output(c,h,w);


   return 0;
}

void input(char a[][10], int h, int w) {
   int i, j;
   char temp;
   //printf( "Enter the minefield:\n");
    for (i=0; i<h; i++){
       scanf("\n");

       for (j=0; j<w; j++){
         //scanf("%c", &a[i][j]);
           scanf("%c", &temp);
           if('1' == temp){
               a[i][j] = (char)1;
           }
           if('0'== temp){
               a[i][j] = (char)0;
           }

       }
    }
}

void count(char a[][10], int c[][10], int h, int w){
    int BombNum = 0;
    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            if(a[i][j] == (char)1){
                for(int k = -1; k < 2; k ++){
                    for(int l = -1; l < 2; l ++){

                        if(a[i+k][j+l] == (char)0){
                            printf("%c", '0');
                            c[i+k][j+l]++;
                            //c[i][j]++;
                        }
                    }
                }
            }
        }
    }


    /*
    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            if(a[i-1][j-1] == (char)1 && i-1 >= 0 && j-1 >= 0) BombNum++;
            if(a[i-1][j] == (char)1 && i-1 >= 0) BombNum++;
            if(a[i-1][j+1] == (char)1 && i-1 >= 0 && j+1 <= w) BombNum++;

            if(a[i][j-1] == (char)1 && j-1 >= 0) BombNum++;
            if(a[i][j+1] == (char)1 && j+1 <= w) BombNum++;

            if(a[i+1][j-1] == (char)1 && i+1 <= h && j-1 >= 0) BombNum++;
            if(a[i+1][j] == (char)1 && i+1 <= h) BombNum++;
            if(a[i+1][j+1] == (char)1 && i+1 <= h && j+1 <= w) BombNum++;
            if(BombNum > 0 && a[i][j] != (char)1){
                b[i][j] = '-0' +BombNum;
            }
            else if(BombNum == 0 && a[i][j] != (char)1){
                b[i][j] = '.';
            }
            else if(a[i][j] == (char)1){
                b[i][j] = '#';
            }
            BombNum = 0;
        }
    }
    */
}

void output(int c[][10], int H, int W){
    for(int i=0; i<H; i++){
        for(int j=0; j<W; j++){
            printf("%c", '-0' + c[i][j]);
        }
        printf("\n");
    }
}
