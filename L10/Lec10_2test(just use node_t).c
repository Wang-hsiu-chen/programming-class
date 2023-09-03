#include <stdio.h>
#include <stdlib.h>

struct node{
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

void output(node_t *s) {
    if(s != NULL){
        printf("%d ",s->data);
        output(s->next);
    }
    else{
        printf("no\n");
        return ;
    }
}

void pop(linked_list_t *list_ptr) {
    if(list_ptr->head != NULL){
        printf("%d\n",list_ptr->head->data);
        list_ptr->head = list_ptr->head->next;
        return ;
    }
    else{
        printf("no\n");
        return ;
    }
}

void reverse_output(node_t *s) {
    if (s != NULL) {
        reverse_output(s->next);
        printf("%d ",s->data);
    }
}

void add_node(linked_list_t *list_ptr, int data) {
    node_t *next;
    int inputdata;

    if (list_ptr->head == NULL) {
        list_ptr->head = (struct node*)malloc(sizeof(struct node));
        list_ptr->head->data = data;
        list_ptr->head->next = NULL;
    } else {
        inputdata = data;
        next = list_ptr->head;
        list_ptr->head = (struct node*)malloc(sizeof(struct node));
        list_ptr->head->next = next;
        list_ptr->head->data = inputdata;
    }
}
/*
void add_node(node_t *s, int data) {
    node_t *next;
    int inputdata;
        inputdata = data;
        next = s;
        printf("s:%d ", s);
        s = (node_t*)malloc(sizeof(node_t));
        printf("s:%d ", s);
        s->next = next;
        printf("s->next:%d ", s->next);
        s->data = inputdata;
        printf("data:%d\n", s->data);
}
*/

void free_list(node_t *s) {
    if (s != NULL) {
        free_list(s->next);
        free(s);
    }
}

int main(){
    linked_list_t my_list;
    initialize(&my_list);
    char commend[8] = {}, receive = '1';
    int data, input_size;

    scanf("%d\n", &input_size);
    for(int i = 0; i < input_size; ++i) {
        scanf("%d", &data);
        add_node(&my_list, data);
    }

    output(my_list.head);
    while (receive != '0') {
        scanf("%s", commend);
        switch (commend[0]) {
            case 'p':
                pop(&my_list);
                output(my_list.head);
                break;
            case 'r':
                reverse_output(my_list.head);
                break;
            case 'a':
                scanf("%d", &data);
                add_node(&my_list, data);
                output(my_list.head);
            default :
                receive = '0';
        }
    
    }
    

    //reverse_output(my_list.head);

    free_list(my_list.head);
    return 0;
}
