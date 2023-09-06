#include <stdio.h>
#include <string.h>

int main(void){
    float a, b, c, d, e;
    float ans;
    scanf("%f", &a);
    scanf("%f", &b);
    scanf("%f\n", &c);
    scanf("%f", &d);
    scanf("%f", &e);

    if(d == 0){
        ans = a/b*e + c;
        printf("%.3f\n", ans);
    }
    else if(d != 0){
        ans = (e-c)*b/a;
        printf("%.3f\n", ans);
    }
}
