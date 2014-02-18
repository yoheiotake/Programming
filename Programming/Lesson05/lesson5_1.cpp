#include <iostream>
using namespace std;


class Cell {
  friend class Stack;
private:
  int data;
  Cell *next;
public:
  Cell( int _data, Cell *_next );
};

class Stack {
private:
  Cell *top;
public:
  Stack( );
  ~Stack( );
  void push( int data );
  int pop( );
  void print( );
};


Cell::Cell( int _data, Cell *_next = NULL ) {
  data = _data;
  next = _next;
}

Stack::Stack( ) {
  top = NULL;
};


Stack::~Stack( ) {
  while( top != NULL ) {
    pop( );
  }
};


void Stack::push( int data ) {
  Cell *p = top;
  top = new Cell(data);
  top -> next = p;
  return;
}


int Stack::pop( ) {
  int n = 0;
  if(top == NULL){
    cout <<"スタックは空です．データを取り出せません．"<< endl;
    n = -1;
  }
  else if(top -> next == NULL){
    n = top -> data;
    delete top;
    top = NULL;
  }
  else{
    n = top -> data;
    Cell *rm = top;
    top = top -> next;
    delete rm;
  }
  return n;
}


void Stack::print( ) {
  if(top == NULL) {
    cout << "スタックは空です. データを表示できません. " << endl;
    return;
  }
  cout << "スタックの内容: ";
  for( Cell* p = top; p != NULL ; p = p->next ) {
    cout << p->data << " ";
  }
  cout << endl;
}

int main( ) {
  Stack s1;
  int option, newData;
  bool flag = 1;

  while(flag) {
    cout << "1:Push, 2:Pop, 3:スタックの内容を表示, 4:停止 >> ";
    cin >> option;
    if ( option == 1 ) {
      cout << "追加するデータを入力してください: ";
      cin >> newData;
      s1.push( newData );
    }
    else if ( option == 2 ) {
      int value = s1.pop( );
      if ( value != -1 ) {
	cout << value << " をスタックから取り出しました. " << endl;
      }
    }
    else if ( option == 3 ) {
      s1.print( );
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

