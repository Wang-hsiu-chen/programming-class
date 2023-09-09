建立陣列：
    建立map array，輸入map array行、列、大小、map array內容(0為路、1為牆)
    建立與map array大小相同的storage array儲存已走過路徑，初始化為空白字元

找路：
    兩個變數儲存目前所在的格子點
    建立stackx, stacky儲存正確路徑兩個座標值，初始化stackx, stacky大小與起始資料量
    當兩個變數點還不等於右上角的終點則持續執行下方判斷
        依序檢查右上左下方的格子點，沒有超出map array(數值介於0和行或列數中間)、不是牆壁(map array內容不等於'1')、沒有走過(此格子點的storage array內容不為1)
            如果此方向的格子點符合則上述三項條件則移到下一格，將新的格子點儲存到stackx, stacky和storage array(將陣列內容存入'1')
            如果都沒有路，則到退回前一個格子點，將錯誤的格子點從stackx, stacky刪除

輸出：
    如果stackx, stacky中的資料被刪光了，表示沒有解，輸出No way
    如果有資料，按照指定格式輸出
