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

    printf("�п�J�r�G");
    scanf("%s", &input);
    scanf("%s", &input1);
    printf("�A��J���r�Ginput=%s, input1=%s", input,input1);

    int a;
	char ch;
	printf("�п�J�@�Ӿ��:");
	scanf("%d", &a);
	fflush(stdin);//����a����J�ɫ��U��space or enter�Q�O���b�Ȧs�̤F�A�n�Φ��禡����
	printf("�п�J�@�Ӧr��:");
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
%c�G�H�r���覡��X
%d�G10 �i���ƿ�X
%o�G�H 8 �i���Ƥ覡��X
%u�G�L����ƿ�X
%x�B%X�G�N��ƥH 16 �i��覡��X
%f�G�B�I�ƿ�X
%e�B%E�G�ϥά�ǰO����ܯB�I��
%g�B%G�G�B�I�ƿ�X�A�� %f �� %e�]%f �� %E�^�A�ݭ��Ӫ�ܺ�²
%%�G��� %
%s�G�r���X
%lu�Glong unsigned ���A�����
%p�G���Ы��A
%[a-b]:�����J��
%9s:����r���Ƥp��9
%.*s\n", 5,:�u��ܶ}�Y5�Ӧr��
%*d\n", 1,:�}�Y�ťX�@�r�����
%10s:\n:�]�w�������e��
*/
