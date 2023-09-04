/*
    See the markdown attached.
*/

#include <iostream>
#include <cstdlib>
#include <math.h>

using namespace std;

class Fraction {
public:
    void input();
    void display();
    Fraction operator +(Fraction frac2);
    Fraction operator -(Fraction frac2);
    Fraction operator *(Fraction frac2);
    Fraction operator /(Fraction frac2);
    friend istream& operator>>( istream& ins, Fraction &arg );
    friend ostream& operator<<( ostream& outs , const Fraction &arg );


private:
    void reduce();
    int numer, denom;
};


int gcd(int u, int v) {
    int t;
    while (u > 0){
        if (u < v) {
            t = u;
            u = v;
            v = t;
        }
        u = u-v;
    }
    return v;
}

void Fraction::input(){
    char slash;
    cin>>numer>>slash>>denom;
    if (denom == 0) {
        cout <<"dividing by zero\n";
        exit(0);
    }
}
void Fraction::reduce(){
    int v = gcd(sqrt(numer * numer), sqrt(denom * denom));
    numer /= v;
    denom /= v;
}
void Fraction::display(){
    cout<<numer<<"/"<<denom;
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

ostream& operator <<(ostream& outs, const Fraction &arg){
    outs << arg.numer << "/" << arg.denom;
    return outs;
}

istream& operator >>(istream& ins, Fraction &arg ){
    char oper;
    ins >> arg.numer >>oper >> arg.denom;
    return ins;
}

int main() {
    Fraction num1, num2, ans;
    char oper;
    cin >> num1 >> oper >> num2;

    switch (oper) {
      case '+':
        ans = num1 + num2; break;
      case '-':
        ans = num1 - num2; break;
      case '*':
        ans = num1 * num2; break;
      case '/':
        ans = num1 / num2; break;
    }

    cout << '(' << num1 << ") " << oper << " (" << num2 << ") = "
         << ans << endl;
    return 0;
}
