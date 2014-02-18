#include <iostream>
#include <fstream>
using namespace std;

// クラスの宣言
class Cell {
  friend class List;    // Listクラスから，このクラスに自由にアクセスできるようにする
private:
  int data;    // データ
  Cell *next;    // 次のセルのアドレスを指すポインタ
public:
  Cell( int _data, Cell *_next );
};

class List {
private:
  Cell *head;    // 連結リストの先頭要素のアドレスを指すポインタ
public:
  List( );
  ~List( );
  void addFirst( int data );
  void removeFirst( );
  void print( );
  int linearSearch( int key );
};

// コンストラクタの定義
Cell::Cell( int _data, Cell *_next = NULL ) {
  data = _data;
  next = _next;
}

List::List( ) {
  head = NULL;
};

// デストラクタの定義
List::~List( ) {
  while( head != NULL ) {
    removeFirst( );
  }
};

// 新たなデータを連結リストの先頭に追加する関数
void List::addFirst( int data ) {
  head = new Cell( data, head );
}

// 連結リストの先頭の要素を削除する関数
void List::removeFirst( ) {
  Cell *target = head;
  if( target != NULL ) {
    head = target->next;
    delete target;
  }
}

// 連結リストの内容を表示する関数
void List::print( ) {
  cout << "リストの内容: ";
  for( Cell* p = head; p != NULL ; p = p->next ) {
    cout << p->data << " ";
  }
  cout << endl;
}

// 連結リストを線形探索し，探索キーと一致したデータの個数を返す関数
int List::linearSearch( int key ) {
  int n = 0;
  if(head == NULL)
    return n;
  Cell *p = head;
  for(;p != NULL; p = p -> next){
    if(p -> data == key)
      n++;
  }
  return n;
}

int main( ) {
  List l1;
  int value, key;

  ifstream fin( "data7-1.txt" );
  if ( !fin ) {
    cout << "データファイルを開くことができません. " << endl;
    return 1;
  }

  while ( !fin.eof( ) ) {
    fin >> value;
    l1.addFirst( value );
  }
  fin.close( );

  cout << "探索キーを入力してください: ";
  cin >> key;

  l1.print( );
  cout << "キーと一致したデータの数: " << l1.linearSearch( key ) << endl;

  return 0;
}
