#include <iostream>
using namespace std;

void move( int n, string from, string to, string temp );

// n 枚の円盤を from から，to に移動させる．temp は作業用
void move( int n, string from, string to, string temp ) {
  if(n == 1){
    cout << n <<"番目の円盤を "<< from <<" から "<< to <<" へ移動させる．"<< endl;
    return;
  }
  move(n-1,from,temp,to);
  cout << n <<"番目の円盤を "<< from <<" から "<< to <<" へ移動させる．"<< endl;
  move(n-1,temp,to,from);
  return;
}

int main(  ) {
  int n;
  cout << "円盤の数を入力してください: ";
  cin >> n;
  move( n, "棒 A", "棒 B", "棒 C" );
  return 0;
}
