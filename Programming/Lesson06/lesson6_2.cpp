#include <iostream>
using namespace std;

class Queue {
private:
  int size;    // キューのサイズ
  int front;    // キューの先頭位置
  int rear;    // キューの最後尾位置
  int count;    // キューに保存されているデータ数
  int *queue;    // 配列の先頭アドレス
public:   
  Queue( int _size );
  ~Queue( );
  void enqueue( int data );
  int dequeue( );
  void print( );
};


Queue::Queue( int _size ) {
  size = _size;
  front = 0;
  rear = 0;
  count = 0;
  queue = new int[size];
};


Queue::~Queue( ) {
  delete [] queue;
};


void Queue::enqueue( int data ) {
  if(count == size){
    cout <<"キューが一杯です．データを追加できません．"<< endl;
    return;
  }
  queue[rear] = data;
  rear++;
  count++;
  if(rear == size)
    rear = 0;
  cout << data <<" をキューに追加しました．"<< endl;
  return;
}


int Queue::dequeue( ) {  
  if(count == 0){
    cout <<"キューは空です．データを取り出せません．"<< endl;
    return -1;
  }
  int val = queue[front];
  front++;
  count--;
  if(front == size)
    front = 0;
  return val;
}


void Queue::print( ) {
  if( count == 0 ) {
    cout << "キューは空です. データを表示できません. " << endl;
    return;
  }
  cout << "キューの内容: ";
  for( int i = 0; i < count; i++ ) {
    cout << queue[( front + i ) % size] << " ";
  }
  cout << endl;    
}

int main ( ) {
  Queue q1( 6 );
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
