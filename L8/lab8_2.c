/*
Description: 

Sample: 
    sample input 1
    5
    5 4 7 2 9
    sample output 1
    5 4 7 2 9

    sample input 2
    10
    98 5 4 7 93 2 9 7 76 9
    sample output 2
    98 5 4 7 93 2 9 7 76 9
*/

#include <stdio.h>
#include <stdlib.h>

/* DO NOT CHANGE STRUCT */
typedef struct node{
    int data;
    struct node *next;
}node_t;
// typedef struct node node_t;

typedef struct linked_list{
    node_t *head;
    node_t *tail;
} linked_list_t;

void output_list(linked_list_t *ptr_list){
    ptr_list->tail = ptr_list->head;
    printf("%d", ptr_list->tail->data);
    ptr_list->tail = ptr_list->tail->next;
    do{
        printf(" %d", ptr_list->tail->data);
        ptr_list->tail = ptr_list->tail->next;
    }while(ptr_list->tail != NULL);
    printf("\n");
}

void add_node(linked_list_t *list_ptr, int data){
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

/* DO NOT CHANGE MAIN */

int main(){
    linked_list_t my_list;
    my_list.head = NULL;
    my_list.tail = NULL;
    int data, input_size;
    /* when you add a node, you add it at the tail */

    scanf("%d\n", &input_size);
    for(int i=0; i < input_size; ++i){
        scanf("%d", &data);
        add_node(&my_list, data);
    }

    output_list(&my_list);

    return 0;
}
