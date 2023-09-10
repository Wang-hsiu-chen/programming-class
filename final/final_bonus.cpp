#include <iostream>
#include <string>
#include <stack>
using namespace std;

class Type{
public:
    stack<int> length;
    stack<int> endpoint;
    int Find(int *a, int s1, int *b, int s2);
    void Result();
    int getlen(){
        return leng;
    }
    int getstr(){
        return endp;
    }
protected:

private:
    int leng;
    int endp;
};

int Type::Find(int *a, int s1, int *b, int s2){
    int i = 0, j = 0, len = 0, end = 0;
    int *str = new int[1];
    while (i < s1) {
        while (j < s2) {
            if (b[j] == a[i]) {
                len++;
                end = i;
                //end2 = j;
                i++;
            } else {
                if (len) {
                    length.push(len);
                    endpoint.push(i);
                }
                len = 0;
            }
            j++;
        }
        j = 0;
        i++;
    }
    return 0;
}
void Type::Result(){
    leng = 0;
    while (length.size() ) {
        if (length.top() > leng) {
            leng = length.top();
            endp = endpoint.top();
        }
        length.pop();
        endpoint.pop();
    }
    return ;
}

int main(){
    Type my_type;
    int size1, size2;
    string mode;
    cin >> size1;
    int *a = new int[size1];
    for (int i = 0; i < size1; i++) {
        cin >> a[i];
    }
    cin >> size2;
    int *b = new int[size2];
    for (int i = 0; i < size2; i++) {
        cin >> b[i];
    }

    cin >> mode;

    my_type.Find(a, size1, b, size2);
    my_type.Result();

    if (mode == "len") {
        cout << my_type.getlen() << endl;
    } else if (mode == "str") {
        int end = my_type.getstr(), len = my_type.getlen();
        for (int i = end - len ; i < end - 1; i++) {
            cout << a[i] << ' ';
        }
        cout << a[end - 1] << endl;
    }
    return 0;
}



