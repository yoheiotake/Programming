#include <iostream>
using namespace std;

int sub(int n){
  if(n == 1){
    cout << n <<',';
    return n;
  }
  int x = sub(n-1) + 2*n + 1;
  cout << x <<'.';
  return x;
}

int main(){
  int n = 0;
  cout <<"整数n項目の値を計算します.nを入力してください:";
  cin >> n;

  int z = sub(n);
  cout << endl;
  cout <<"数列の "<< n <<" 項目の値:"<< z << endl;

  return 0;
}
