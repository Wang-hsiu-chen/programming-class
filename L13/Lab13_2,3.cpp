//a child class gets protected variables directly.
#include <iostream>
#include <string>

using namespace std;

class Shape{
public:
    Shape(int x, int y, string str){
        location_x = x;
        location_y = y;
        color = str;
    }
    
    void virtual output(){
        cout<<"I'm a Shape\n";
    }

protected:
    int location_x;
    int location_y;
    string color;
};

class Rectangle: public Shape{
public:
    Rectangle(int x = 0, int y = 0, string c = "c"):Shape(x, y, c){}

    void output(){
        cout<<"I'm a Rectangle: location_x = "<< location_x <<", location_y = "<< location_y <<", color = "<< color <<endl;
    }
private:
    int x;
    int y;
    string c;
};
class Triangle: public Shape{
public:
    Triangle(int x = 0, int y = 0, string c = "c"):Shape(x, y, c){}

    void output(){
        cout<<"I'm a Triangle: location_x = "<< location_x <<" , location_y = "<< location_y <<", color = "<< color <<endl;
    }
private:
    int x;
    int y;
    string c;
};


// Do NOT CHANGE main()! You may get penalty points.
int main() {
    int x, y;
    string str;
    cin >> x >> y >> str;
    Rectangle rec(x, y, str);
    cin >> x >> y >> str;
    Triangle  tri(x, y, str);

    rec.output();
    tri.output();


    Shape *p = &rec;
    p->output();
    p = &tri;
    p->output();

    return 0;
}
/*
*/
