#include <iostream>
using namespace std;

class Time{
private:
    int hour, minit, sec;
public:
    friend int operator <=(Time a, Time b);
    friend int operator >(Time a, Time b);
    friend istream &operator >>(istream &s, Time &a);
    friend ostream &operator <<(ostream &s, Time a);
};

template <class T>
int partition(T *arr, int start, int end) {
    T pivot = arr[start];
    int count = 0;
    for (int i = start + 1; i <= end; i++) {
        if (arr[i] <= pivot)
            count++;
    }
    // Giving pivot element its correct position
    int pivotIndex = start + count;
    swap(arr[pivotIndex], arr[start]); // defined in <iostream>

    // Sorting left and right parts of the pivot element
    int i = start, j = end;
    while (i < pivotIndex && j > pivotIndex) {
        while (arr[i] <= pivot) {
            i++;
        }
        while (arr[j] > pivot) {
            j--;
        }
        if (i < pivotIndex && j > pivotIndex) {
            swap(arr[i++], arr[j--]);
        }
    }
    return pivotIndex;
}
template <class T>
void quickSort(T *arr, int start, int end) {
    // base case
    if (start >= end)
        return;

    // partitioning the array
    int p = partition(arr, start, end);

    // Sorting the left part
    quickSort(arr, start, p - 1);

    // Sorting the right part
    quickSort(arr, p + 1, end);
}


int operator <=(Time a, Time b){
    return (a.hour > b.hour)? 0 : (a.hour < b.hour)? 1 :(a.minit > b.minit)? 0:(a.minit < b.minit)? 1:(a.sec > b.sec)? 0: 1;
}
int operator >(Time a, Time b){

    return (a.hour > b.hour)? 1 : (a.hour < b.hour)? 0: (a.minit > b.minit)? 1: (a.minit < b.minit)? 0 : (a.sec > b.sec)? 1 : 0;
}
istream& operator >>(istream& ins, Time &t ){
    char oper;
    ins >> t.hour >> oper >> t.minit >> oper >> t.sec;
    return ins;
}
ostream& operator <<(ostream& outs, const Time t){
    outs << t.hour << ":" << t.minit << ":" << t.sec;
    return outs;
}


int main(){
    int maxsize;
    cin >> maxsize;
    Time *a = new Time[maxsize];
    for(int i=0; i< maxsize; i++) {
        cin >> a[i];
    }

    quickSort<Time>(a, 0, maxsize - 1);

    for(int i = 0; i < maxsize-1; i++) {
        cout << a[i] << ' ';
    }
    cout << a[maxsize - 1] << endl;
    return 0;
}


