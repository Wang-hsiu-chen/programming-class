#include "function.h"
#include <iostream>
#include <cstdlib>
#include <math.h>

using namespace std;

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
void Fraction::display(){
    cout<<numer<<"/"<<denom;
}
void Fraction::add(Fraction frac2){
    numer = numer * frac2.denom + frac2.numer * denom;
    denom = denom * frac2.denom;
    if (denom == 0) {
        cout <<"dividing by zero\n";
        exit(0);
    }
    reduce();
}
void Fraction::sub(Fraction frac2){
    numer = numer * frac2.denom - frac2.numer * denom;
    denom = denom * frac2.denom;
    if (denom == 0) {
        cout <<"dividing by zero\n";
        exit(0);
    }
    reduce();
}
void Fraction::mul(Fraction frac2){
    numer = numer *  frac2.numer;
    denom = denom * frac2.denom;
    if (denom == 0) {
        cout <<"dividing by zero\n";
        exit(0);
    }
    reduce();
}
void Fraction::div(Fraction frac2){
    numer = numer * frac2.denom;
    denom = denom * frac2.numer;
    if (denom == 0) {
        cout <<"dividing by zero\n";
        exit(0);
    }
    reduce();
}
void Fraction::reduce(){
    int v = gcd(sqrt(numer * numer), sqrt(denom * denom));
    numer /= v;
    denom /= v;
}
