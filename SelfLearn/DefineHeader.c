#include<stdio.h>
#include<stdlib.h>
#define MAX(x,y) ((x)>(y)?(x):(y)) //����B��l>...:...if�uthen���eif��then����
#define min(x,y) ((x)<(y)?(x):(y)) //���� �����ۭq��ƪ��N��

int a = 100, b = 10, C = 2;
int E(int);
int main(){
    int constant = 0;
    switch(C) //�\��P��ܵ��cif,else if�ۦP
    {
    case 1:
        printf("Max is %d\n", MAX(a,b));
    case 2:
        printf("min is %d\n", min(a,b));
    }
    printf("E(a):%d\n", E(MAX(a,b)));
}

//���󦡽sĶ����
#if MAX(a,b) == a
    #define EMPOWER(x) ((x)*(100))
#endif // MAX

int E(int A){
    printf("EMPOWER:%d, a=%d\n", EMPOWER(A), a);
    return a;
}
