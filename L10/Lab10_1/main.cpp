/*
    See the markdown attached.
*/

#include <iostream>
#include <stdlib.h>

using namespace std;

int array_month[12]={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
char LegalDate(int m, int d, char s);
int main(){
    int month, day, sum=0, weekday;
    char slash, error;
    cin >> month >> slash >> day;

    error = LegalDate(month, day, slash);
    if (error == '1') {
        cout << "Input Error\n";
    }
    else {
        for (int i = 0; i < month - 1; i++) {
            sum += array_month[i];
        }
        sum += day;
        weekday = sum % 7;
        switch(weekday){
            case 3:
                cout << "Monday\n";
                break;
            case 4:
                cout << "Tuesday\n";
                break;
            case 5:
                cout << "Wednesday\n";
                break;
            case 6:
                cout << "Thursday\n";
                break;
            case 0:
                cout << "Friday\n";
                break;
            case 1:
                cout << "Saturday\n";
                break;
            case 2:
                cout << "Sunday\n";
                break;
        }
    }
}

char LegalDate(int m, int d, char s){
    char error = '0';
    for (int i = 0; i < 12; i++) {
        if (m == i + 1 && d > array_month[i]) {
            error = '1';
        }
        if (m > 12) {
            error = '1';
        }
        if (s != '/') {
            error = '1';
        }
    }
    return error;
}
