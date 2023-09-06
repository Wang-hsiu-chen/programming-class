#include <stdio.h>
#include <string.h>

int func1(int s);
int f(int d){
    return 2;
};
int main(void) {
    int input, i=0;
	int binary[4]={};

    scanf("%d", &input);

    func1(input);
	do{
		binary[i] = input%2;
		input = input/2;
		i++;
	}while(input > 0);

	for(int j=3; j>=0; j--){
        printf("%d", binary[j]);
	}
	printf("\n");
    return 0;
}
