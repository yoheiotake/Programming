#include <iostream>
#include <vector>
#include <fstream>
#include <functional>
#include <algorithm>
#include <ctime>
using namespace std;

int main(  ) {
  int value;
  bool option;
  char filename[20];
  vector<int> array;
    
  cout << "データファイルを開きます. " << endl;
  cout << "ファイル名: ";
  cin >> filename;
  ifstream fin( filename );
  if ( !fin ) {
    cout << "データファイルを開くことができません. " << endl;
    return 1;
  }
  while ( !fin.eof( ) ) {
    fin >> value;
    array.push_back( value );
  }
  fin.close( );
    
  cout << "要素数: " << array.size( ) << endl;
    
  cout << "- ソート開始 -" << endl;
  clock_t starttime = clock( );
    
  sort( array.begin( ), array.end( ) );
    
  clock_t endtime = clock( );
  cout << "- ソート完了 -" << endl;
    
  double sec = endtime - starttime;
  sec /= CLOCKS_PER_SEC;
  cout << "ソート時間: " << sec << " sec" << endl;
    
  cout << "ソート結果を表示しますか？　0: 表示しない, 1: 表示する > ";
  cin >> option;
  if( option ) {
    for ( int i = 0; i < array.size( ); i++ ) {
      cout << array[i] << " ";
    }  
    cout << endl;
  }
  return 0;
}


/***************************************************************

<Sort済み>
データファイルを開きます. 
ファイル名: data.txt
要素数: 131074
- ソート開始 -
- ソート完了 -
ソート時間: 0.02 sec
ソート結果を表示しますか？　0: 表示しない, 1: 表示する > 0

<未Sort>
データファイルを開きます. 
ファイル名: data.txt
要素数: 131073
- ソート開始 -
- ソート完了 -
ソート時間: 0.03 sec
ソート結果を表示しますか？　0: 表示しない, 1: 表示する > 0

/***************************************************************
