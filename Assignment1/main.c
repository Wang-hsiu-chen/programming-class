#include <stdio.h>
#include <stdlib.h>

void inputmap(int M, int N, char **MAP) {
    for (int i = 0; i < M; ++i) {
        scanf("\n");
        for (int j = 0; j < N; ++j) {
            scanf("%c", &*(*(MAP + i) + j));
        }
    }
    printf("inputcheck:\n");
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            printf("%c ", *(*(MAP + i) + j));
        }
        printf("\n");
    }
}


typedef struct stack {
    int *headX;
    int *headY;
    int top;
    int max_size;
} stack_arr_t;
void stack_init(stack_arr_t *s, int size) {
    s->headX = (int*)malloc(size * sizeof(int));
    s->headY = (int*)malloc(size * sizeof(int));
    s->top = 0;
    s->max_size = size;
}
void stack_destroy(stack_arr_t *s) {
    free(s->headX);
    free(s->headY);
}
void push(stack_arr_t *s, int elemx, int elemy) {
    s->headX[s->top] = elemx;
    s->headY[s->top] = elemy;
    s->top += 1;
}


int visitmap(int M, int N, int MAX, char **MAP, char **VISITED) {
    stack_arr_t s;
    int locaX = 0, locaY = M - 1, i = 1;

    stack_init(&s, MAX);
    push(&s, locaX, locaY);
    *(*(VISITED + locaY) + locaX) = '1';

    while (locaX < N - 1 || locaY > 0) {
        /*printf("step %d", i);
        i ++;
        if(locaX + 1 < N)printf("%c,",*(*(VISITED + locaY) + locaX + 1));
        if(locaY - 1 >= 0)printf("%c,",*(*(VISITED + locaY - 1) + locaX));
        if(locaX - 1 >= 0)printf("%c,",*(*(VISITED + locaY) + locaX - 1));
        if(locaY + 1 < M)printf("%c",*(*(VISITED + locaY + 1) + locaX));
        */
        if (locaX + 1 >= 0 && *(*(MAP + locaY) + locaX + 1) == '0' && *(*(VISITED + locaY) + locaX + 1) != '1') {
            locaX += 1;
            push(&s, locaX, locaY);
            *(*(VISITED + locaY) + locaX) = '1';
            printf("r");
        }
        else if (locaY - 1 >= 0 && *(*(MAP + locaY - 1) + locaX) == '0' && *(*(VISITED + locaY - 1) + locaX) != '1') {
            locaY -= 1;
            push(&s, locaX, locaY);
            *(*(VISITED + locaY) + locaX) = '1';
            printf("u");
        }
        else if (locaX - 1 >= 0 && *(*(MAP + locaY) + locaX - 1) == '0' && *(*(VISITED + locaY) + locaX - 1) != '1') {
            locaX -= 1;
            push(&s, locaX, locaY);
            *(*(VISITED + locaY) + locaX) = '1';
            printf("l");
        }
        else if (locaY + 1 < M && *(*(MAP + locaY + 1) + locaX) == '0' && *(*(VISITED + locaY + 1) + locaX) != '1') {
            locaY += 1;
            push(&s, locaX, locaY);
            *(*(VISITED + locaY) + locaX) = '1';
            printf("d");
        }
        else {
            if (s.top > 1) {
                s.top -= 1;
                locaX = s.headX[s.top - 1];
                locaY = s.headY[s.top - 1];
                printf("n");
            }
            else if (s.top <= 1) {
                printf("No way\n");
                return 0;
            }
        }
        printf("(%d, %d)\n", locaX, locaY);
    }

    printf("(%d,%d)", s.headX[0] + 1, M - s.headY[0]);
    for (int j = 1; j < s.top; ++j) {
        printf("->(%d,%d)", s.headX[j] + 1, M - s.headY[j]);
    }
    printf("\n");
}

int main()
{
    int m, n;
    scanf("%d%d", &m, &n);
    int max_size = m * n;
    char **map = (char**)malloc(m * sizeof(char*));
    char **visitedlocation = (char**)malloc(m * sizeof(char*));

    for(int i = 0; i < m; ++i){
        *(map + i) = (char*)malloc(n * sizeof(char));
        *(visitedlocation + i) = (char*)calloc(' ', n * sizeof(char));
    }

    inputmap(m, n, map);

    visitmap(m, n, max_size, map, visitedlocation);

    return 0;
}

/*
#include <stdio.h>
#include <stdlib.h>

void inputmap(int M, int N, char **MAP) {
    for (int i = 0; i < M; ++i) {
        scanf("\n");
        for (int j = 0; j < N; ++j) {
            scanf("%c", &*(*(MAP + i) + j));
        }
    }
}


typedef struct stack {
    int *headX;
    int *headY;
    int top;
    int max_size;
} stack_arr_t;

void stack_init(stack_arr_t *s, int size) {
    s->headX = (int*)malloc(size * sizeof(int));
    s->headY = (int*)malloc(size * sizeof(int));
    s->top = 0;
    s->max_size = size;
}

void stack_destroy(stack_arr_t *s) {
    free(s->headX);
    free(s->headY);
}

void push(stack_arr_t *s, int elemx, int elemy) {
    s->headX[s->top] = elemx;
    s->headY[s->top] = elemy;
    s->top += 1;
}


int visitmap(int M, int N, int MAX, char **MAP, char **VISITED) {
    stack_arr_t s;
    int locaX = 0, locaY = M - 1;

    stack_init(&s, MAX);
    push(&s, locaX, locaY);
    *(*(VISITED + locaY) + locaX) = '1';

    while (locaX < N - 1 || locaY > 0) {
        if (locaX + 1 >= 0 && *(*(MAP + locaY) + locaX + 1) == '0' && *(*(VISITED + locaY) + locaX + 1) != '1') {
            locaX += 1;
            push(&s, locaX, locaY);
            *(*(VISITED + locaY) + locaX) = '1';
        }
        else if (locaY - 1 >= 0 && *(*(MAP + locaY - 1) + locaX) == '0' && *(*(VISITED + locaY - 1) + locaX) != '1') {
            locaY -= 1;
            push(&s, locaX, locaY);
            *(*(VISITED + locaY) + locaX) = '1';
        }
        else if (locaX - 1 >= 0 && *(*(MAP + locaY) + locaX - 1) == '0' && *(*(VISITED + locaY) + locaX - 1) != '1') {
            locaX -= 1;
            push(&s, locaX, locaY);
            *(*(VISITED + locaY) + locaX) = '1';
        }
        else if (locaY + 1 < M && *(*(MAP + locaY + 1) + locaX) == '0' && *(*(VISITED + locaY + 1) + locaX) != '1') {
            locaY += 1;
            push(&s, locaX, locaY);
            *(*(VISITED + locaY) + locaX) = '1';
        }
        else {
            if (s.top > 1) {
                s.top -= 1;
                locaX = s.headX[s.top - 1];
                locaY = s.headY[s.top - 1];
            }
            else if (s.top <= 1) {
                printf("No way\n");
                return 0;
            }
        }
    }

    printf("(%d,%d)", s.headX[0] + 1, M - s.headY[0]);
    for (int j = 1; j < s.top; ++j) {
        printf("->(%d,%d)", s.headX[j] + 1, M - s.headY[j]);
    }
    printf("\n");
}

int main()
{
    int m, n;
    scanf("%d%d", &m, &n);
    int max_size = m * n;
    char **map = (char**)malloc(m * sizeof(char*));
    char **visitedlocation = (char**)malloc(m * sizeof(char*));

    for(int i = 0; i < m; ++i){
        *(map + i) = (char*)malloc(n * sizeof(char));
        *(visitedlocation + i) = (char*)calloc(' ', n * sizeof(char));
    }

    inputmap(m, n, map);

    visitmap(m, n, max_size, map, visitedlocation);

    return 0;
}
*/
