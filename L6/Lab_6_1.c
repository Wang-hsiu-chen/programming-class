/*
Description: 

Sample: 
    sample input 1
    8
    1 2 3 4 5 6 7 8
    7 8 5 6 3 4 1 2
    4 3 2 1 8 7 6 5
    6 5 8 7 2 1 4 3
    8 7 6 5 4 3 2 1
    2 1 4 3 6 5 8 7
    5 6 7 8 1 2 3 4
    3 4 1 2 7 8 5 6
    sample output 1
    yes

*/

#include <stdio.h>
#include <stdlib.h>

int main(){
    int N = 0, R = 0, C = 0;
    scanf("%d", &N);
    int array[N][N];
    for(int i=0; i<N; i++){
        for(int j = 0; j < N; j++){
            scanf("%d", &array[i][j]);
        }
    }
    for(int i=0; i<N; i++){
        for(int j = 0; j < N; j++){
            for(int k = 0; k < N; k++){
                if(array[i][k] == j+1){
                    R++;
                    break;
                }
            }
        }
        //printf("%d\n", R);
    }
    for(int i=0; i<N; i++){
        for(int j = 0; j < N; j++){
            for(int k = 0; k < N; k++){
                if(array[k][i] == j+1){
                    C++;
                    break;
                }
            }
        }
        //printf("%d\n", C);
    }
    if(R == N*N && C == N*N){
        printf("yes\n");
    }
    else{
        printf("no\n");
    }

}
