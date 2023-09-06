#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
 int a[6] = {1,1,4,6,6,7};
 int *p = unique(a,a+6);
 for(int i = 0;i < p-a+4;i++)
 {
  cout << a[i] << endl;
 }
 return 0;
}
