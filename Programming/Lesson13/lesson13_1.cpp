#include <iostream>
#include <vector>
using namespace std;

class Array {
private:
  vector<int> array;
public:
  void insert( int value ){ array.push_back( value ); }
  int getSize( ){ return (int)array.size( ); }
  void marge_sort(  ){ marge_sort( 0, (int)array.size( ) - 1 ); }
  void marge_sort( int left, int right );
  void marge( int left, int middle, int right );
  void print(  );
};


void Array::marge_sort( int left, int right ){
    
  if( left >= right ) {
    return;
  }

  int middle = (left + right) / 2;
    
  marge_sort( left, middle );
  marge_sort( middle + 1 , right );
    
  marge( left, middle, right );
    
}


void Array::marge( int left, int middle, int right ) {

  vector<int> tmp(right - left +1);
  int i = left;
  int j = middle + 1;
  int k = 0;

  while(i <= middle && j <= right){
    if(array[i] <= array[j]){
      tmp[k] = array[i];
      k++;
      i++;
    }
    else{
      tmp[k] = array[j];
      k++;
      j++;
    }
  }
  while(i <= middle){
    tmp[k] = array[i];
    k++;
    i++;
  }
  while(j <= right){
    tmp[k] = array[j];
    k++;
    j++;
  }
  for(i = left,k = 0; i <= right; i++,k++){
    array[i] = tmp[k];
  }
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
    
  a1.marge_sort(  );    // ここで，ソートを行う関数を呼び出す
    
  cout << "ソート後: ";
  a1.print(  );       
    
  return 0;
}
