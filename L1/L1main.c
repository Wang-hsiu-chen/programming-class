#include <stdio.h>
#include <string.h>
#include <string.h>

int main(void) {
    char a[2] = {'2', '3'};
    int sum=0;
    float num1=1.1, num2=1.1111;
    double num3=2.2, num4=2.2222;
    sum = a[0] - '0' + a[1] - '0';

 /*   char input[10], input1[10];

    printf("請輸入字：");
    scanf("%s", &input);
    scanf("%s", &input1);
    printf("你輸入的字：input=%s, input1=%s", input,input1);

    int a;
	char ch;
	printf("請輸入一個整數:");
	scanf("%d", &a);
	fflush(stdin);//結束a的輸入時按下的space or enter被記錄在暫存裡了，要用此函式消除
	printf("請輸入一個字元:");
	scanf("%c", &ch);
	printf("a=%d, c1=%c", a, ch);
*/
/*
    for(int i=0; i<9; i++){
        printf("%.*s\n",i, "11111111111");
    }
    printf("%d\n", sum);
    return 0;
*/
    printf("1.f: %f\n", num1);
    printf("1.f: %f\n", num4);
    printf("1.g: %e\n", num1);
    printf("1.g: %E\n", num2);
}

/*
%c：以字元方式輸出
%d：10 進位整數輸出
%o：以 8 進位整數方式輸出
%u：無號整數輸出
%x、%X：將整數以 16 進位方式輸出
%f：浮點數輸出
%e、%E：使用科學記號顯示浮點數
%g、%G：浮點數輸出，取 %f 或 %e（%f 或 %E），看哪個表示精簡
%%：顯示 %
%s：字串輸出
%lu：long unsigned 型態的整數
%p：指標型態
%[a-b]:限制輸入值
%9s:限制字元數小於9
%.*s\n", 5,:只顯示開頭5個字元
%*d\n", 1,:開頭空出一字元欄位
%10s:\n:設定佔據欄位寬度
*/
