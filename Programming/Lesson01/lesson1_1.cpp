#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
  ifstream ifs("numbers.txt");
  ofstream ofs("numbers3.txt");

  if(!ifs || !ofs){
    cout <<"Invalid FileName"<<endl;
    return 1;
  }

  int p=0;
  string s(" ");
  while(true){
    if(ifs >> p == false)
      break;
    if(p % 3 == 0)
      ofs << p << s;
  }

  ifs.close();
  ofs.close();

  return 0;
}

/*******************************************************************

　　　　　＜ファイル入出力＞

ヘッダのインクルード
　#include <fstream>

ファイル指定
　ifstream 入力オブジェクト名("ファイル名");
  ofstream 出力オブジェクト名("ファイル名");

ファイルを閉じる
  入力オブジェクト名.close();
  出力オブジェクト名.close();

ファイルの読み書き
　入力オブジェクト名 >> 変数；　　　　　　データの読み込み
　入力オブジェクト名 >> 変数1 >> 変数2;　 複数データの読み込み
　出力オブジェクト名 >> 変数 ;　　　　　　データの書き出し

string型変数への代入
　string 変数("値")

string型変数は可変長なのでスペースなどの1文字でも""を使用する。


以下のようにしてファイル入出力をする方法もある。
eof()はファイルの終端に到達した際にtrueを返すメンバ関数。
しかしこれはファイルの最後のバッファ（この場合８）を2度くり返す
ためよくない。

int x =0;
int y =0;
while(!ifs.eof()){
  ifs >> y;
  x++;
  cout << y <<" : "<< x  <<endl;
 }

eof()メンバ関数の出力例
24 : 1
32 : 2
　・
　・
　・
34 : 36
18 : 37
20 : 38
23 : 39
8 : 40
8 : 41


*******************************************************************/
