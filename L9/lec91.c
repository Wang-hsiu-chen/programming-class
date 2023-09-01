/*
Description: 
    * DO NOT SUBMIT main() !!!
    * submit EVERYTHING ELSE except main()
    * containing the #include directives and struct definition
    
Sample: 
    sample input 1
    8
    1 2 3 4 5 6 7 8
    sample output 1
    mid = 5

    sample input 2
    7
    1 2 3 4 5 6 7
    sample output 2
    mid = 4
*/

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
    printf("%d", ptr_list->head->data);
    ptr_list->head = ptr_list->head->next;
    do{
        printf(" %d", ptr_list->head->data);
        ptr_list->head = ptr_list->head->next;
    }while(ptr_list->head != NULL);
    printf("\n");
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

node_t* find_middle(linked_list_t *list_ptr) {
    int n = 0;
    list_ptr->tail = list_ptr->head;
    do{
        n ++;
        list_ptr->tail = list_ptr->tail->next;
    }while(list_ptr->tail != NULL);
    list_ptr->tail = list_ptr->head;
    for(int i = 0; i < (n/2); i++){
        list_ptr->tail = list_ptr->tail->next;
    }
    return list_ptr->tail;

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
    node_t *middle_ptr;

    int data, input_size;
    /* when you add a node, you add it at the tail */

    scanf("%d\n", &input_size);
    for(int i=0; i < input_size; ++i) {
        scanf("%d", &data);
        add_node(&my_list, data);
    }

    middle_ptr = find_middle(&my_list);
    printf("mid = %d\n", middle_ptr->data);

    free_list(&my_list);

    return 0;
}

