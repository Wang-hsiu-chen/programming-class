#include <stdio.h>
#include <stdlib.h>

int main(){
    //�ŧi����
    int a = 1, b = 2;
    int *ptr_a = &a, *ptr_b = &b;
    printf("%d %d\n", a, b);
    printf("%d %d\n", &a, &b);
    printf("%d %d\n", ptr_a, ptr_b);
    printf("%d %d\n", *ptr_a, *ptr_b);
    //�h������
    int k = 3, *ptr1 = &k, **ptr2 = &ptr1;
    *ptr1 = *ptr1 + 1;
    printf("%d %d, %d %d, %d %d %d\n", &k, k, ptr1, *ptr1, ptr2, *ptr2, **ptr2);
    //���а}�C
    int array[5] = {1, 2, 3, 4, 5};
    *array = *(array+4);
    for(int i = 0; i < 5; i++){
        printf("%d ", *(array+i));
    }
    printf("\n");
    //�ʺA�t�m�O����
    int N = 5;
    int *ptr_N = (int*)malloc(sizeof(int) * N);
    for(int i = 0; i < 5; i++){
        *(ptr_N + i) = i + 1;
        printf("%d ", *(ptr_N + i));
    }
    printf("\n");
    free(ptr_N);
}
