#include <stdio.h>
#include <stdlib.h>

/* DO NOT CHANGE STRUCT */
struct node{
    int data;
    struct node *next;
};
typedef struct node node_t;

typedef struct linked_list{
    node_t *head;
} linked_list_t;

void add_node(linked_list_t *list_ptr, int data){
    if(list_ptr->head == NULL){
        list_ptr->head = (struct node*)malloc(sizeof(struct node));
        /*
        list_ptr->head->next = (struct node*)malloc(sizeof(struct node));
        list_ptr->head->next->next = (struct node*)malloc(sizeof(struct node));
        list_ptr->head->next->next->next = (struct node*)malloc(sizeof(struct node));
        list_ptr->head->next->next->next->next = (struct node*)malloc(sizeof(struct node));
        */
        list_ptr->head->data = 6 - data;
        list_ptr->head->next = NULL;
    }
    else{
        void *temp, *newhead;
        //temp = NULL;
        if (list_ptr->head->next == NULL) {
            list_ptr->head->next = (struct node*)malloc(sizeof(struct node));
            list_ptr->head->next->data = 6 - data;
            list_ptr->head->next->next = NULL;
        }
        else if (list_ptr->head->next->next == NULL) {
            list_ptr->head->next->next = (struct node*)malloc(sizeof(struct node));
            list_ptr->head->next->next->data = 6 - data;
            list_ptr->head->next->next->next = NULL;
        }
        else if (list_ptr->head->next->next->next == NULL) {
            list_ptr->head->next->next->next = (struct node*)malloc(sizeof(struct node));
            list_ptr->head->next->next->next->data = 6 - data;
            list_ptr->head->next->next->next->next = NULL;
        }
        else if (list_ptr->head->next->next->next->next == NULL) {
            list_ptr->head->next->next->next->next = (struct node*)malloc(sizeof(struct node));
            list_ptr->head->next->next->next->next->data = 6 - data;
            list_ptr->head->next->next->next->next->next = NULL;
        }


        /*
        list_ptr->tail->next = (struct node*)malloc(sizeof(struct node));
        list_ptr->tail->next->data = data;
        list_ptr->tail->next->next = NULL;
        list_ptr->tail = list_ptr->tail->next;
        */
    }
}

void output_list(linked_list_t *ptr_list){
    int i = 0;
    ptr_list->head;
    printf("%d", ptr_list->head->data);
    ptr_list->head = ptr_list->head->next;
    do{
        printf(" %d", ptr_list->head->data);
        ptr_list->head = ptr_list->head->next;
        i++;
    }while(ptr_list->head != NULL);
    printf("\n");
}



/* DO NOT CHANGE MAIN */

int main(){
    linked_list_t my_list;
    my_list.head = NULL;
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
