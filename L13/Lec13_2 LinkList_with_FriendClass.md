# Lec13_2 LinkList_with_FriendClass
## Description
- **Friend Classes**

    A friend class **has access to all private members of another class**. In this exercise, you are going to practice friend classes by re-implementing the linked list structure.

- **What You Need to Do**

    1. Declare a class called `Node` that has two private data members: `data` and `next`.
    2. Declare another class called `Linked_list` that has two private data members: `head` and `tail` and four public member functions: `output()`, `add_node(int)`, `reverse()`, as well as **a default constructor**.
    3. In the class `Node`, declare friend class `Linked_list`;
    4. Implement those four member functions of `Linked_list`, in which the `add_node(int)`function adds a node at the tail.

## Sample
- Input1
    ```
    5
    1 2 3 4 5
    ```
- Output1
    ```
    1 2 3 4 5
    5 4 3 2 1
    ```
---
- Input2
    ```
    9
    3 98 34 9 1 4 8 8 54
    ```
- Output2
    ```
    3 98 34 9 1 4 8 8 54
    54 8 8 4 1 9 34 98 3
    ```

## Reference of linklist in c++:

>[Linked List: 新增資料、刪除資料、反轉](http://alrightchiu.github.io/SecondRound/linked-list-xin-zeng-zi-liao-shan-chu-zi-liao-fan-zhuan.html)