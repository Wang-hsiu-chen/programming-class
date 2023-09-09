#include <stdio.h>
#include <stdlib.h>

void count(int queens,int *cases, int column, int *bottom, int *bottomright, int *bottomleft, int **chessboard) {
  int row = 0;//宣告行變數，每開始一次此函式皆從第一行開始尋訪

  while (++row <= queens) {//當行變數加一小於棋盤行數時
    if (!(bottom[row] + bottomright[row - column] + bottomleft[row + column]) ) {//如果三個陣列皆沒顯示代表不可放皇后的數字1
      chessboard[column][row] = bottom[row] = bottomright[row - column] = bottomleft[row + column] = 1;
      //將棋盤上此位置記為1，三個變數也存入1
      //如果往後檢查bottom[row]為1，表示此行不可再放皇后
      //如果往後檢查bottomright[row - column]為1，表示此時的位置行列變數數值相減和前面列皇后行列變數數值相減值相同，表示在相同的y=-x+k斜線上
      //如果往後檢查bottomleft[row + column]為1，表示此時的位置行列變數數值相加和前面列皇后行列變數數值相加值相同，表示在相同的y=x+k斜線上
      if (column < queens) {//如果列變數還小於棋盤列數
        count(queens, cases, column + 1, bottom, bottomright, bottomleft, chessboard);//將列變數加一，也就是進入下一列，將所需數值丟入函式再次判斷皇后位置
      } else {//如果列變數等於棋盤列數，表示成功跑完棋盤並找出一組解
        *cases += 1;//解法變數加1
        for (int i = 1; i < queens + 1; ++i) {//尋訪列
          for (int j = 1; j < queens + 1; ++j) {//尋訪行
            if (chessboard[i][j] ) {//找到棋盤陣列值為1
              printf("%d ", j);//輸出此時行變數
            }
          }
        }
        //輸出此解各列皇后的行位置
        printf("\n");
      }
      bottom[row] = bottomright[row - column] = bottomleft[row + column] = chessboard[column][row] = 0;
      //清空找到此解法過程中各陣列所存的資料紀錄
      //如果列變數尚未等於棋盤列數，表示沒有跑完棋盤就有皇后沒地方放了，跳出一層遞迴，執行此段程式清空剛才記錄下的錯誤資料，改變上一列的行變數值再次執行
      //如果持續沒有找到姊則持續跳出遞迴至上一列
    }
  }
}

int main(int argc, char *argv) {
  int queens, cases = 0;//宣告皇后數量儲存變數、解法數量儲存變數
  scanf("%d", &queens);//輸入皇后數量

  int *a = (int*) calloc((queens + 1), sizeof(int));//配置大小為行數加一的陣列，第一格不使用
  int *b = (int*) calloc((queens * 2 + 1), sizeof(int));//配置大小為行數加列數加一的陣列，第一格不使用
  int *c = (int*) calloc((queens * 2 + 1), sizeof(int));//配置大小為行數加列數加一的陣列，第一格不使用
  int **chessboard = (int**) calloc((queens + 1), sizeof(int*));//配置二微陣列做棋盤儲存皇后位置，第一格不使用
  for (int i = 0; i < queens + 1; ++i) {
    *(chessboard + i) = (int*) calloc((queens + 1), sizeof(int));
  }

  int *bottom = a, *bottomright = b + queens, *bottomleft = c;//三個陣列分別儲存正下方、右下方、左下方不可放皇后的狀況。將b的位置代換以預留空間，因為row - column可能是負的

  count(queens, &cases, 1, bottom, bottomright, bottomleft, chessboard);//將皇后變數、解法變數的址、三個陣列、棋盤丟入函式判斷第一列的皇后位置
  printf("%d solution(s) for the %d-Queen problem.\n", cases, queens);//輸出解法函數最終結果
  return 0;
}