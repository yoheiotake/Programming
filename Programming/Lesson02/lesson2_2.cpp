#include <iostream>
using namespace std;

void showArray(int *pt);

void showArray(int *pt)
{
  for(int i = 0; i < 5; i++) {
    cout << "アドレス " << pt << " に保存されている値: " << *pt << endl;
    pt+=2;
  }
}

int main ( )
{
  int array[10] = {12, 23, 8, 7, 1, 17, 2, 4, 15, 9};
  showArray(array);    // 配列のアドレス渡し
  return 0;
}
