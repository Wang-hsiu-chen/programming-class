# Lec12_1 fraction_operation_with_friendfunction
## Description
- **Fraction Class w/ Friend Functions**

  In **Lab 11**, we practiced the **Fraction class**. 
  However, that version is far from perfect. 
  In Lab 11's main function, when we performed arithmetic operations we did things like `ans.add(num2);` This is **ugly** and **asymmetric**. 
  It contradicts to our basic understanding of addition. We want to use `add(ans, num)` instead to reflect the nature of addition as well as other arithmetic operations. 
  The best way to achieve this goal is to use **friend functions**.

- **What you need to do**

  You need to re-implement the four arithmetic functions in fraction.cpp using **friend functions**.
  Declare these 4 arithmetic operations as friend functions in the class definition (from Lab 11's header file).

  Implement these friend functions in "fraction.cpp". Note that they are **not** member functions, so they don't belong to the Fraction class. 
  There is no need to add the class name and the scope resolution operator `Fraction::`
  Main function is given. DO NOT CHANGE MAIN, otherwise your work will not be regarded as correct even if you pass all test cases.  You may get PENALTY POINTS for changing `main()`.

  You can use all other member functions from Lab 11. Submit everything including main().

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
      ans = add(num1, num2); break;
    case '-':
      ans = sub(num1, num2); break;
    case '*':
      ans = mul(num1, num2); break;
    case '/':
      ans = div(num1, num2); break;
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