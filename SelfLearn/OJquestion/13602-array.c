#include <stdio.h>
#include <stdlib.h>

int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    int array_n[n], array_m[m], array_nm[n+m];
    for(int i=0; i<n; i++){
        scanf("%d", &array_n[i]);
        array_nm[i] = array_n[i];
    }
    for(int i=0; i<m; i++){
        scanf("%d", &array_m[i]);
        array_nm[n+i] = array_m[i];
    }

    int max = array_nm[0];
    for(int i=0; i<n+m; i++){
        if(array_nm[i]>max){
            max = array_nm[i];
        }
    }
    printf("%d", max);

    return 0;
}


