#include <stdio.h>
#include <stdlib.h>


struct node {
    int data;
    struct node *next;
};

typedef struct node node_t;

typedef struct linked_list {
    node_t *head;

} linked_list_t;

void initialize(linked_list_t *list_ptr) {
    list_ptr->head = NULL;

}

void free_list(linked_list_t *ptr_list) {
    void *temp;
    do{
        temp = ptr_list->head->next;
        free(ptr_list->head);
        ptr_list->head = temp;
    }while(ptr_list->head != NULL);
    free(ptr_list->head);
}



void output_list(linked_list_t *ptr_list) {
    void *originhead;
    originhead = ptr_list->head;
    // printf("%d", ptr_list->head->data);
    do {
        ptr_list->head = ptr_list->head->next;
        printf(" %d", ptr_list->head->data);
    }while (ptr_list->head->next != NULL);
    printf("\n");
    ptr_list->head = originhead;
}

void add_node(linked_list_t *list_ptr, int data) {
    // node_t *next;
    // int inputdata;

    // inputdata = data;
    // next = list_ptr->head;
    // free(list_ptr->head);
    // list_ptr->head = (struct node*)malloc(sizeof(struct node));
    // list_ptr->head->next = next;
    // list_ptr->head->data = inputdata;
    node_t *org = list_ptr->head;
    org = (struct node*)malloc(sizeof(struct node));
    org->data = data;
    org->next = NULL;
}

// void reverse_list(linked_list_t *ptr_list) {
//     void *temphead = ptr_list->head, *tempnext = NULL;

//     do{
//         ptr_list->head = temphead;
//         temphead = ptr_list->head->next;
//         ptr_list->head->next = tempnext;
//         tempnext = ptr_list->head;
//     }while(temphead != NULL);
// }

int main() {
    linked_list_t my_list;
    initialize(&my_list);
    node_t *middle_ptr;

    int data, input_size;
    /* when you add a node, you add it at the tail */

    scanf("%d\n", &input_size);
    for(int i = 0; i < input_size; ++i) {
        scanf("%d", &data);
        add_node(&my_list, data);
    }
    output_list(&my_list);
    // reverse_list(&my_list);
    output_list(&my_list);
    free_list(&my_list);

    return 0;
}
