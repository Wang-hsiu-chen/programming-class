#include <stdio.h>
#include <stdlib.h>

//有幾題
int main(void){
    int T;
    scanf("%d", &T);
    for(int i=0; i<T; i++){
        w();
    }
}

//解題
int w(void){
    //輸入數據
    int Y, X;
    scanf("%d", &Y);
    scanf("%d", &X);
    printf("X=%d, Y=%d\n", X, Y);
    //輸入地圖
    char map[Y][X];
    for(int i=0; i<Y; i++){
        fflush(stdin);
        for(int j=0; j<X; j++){
            scanf("%c", &map[i][j]);
        }
    }
    //列印地圖確認
    printf("map=\n");
    for(int i=0; i<Y; i++){
        for(int j=0; j<X; j++){
            printf("%c", map[i][j]);
        }
        printf("\n");
    }
    //抓取玩家和目標
    int PacMan[1][2];
    int dot[5][2]={};
    int dotnumber=1;//目標點數量
    for(int i=0; i<Y; i++){
        for(int j=0; j<X; j++){
            if(map[i][j] == 'o'){
                PacMan[0][0]= j; //PacMan x座標
                PacMan[0][1]= i; //PacMan y座標
            }
            if(map[i][j] == '.'){

                dot[dotnumber-1][0] = j;//第dotnumber個目標點x座標
                dot[dotnumber-1][1] = i;//第dotnumber個目標點y座標
                dotnumber++;
            }
        }
    }
    //列印確認
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
