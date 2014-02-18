#include <iostream>
using namespace std;


class Array{
private:
  int size;
  int *array;
public:
  Array( int set );
  int getSize( );
  void put( int index, int data );
  int get( int index );
  void show( );
};


Array::Array( int set ) 
{
  size = set;
  array = new int[size];
  for ( int i = 0; i < size; i++ ) {
    array[i] = 0;
  }
}


int Array::getSize( ) {
  return size;
}


void Array::put( int index, int data ) {
  array[index] = data;
}


int Array::get( int index ) {
  return array[index];
}


void Array::show( ) {
  cout << "配列の中身: " << endl << "| ";
  for ( int i = 0; i < getSize( ); i++ ) {
    cout << get(i) << " | ";
  }
  cout << endl;
}

int main( ) {

  Array array1(6);
  array1.put(1, 2);
  array1.put(4, 1);
  array1.show( );

  return 0;
}
