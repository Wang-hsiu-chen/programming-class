/*
Reference of linklist in c++:
    http://alrightchiu.github.io/SecondRound/linked-list-xin-zeng-zi-liao-shan-chu-zi-liao-fan-zhuan.html
*/

#include <iostream>
using namespace std;

class Node {
public:
    //Node():data(0),next(0){};
    //Node(int a):data(a),next(0){};
    friend class Linked_list;
private:
    int data;
    Node *next;
};

class Linked_list {
public:
    void output();
    void add_node(int x);
    void reverse();
    Linked_list();
private:
    Node *head;
    Node *tail;
};

Linked_list::Linked_list() {
    head = NULL;
    tail = NULL;
}

void Linked_list::output() {
    if (head == NULL) {                     
        return;
    }
    tail = head;
    //Node *current = head;             
    cout << tail->data;
    tail = tail->next;
    while (tail != NULL) {                 // Traversal
        cout << " "<<tail->data;
        tail = tail->next;
    }
    cout << endl;
}
void Linked_list::add_node(int data) {
    if (head == NULL || tail == NULL) {
        head = (Node*)malloc(sizeof(Node));
        head->data = data;
        head->next = NULL;
        tail = head;
    } else {
        tail->next = (Node*)malloc(sizeof(Node));
        tail->next->data = data;
        tail->next->next = NULL;
        tail = tail->next;
    }
}
void Linked_list::reverse() {
    if (head == NULL || head->next == NULL) {
        // list is empty or list has only one node
        return;
    }
    Node *previous = NULL,
        *current = head,
        *preceding = head->next;
    while (preceding != NULL) {
        current->next = previous;     
        previous = current;          
        current = preceding;        
        preceding = preceding->next; 
    }                               

    current->next = previous;      
    head = current;
}


int main(){
    Linked_list my_list;

    int data, input_size;
    /* when you add a node, you add it at the tail */

    cin >> input_size;

    for(int i = 0; i < input_size; ++i) {
        cin >> data;
        my_list.add_node(data);
    }
    my_list.output();
    my_list.reverse();
    my_list.output();

    return 0;
}

