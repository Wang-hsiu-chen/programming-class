/*
Description: 


Sample: 
    sample input 1

    sample output 1


    sample input 2

    sample output 2

*/

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Shape{
public:
    virtual void output() = 0;
    virtual double area() = 0; 

protected:
    int location_x;
    int location_y;
    string color;
};

class Rectangle: public Shape{
public:
    Rectangle(double a, double b, int x, int y, string str){
        width = a;
        height = b;
        location_x = x;
        location_y = y;
        color = str;
    }
    void output(){
        cout<< color <<" Rectangle at ("<< location_x <<","<< location_y <<")"<<endl;
    }
    double area(){
        return width * height;
    }
protected:
    double width;
    double height;
};
class Triangle: public Shape{
public:
    Triangle(double a, double b, int x, int y, string str){
        base = a;
        height = b;
        location_x = x;
        location_y = y;
        color = str;
    }
    void output(){
        cout<< color <<" Triangle at ("<< location_x <<","<< location_y <<")"<<endl;
    }
    double area(){
        return base * height / 2;
    }
protected:
    double base;
    double height;
};
class Circle: public Shape{
public:
    Circle(double a, int x, int y, string str){
        radius = a;
        location_x = x;
        location_y = y;
        color = str;
    }
    void output(){
        cout<< color <<" Circle at ("<< location_x <<","<< location_y <<")"<<endl;
    }
    double area(){
        return M_PI * radius * radius;
    }
protected:
    double radius;
};
// Do NOT CHANGE main()! You may get penalty points.
int main() {
    double a, b;
    int x, y; // location of the shape
    string str;
    cin >> a >> b >> x >> y >> str;
    Rectangle rec(a, b, x, y, str);

    cin >> a >> b >> x >> y >> str;
    Triangle tri(a, b, x, y, str);
    
    cin >> a >> x >> y >> str;
    Circle cir(a, x, y, str);
    
    // polymorphism using pointer
    Shape *ptr = &rec;
    ptr->output();
    cout << ptr->area() << endl;
    ptr = &tri;
    ptr->output();
    cout << ptr->area() << endl;
    // polymorphism using reference
    Shape &s1 = cir;
    s1.output();
    cout << s1.area() << endl;
    
    return 0;
}