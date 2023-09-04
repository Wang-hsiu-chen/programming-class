# Lec12_2 OperatorOverloading_as_FriendFunction
## Description
- **Operator Overloading as Friend Functions**

  In Lec 12-1, we practiced the Fraction class with friend functions. The function calls are already much better like `add(ans, num)`. 
  We want to further increase the readability of `main()`. We want to apply **operator overloading** so that expressions like `num1 + num2` will work. 
  There are two ways to do that. We can either **overload** the arithmetic operators either as member functions or **friend functions**. 
  In this project, we are to overload them as friend functions. In Lab 12-1, you are to practice the other one.

- **What you need to do**

  1. Re-write `add()`, `sub()`, `mul()`, and `div()` as operators using friend functions in in the class definition (in "fraction.h")

  2. Implement these operators in "fraction.cpp". Note that they are friend functions, so they **do not belong to the Fraction class**. The class name and the scope resolution operator `Fraction::` are not necessary.

  3. Main function is given. **DO NOT CHANGE MAIN**, otherwise your work will not be regarded as correct even if you pass all test cases.  You may get PENALTY POINTS for changing `main()`.

  4. You can use all other member functions from Lab 11. Submit everything including `main()`.

## Given main function
```cpp
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
```