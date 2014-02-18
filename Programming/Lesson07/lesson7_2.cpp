#include <iostream>
#include <fstream>
using namespace std;

class Array {
private:
  int size;    // 配列のサイズ
  int *array;    // 配列の先頭アドレス
public:
  Array( int _size );
  ~Array( );
  void put( int index, int data );
  int get( int index );
  void print( );
  int linearSearch( int key );
};

// コンストラクタの定義
Array::Array( int _size ) {
  size = _size;
  array = new int[size];
};

// デストラクタの定義
Array::~Array( ) {
  delete [] array;
}

// index 番目の配列要素に data の値を代入する関数
void Array::put( int index, int data ) {
  array[index] = data;
}

// index 番目の配列要素の値を返す関数
int Array::get( int index ) {
  return array[index];
}

// 配列の内容を表示する関数
void Array::print( )
{
  cout << "配列の内容: ";
  for ( int i = 0; i < size; i++ ) {
    cout << array[i] << " ";
  }
  cout << endl;
}

// 線形探索を行ない，探索キー key と一致するデータの位置を返す関数
int Array::linearSearch( int key ) {
  int n = -1;
  if(array == NULL)
    return n;
  for(int a = 0; a < size; a++){
    if(array[a] == key)
      n = a;
  }
  return n;
}

int main ( ) {
  const int datasize = 20;
  Array a1( datasize );
  int value, key;

  ifstream fin( "data7-2.txt" );
  if ( !fin ) {
    cout << "データファイルを開くことができません. " << endl;
    return 1;
  }

  for(int i = 0; i < datasize; i++) {
    fin >> value;
    a1.put( i, value );
  }
  fin.close( );

  cout << "探索キーを入力してください: ";
  cin >> key;

  a1.print( );
  int result = a1.linearSearch( key );

  if( result == -1 ) {
    cout << "キーと一致するデータは見つかりませんでした. " << endl;
  }
  else {
    cout << "キーと一致したデータの位置: " << result << endl;
  }

  return 0;
}
