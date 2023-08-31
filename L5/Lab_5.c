/*
Description: 

Sample: 
    sample input 1
    2011/04/07
    2008/07/11
    sample output 1
    2008/7/11 is 1000 day(s) earlier

    sample input 2
    2021/02/29
    2011/02/28
    sample output 2
    Invalid input 1
*/

#include<stdio.h>

int is_a_leap_year(int y){
    if(y%4 == 0 && y % 100 != 0 || y % 400 == 0){
        return 1;
    }
    else return 0;
}

int input_check(int Year, int Month, int Day, int Is_a_Leap_Year){
    int array[13] = {0,31,29,31,30,31,30,31,31,30,31,30,31};
    if(Is_a_Leap_Year == 1 && Month == 2 && Day > 29){
        return 1;
    }
    else if(Is_a_Leap_Year == 0 && Month == 2 && Day > 28){
        return 1;
    }
    for(int i=1; i<13; i++){
        if(Month == array[i] && Day > array[i]){
            return 1;
        }
    }
    if(Month > 12 || Month < 1 || Day < 1){
        return 1;
    }
    else{
        return 0;
    }
}

int change_one_two(int *ptry1, int *ptrm1, int *ptrd1, int *ptry2, int *ptrm2, int *ptrd2){
    int temp = 0;
    temp = *ptry2;
    *ptry2 = *ptry1;
    *ptry1 = temp;
    temp = *ptrm2;
    *ptrm2 = *ptrm1;
    *ptrm1 = temp;
    temp = *ptrd2;
    *ptrd2 = *ptrd1;
    *ptrd1 = temp;
}

void compare_days(int y1, int m1, int d1, int y2, int m2, int d2){
    int array[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
    int temp = 0, dd1 = 0, dd2 = 0, dd3 = 0, LeapYearNum = 0;
    if(y1 < y2){
        change_one_two(&y1, &m1, &d1, &y2, &m2, &d2);
    }
    else if(y1 == y2 && m1 < m2){
        change_one_two(&y1, &m1, &d1, &y2, &m2, &d2);
    }
    else if(y1 == y2 && m1 == m2 && d1 < d2){
        change_one_two(&y1, &m1, &d1, &y2, &m2, &d2);
    }
    for(int i = y2+1; i<y1; i++){
        if(is_a_leap_year(i) == 1){
            LeapYearNum +=1;
        }
    }
    if(m2 <= 2 && is_a_leap_year(y2)){
        LeapYearNum +=1;
    }
    if(m1 > 2 && is_a_leap_year(y1)){
        LeapYearNum +=1;
    }

    for(int i=m2; i<=12; i++){
        dd1 += array[i];
    }
    dd1 -=d2;
    dd2 = (y1 - y2 - 1) * 365 + LeapYearNum;
    for(int i = 1; i < m1; i++){
        dd3 += array[i];
    }
    dd3 += d1;

    printf("%d/%d/%d is %d day(s) earlier\n", y2, m2, d2, dd1+dd2+dd3);
}

int main() {
    int year1 =0, year2=0, month1 = 0, month2 = 0, day1 =0, day2 = 0;

    scanf("%d/%d/%d",&year1, &month1, &day1);
    if( input_check(year1, month1, day1, is_a_leap_year(year1)) ){
        printf("Invalid input 1\n");
        return 0;
    }

    scanf("%d/%d/%d",&year2, &month2, &day2);
    if( input_check(year2, month2, day2, is_a_leap_year(year2)) ){
        printf("Invalid input 2\n");
        return 0;
    }

    compare_days(year1, month1, day1, year2, month2, day2);

    return 0;
}


