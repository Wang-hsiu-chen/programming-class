#include <iostream>
using namespace std;

class DayOfYear{
public:
    DayOfYear(int month, int day){
        monthday = month * 10 + day;
    }
    int get_monthday(){
        return monthday;
    }
protected:
    int monthday;
};
class today: DayOfYear{
public:
    today(int month, int day): DayOfYear(month, day){}

    void output(){
        char mon[12][5] = {"Jan ", "Feb ", "Mar ", "Apr ", "May ", "Jun ", "Jul ", "Aug ", "Sep ", "Oct ", "Nov ", "Dec "};
        cout << mon[monthday / 10 - 1] << monthday % 10 <<endl;
    }
private:
};
class birthday: DayOfYear{
public:
    birthday(int month, int day): DayOfYear(month, day){}

    void output(){
        char mon[12][5] = {"Jan ", "Feb ", "Mar ", "Apr ", "May ", "Jun ", "Jul ", "Aug ", "Sep ", "Oct ", "Nov ", "Dec "};
        cout << mon[monthday / 10 - 1] << monthday % 10 <<endl;
    }

private:
};



int main() {
    int month, day;
    char dummy;
    cin >> month >> dummy >> day;
    today tod(month, day);
    cin >> month >> dummy>> day;
    birthday bir(month, day);

    cout << "Today is ";
    tod.output();
    cout << "Your birthday is ";
    bir.output();

    return 0;
}
