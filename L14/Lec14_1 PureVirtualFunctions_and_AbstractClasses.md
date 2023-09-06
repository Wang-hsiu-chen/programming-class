# Lec14_1 PureVirtualFunctions_and_AbstractClasses
## Description
- **Pure Virtual Functions & Abstract Classes**

    An **abstract class** is **a class with a virtual function declaration only**, i.e., no function implementation. In the example of Lab 13-3, `Shape` has the virtual function `output()`. In many cases, we actually do not need to use any object of `Shape` class, since we either use `Rectangle` or `Triangle` directly instead of `Shape`. Therefore, we do not need to implement the `output()` function for `Shape`. We can use the following function delcaration
    ```
    virtual void output() = 0;
    ```
    in `Shape`'s class definition. This means there is no function implementation and therefore we cannot define an object of `Shape` class any more. `output()` is a **pure virtual function** and `Shape` is an **abstract class**.

- **What You Need to Do**
1. In the class `Shape`:

    (1) modify `output()` to be a **pure virtual function**. 

    (2) Define another **pure virtual function** `area()` which returns a double.
2. In the class `Rectangle`: 

    (1) Add two **protected** data members: `width` and `height`, both are of type double. 

    (2) Modify all member functions accordingly and implement `area()`.
3. In the class `Triangle`: 

    (1) Add two **protected** data members: `base` and `height`, both are of type double. 

    (2) Modify all member functions accordingly and implement `area()`.
4. Define another derived class `Circle` from `Shape` that has one **protected** data member `radius` of type double and three member functions `output()`, `area()`, and a **constructor**.

## Sample
- Input
    ```
    3.54 2.7 10 7 blue
    8.22 7.14 10 5 black
    7.333 64 3 green
    ```
- Output
    ```
    blue Rectangle at (10,7)
    9.558
    black Triangle at (10,5)
    29.3454
    green Circle at (64,3)
    168.932
    ```