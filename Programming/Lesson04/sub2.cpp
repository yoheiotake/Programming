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
  void moveToArray( int *array, int index, int number );
  void print( );
  bool removeLast( );
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
    delete target;
  }
}


void List::moveToArray( int *array, int index, int num ) {
  if(head == NULL || num == 0)
    return;

  Cell *p = head;
  for(int n = 0; n < (index-1); n++){
    p = p -> next;
    if(p == NULL)
      return;
  }

  Cell *jmp = p;
  if(index != 0)
    p = p -> next;

  for(int c = 0; c < num && p != NULL; c++){
    Cell *rm = p;
    array[c] = p -> data;
    p = p -> next;
    delete rm;
  }

  if(index == 0)
    head = p;
  else
    jmp -> next = p;

  return;
}


void List::print( ) {
  cout << "リストの内容: ";
  if(head == NULL){
    cout << "NULL" << endl;
    return;
  }

  Cell *p = head;
  while(true){
    cout << p -> data << ' ';
    if( p -> next == NULL)
      break;
    p = p -> next;
  }
  cout << endl;	
}

bool List::removeLast( ){
  Cell *rm = head;
  if(head == NULL)
    return 1;
  else if(rm -> next == NULL){
    head = NULL;
    delete rm;
    return 0;
  }
  else{
    while(rm -> next -> next != NULL){
      rm = rm -> next;
    }
    delete rm -> next;
    rm -> next = NULL;
    return 0;
  }
}

int main( ) {

  int index, number;

  List l1;
  l1.addFirst( 8 );
  l1.addFirst( 10 );
  l1.addFirst( 23 );
  l1.addFirst( -3 );
  l1.addFirst( 12 );

  int array1[5] = {0, 0, 0, 0, 0};

  l1.print();

  cout << "配列の中身: ";
  for ( int i = 0; i < 5; i++ )
    cout << array1[i] << " ";
  cout << endl;

  cout << "開始位置: ";
  cin >> index;
  cout << "移動要素数: ";
  cin >> number;


  l1.moveToArray( array1, index, number);

  l1.print();

  cout << "配列の中身: ";
  for ( int i = 0; i < 5; i++ )
    cout << array1[i] << " ";
  cout << endl;

  return 0;
}
