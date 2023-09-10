#include <iostream>
#include <cstdlib>
#include <math.h>
#include <string>

using namespace std;

class Time {
public:
    Time();
    Time(int h, int m, int s);

    friend istream& operator >>(istream& ins, Time &t );
    friend ostream& operator <<(ostream& outs , const Time t );
private:

protected:
    int hour, minit, sec;
};
Time::Time(){
    hour = 0;
    minit = 0;
    sec = 0;
}
Time::Time(int h, int m, int s){
    hour = h;
    minit = m;
    sec = s;
}
istream& operator >>(istream& ins, Time &t ){
    char oper;
    ins >> t.hour >> oper >> t.minit >> oper >> t.sec;
    return ins;
}
ostream& operator <<(ostream& outs, const Time t){
    outs << t.hour << ":" << t.minit << ":" << t.sec;
    return outs;
}

int main()
{
    Time t1, t2(10, 3, 27);
    cout << t1 << endl << t2 << endl;
    cin >> t1;
    cout << t1 << endl;
    return 0;
}
