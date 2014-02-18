#include <iostream>
#include <fstream>
using namespace std;


class Cell {
  friend class List; 
private:
  int data;
  Cell *next;
public:
  Cell( int _data, Cell *_next );
};

class List {
private:
  Cell *head;
public:
  List( );
  ~List( );
  void addFirst( int data );
  void removeFirst( );
  void print( );
  int linearSearch( int key );
  int linearSearch( int key, Cell *p );
};


Cell::Cell( int _data, Cell *_next = NULL ) {
  data = _data;
  next = _next;
}

List::List( ) {
  head = NULL;
};


List::~List( ) {
  while( head != NULL ) {
    removeFirst( );
  }
};


void List::addFirst( int data ) {
  head = new Cell( data, head );
}


void List::removeFirst( ) {
  Cell *target = head;
  if( target != NULL ) {
    head = target->next;
    delete target;
  }
}


void List::print( ) {
  cout << "リストの内容: ";
  for( Cell *p = head; p != NULL ; p = p->next ) {
    cout << p->data << " ";
  }
  cout << endl;
}


int List::linearSearch( int key ) {
  return linearSearch( key, head );
}


int List::linearSearch( int key, Cell *p ) {
  int n = 0;
  if(p == NULL)
    return n;

  if(p -> data == key)
    n++;

  n = n + linearSearch(key ,p->next);
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
