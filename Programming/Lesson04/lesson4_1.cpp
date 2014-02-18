#include <iostream>
using namespace std;


class Cell {
  friend class List;    
private:
  int data;    
  Cell *next;    
public:
  Cell( int _data );
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
};


Cell::Cell( int _data ) {
  data = _data; 
  next = NULL;
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
  if(head==NULL)
    head = new Cell(data);
  else{
    Cell *oldp = head;
    head = new Cell(data);
    head -> next = oldp;
  }
  return;	
}


void List::removeFirst( ) {	
  Cell *target = head;
  if(target != NULL) {
    head = target->next;
    // cout << "データ " << target->data << " のセルを削除します. " << endl;    // 動作確認用
    delete target;
  }
}


void List::print( ) {
  cout << "リストの内容: ";
  
  Cell *p = head;
  while(true){
    cout << p -> data << ' ';
    if( p -> next == NULL)
      break;
    p = p -> next;
  }
  cout << endl;
}

int main( ) { 
  List l1;
	
  l1.addFirst( 0 );
  l1.addFirst( 1 );
  l1.addFirst( 2 );
  l1.addFirst( 3 );
  l1.print();
  l1.removeFirst( );
  l1.print();	   
  l1.addFirst( 4 ); 
  l1.addFirst( 5 );	   
  l1.print();	   
  l1.addFirst( 1 );
  l1.addFirst( 2 );
  l1.print();
  l1.removeFirst( );
  l1.print();
	
  return 0;
} 
