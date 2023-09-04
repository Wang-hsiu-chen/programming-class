#include <iostream>
#include <stack>

using namespace std;

int main(){
    int maxsize, inputsize, popsize, temp, i;
    stack<int> stack_arr, stack_temp;
    cin >> inputsize;
    for (i = 0; i < inputsize; ++i) {
        cin >> temp;
        stack_arr.push(temp);
    }
    cin >> popsize;
    for (i = 0; i < popsize - 1; ++i) {
        cout << stack_arr.top() << ' ';
        stack_arr.pop();
    }
    if (0 != popsize) {
        cout << stack_arr.top() << endl;
        stack_arr.pop();
    }
    while (stack_arr.size() ) {
        stack_temp.push(stack_arr.top());
        stack_arr.pop();
    }
    cout << "Stack contains " << stack_temp.size() << " element(s)" <<endl;
    while (stack_temp.size() ) {
        stack_arr.push(stack_temp.top());
        cout << stack_temp.top() << ' ';
        stack_temp.pop();
    }
    cout << "\n" << "top = " << stack_arr.top() <<endl;
    
    return 0;
}