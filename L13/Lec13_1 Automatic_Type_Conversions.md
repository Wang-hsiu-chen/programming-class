# Lec13_1 Automatic_Type_Conversions
## Description
- **Automatic Type Conversions for Fraction Class**
    
    In this lecture, we are going to facilitate the expressions below
    ```
    2/3 + 5.6
    4 + 8/17
    ```
    In which, the first one is the addition of a **Fraction and a double** while the second one is the addition of an **int and a Fraction**. In the first case, we need to convert a Fraction to a double and then perform the addition for double's, while in the second case we convert an int to a Fraction and then perform the addition for Fraction's.

- **What You Need to Do**
    1. Implement a **special member function operator double()** without a returning type (not even void) just like constructors.
    2. Implement a **constructor Fraction(int)** that converts the given int to a Fraction.
    3. Implement a **default constructor Fraction()** that takes no argument.

## Sample
- Input1

    ```
    8/17 + 3.4 ,  5* 6/17
    ```
- Output1
    ```
    (8/17) + (3.4) = 3.87059
    (5) * (6/17) = 30/17
    ```
---
- Input2

    ```
    9/38 / 7.234,18- 634/29
    ```
- Output2
    ```
    (9/38) / (7.234) = 0.0327401
    (18) - (634/29) = -112/29
    ```