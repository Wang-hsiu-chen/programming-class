/*
Description: 
    * Implement MergeSort() using recursion.
    * Please use the recursion method described in this lab to do this. 
      Otherwise you may lose points even PENALTY POINTS.
    * 請用上課教的遞迴方式寫，否則不但不得分還可能會被倒扣分數！！

Sample: 
    sample input 1
    10
    67 85 3 2 87 9 56 8 19 48
    sample output 1
    2 3 8 9 19 48 56 67 85 87

    sample input 2
    14
    32 3 33 123 83 9 2 199 92 923 87 4 436 65
    sample output 2
    2 3 4 9 32 33 65 83 87 92 123 199 436 923
*/

#include <stdio.h>
#include <stdlib.h>

int merge(int *a, int size_1, int size_2){
    //printf("size_1:%d size_2:%d\n", size_1, size_2);
    int size;
    size = size_1 + size_2;

    int A[size], i = 0, j = 0;
    for (int k = 0; k < size; k++) {
        if (a[i] <= a[size_1 + j] && i < size_1 && j < size_2) {
            A[k] = a[i];
            i++;
        }
        else if (a[i] > a[size_1 + j] && i < size_1 && j < size_2) {
            A[k] = a[size_1 + j];
            j++;
        }

        else if (i == size_1) {
            A[k] = a[size_1 + j];
            j++;
        }
        else if (j == size_2) {
            A[k] = a[i];
            i++;
        }
    }
    for (int i = 0; i < size; i++) {
        a[i] = A[i];
    }
}

void MergeSort(int *arr, int begin_pos, int end_pos){
    //printf("begin:%d end:%d\n", begin_pos, end_pos);
    if (end_pos - begin_pos > 0) {
        MergeSort(arr, begin_pos, (end_pos - begin_pos + 1) / 2 + begin_pos - 1);
        MergeSort(arr, (end_pos - begin_pos + 1) / 2 + begin_pos, end_pos);
    }
    if ((end_pos - begin_pos + 1) / 2 > 0 && (end_pos - begin_pos + 1) - (end_pos - begin_pos + 1) / 2 > 0) {
        merge(arr + begin_pos, (end_pos - begin_pos + 1) / 2, (end_pos - begin_pos + 1) - (end_pos - begin_pos + 1) / 2);
    }
}


int main(){
    int *a,  size;

    //  input
    scanf("%d", &size);
    a = (int*) malloc(sizeof(int)*size);
        for (int i=0; i< size; i++) {
            scanf("%d", a+i);
        }

    MergeSort(a, 0, size-1);

    //  output

    for (int i=0; i< size-1; i++)
        printf("%d ", a[i]);

    printf("%d\n", a[size-1]);
    return 0;
}
