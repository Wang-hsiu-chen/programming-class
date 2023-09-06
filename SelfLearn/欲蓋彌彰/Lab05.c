#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int Sum = 0, target = 0, Cardamount = 0, cardamount = 0, Card_A = 0;
int ChooseCard(), Determine(int);

int ChooseCard(){
    int Cardpoint = 0, Cardvalue = 0;
    Cardpoint = rand() % 13 + 1;
    if(Cardpoint > 10){
        Cardvalue = 10;
    }
    else if(Cardpoint <= 10 && Cardpoint > 1){
        Cardvalue = Cardpoint;
    }
    else if(Cardpoint == 1){
        Card_A += 1;
        Cardvalue = 11;
        /*if(Sum <= 21){
            Cardvalue = 11;
        }
        else if(Sum > 21){
            Cardvalue = 1;
        }*/
    }
    cardamount ++;
    return Cardvalue;
}

int Determine(int sum){
    if(sum > target){
        return 0;
    }
    int cardvalue = ChooseCard();
    sum += cardvalue;
    Sum = sum;
    if(sum > target && sum <= 21){
        return 0;
    }
    else if(sum > target && sum > 21){
        sum = sum - Card_A * 10;
        Card_A = 0;
        Sum = sum;
        if(sum > target)return 0;
        else if(sum == target)return 1;
        else if(sum < target) Determine(sum);
    }
    /*if(sum > target && cardvalue != 11){
        return 0;
    }
    else if(sum > 21 && cardvalue == 11){
        Sum = sum -= 10;
        if(sum > target)return 0;
        else if(sum == target)return 1;
        else if(sum < target) Determine(sum);
    }*/
    /*else if(sum == 21 && target != 21 && cardvalue == 11){

    }*/
    else if(sum == target){
        return 1;
    }
    else if(sum < target){
        Determine(sum);
    }
}

int main(){
    int determine = 0;
    double success = 0.0, fail = 0.0;
    printf("Points Probability #Cards\n");
    for(int i = 4; i <= 21; i++){
        //srand( time(NULL) );
        target = i;
        Cardamount = success = fail = 0;
        for(int j = 0; j < 100000; j++){
            Sum = ChooseCard();
            determine = Determine(Sum);
            if(determine == 0){
                fail += 1;
            }
            else if(determine == 1){
                success += 1;
                Cardamount += cardamount;
            }
            cardamount = Card_A = Sum = determine = 0;
        }
        printf("%3d%11.2f%%%9.2f\n", target, success/1000, Cardamount/success);
    }
}
