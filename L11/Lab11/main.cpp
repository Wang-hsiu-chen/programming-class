/*
https://drive.google.com/file/d/1rqzs0rbYyO2wrwLmn_UXTavlLbKaSOJc/view?usp=share_link
*/

#include "function.h"
// fraction.h and fraction.cpp contain the definitions of
// fraction class
#include <iostream>

using namespace std;

int main() {
  Fraction num1, num2, ans;
  char oper;
  num1.input();
  cin >> oper;
  num2.input();
  ans = num1;

  switch (oper) {
    case '+':
      ans.add(num2); break;
    case '-':
      ans.sub(num2); break;
    case '*':
      ans.mul(num2); break;
    case '/':
      ans.div(num2); break;
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
