#include <iostream>
using namespace std;


class Cell {
  friend class Queue;
private:
  int data;
  Cell *next; 
public:
  Cell( int _data, Cell *_next );
};

class Queue {
private:
  Cell *front;
  Cell *rear;
public:
  Queue();
  ~Queue();
  void enqueue(int data);
  int  dequeue();
  void print();
};


Cell::Cell( int _data, Cell *_next = NULL ) {
  data = _data; 
  next = _next;
}

Queue::Queue( ) {
  front = NULL;
  rear  = NULL;
};


Queue::~Queue( ) {
  while( front != NULL ) {
    dequeue( );
  }
};


void Queue::enqueue( int data ) {
  rear = new Cell(data);
  if(front == NULL){
    front = rear;
    return;
  }
  Cell *p = front;
  while(p -> next != NULL)
    p = p -> next;
  p -> next = rear;
  cout << data <<"をキューに追加しました．"<< endl;
  return;
}


int Queue::dequeue( ) {
  if(front == NULL){
    cout <<"キューは空です．データを取り出せません．"<< endl;
    return -1;
  }
  int n = front -> data;
  if(front == rear){
    delete front;
    rear = front = NULL;
  }
  else{
    Cell *p = front -> next;
    delete front;
    front = p;
  }
  return n;
}


void Queue::print( ) {
  if(front == NULL) {
    cout << "キューは空です. データを表示できません. " << endl;
    return;
  }
  cout << "キューの内容: ";
  for( Cell* p = front; p != NULL ; p = p->next ) {
    cout << p->data << " ";
  }
  cout << endl;
}

int main( ) { 
  Queue q1;
  int option, newData;
  bool flag = 1;
	
  while(flag) {
    cout << "1:Enqueue, 2:Dequeue, 3:キューの内容を表示, 4:停止 >> ";
    cin >> option;
    if ( option == 1 ) {
      cout << "追加するデータを入力してください: ";
      cin >> newData;
      q1.enqueue( newData );
    }
    else if ( option == 2 ) {
      int value = q1.dequeue( );
      if ( value != -1 ) {
	cout << value << " をキューから取り出しました. " << endl;
      }
    }
    else if ( option == 3 ) {
      q1.print( );
    }
    else if ( option == 4 ) {
      flag = 0;
    }
    else {
      cout << "1〜4 の数字を入力してください. " << endl;
    }
  }
	
  return 0;
}
