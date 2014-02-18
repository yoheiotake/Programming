#include <iostream>
using namespace std;

class Cell {
private:
  int data;     
  Cell *next;    

public:
  Cell( int dataValue );
  void connect( Cell *nextPtr );
  void show( );
};


Cell::Cell( int dataValue ) {
  data = dataValue;
  next = NULL;
}


void Cell::connect( Cell *nextPtr ) {

  next = nextPtr;

}


void Cell::show( ) {
  cout << data ;
  if(next==NULL){
    cout << endl;
    return;
  }
  next->show();
  return;
}

int main( ) {

  Cell cellA(1);
  Cell cellB(2);
  Cell cellC(3);

  cellB.show();
  cellB.connect(&cellA);
  cellB.show();
  cellC.connect(&cellB);
  cellC.show();

  return 0;
}
