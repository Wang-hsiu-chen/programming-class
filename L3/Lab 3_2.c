/*
Description: 
    Write a program to input a date in year 2021 and calculate the number of days from 2021/1/1 to your input date, inclusive.
    You should exclude invalid inputs such as 1/32, 2/29, 13/1, ...

Sample: 
    sample input 1
    1/1
    sample output 1
    There is 1 day

    sample input 2
    12/31
    sample output 2
    There are 365 days

    sample input 3
    2/29
    sample output 3 
    Input Error
*/

#include <stdio.h>
#include <stdlib.h>

static int array_month[12]={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
char ErrorOrNot(int m, int d, char s);
int main(void){
    int month, day, sum=0, weekday;
    char slash, error='0';
    scanf("%d%c%d", &month, &slash, &day);

    error = ErrorOrNot(month, day, slash);
    if(error=='e'){
        printf("Input Error\n");
    }
    else if(error!='e'){
        for(int i=0; i<month-1; i++)
            sum += array_month[i];
        sum +=day;
        if(sum!=1)
            printf("There are %d days\n", sum);
        else
            printf("There is 1 day\n");
    }

}

char ErrorOrNot(int m, int d, char s){
    char error='0';
    for(int i=0; i<12; i++){
        if(m==i+1 && d>array_month[i]){
            error='e';
        }
        if(m>12){
            error='e';
        }
        if(s!='/'){
            error='e';
        }
    }
    return error;
}
