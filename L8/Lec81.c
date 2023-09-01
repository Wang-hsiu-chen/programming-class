/*
Description: 

Sample: 
    sample input 1
    S2 H2 D2 CT S8 HA DJ HK HQ C5
    sample output 1
    S2 H2 D2 C10 S8 HA DJ HK HQ C5
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char suit;
    char face;
} card_t;
/*
 * face's values are 'A', '2',..., 'T', 'J', 'Q', 'K',
 * in which 'T' stands for 10.
 * suit's values are 'S', 'H', 'D', 'C'
*/

void input_card_t(card_t *ptr_card1){
    char t;
    /*if(ptr_card1 == 0){
        scanf("%c%c", &(ptr_card1->suit), &(ptr_card1->face));
    }*/
    {
        scanf("%c%c%c", &(ptr_card1->suit), &(ptr_card1->face), &t); // t is space
    }

}
void output_card_t(card_t *ptr_card1){
    if(ptr_card1->face == 'T'){
        printf("%c%c%c", (ptr_card1->suit), '1', '0');
        //ptr_card1->face = '1';
    }
    else{
        printf("%c%c", (ptr_card1->suit), (ptr_card1->face));
    }
}

int main(){
    card_t card_arr[10];
    for(int i=0; i<10; ++i){
        input_card_t(card_arr + i);
        //scanf(" ");
    }

    for(int i=0; i<9; ++i){
        output_card_t(card_arr + i);
        printf(" ");
    }
    output_card_t(card_arr + 9);
    printf("\n");



    return 0;
}
