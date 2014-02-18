#include <iostream>
using namespace std;

int sub(int n){
  if(n == 1){
    cout << n ;
    return n;
  }
  int z = sub(n-1);
  cout <<" + "<< n;
  return n + z;
}

int main(){
  int n = 0;
  cout <<"1からnまでの総和を表示します.nを入力してください:";
  cin  >> n;

  cout <<" = "<< sub(n) << endl;

  return 0;
}
