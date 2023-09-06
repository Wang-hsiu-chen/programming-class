# Lab13_1 Inheritance
## Description
- **Basic Inheritance**
- **What You Need to Do**

    Define a class Shape that contains two data members of int type: `location_x` and `location_y`. It also contains another data member color of string class (`#include <string>` for using the string class).
    Shape contains 3 member functions `get_x()`, `get_y()`, `get_color()`, and a constructor `Shape(int, int, string)`.
    Define another two derived classes `Rectangle` and `Triangle` that inherit from Shape. Both of them have a constructor with 3 arguments (int, int, string). Note that in these constructors you need to **use the C++ initializer list to call Shape's constructor**, otherwise only the default constructor of Shape will be called.
    Both Rectangle and Triangle have a member function `output()`.

## Sample
- sample input
    ```
    10 7 blue
    10 5 black
    ```
- sample output
    ```
    I'm a Rectangle: location_x = 10, location_y = 7, color = blue
    I'm a Triangle: location_x = 10 , location_y = 5, color = black
    ```
# Lab13_2 ProtectedMember
## Description
- **Protected Members & Static Binding**

    In 13-1, `Rectangle` and `Triangle` do nothave access to Shape's private members and we have to use access functions `get_x()`, `get_y()`, `get_color()`. This makes our program **quite messy**. On one hand, a derived class do not have access to the private members of its base class, which makes programming cumbersome. On the other hand, granting **a derived class access to their private members is not a good idea** either (since we can always access the private members of any class by simply inheriting it!) How to solve this problem? **Using the protected members**.

- **What You Need to Do**
1. Modify the class Shape by changing its privated data members to protected data members.
2. We can **remove** all 3 member functions `get_x()`, `get_y()`, `get_color()`. Keep the constructor Shape(int, int, string).
3. Define another member function `output()` in `Shape` that simply outputs `"I'm a shape\n"`.

## Sample
- Input
    ```
    10 7 blue
    10 5 black
    ```
- Output
    ```
    I'm a Rectangle: location_x = 10, location_y = 7, color = blue
    I'm a Triangle: location_x = 10 , location_y = 5, color = black
    I'm a Shape
    I'm a Shape
    ```

# Lab13_3 DynamicBinding
## Description
- **Virtual Functions & Dynamic Binding**
- **What You Need to Do**

    In the class Shape, add keyword virtual to the `output()` function as follows: `virtual void output();` This **allows the `output()` function of `Shape` to be overridden by the `output()` of `Rectangle` and `Triangle` in dynamic binding** (when it's called from <font color=orange>reference</font> or a pointer).

    The main function is the same as Lab 13-2.

- Input
    ```
    10 7 blue
    10 5 black
    ```
- Output
    ```
    I'm a Rectangle: location_x = 10, location_y = 7, color = blue
    I'm a Triangle: location_x = 10 , location_y = 5, color = black
    I'm a Rectangle: location_x = 10, location_y = 7, color = blue
    I'm a Triangle: location_x = 10 , location_y = 5, color = black
    ```
