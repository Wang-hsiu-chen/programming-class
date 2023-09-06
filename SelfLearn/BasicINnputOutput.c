#include<stdio.h>
#include<stdlib.h>

int main(){
    int a = 20, b = 9, m, n;
    double i = 1000.0/7.0, j = 3.14159265358979, k = -1234.1234, l;

    printf("g %g %g %g\n", i, j, k);    //total 6 digit
    printf("lg %lg %lg %lg\n", i, j, k);
    printf(".g %.g %.g %.g\n", i, j, k);//science note
    printf(".lg %.lg %.lg %.lg\n", i, j, k);
    printf(".2g %1.2g %1.2g %1.2g\n", i, j, k);//science note, and first two digit
    printf("10g %10.2g %10.2g %10.2g\n\n", i, j, k);    //10 digit space in total 

    printf("f %f %f %f\n", i, j, k);
    printf(".f %.f %.f %.f\n", i, j, k); // delete numbers after dot
    printf("-f %-f %-f %-f\n", i, j, k);
    printf("lf %lf %lf %lf\n", i, j, k);
    printf(".lf %.lf %.lf %.lf\n\n", i, j, k);

    printf("%3.3d %3.3d %3.3d\n", a, b, a/b);   //total 3 digit, and 3 digit space in total 
    printf("%3d %3d %3d\n\n", a, b, a/b);       //3 digit space in total 

    m = ++a + ++b;
    printf("++Z %d %d %d\n", a, b, m);
    n = a++ + b++;
    printf("Z++ %d %d %d\n", a, b, n);
    return 0;
}
