#include <stdio.h>
#include <string.h>
#include <string.h>

int main(void) {
    int e2, e3;
    double e1, ans1;
    char e4[100]={};
    scanf("%lf %d%d%s", &e1, &e2, &e3, &e4);
    //printf("%g %d %d %s", e1, e2, e3, e4);

    ans1 = e2*e1;
    printf("%.1f", ans1);
    for(int i=0; i<e3; i++){
        printf("%s", e4);
    }
    printf("\n");
}
