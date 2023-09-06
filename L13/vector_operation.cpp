//Example for L13
#include <iostream>
#include <cstdlib>
#include <math.h>

using namespace std;

class Vector {
public:
    Vector operator +(Vector vec2);
    Vector operator -(Vector vec2);
    Vector operator *(Vector vec2);
    Vector operator /(Vector vec2);
    friend istream& operator>>( istream& ins, Vector &vec );
    friend ostream& operator<<( ostream& outs , const Vector &vec );


private:
    int vec_x, vec_y;
};

Vector Vector:: operator +(Vector vec2){
    vec2.vec_x = vec_x + vec2.vec_x;
    vec2.vec_y = vec_y + vec2.vec_y;
    return vec2;
}

Vector Vector::operator -(Vector vec2){
    vec2.vec_x = vec_x - vec2.vec_x;
    vec2.vec_y = vec_y - vec2.vec_y;
    return vec2;
}
Vector Vector::operator *(Vector vec2){
    vec2.vec_x = vec_x *  vec2.vec_x;
    vec2.vec_y = vec_y * vec2.vec_y;
    return vec2;
}
Vector Vector::operator /(Vector vec2){
    vec2.vec_x = vec_x / vec2.vec_x;
    vec2.vec_y = vec_y / vec2.vec_y;
    if (!vec2.vec_x || !vec2.vec_y) {
        cout <<"dividing by zero\n";
        exit(0);
    }
    return vec2;
}

ostream& operator <<(ostream& outs, const Vector &vec){
    outs << " [" << vec.vec_x << ", " << vec.vec_y << "] ";
    return outs;
}

istream& operator >>(istream& ins, Vector &vec){
    char comma;
    ins >> vec.vec_x >> comma >> vec.vec_y;
    return ins;
}

int main() {
    Vector num1, num2, ans;
    char oper;
    cin >> num1 >> oper >> num2;

    switch (oper) {
      case '+':
        ans = num1 + num2; break;
      case '-':
        ans = num1 - num2; break;
      case '*':
        ans = num1 * num2; break;
      case '/':
        ans = num1 / num2; break;
    }

    cout << num1 << oper << num2 << '='
         << ans << endl;
    return 0;
}
