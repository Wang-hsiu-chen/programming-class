/*
Description: Templates and Generic Programing
    You are going to implement a simple function GetMax that returns the bigger object of two. 
    It works for any types/class that can be compared by a > or < operator. 
    Check out function templates for its syntax.

Sample: 
    sample input 1
    4 53 2.2 993.548 oh my!
    sample output 1
    53
    993.548
    oh

*/

#include <iostream>
#include <string>

using namespace std;

template <typename T>
T GetMax(T para1, T para2) {
    return (para1 >= para2)?para1 : para2;
}

int main () { // DO NOT CHANGE MAIN!!
    int i, j;
    double l, m;
    string s1, s2;
    cin >> i >> j >> l >> m >> s1 >> s2;
    cout << GetMax(i, j) << endl << GetMax(l, m) << endl
         << GetMax<string>(s1, s2) << endl;
    return 0;
}