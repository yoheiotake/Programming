#include <iostream>
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
  void removeValue( int value );
  Cell *removeValue( int value, Cell *p );
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
  if(target != NULL) {
    head = target->next;
    delete target;
  }
}


void List::removeValue( int value ) {
  head = removeValue( value, head );
}


Cell* List::removeValue( int value, Cell *p ) {
  if(p == NULL)
    return p;
  if(p -> data == value){
    Cell *np = p -> next;
    delete p;
    return removeValue(value, np);
  }
  p -> next = removeValue(value,p -> next);
  return p;
}


void List::print( ) {
  cout << "リストの内容: ";
  for( Cell *p = head; p != NULL ; p = p->next ) {
    cout << p->data << " ";
  }
  cout << endl;
}

int main( ) {
  List l1;

  l1.removeValue( 5 );    // リストが空の状態で動作確認
  l1.print( );
  l1.addFirst( 1 );
  l1.addFirst( 2 );
  l1.addFirst( 3 );
  l1.addFirst( 3 );
  l1.addFirst( 4 );
  l1.addFirst( 3 );
  l1.addFirst( 2 );
  l1.addFirst( 1 );
  l1.print( );
  l1.removeValue( 1 );    // リストの先頭要素で動作確認
  l1.print( );
  l1.removeValue( 5 );   // リストに存在しない要素で動作確認
  l1.print( );
  l1.removeValue( 3 );   // 複数が連続する要素で動作確認
  l1.print( );
  l1.addFirst( 5 );
  l1.print( );
  l1.removeValue( 2 );    // リストの最後尾要素で動作確認
  l1.print( );

  return 0;
}
