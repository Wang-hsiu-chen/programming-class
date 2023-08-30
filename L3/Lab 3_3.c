/*
Description: 
    Write a program to input a date in year 2021 and find out which day of the week it is.As usual, there should be a new line at the end of the output string.
    You should exclude invalid inputs like Lab 3-2, too.

Sample: 
    sample input 1
    10/14
    sample output 1
    Thursday

    sample input 2
    13/1
    sample output 2
    Input Error
*/

#include <stdio.h>
#include <stdlib.h>

int array_month[12]={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
char ErrorOrNot(int m, int d, char s);
int main(){
    int month, day, sum=0, weekday;
    char slash, error;
    scanf("%d%c%d", &month, &slash, &day);

    error = ErrorOrNot(month, day, slash);
    if(error=='e'){
        printf("Input Error\n");
    }
    else{
        for(int i=0; i<month-1; i++){
            sum += array_month[i];
        }
        sum +=day;
        weekday = sum%7;
        switch(weekday){
            case 4:
                printf("Monday\n");
                break;
            case 5:
                printf("Tuesday\n");
                break;
            case 6:
                printf("Wednesday\n");
                break;
            case 0:
                printf("Thursday\n");
                break;
            case 1:
                printf("Friday\n");
                break;
            case 2:
                printf("Saturday\n");
                break;
            case 3:
                printf("Sunday\n");
                break;
        }
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

