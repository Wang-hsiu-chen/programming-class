/*
Description: 
    * dynamic stack : Please follow our exact rules otherwise you WILL LOSE POINTS
    * dynamic push rule: if the stack is full then double the stack's size
    * dynamic pop rule: after the pop, if the number of elements in stack < (1/4)*max_size, then shrink the stack by half.

Sample: 
    sample input 1
    4
    5
    21 3 4 5 8
    4
    sample output 1
    8 5 4 3
    Stack contains 1 element(s)
    21
    top = 1, max_size = 4

    sample input 2
    4
    5
    21 3 4 5 8
    0
    sample output 2
    Stack contains 5 element(s)
    21 3 4 5 8
    top = 5, max_size = 8
*/

#include <stdio.h>
#include <stdlib.h>
#define MAX_NEG -1000000000

typedef struct stack {
    int *head;
    int top;
    int max_size;
} stack_arr_t;


void stack_init(stack_arr_t *s, int size){
    s->head = (int*)malloc(size*sizeof(int));
    s->top = 0;
    s->max_size = size;
}
void stack_destroy(stack_arr_t *s){
    free(s->head);
}



/* DO NOT CHANGE THIS FUNCTION */

void show_stack(stack_arr_t *s) {
    if(s->top==0){
        printf("Stack empty!\n");
        printf("\ntop = %d, max_size = %d\n", s->top, s->max_size);
    }
    else{
        printf("Stack contains %d element(s)\n", s->top);
        for(int i=0; i< s->top - 1; ++i) {
            printf("%d ", s->head[i]);
        }
        printf("%d\n", s->head[s->top - 1]);
    }

   printf("top = %d, max_size = %d\n", s->top,s->max_size);
}



void dynamic_push(int elem, stack_arr_t *s){
    if(s->top == s->max_size){
        int *arr = (int*) malloc(s->max_size * sizeof(int));
        for(int i = 0; i < s->max_size; i ++){
            arr[i] = s->head[i];
        }
        free(s->head);
        s->max_size *= 2;
        s->head = (int*) malloc(s->max_size * sizeof(int));
        for(int i = 0; i < (s->max_size)/2; i ++){
            s->head[i] = arr[i];
        }
        free(arr);
    }
    s->head[s->top] = elem;
    s->top += 1;
}

int dynamic_pop(stack_arr_t *s){
    //printf("top:%d max:%d\n", s->top, s->max_size);
    if(s->top == 0){
        return MAX_NEG;
    }
    else if(s->top > 0){
        s->top -= 1;
        int temp;
        temp = s->head[s->top];
        if(((s->top))*4 < ((s->max_size))){
            int *arr = (int*) malloc(s->max_size * sizeof(int));
            for(int i = 0; i < s->max_size; i ++){
                arr[i] = s->head[i];
            }
            free(s->head);
            s->max_size /= 2.0;
            s->head = (int*) malloc(s->max_size * sizeof(int));
            for(int i = 0; i < (s->max_size)/2.0; i ++){
                s->head[i] = arr[i];
            }
            free(arr);
        }
        return temp;
    }


}



/*** DO NOT CHANGE MAIN!!! You will lose points if you make any change ***/
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
        dynamic_push(temp, &my_stack);
    }

    /* input number of elements to be popped */
    scanf("\n%d", &pop_size);
    for(i=0; i < pop_size-1; ++i){
        printf("%d ", dynamic_pop(&my_stack));
    }
    if (0 != pop_size){
        printf("%d\n", dynamic_pop(&my_stack));
    }

    show_stack(&my_stack);

    stack_destroy(&my_stack);

    return 0;
}
