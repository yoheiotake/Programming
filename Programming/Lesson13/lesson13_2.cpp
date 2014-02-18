#include <iostream>
#include <vector>
using namespace std;

class Array {
private:
  vector<int> array;
public:
  void insert( int value ){ array.push_back( value ); }
  int getSize( ){ return (int)array.size( ); }
  void quick_sort(  ){ quick_sort( 0, (int)array.size( ) - 1 ); }
  void quick_sort( int left, int right );
  int partition( int left, int right );
  void print(  );
};


void Array::quick_sort( int left, int right ) {
    
  if ( left >= right ) {
    return;
  }
    
  int v = partition( left, right );
    
  quick_sort( left, v - 1 );
  quick_sort( v + 1, right );
}



int Array::partition( int left, int right ) {
  int pivot = array[right];
  int i = left;
  int j = right - 1;

  while(true){
    while(array[i] < pivot){
      i++;
    }
    while(i < j && pivot <= array[j]){
      j--;
    }
    if(i >= j)
      break;
    int tmp  = array[i];
    array[i] = array[j];
    array[j] = tmp;
  }
  int tmp = array[right];
  array[right] = array[i];
  array[i] = tmp;
  return i;
}

// 配列の内容を表示する関数
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
    
  a1.quick_sort(  );
    
  cout << "ソート後: ";
  a1.print(  );       
    
  return 0;
}
