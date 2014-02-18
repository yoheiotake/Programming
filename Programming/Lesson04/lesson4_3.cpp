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
  void removeAt( int index );
  bool removeLast( );
  void print( );
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
    // cout << "データ " << target->data << " のセルを削除します. " << endl;    // 動作確認用
    delete target;
  }
}


void List::removeAt( int index ) {
  Cell *r = head;

  if(head==NULL)
    return;

  else if(index == 0){
    head = r -> next;
    delete r;
  }
  else{
    for(int i = 0; i!=(index-1); i++){
      r = r -> next;
      if(r -> next == NULL)
        return;
    }
    Cell *d = r -> next;
    r -> next = r -> next -> next;
    delete d;
  }
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
  List l1;
  for( int i = 0; i < 10; i++ ) {
    l1.addFirst( i );
  }

  l1.print();
  l1.removeAt( 0 );   
  l1.print();
  l1.removeAt( 2 );
  l1.print();
  l1.removeAt( 4 );
  l1.print();
  l1.removeAt( 17 );    
  l1.print();
  l1.removeAt( 0 );   
  l1.print();
  l1.removeAt( 6 );    
  l1.print();
  l1.removeAt( 5 );
  l1.print();

 
  while(l1.removeLast() != 1){
    l1.print();
  }

  return 0;
}



/**********************************************************************
　＜フレンドクラス＞

　クラスA{ frend class B }

　クラスBはクラスAのprivateメンバにアクセス可能。


　＜if()の条件＞

　if() と else()を使って条件分岐する場合、条件に使用する変数は
　最初の条件文（if）に入る前に宣言する必要があり，条件分岐の
　途中で改に宣言した変数を利用して比較を行うことはできない。

　（例）　
  if(head == NULL){ }
  Cell *rm = head;
  else if( rm -> next == NULL){ }

  例えば上の例はif命令の後にポインタを宣言し、そのポインタをelse if()
  の条件として利用しているためにエラーとなる。

**********************************************************************/
