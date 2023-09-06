# Lab14_2 GenericLinkList, ClassTemplates
## Description
- **Generic Linked List / Class Templates**

    You are going to **re-implement Lec 13-2's Linked_list and Node using class templates**. Your Node should be able to store any class with << and >> overloaded. Same as Lab 14-1, we will test your `Linked_list()` with `Card` class. You can take a look at the [class templates](https://www.programiz.com/cpp-programming/class-templates) or [類別樣板](https://www.rocksaying.tw/archives/3641717.html).

    In your **Node template definition**, you need to **declare its friend class**, but at that time your Linked_list template has not been declared yet. You should **follow the style below to avoid problems**.
    ```cpp
    template <class T>
    class Linked_list;

    template <class T>
    class Node {
        friend class Linked_list<T>;
    private:
        // ...
    };

    template <class T>
    class Linked_list {
    public:
        // your member functions
        
    private:
        Node<T> *head;
        Node<T> *tail;
    };
    ```
    Moreover, when you implement their member function, **the corresponding class name** should be specialized **as follows**.
    ```cpp
    template <class T>
    void Linked_list<T>::add_node(T newdata){
        // ...
    }
    ```
    Note that the function name is NOT specialized, it'll be automatically added by the C++ preprocessor. In particular, **constructors should be written as follows**.
    ```cpp
    template <class T>
    Linked_list<T>::Linked_list() {
        // ...
    }
    ```
    Also, in Linked_list's member function implementation, all **pointers to Node** **should be specialized** as well.
    ```cpp
    Node<T> *ptr = head;
    ```
    In short, **except for** the **template** names and **(member) function** names, everything **else** should **be specialized!**

## Sample
- Input
    ```
    7
    S2 CT HA SK H3 D5 CQ
    ```
- Output
    ```
    ♠2 ♣10 ♥A ♠K ♥3 ♦5 ♣Q
    ♣Q ♦5 ♥3 ♠K ♥A ♣10 ♠2
    ```

## Given main function
```cpp
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
```