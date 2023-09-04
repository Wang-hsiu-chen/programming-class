#ifndef FUNCTION_H
#define FUNCTION_H

class Fraction {
public:
    void input();
    void display();
    void add(Fraction frac2);
    void sub(Fraction frac2);
    void mul(Fraction frac2);
    void div(Fraction frac2);

private:
    void reduce();
    int numer, denom;
};

#endif // FUNCTION_H_INCLUDED
