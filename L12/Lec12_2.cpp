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
    friend Fraction operator +(Fraction frac1, Fraction frac2);
    friend Fraction operator -(Fraction frac1, Fraction frac2);
    friend Fraction operator *(Fraction frac1, Fraction frac2);
    friend Fraction operator /(Fraction frac1, Fraction frac2);

private:
    void reduce();
    int numer, denom;
};


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

Fraction operator +(Fraction frac1, Fraction frac2){
    frac1.numer = frac1.numer * frac2.denom + frac2.numer * frac1.denom;
    frac1.denom = frac1.denom * frac2.denom;
    if (frac1.denom == 0) {
        cout <<"dividing by zero\n";
        exit(0);
    }
    frac1.reduce();
    return frac1;
}

Fraction operator -(Fraction frac1, Fraction frac2){
    frac1.numer = frac1.numer * frac2.denom - frac2.numer * frac1.denom;
    frac1.denom = frac1.denom * frac2.denom;
    if (frac1.denom == 0) {
        cout <<"dividing by zero\n";
        exit(0);
    }
    frac1.reduce();
    return frac1;
}
Fraction operator *(Fraction frac1, Fraction frac2){
    frac1.numer = frac1.numer *  frac2.numer;
    frac1.denom = frac1.denom * frac2.denom;
    if (frac1.denom == 0) {
        cout <<"dividing by zero\n";
        exit(0);
    }
    frac1.reduce();
    return frac1;
}
Fraction operator /(Fraction frac1, Fraction frac2){
    frac1.numer = frac1.numer * frac2.denom;
    frac1.denom = frac1.denom * frac2.numer;
    if (frac1.denom == 0) {
        cout <<"dividing by zero\n";
        exit(0);
    }
    frac1.reduce();
    return frac1;
}

int main() {
    Fraction num1, num2, ans;
    char oper;
    num1.input();
    cin >> oper;
    num2.input();

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

    // display result
    cout << '(';
    num1.display();
    cout << ") "  << oper << " (";
    num2.display();
    cout << ") = ";
    ans.display();
    cout << endl;

    return 0;
}
