/*
Description: Generic MergeSort
    You are going to re-implement Lab 9's MergeSort() function using function templates. 
    Your MergeSort() should work on all types with < and <= overloaded. 
    We will test your MergeSort() with Card type from Lec 8-1. Re-implement Card as a class with the following member functions so that it will work with our given main(): < , <= , << , >>, and (possibly) constructors. You should use the following macro so that your output will show the suit symbols.

Sample: 
    sample input 1
    7
    S2 CT HA SK H3 D5 CQ
    sample output 1
    ♠2 ♥3 ♦5 ♣10 ♣Q ♠K ♥A

*/

#include <iostream>
#if defined(_WIN32) || defined(__MSDOS__)
   #define SPADE   "\xE2\x99\xA0"
   #define CLUB    "\xE2\x99\xA3"
   #define HEART   "\xE2\x99\xA5"
   #define DIAMOND "\xE2\x99\xA6"
#else
   #define SPADE   "\x06"
   #define CLUB    "\x05"
   #define HEART   "\x03"
   #define DIAMOND "\x04"
#endif
//If you include the above macro, then you can show a spade symbol by adding

using namespace std;

class Card{
private:
    char num;
    char simble;
public:
    friend int operator <=(Card a, Card b);
    friend int operator >(Card a, Card b);
    friend istream &operator>>(istream &s, Card &a);
    friend ostream &operator<<(ostream &s, Card a);
};
template <class T>
int merge(T *a, int size_1, int size_2){
    //printf("size_1:%d size_2:%d\n", size_1, size_2);
    int size;
    size = size_1+size_2;

    T *A = new T[size];
    int i = 0, j = 0;
    for(int k = 0; k < size; k++){
        if(a[i] <= a[size_1 + j] && i < size_1 && j < size_2){
            A[k] = a[i];
            i++;
        }
        else if(a[i] > a[size_1 + j] && i < size_1 && j < size_2){
            A[k] = a[size_1 + j];
            j++;
        }

        else if(i == size_1){
            A[k] = a[size_1 + j];
            j++;
        }
        else if(j == size_2){
            A[k] = a[i];
            i++;
        }
    }
    for(int i = 0; i < size; i++){
        a[i] = A[i];
    }
    return 0;
}
template <class T>
void MergeSort(T *arr, int begin_pos, int end_pos){
    //printf("begin:%d end:%d\n", begin_pos, end_pos);
    if (end_pos - begin_pos > 0) {
        MergeSort<Card>(arr, begin_pos, (end_pos - begin_pos + 1) / 2 + begin_pos - 1);
        MergeSort<Card>(arr, (end_pos - begin_pos + 1) / 2 + begin_pos, end_pos);
    }
    if((end_pos - begin_pos + 1) / 2 > 0 && (end_pos - begin_pos + 1) - (end_pos - begin_pos + 1) / 2 > 0){
        merge(arr + begin_pos, (end_pos - begin_pos + 1) / 2, (end_pos - begin_pos + 1) - (end_pos - begin_pos + 1) / 2);
    }
}

int operator <=(Card a, Card b){
    int aa, bb;
    switch(a.simble){
    case 'S': aa = 0;break;
    case 'H': aa = 1;break;
    case 'D': aa = 2;break;
    case 'C': aa = 3;break;
    }
    switch(a.num) {
    case '2': aa += 0;break;
    case '3': aa += 10;break;
    case '4': aa += 20;break;
    case '5': aa += 30;break;
    case '6': aa += 40;break;
    case '7': aa += 50;break;
    case '8': aa += 60;break;
    case '9': aa += 70;break;
    case 'T': aa += 80;break;
    case 'J': aa += 90;break;
    case 'Q': aa += 100;break;
    case 'K': aa += 110;break;
    case 'A': aa += 120;break;
    }
    switch(b.simble){
    case 'S': bb = 0;break;
    case 'H': bb = 1;break;
    case 'D': bb = 2;break;
    case 'C': bb = 3;break;
    }
    switch(b.num) {
    case '2': bb += 0;break;
    case '3': bb += 10;break;
    case '4': bb += 20;break;
    case '5': bb += 30;break;
    case '6': bb += 40;break;
    case '7': bb += 50;break;
    case '8': bb += 60;break;
    case '9': bb += 70;break;
    case 'T': bb += 80;break;
    case 'J': bb += 90;break;
    case 'Q': bb += 100;break;
    case 'K': bb += 110;break;
    case 'A': bb += 120;break;
    }
    return (aa <= bb) ? 1 : 0;
}
int operator >(Card a, Card b){
    int aa, bb;
    switch(a.simble){
    case 'S': aa = 0;break;
    case 'H': aa = 1;break;
    case 'D': aa = 2;break;
    case 'C': aa = 3;break;
    }
    switch(a.num) {
    case '2': aa += 0;break;
    case '3': aa += 10;break;
    case '4': aa += 20;break;
    case '5': aa += 30;break;
    case '6': aa += 40;break;
    case '7': aa += 50;break;
    case '8': aa += 60;break;
    case '9': aa += 70;break;
    case 'T': aa += 80;break;
    case 'J': aa += 90;break;
    case 'Q': aa += 100;break;
    case 'K': aa += 110;break;
    case 'A': aa += 120;break;
    }
    switch(b.simble){
    case 'S': bb = 0;break;
    case 'H': bb = 1;break;
    case 'D': bb = 2;break;
    case 'C': bb = 3;break;
    }
    switch(b.num) {
    case '2': bb += 0;break;
    case '3': bb += 10;break;
    case '4': bb += 20;break;
    case '5': bb += 30;break;
    case '6': bb += 40;break;
    case '7': bb += 50;break;
    case '8': bb += 60;break;
    case '9': bb += 70;break;
    case 'T': bb += 80;break;
    case 'J': bb += 90;break;
    case 'Q': bb += 100;break;
    case 'K': bb += 110;break;
    case 'A': bb += 120;break;
    }
    return (aa > bb) ? 1 : 0;
}
istream &operator>>(istream &s, Card &a){
    s >> a.simble >> a.num;
    return s;
}
ostream &operator<<(ostream &s, Card a){
    switch(a.simble) {
    case 'S':
        cout << SPADE;break;
    case 'C':
        cout << CLUB;break;
    case 'H':
        cout << HEART;break;
    case 'D':
        cout << DIAMOND;break;
    }
    if (a.num == 'T') {
        s<<"10";
    }
    else s << a.num;
    return s;
}

int main()
{
    int size;
    cin >> size;
    Card *a = new Card[size];
    for(int i=0; i< size; i++) {
        cin >> a[i];
    }

    //  sort
    MergeSort<Card>(a, 0, size-1);

    //  output
    for(int i=0; i< size-1; i++) {
        cout << a[i] << ' ';
    }

    cout << a[size - 1] << endl;
    return 0;

}
