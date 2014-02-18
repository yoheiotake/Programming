#include <iostream>
#include<fstream>
using namespace std;


class Time {
  friend class List;
private:
  int hour;
  int minute;
  Time *next;
public:
  Time( int _hour, int _minute );
};

class List {
private:
  Time *head;
public:
  List( );
  ~List( );
  void addData( int i_hour, int i_minute );
  void removeData( );
  void printNext( int key_hour, int key_minute );
  void print( );
};


Time::Time( int _hour, int _minute ) {
  hour = _hour;
  minute = _minute;
  next = NULL;
}

List::List( ) {
  head = NULL;
};


List::~List( ) {
  while( head != NULL ) {
    removeData( );
  }
};


void List::removeData( ) {
  Time *target = head;
  if(target != NULL) {
    head = target->next;
    delete target;
  }
}


void List::addData( int i_hour, int i_minute ) {
  if(head == NULL)
    head = new Time(i_hour, i_minute);
  Time *p = head;
  while(p -> next != NULL)
    p = p -> next;
  p -> next = new Time(i_hour, i_minute);
  return;
}


void List::printNext( int key_hour, int key_minute ) {
  if(head == NULL){
    cout <<"該当データなし"<< endl;
    return;
  }
  Time *p = head;
  bool flag = 0;
  if( key_hour < p -> hour){
    cout << p -> hour <<" 時 "<< p -> minute <<" 分 "<< endl;
    return;
  }
  while( p -> next != NULL){
    if( p -> hour == key_hour){
      flag = 1;
      if( key_minute <= p -> minute ){
        cout << p -> hour <<" 時 "<< p -> minute <<" 分 "<< endl;
      return;
      }
      p = p -> next;
      continue;
    }
    if(flag == 1){
      cout << p -> hour <<" 時 "<< p -> minute <<" 分 "<< endl;
      return;
    }
    p = p -> next;
  }
  cout <<"該当データなし"<< endl;
  return;
}

int main( ) {
  List l1;
  int i_hour, i_minute, key_hour, key_minute;

  ifstream fin( "busData.txt" );
  if ( !fin ) {
    cout << "データファイルを開くことができません. " << endl;
    return 1;
  }

  while ( !fin.eof( ) ) {
    fin >> i_hour >> i_minute;
    l1.addData( i_hour, i_minute);
  }
  fin.close( );

  cout << "次に来るバスを検索します. 現在の時刻を入力してください. \n時: ";
  cin >> key_hour;
  cout << "分: ";
  cin >> key_minute;

  cout << "次のバスの発車時刻: " << endl;
  l1.printNext( key_hour, key_minute );

  return 0;
}
