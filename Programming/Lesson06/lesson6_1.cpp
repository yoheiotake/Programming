#include <iostream>
using namespace std;

class Stack {
private:
  int size;    // スタックのサイズ
  int top;    // データを積む位置
  int *stack;    // 配列の先頭アドレス
public:   
  Stack( int _size );
  ~Stack( );
  void push( int data );
  int pop( );
  void print( );
};


Stack::Stack( int _size ) {
  size = _size;
  top = 0;
  stack = new int[size];
};


Stack::~Stack( ) {
  delete [] stack;
};


void Stack::push( int data ) {
  if(top == size){
    cout <<"スタックが一杯です．データを追加できません."<< endl;
    return;
  }
  stack[top] = data;
  top++;
  cout << data <<" をスタックに追加しました."<< endl;
  return;
}


int Stack::pop( ) {  
  if(top == 0){
    cout <<"スタックは空です．データを取り出せません."<< endl;
    return -1;
  }
  top=top-1;
  return stack[top];
}


void Stack::print( ) {
  if( top == 0 ) {
    cout << "スタックは空です. データを表示できません. " << endl;
    return;
  }
  cout << "スタックの内容: ";
  for( int i = top - 1; i >= 0; i-- ) {
    cout << stack[i] << " ";
  }
  cout << endl;    
}

int main ( ) {
  Stack s1( 5 );
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
