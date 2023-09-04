# Lab12_2 Overloading_input_and output
## Description
- **Overloading `>>` and `<<`**

  Here we are to overload the stream extraction operator `>>` and stream insertion operator `<<` for the Fraction class. 
  Note that it is **not possible to overload them as member functions** for the following reason: 
  > this expression `cout << frac1` will be translated as `cout.operator<<(frac1)`. 
  >So if we want to overload `<<` as a member function, it must be the member function of the class `ostream&` (`cout`'s class). 
  >There is no way we can overload `<<` as one of Fraction's member function! Moreover, we should allow multiple operators like  `cout << x << y;` which will be interpreted as `(cout << x) << y;`   
  >Therefore, the return type must be the same as `cout`'s class. Same arguments also apply to `>>`.

- **What you need to do**

  1. Overload  `>>` and `<<` as friend functions of Fraction. Modify the class definition accordingly.

  2. Main function is given. DO NOT CHANGE MAIN, otherwise your work will not be regarded as correct even if you pass all test cases.  You may get PENALTY POINTS for changing `main()`.

  3. The I/O should be exactly the same as Lab11/Lec 12.

  4. You can use all other member functions from Lab 11/Lec 12. Submit everything including `main()`.

## Given main function
```cpp
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

  cout << '(' << num1 << ") " << oper << " (" << num2 << ") = " << ans << endl;
  return 0;
}
```