#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

typedef struct node node_t;

typedef struct linked_list {
    node_t *head;
    node_t *tail;
} linked_list_t;

void initialize(linked_list_t *list_ptr) {
    list_ptr->head = NULL;
    list_ptr->tail = NULL;
}

void output_list(linked_list_t *ptr_list) {
    ptr_list->tail = ptr_list->head;
    printf("%d", ptr_list->tail->data);
    ptr_list->tail = ptr_list->tail->next;
    do{
        printf(" %d", ptr_list->tail->data);
        ptr_list->tail = ptr_list->tail->next;
    }while(ptr_list->tail != ptr_list->head);
    printf("\n");
    ptr_list->tail = ptr_list->tail->next;
}

void add_node(linked_list_t *list_ptr, int data) {
    if (list_ptr->head == NULL || list_ptr->tail == NULL) {
        list_ptr->head = (struct node*)malloc(sizeof(struct node));
        list_ptr->head->data = data;
        list_ptr->head->next = list_ptr->head;
        list_ptr->tail = list_ptr->head;
    }
    else {
        list_ptr->tail->next = (struct node*)malloc(sizeof(struct node));
        list_ptr->tail->next->data = data;
        list_ptr->tail->next->next = list_ptr->head;
        list_ptr->tail = list_ptr->tail->next;
    }
}

int main() {
    linked_list_t my_list;
    initialize(&my_list);
    node_t *middle_ptr;

    int data, input_size;
    /* when you add a node, you add it at the tail */

    scanf("%d\n", &input_size);
    for(int i=0; i < input_size; ++i) {
        scanf("%d", &data);
        add_node(&my_list, data);
    }
    output_list(&my_list);
    output_list(&my_list);
    return 0;
}
