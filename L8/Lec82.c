/*
Description: 

Sample: 
    sample input 1
    6
    6
    1 2 3 4 5 6
    4
    sample output 1
    6 5 4 3
    Stack contains 2 element(s)
    1 2
    top = 2, max_size = 6
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_NEG -1000000000

typedef struct stack {
    int *head;
    int top;
    int max_size;
} stack_arr_t;


void stack_init(stack_arr_t *s, int size) {
    s->head = (int*)malloc(size*sizeof(int));
    s->top = 0;
    s->max_size = size;
    printf("top:%d\n", s->top);
}

void stack_destroy(stack_arr_t *s) {
    free(s->head);
}

void push(int elem, stack_arr_t *s) {
    s->head[s->top] = elem;
    s->top += 1;
}

int pop(stack_arr_t *s) {
    if(s->top == 0){
        return MAX_NEG;
    }
    else if(s->top > 0){
        s->top -= 1;
        return s->head[s->top];
    }

}



void show_stack(stack_arr_t *s) {
    if(s->top == 0){
        printf("Stack empty!\n");
        printf("top = %d, max_size = %d\n", s->top, s->max_size);
    }
    else if(s->top > 0){
        printf("Stack contains %d element(s)\n", s->top);
        for(int i = 0; i < s->top; i++){
            if(i == 0){
                printf("%d", s->head[i]);
            }
            else{
                printf(" %d", s->head[i]);
            }
        }
        printf("\ntop = %d, max_size = %d\n", s->top, s->max_size);
    }
}
/*  do not change main() !!!  */
int main(){
    stack_arr_t my_stack;

    int input_size, temp, max_size, pop_size;

    /* input stack's max size */
    scanf("%d", &max_size);
    stack_init(&my_stack, max_size);

    /* input elements to be pushed */
    scanf("\n%d", &input_size);
    int i;
    for(i=0; i<input_size; ++i){
        scanf("\n%d", &temp);
        push(temp, &my_stack);
    }

    /* input number of elements to be popped */
    scanf("\n%d", &pop_size);
    for(i=0; i < pop_size-1; ++i){
        printf("%d ", pop(&my_stack));
    }
    if (0 != pop_size){
        printf("%d\n", pop(&my_stack));
    }

    show_stack(&my_stack);

    stack_destroy(&my_stack);

    return 0;
}
