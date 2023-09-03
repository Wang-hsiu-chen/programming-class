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

#include <stdio.h>
#include <stdlib.h>

struct node{
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

void output(node_t *s) {
    if (s != NULL) {
        printf("%d ",s->data);
        output(s->next);
    } else {
        printf("\n");
        return ;
    }
    // while (s != NULL) {
    //     printf("%d ",s->data);
    //     s = s->next;
    // }
}

void reverse_output(node_t *s) {
    if(s != NULL){
        reverse_output(s->next);
        printf("%d ",s->data);
    }
}

void add_node(linked_list_t *list_ptr, int data) {
    if(list_ptr->head == NULL || list_ptr->tail == NULL){
        list_ptr->head = (struct node*)malloc(sizeof(struct node));
        list_ptr->head->data = data;
        list_ptr->head->next = NULL;
        list_ptr->tail = list_ptr->head;
    }
    else{
        list_ptr->tail->next = (struct node*)malloc(sizeof(struct node));
        list_ptr->tail->next->data = data;
        list_ptr->tail->next->next = NULL;
        list_ptr->tail = list_ptr->tail->next;
    }
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

int main(){
    linked_list_t my_list;
    initialize(&my_list);

    int data, input_size;

    scanf("%d\n", &input_size);
    for(int i=0; i < input_size; ++i) {
        scanf("%d", &data);
        add_node(&my_list, data);
    }

    output(my_list.head);

    reverse_output(my_list.head);

    free_list(&my_list);
    return 0;
}
