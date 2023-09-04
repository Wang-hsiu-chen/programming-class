# Lab12_1 OperatorOverloading_as_MemberFunction
## Description
- **Operator Overloading as Member Functions**

  In Lec 12-2, we practiced the operator overloading as friend functions. Now we are to **re-overload them as member functions**.

- **What you need to do**

  1. Re-overload `operator+()`, `operator-()`, `operator*()`, and `operator/()`  member functions in the class definition (in "fraction.h")

  2. Implement these operators in "fraction.cpp". Note that they are member functions, so **they belong to the Fraction class**. The class name and the scope resolution operator `Fraction::` are absolutely necessary.

  3. *Use the main function in Lec 12-2*. **DO NOT CHANGE MAIN** and you should overload them as member functions only. otherwise your work will not be regarded as correct even if you pass all test cases.  You may get PENALTY POINTS for doing those.

  4. I/O testcases are the same as Lab11/Lec12.

  5. You can use all other member functions from Lab 11/Lec 12. Submit everything including `main()`.