/*
Description: 
    Implement the Merge operation. Read this first

    >http://homepages.math.uic.edu/~leon/cs-mcs401-r07/handouts/mergesort.pdf   (English)
    >https://alrightchiu.github.io/SecondRound/comparison-sort-merge-sorthe-bing-pai-xu-fa.html  (Chinese)

    Ignore the Mergesort for now. Just focus on Merge.
    Do not use any sorting algorithm to implement this function. You will get no points for that.
    Your I/O format should be adjusted accordingly according to what we explained in the class (or what's said in the videoclip).

Sample: 
    sample input 1
    5
    4 19 23 38 56
    6
    1 5 38 42 59 63
    sample output 1
    11
    1 4 5 19 23 38 38 42 56 59 63
    
*/

#include <stdio.h>
#include <stdlib.h>

int main(){
    int N, M, i = 0, j = 0;
    scanf("%d\n", &N);
    int *arr_L = (int*) malloc(N * sizeof(int));
    for (int i = 0; i < N; i ++) {
        scanf("%d", &arr_L[i]);
    }
    scanf("%d\n", &M);
    int *arr_R = (int*) malloc(M * sizeof(int));
    for (int i = 0; i < M; i ++) {
        scanf("%d", &arr_R[i]);
    }
    int *A = (int*) malloc((N + M) * sizeof(int));

    printf("%d\n", (N + M));

    for (int k = 0; k < (N + M); k ++) {
        if (arr_L[i] <= arr_R[j] && arr_L[i] != 0 && i < N && j < M) {
            A[k] = arr_L[i];
            i++;
        }
        else if (arr_L[i] > arr_R[j] && arr_L[i] != 0 && i < N && j < M) {
            A[k] = arr_R[j];
            j++;
        }

        else if (i >= N) {
            A[k] = arr_R[j];
            j++;
        }
        else if (j >= M) {
            A[k] = arr_L[i];
            i++;
        }

        if (k < N + M - 1) {
            printf("%d ", A[k]);
        }
        else if (k == N + M - 1) {
            printf("%d", A[k]);
        }
    }
    printf("\n");
}
