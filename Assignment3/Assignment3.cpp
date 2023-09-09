#include <iostream>
#include <string>
#include <cmath>
#include <stack>
#include <sstream>
#include <algorithm>

using namespace std;

class Expression{
public:
    void input();
    int eval();
    stack<double> operand;
    stack<string> oper;

private:
    string str;
    double num = 0, ans = 0;
};
void Expression::input(){
    getline(cin, str);
    str.erase(std::remove_if(str.begin(), str.end(), ::isspace), str.end());
    //cin>>str;
    int len_s = str.size();
    int i = 0, j = 0, len = 0;
    while (i < len_s) {
        if (str[i] >= '0' && str[i] <= '9' || str[i] == '.') {
            if (i > (j + len) && (j + len) >= 0) {
                string str1 = str.substr(j + len, i - (j + len));
                oper.push(str1);
            }
            j = i;
            len = 0;
            while (str[i] >= '0' && str[i] <= '9' || str[i] == '.') {
                i ++;
                len ++;
            }
            string str0 = str.substr(j, len);
            stringstream s1(str0);
            s1 >> num;
            operand.push(num);
        } else {
            i ++;
        }
    }
    return ;
}
int Expression::eval(){
    int i = 0, j = 0;
    /*while (i < operand.size()) {
        printf("%d:%g\n", operand.size(), operand.top());
        operand.pop();
    }
    while (j < oper.size()) {
        if (oper.top() == "+" || oper.top() == ")") {
            printf("%d:%s\n", oper.size(), oper.top());
        }
        oper.pop();
    }*/
    while (operand.size() > 0 && oper.size() > 0) {
        if (oper.top() == "*") {
            double num1 = operand.top();
            operand.pop();
            oper.pop();
            operand.top() = operand.top() * num1;
        } else if (oper.top() == "/") {
            double num1 = operand.top();
            operand.pop();
            oper.pop();
            operand.top() = operand.top() / num1;
        } else {
            operand.pop();
            oper.pop();
        }
    }
    cout << operand.top();
    return 0;
}

int main(){
    Expression exp1;
    exp1.input();
    exp1.eval();
    return 0;
}