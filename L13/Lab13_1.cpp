//a child class gets privates variable by using a function that can return these variables.
#include <iostream>
#include <string>

using namespace std;

class shape{
public:
    shape(int x, int y, string str){
        location_x = x;
        location_y = y;
        color = str;
    }
    int get_x(){
        return location_x;
    }
    int get_y(){
        return location_y;
    }
    string get_color(){
        return color;
    }
private:
    int location_x;
    int location_y;
    string color;
};

class Rectangle: shape{
public:
    Rectangle(int x, int y, string c):shape(x, y, c){}

    void output(){
        cout<<"I'm a Rectangle: location_x = "<< get_x() <<", location_y = "<< get_y() <<", color = "<< get_color() <<endl;
    }
private:
};
class Triangle: public shape{
public:
    Triangle(int x = 0, int y = 0, string c = "c"):shape(x, y, c){}

    void output(){
        cout<<"I'm a Triangle: location_x = "<< get_x() <<" , location_y = "<< get_y() <<", color = "<< get_color() <<endl;
    }
private:
};

// Do NOT CHANGE main()! You may get penalty points.
int main() {
    int x, y;
    string str;
    cin >> x >> y >> str;
    Rectangle rec(x, y, str);
    cin >> x >> y >> str;
    Triangle tri(x, y, str);

    rec.output();
    tri.output();

    return 0;
}