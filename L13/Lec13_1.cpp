#include <iostream>
#include <cstdlib>
#include <math.h>

using namespace std;

class Fraction {
public:
    void input();
    void display();
    Fraction(int int_y);
    Fraction();
    operator double();
    Fraction operator +(Fraction frac2);
    Fraction operator -(Fraction frac2);
    Fraction operator *(Fraction frac2);
    Fraction operator /(Fraction frac2);
    friend istream& operator>>( istream& ins, Fraction &arg );
    friend ostream& operator<<( ostream& outs , const Fraction arg );

private:
    void reduce();
    int numer, denom;
};
Fraction::Fraction() {
    numer = 0;
    denom = 1;
}
Fraction::Fraction(int int_y) {
    denom = 1;
    numer = int_y;
}

Fraction::operator double() {
    /*double dou_num1 = (static_cast<double>(numer) / static_cast<int>(denom));
    return dou_num1;*/
    return ((double)numer / (double)denom);
}
int gcd(int u, int v) {
    int t;
    while (u > 0){
        if(u < v) {
            t = u;
            u = v;
            v = t;
        }
        u = u-v;
    }
    return v;
}

void Fraction::reduce(){
    int v = gcd(sqrt(numer * numer), sqrt(denom * denom));
    numer /= v;
    denom /= v;
}

Fraction Fraction:: operator +(Fraction frac2){
    frac2.numer = numer * frac2.denom + frac2.numer * denom;
    frac2.denom = denom * frac2.denom;
    if (frac2.denom == 0) {
        cout <<"dividing by zero\n";
        exit(0);
    }
    frac2.reduce();
    return frac2;
}
Fraction Fraction::operator -(Fraction frac2){
    frac2.numer = numer * frac2.denom - frac2.numer * denom;
    frac2.denom = denom * frac2.denom;
    if (frac2.denom == 0) {
        cout <<"dividing by zero\n";
        exit(0);
    }
    frac2.reduce();
    return frac2;
}
Fraction Fraction::operator *(Fraction frac2){
    frac2.numer = numer *  frac2.numer;
    frac2.denom = denom * frac2.denom;
    if (frac2.denom == 0) {
        cout <<"dividing by zero\n";
        exit(0);
    }
    frac2.reduce();
    return frac2;
}
Fraction Fraction::operator /(Fraction frac2){
    int temp;
    temp = numer * frac2.denom;
    frac2.denom = denom * frac2.numer;
    frac2.numer = temp;
    if (frac2.denom == 0) {
        cout <<"dividing by zero\n";
        exit(0);
    }
    frac2.reduce();
    return frac2;
}
ostream& operator <<(ostream& outs, const Fraction arg){
    outs << arg.numer << "/" << arg.denom;
    return outs;
}
istream& operator >>(istream& ins, Fraction &arg ){
    char oper;
    int a, b;
    ins >> arg.numer >>oper >> arg.denom;
    //ins >> a >>oper >> b;
    //arg.numer = a;
    //arg.denom = b;
    return ins;
}

int main() {
    Fraction num1, num2;
    double x;
    int y;
    char oper1, oper2;
    cin >> num1 >> oper1 >> x;
    cin.ignore(1024, ',');
    cin >> y >> oper2 >> num2;

    switch (oper1) {
      case '+':
        cout << '(' << num1 << ") + (" << x << ") = "<< (double)num1 + x << endl; break;
      case '-':
        cout << '(' << num1 << ") - (" << x << ") = "<< (double)num1 - x << endl; break;
      case '*':
        cout << '(' << num1 << ") * (" << x << ") = "<< (double)num1 * x << endl; break;
      case '/':
        cout << '(' << num1 << ") / (" << x << ") = "<< (double)num1 / x << endl; break;
    }

    switch (oper2) {
      case '+':
        cout << '(' << y << ") + (" << num2 << ") = "<< (Fraction)y + num2 << endl; break;
      case '-':
        cout << '(' << y << ") - (" << num2 << ") = "<< (Fraction)y - num2 << endl; break;
      case '*':
        cout << '(' << y << ") * (" << num2 << ") = "<< (Fraction)y * num2 << endl; break;
      case '/':
        cout << '(' << y << ") / (" << num2 << ") = "<< (Fraction)y / num2 << endl; break;
    }
    return 0;
}
