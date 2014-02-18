#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

class Array {
private:
  vector<int> array;
public:
  void insert( int value ){ array.push_back( value ); }
  int getSize( ){ return (int)array.size( ); } // array.size()は戻り値としてunsigned intを返す
  void selection_sort(  );
  void insertion_sort(  );
  void bubble_sort(  );
  void print(  );
};


void Array::selection_sort( ) {
  for(int min = 0; min < (int)array.size(); min++){
    int x = min;
    for(int y = min + 1; y < (int)array.size(); y++){
      if(array[x] > array[y])
        x = y;
    }
    int tmp    = array[min];
    array[min] = array[x];
    array[x]   = tmp;
  }
  return;
} 


void Array::bubble_sort( ) {
  for(int min = 0; min < (int)array.size(); min++){
    for(int x = (int)array.size() - 1; x > min; x--){
      int y = x - 1;
      if(array[y] > array[x]){
        int tmp = array[y];
        array[y] = array[x];
        array[x] = tmp;
      }
    }
  }
  return;
}


void Array::insertion_sort( ) {
  for(int x = 1; x < (int)array.size(); x++){
    int tmp = array[x];
    int y = x - 1;
    while(tmp < array[y] && y >= 0){
      array[y + 1] = array[y];
      y--;
    }
    array[y + 1] = tmp;
  }
  return;
}


void Array::print(  ) {
  for ( int i = 0; i < (int)array.size( ); i++ ) {
    cout << array[i] << " ";
  }
  cout << endl;
}

int main(  ) {

  Array a1;

  a1.insert( 56 );
  a1.insert( 34 );
  a1.insert( 57 );
  a1.insert( 64 );    
  a1.insert( 3 );   
  a1.insert( 87 );
  a1.insert( 85 );
  a1.insert( 37 );
  a1.insert( 21 );    
  a1.insert( 4 );   
  a1.insert( 68 );
  a1.insert( 62 );
  a1.insert( 42 );
  a1.insert( 55 );    
  a1.insert( 63 );    
  a1.insert( 95 );
  a1.insert( 7 );
  a1.insert( 32 );
  a1.insert( 78 );    
  a1.insert( 11 );   

  cout << "要素数: " << a1.getSize( ) << endl;
  cout << "ソート前: ";
  a1.print(  );

  //a1.selection_sort(  );
  //a1.bubble_sort( );
  a1.insertion_sort( );

  cout << "ソート後: ";
  a1.print(  );       

  return 0;
}
