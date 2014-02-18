#include <iostream>
using namespace std;

int main( )
{
  int a = 611, *ptr;

  // ptr = &a;    // ポインタの値として変数 a のアドレスを設定

  ptr =(int *)100;

  cout << "変数 a のアドレス: " << &a << endl
       << "変数 a の値: " << a << endl
       << "ポインタ ptr の値: " << ptr+1 << endl
       << "ポインタ ptr の指すアドレスに保存されている値: " << *ptr << endl;

  return 0;
}
