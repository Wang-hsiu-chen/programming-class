#include <iostream>
#if defined(_WIN64) || defined(__MSDOS__)
   #define SPADE   "\xE2\x99\xA0"
   #define CLUB    "\xE2\x99\xA3"
   #define HEART   "\xE2\x99\xA5"
   #define DIAMOND "\xE2\x99\xA6"
#else
   #define SPADE   "\x06"
   #define CLUB    "\x05"
   #define HEART   "\x03"
   #define DIAMOND "\x04"
#endif

using namespace std;

class Card{
protected:

public:
    char num;
    char simble;
    friend istream &operator>>(istream &s, Card &a);
    friend ostream &operator<<(ostream &s, Card a);
};

istream &operator>>(istream &s, Card &a){
    s >> a.simble >> a.num;
    return s;
}
ostream &operator<<(ostream &s, Card a){
    switch(a.simble) {
    case 'S':
        cout << SPADE;break;
    case 'C':
        cout << CLUB;break;
    case 'H':
        cout << HEART;break;
    case 'D':
        cout << DIAMOND;break;
    }
    if (a.num == 'T') {
        s<<"10";
    }
    else s << a.num;
    return s;
}
template <class T>
class Linked_list;

template <class T>
class Node {
    friend class Linked_list<T>;
private:
    T data;
    Node<T> *next;
};

template <class T>
class Linked_list {
public:
    void output();
    void add_node(T newdata);
    void reverse();
    Linked_list();

private:
    Node<T> *head;
    Node<T> *tail;
};

template <class T>
void Linked_list<T>::output() {
    if (head == NULL) {
        return;
    }
    tail = head;
    cout << tail->data;
    tail = tail->next;
    while (tail != NULL) {                 // Traversal
        cout << " "<<tail->data;
        tail = tail->next;
    }
    cout << endl;
    return ;
}
/*Moreover, when you implement their member function, 
the corresponding class name should be specialized as follows.*/
template <class T>
void Linked_list<T>::add_node(T newdata){
    if (head == NULL || tail == NULL) {
        head = new Node<T>[sizeof(Node<T>)];
        head->data.num = newdata.num;
        head->data.simble = newdata.simble;
        head->next = NULL;
        tail = head;
    } else {
        tail->next = new Node<T>[sizeof(Node<T>)];
        tail->next->data.num = newdata.num;
        tail->next->data.simble = newdata.simble;
        tail->next->next = NULL;
        tail = tail->next;
    }
    return ;
}
template <class T>
void Linked_list<T>::reverse() {
    if (head == NULL || head->next == NULL) {
        return;
    }
    Node<T> *previous = NULL,
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
template <class T>
Linked_list<T>::Linked_list() {
    head = NULL;
    tail = NULL;
}

int main(){
    Linked_list<Card> my_list;

    Card data;
    int input_size;
    /* when you add a node, you add it at the tail */

    cin >> input_size;

    for(int i=0; i < input_size; ++i) {
        cin >> data;
        my_list.add_node(data);
    }
    my_list.output();
    my_list.reverse();
    my_list.output();

    return 0;
}

