#include <stdio.h>
#include <string.h>
#include <string.h>

int main(void) {

    char A[1000]={}, B[1000]={};
    int deg_a=1,deg_b=1, i=0, j=0;
    //input A
    while(i<deg_a){
        scanf("%c", &A[i]);
        deg_a++;
        if(A[i] == '\n'){
            deg_a = i;
        }
        i++;
    }
    //move the number of A to correct place
    for(int i=0; i<deg_a; i++){
        A[999-i] = A[deg_a-1-i];
    }
    for(int i=0; i<1000-deg_a; i++){
        A[i] = '0';
    }

    //input B
    while(j<deg_b){
        scanf("%c", &B[j]);
        deg_b++;
        if(B[j] == '\n'){
            deg_b = j;
        }
        j++;
    }
    //move the number of B to correct place
    for(int j=0; j<deg_b; j++){
        B[999-j] = B[deg_b-1-j];
    }
    for(int j=0; j<1000-deg_b; j++){
        B[j] = '0';
    }
/*
    printf("\n");
    //print A, B to check
    printf("deg_a:%d\n", deg_a);
    for(int i=0; i<1000; i++){
        printf("%c", A[i]);
    }
    printf("\n");
    printf("deg_b:%d\n", deg_b);
    for(int i=0; i<1000; i++){
        printf("%c", B[i]);
    }
    printf("\n");
*/
    //plus two number
    int P1[1000]={}, P2[1000]={}, Sum[1001]={}, deg=0;
    for(int p=0; p<1000; p++){
        P1[p] = ((A[p] - '0')+(B[p] - '0'))%10;
        P2[p] = ((A[p] - '0')+(B[p] - '0'))/10;
    }
    Sum[0] = P2[0];
    for(int p=1; p<1001; p++){
        Sum[p] = (P1[p-1] + P2[p])%10;
        if(P1[p-1] + P2[p] >=10){
            Sum[p-1] = Sum[p-1] + 1;
        }
    }
    //delete the zero behind
    for(int p=0; p<1001; p++){
        if(Sum[p] != 0){
            deg = p;
            break;
        }
    }
    //print the sum
    for(int p=deg; p<1001; p++){
        printf("%d", Sum[p]);
    }
    printf("\n");
    return 0;
}
