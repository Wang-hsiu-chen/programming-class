#include <stdio.h>
#include <stdlib.h>

void inputmap(int m_input, int n_input, char **map_input) {
    for (int i = 0; i < m_input; ++i) {
        scanf("\n");    //吸收掉輸入換行時按下的Enter
        for (int j = 0; j < n_input; ++j) {
            scanf("%c", &*(*(map_input + i) + j));    //巢狀迴圈輸入地圖內容
        }
    }
}


//定義自訂資料型別作為stack儲存正確路徑解的格子點在第幾行與第幾列
typedef struct stack {
    int* headx;    //宣告指標，儲存路徑格子點位在第幾行
    int* heady;    //宣告指標，儲存路徑格子點位在第幾列
    int top;    //宣告變數，儲存最後推入資料的位置，也就是目前資料量
    int max_size;   //宣告變數，儲存stack大小數值
} stack_arr_t;

//初始化stack，設定自訂資料型別包含的資料初始值
void stack_init(stack_arr_t *s, int size) {
    s->headx = (int*)malloc(size * sizeof(int));    //建立stack，儲存路徑格子點'行'位置
    s->heady = (int*)malloc(size * sizeof(int));    //建立stack，儲存路徑格子點'列'位置
    s->top = 0;    //初始設定資料量為0筆
    s->max_size = size;    //定義stack大小為最大可能尋訪步數
}
//釋放stack
void stack_destroy(stack_arr_t *s) {
    free(s->headx);    
    free(s->heady);
}
//輸入stack內容
void push(stack_arr_t *s, int elemx, int elemy) {
    s->headx[s->top] = elemx;   //存入目前在地圖上格子點的第幾行
    s->heady[s->top] = elemy;   //存入目前在地圖上格子點的第幾列
    s->top += 1;    //數據量計算加1
}

//尋訪函式，找出正確路徑解並輸出，如果沒有路徑解則輸出No way
int visitmap(int m_visit, int n_visit, int max, char **map_visit, char **visited) {
    stack_arr_t s;  //宣告一個自訂資料型別
    int locax = 0, locay = m_visit - 1;    //宣告兩個變數儲存目前尋訪的地圖格子點，幾使位置在地圖左下角

    stack_init(&s, max);    //初始化stack
    push(&s, locax, locay);    //將初始位置存入stack
    *(*(visited + locay) + locax) = '1';    //將初始位置標記為已尋訪

    /*
    當目前尋訪位置未到達地圖右上角的終點前，持續尋訪地圖
    起始位置為左下角
    依序檢查右、上、左、下方格子點是否有路而且並未被標記已尋訪而且並未超出地圖範圍
    當上述條件皆成立，則移動到下一個格子點，並執行stack儲存與標記已尋訪等動作
    如果四個方向皆不符條件，則到退回前一個尋訪過的格子點，並且將stack中儲存的最新一個座標刪除，表示此座標點並非正確路徑解
    如果持續不符合條件而不斷刪除stack中座標直到stack中已無資料，則表示此地圖沒有正確路徑解，所以輸出No way
    */
    while (locax < n_visit - 1 || locay > 0) {
        if (locax + 1 >= 0 && *(*(map_visit + locay) + locax + 1) == '0' && *(*(visited + locay) + locax + 1) != '1') {
            locax += 1;     //移動到右方格子點
            push(&s, locax, locay);    //在stack中存入新的格子點位置
            *(*(visited + locay) + locax) = '1';    //將新的格子點位置標記為已尋訪
        } else if (locay - 1 >= 0 && *(*(map_visit + locay - 1) + locax) == '0' && *(*(visited + locay - 1) + locax) != '1') {
            locay -= 1;     //移動到上方格子點
            push(&s, locax, locay);    //在stack中存入新的格子點位置
            *(*(visited + locay) + locax) = '1';    //將新的格子點位置標記為已尋訪
        } else if (locax - 1 >= 0 && *(*(map_visit + locay) + locax - 1) == '0' && *(*(visited + locay) + locax - 1) != '1') {
            locax -= 1;     //移動到左方格子點
            push(&s, locax, locay);    //在stack中存入新的格子點位置
            *(*(visited + locay) + locax) = '1';    //將新的格子點位置標記為已尋訪
        } else if (locay + 1 < m_visit && *(*(map_visit + locay + 1) + locax) == '0' && *(*(visited + locay + 1) + locax) != '1') {
            locay += 1;     //移動到下方格子點
            push(&s, locax, locay);    //在stack中存入新的格子點位置
            *(*(visited + locay) + locax) = '1';    //將新的格子點位置標記為已尋訪
        } else {
            if (s.top > 1) {
                s.top -= 1;
                locax = s.headx[s.top - 1];
                locay = s.heady[s.top - 1];
            } else if (s.top <= 1) {
                printf("No way\n");
                return 0;
            }
        }
    }

    //將正確路徑解轉換成直角座標點進行輸出
    printf("(%d,%d)", s.headx[0] + 1, m_visit - s.heady[0]);
    for (int j = 1; j < s.top; ++j) {
        printf("->(%d,%d)", s.headx[j] + 1, m_visit - s.heady[j]);
    }
    printf("\n");

    stack_destroy(&s);
    return 0;
}

int main(int argc, char *argv)
{
    int m, n;       //宣告列數n, 行數m
    scanf("%d%d", &m, &n);  //輸入列數與行數
    int max_size = m * n;   //得到地圖所有格子數，也就是最大可能尋訪步數
    char **map = (char**)malloc(m * sizeof(char*));    //宣告字元型態陣列作為被尋訪地圖
    char **visited_location = (char**)malloc(m * sizeof(char*));    //宣告字元型態陣列儲存已尋訪格子
    for (int i = 0; i < m; ++i) {
        *(map + i) = (char*)malloc(n * sizeof(char));   //宣告字元型態陣列作為被尋訪地圖
        *(visited_location + i) = (char*)calloc(' ', n * sizeof(char));  //宣告字元型態陣列標記已尋訪格子，需賦予初始值為空白字元表示皆未尋訪
    }

    inputmap(m, n, map);    //呼叫輸入函式，輸入地圖內容

    visitmap(m, n, max_size, map, visited_location);    //呼叫尋訪函式，丟入地圖行、列數、總格子數、地圖陣列、標記用陣列
    free(visited_location);    //完成尋訪，釋放儲存陣列

    free(map);  //完成尋訪，釋放地圖陣列
      
    return 0;
}