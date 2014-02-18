#include <iostream>
using namespace std;

void hailstones1( int num );
void hailstones2( int num );

void hailstones1( int num )
{
  cout << num <<',';
  if(num == 1)
    return;
  int val = 0;
  if(num % 2 == 0)
    val = num / 2;
  else
    val = 3*num + 1;
  hailstones1(val);
  return;
}

void hailstones2( int num ) {
  while(true){
    cout << num <<',';
    if(num == 1)
      break;
    if(num % 2 == 0)
      num = num / 2;
    else
      num = 3*num + 1;
  }
  return;
}

int main(void)
{
  int n;

  cout << "ヘイルストーン数を生成します．初期値を入力してください: ";
  cin >> n;
  hailstones1( n );    
  cout << endl;
	
  cout << "ヘイルストーン数を生成します．初期値を入力してください: ";
  cin >> n;
  hailstones2( n );
  cout << endl;

  return 0;
}
