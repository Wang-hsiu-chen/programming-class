# Lab10_1 Date_turnto_week
## Description: 
Redo Lab 3-3 using C++. Write a C++ program to input a date in year 2022 and find out which day of the week it is.
As usual, there should be a new line at the end of the output string. 
You should exclude invalid inputs like Lab 3-2, too.
Use 
`cout << "Input Error" << endl;` for outputting all invalid inputs.
To input a date with a slash `10/14`
declare a dummy character and two integers and use cin as follows.

```cpp
char dummy;
int month, day;
cin >> month >> dummy >> day;
```

## Sample: 
- sample input 1

    `10/14`
- sample output 1

    `Friday`

---
- sample input 2

    `13/1`
- sample output 2
    
    `Input Error`