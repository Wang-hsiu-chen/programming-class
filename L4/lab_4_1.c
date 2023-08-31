/*
Description: 

Sample: 
    sample input 1
    12 5 54 2 98 32 -1
    sample output 1
    12>5, 12>2, 5>2, 54>2, 54>32, 98>32
    6 inversion(s)

    sample input 2
    -1
    sample output 2
    0 inversion(s)
*/

#include <stdio.h>
#include <stdlib.h>

int lab4_2(int);
int lab4_3(int);
int Primenum[]={2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
int main()
{
    int num;
    scanf("%d", &num);
    lab4_2(num);
    lab4_3(num);
}

int lab4_2(int int_num)
{
    int i = 0, count = 0;
    char start = 0;
    if(int_num == 1){
        printf("%d", int_num);
    }
    while(int_num>1){
        if(int_num%Primenum[i] == 0){
            if(start == 0){
                printf("%d", Primenum[i]);
                start = 1;
            }
            else printf("*%d", Primenum[i]);
            int_num/=Primenum[i];
            count++;
        }
        else if(int_num%Primenum[i] != 0){
            i++;
            count = 0;
        }
    }
    printf("\n");
}

int lab4_3(int int_num)
{
    int i = 0, count = 0;
    while(int_num>1){
        if(int_num%Primenum[i] == 0){
            int_num/=Primenum[i];
            count++;
        }
        else if(int_num%Primenum[i] != 0){
            if(count != 0){
                printf("%d^%d, ", Primenum[i], count);
            }
            i++;
            count = 0;
        }
    }
    printf("%d^%d", Primenum[i], count);
}

