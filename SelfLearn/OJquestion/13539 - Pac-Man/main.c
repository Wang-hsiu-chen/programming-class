#include <stdio.h>
#include <stdlib.h>

//���X�D
int main(void){
    int T;
    scanf("%d", &T);
    for(int i=0; i<T; i++){
        w();
    }
}

//���D
int w(void){
    //��J�ƾ�
    int Y, X;
    scanf("%d", &Y);
    scanf("%d", &X);
    printf("X=%d, Y=%d\n", X, Y);
    //��J�a��
    char map[Y][X];
    for(int i=0; i<Y; i++){
        fflush(stdin);
        for(int j=0; j<X; j++){
            scanf("%c", &map[i][j]);
        }
    }
    //�C�L�a�ϽT�{
    printf("map=\n");
    for(int i=0; i<Y; i++){
        for(int j=0; j<X; j++){
            printf("%c", map[i][j]);
        }
        printf("\n");
    }
    //������a�M�ؼ�
    int PacMan[1][2];
    int dot[5][2]={};
    int dotnumber=1;//�ؼ��I�ƶq
    for(int i=0; i<Y; i++){
        for(int j=0; j<X; j++){
            if(map[i][j] == 'o'){
                PacMan[0][0]= j; //PacMan x�y��
                PacMan[0][1]= i; //PacMan y�y��
            }
            if(map[i][j] == '.'){

                dot[dotnumber-1][0] = j;//��dotnumber�ӥؼ��Ix�y��
                dot[dotnumber-1][1] = i;//��dotnumber�ӥؼ��Iy�y��
                dotnumber++;
            }
        }
    }
    //�C�L�T�{
    printf(" %d, %d\n", PacMan[0][0], PacMan[0][1]);
    for(int i=0; i<5; i++){
        printf("x=%d, y=%d\n", dot[i][0], dot[i][1]);
    }

    int n = 1;
    /*
    for(int i=0; i<n; i++){
        if()
    }
    for(int i=-n; i<=n; i++){
        for(int j=-n; j<=n; j++){
            if()
        }
    }
    */
    return 0;
}
