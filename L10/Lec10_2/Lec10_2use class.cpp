/*
Description: 

Sample: 
    sample input 1
    7
    1 2 3 4 5 6 7
    sample output 1
    1 2 3 4 5 6 7 <- there's a whitespace at the end! 
    7 6 5 4 3 2 1 <- there's a whitespace but no '\n' at the end!
*/

#include <iostream>
using namespace std;

class node{
public:
    friend class linked_list; 
private:
    int data;
    node *next;
};

class linked_list {
public:
    void output();
    void reverse_output();
    void add_node(int data);
    void free_list();
    linked_list();
private:
    node *head;
    node *tail;
};

linked_list ::linked_list() {
    head = NULL;
    tail = NULL;
}

void linked_list ::output() {
    if (tail->next == NULL) {
        tail = head;
    }
    if (tail->next != NULL) {
        cout << tail->data << ' ';
        tail = tail->next;
        if (tail->next == NULL) {
            cout << tail->data <<endl;
            return ;
        }
        output();
    }
}

void linked_list ::reverse_output() {
    if (tail->next == NULL) {
        cout << tail->data << ' ';
        tail = head;
    }
    if (tail->next != NULL) {
        if (tail->next->next == NULL) {
            cout << tail->data << ' ';
            return ;
        }
        int *temp = &tail->data;
        tail = tail->next;
        reverse_output();
        cout << *temp << ' ';
    }
}

void linked_list ::add_node(int data) {
    if(head == NULL || tail == NULL){
        head = new node[sizeof(node)];
        head->data = data;
        head->next = NULL;
        tail = head;
    }
    else{
        tail->next = new node[sizeof(node)];
        tail->next->data = data;
        tail->next->next = NULL;
        tail = tail->next;
    }
}
void linked_list::free_list() {
    node *temp;
    while (head->next != NULL) {
        temp = head->next;
        free(head);
        head = temp;
    }
    free(head);
}

int main(){
    linked_list my_list;

    int data, input_size;

    cin >> input_size;
    for(int i = 0; i < input_size; ++i) {
        cin >> data;
        my_list.add_node(data);
    }
    my_list.output();

    my_list.reverse_output();

    my_list.free_list();
    return 0;
}
