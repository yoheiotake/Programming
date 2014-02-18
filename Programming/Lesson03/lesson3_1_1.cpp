#include <iostream>
using namespace std;

int main( )
{
  int *ptr;

  ptr = (int *)1000;    // ポインタptrの指すアドレスとして1000番地を代入
  *ptr = 8;             // ポインタptrの指すアドレス（1000番地）に8を代入

  cout << "ポインタ ptr の指すアドレスに保存されている値 = " << *ptr << endl;

  return 0;
}
