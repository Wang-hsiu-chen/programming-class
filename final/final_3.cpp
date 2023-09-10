#include <iostream>

using namespace std;

class Time {
public:
    Time(int h, int m, int s, int g){
        hour = h;
        minit = m;
        sec = s;
        opera = '+';
        global = g;
    }
    void virtual output(){
        cout<<"I'm a Shape\n";
    }

    friend istream& operator >>(istream& ins, Time &t);
private:

protected:
    int hour, minit, sec, global;
    char opera;
};

class GlobalTime: public Time{
public:
    GlobalTime(int h = 0, int m = 0, int s = 0, int g = 0):Time(h, m, s, g){}

    void output(){
        cout<< hour << ":" << minit << ":" << sec << opera << global;
    }

private:
    int h, n, s, g;
protected:

};

istream& operator >>(istream& ins, Time &t){
    char oper;
    ins >> t.hour >> oper >> t.minit >> oper >> t.sec >> t.opera >> t.global;
    return ins;
}
int main()
{
    GlobalTime gt1(10, 3,27, 3), gt2;
    cin >> gt2;
    Time &t1 = gt1;
    t1.output();
    cout << endl;
    Time &t2 = gt2;
    t2.output();
    cout << endl;
    return 0;
}
