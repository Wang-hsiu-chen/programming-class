/*
Description: 
    * Redo Lab 8-1 using class
    * All data members MUST BE PRIVATE
    * Do not change main

Sample: 
    sample input 1
    4
    5
    21 3 4 5 8
    4
    sample output 1
    8 5 4 3
    Stack contains 1 element(s)
    21
    top = 1, max_size = 4

    sample input 2
    4
    5
    21 3 4 5 8
    0
    sample output 2
    Stack contains 5 element(s)
    21 3 4 5 8
    top = 5, max_size = 8
*/

#include <iostream>
#define MAX_NEG -1000000000
using namespace std;

class stack_arr_t {
public:
/*
 * Must include the constructor, dynamic_push, dynamic_pop, and show functions.
 */
    stack_arr_t(int maxsize);
    void dynamic_push(int data);
    int dynamic_pop();
    void show();

private:
/*
 * Data members must be put here !!
 */
    int *head;
    int top = 0;
    int max_size;
};

stack_arr_t::stack_arr_t(int maxsize){
    max_size = maxsize;
    head = new int[maxsize];
}
void stack_arr_t::dynamic_push(int data){
    *(head + top) = data;
    top++;
    if (top == max_size) {
        max_size *= 2;
        int *arr = new int[max_size];
        for (int i = 0; i < max_size/2.0; i ++) {
            *(arr + i) = *(head + i);
        }
        delete [] head;
        head = arr;
    }
}
int stack_arr_t::dynamic_pop(){
    if (top == 0) {
        return MAX_NEG;
    } else if (top > 0) {
        top--;
        int temp;
        temp = *(head + top );
        if (top * 4 < max_size) {
            max_size /= 2;
            int *arr = new int[max_size];
            for(int i = 0; i < max_size/2.0; i ++){
                *(arr + i) = *(head + i);
            }
            delete [] head;
            head = arr;
        }
        return temp;
    }
    return 0;
}
void stack_arr_t::show(){
    if (top == 0) {
        cout<<"Stack empty!\n";
        cout<<"top = "<<top<<", max_size = "<<max_size<<endl;
    } else {
        cout<<"Stack contains "<<top<<" element(s)"<<endl;
        for(int i=0; i< top - 1; ++i) {
            cout<<*(head + i)<<" ";
        }
        cout<<*(head + top - 1)<<endl;
        cout<<"top = "<<top<<", max_size = "<<max_size<<endl;
    }
}

/*
 * Member function definitions should be put here!! Add stack_arr_t:: to their names.
 * Constructor's name must be the same as the class name. Do not specify any return type for the constructor!
 */

int main(){
    int input_size, temp, max_size, pop_size;
    /* input stack's max size */
    cin >> max_size;
    /* constructor will be called here */
    stack_arr_t my_stack(max_size);
    /* input elements to be pushed */
    cin >> input_size;
    int i;
    for(i=0; i<input_size; ++i){
        cin >> temp;
        my_stack.dynamic_push(temp);
    }

    /* input number of elements to be popped */
    cin >> pop_size;
    for(i=0; i < pop_size-1; ++i){
        cout << my_stack.dynamic_pop() << ' ';
    }
    if (0 != pop_size){
        cout << my_stack.dynamic_pop() << endl;
    }

    my_stack.show();

    return 0;
}
