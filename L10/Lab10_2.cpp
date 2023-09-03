/*
Description: 
    Write a C++ program that asks the user to input today's date and his/her birthday.
    Your program simply outputs them according to some format, then it checks whether they are equal.
    If they are, output "Happy birthday\n".

    The main function is given.
    All you need to do is implementing the output member function.

Sample: 
    sample input 1
    10/14
    10/14
    sample output 1
    Today is Oct 14
    Your birthday is Oct 14
    Happy birthday!

    sample input 2
    6/29
    3/27
    sample output 2
    Today is Jun 29
    Your birthday is Mar 27
*/

#include <iostream>
using namespace std;

class DayOfYear{
public:
    void output(); //member func. prototype
    int month;
    int day;
};
void DayOfYear::output(){
    char mon[12][5] = {"Jan ", "Feb ", "Mar ", "Apr ", "May ", "Jun ", "Jul ", "Aug ", "Sep ", "Oct ", "Nov ", "Dec "};
    cout << mon[month - 1] << day <<endl;
}

int main() {
    DayOfYear today, birthday;
    char dummy;
    cin >> today.month >> dummy >> today.day;
    cin >> birthday.month >> dummy>> birthday.day;

    cout << "Today is ";
    today.output();
    cout << "Your birthday is ";
    birthday.output();
    if (today.month == birthday.month && today.day == birthday.day)
        cout << "Happy birthday!\n";
    return 0;
}