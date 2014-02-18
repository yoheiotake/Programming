#include <iostream>
#include <fstream>
#include <cstdlib>    // rand 関数を使用するのに必要
#include <ctime>    // time 関数を使用するのに必要
using namespace std;

int main(  ) {
  const int count = 131072;    // 生成する乱数の数
  bool option;
  char filename[20];
    
  srand( (unsigned int)time( NULL ) );    // 現在時刻を使って擬似乱数の系列を初期化する
    
  cout << "0: ファイルに出力する, 1: コンソールに出力する > ";
  cin >> option;
     
  if( !option ) {
    cout << "ファイル名: ";
    cin >> filename;
    ofstream fout( filename );
    if ( !fout ) {
      cout << "書き出しファイルを開くことができません. " << endl;
      return 1;
    }
        
    for ( int i = 0; i < count; i++ ) {
      fout << rand( ) % 100 << ' ';    // 乱数を生成し，100で割った剰余を書き出す
    }
    fout << flush;
    fout.close();
  }
  else {
    for ( int i = 0; i < count; i++ ) {
      cout << rand( ) % 100 << ' ';    // 乱数を生成し，100で割った剰余を表示
    }
    cout << flush;  
  }
  return 0;
}
