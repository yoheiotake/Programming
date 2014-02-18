#include <iostream>
using namespace std;

// クラスの宣言
class Array {
private:
  const static int size = 6;
  int array[size];
  int *p;
public:
  Array( );
  int getSize( );
  void put( int index, int data );
  int get( int index );
  void swap( int index1 , int index2 );
};

Array::Array( ) {
  p=array;
  for(int c=0;c<size;c++){
    *p=0;
    p++;
  }
}

int Array::getSize( ) {
  return size;
}

void Array::put( int index, int data ) {
  p=array;
  p[index]= data;
}

int Array::get( int index ) {
  p=array;
  return p[index];
}

void Array::swap( int index1, int index2 ) {
  p=array;
  int tmp=p[index1];
  p[index1]=p[index2];
  p[index2]=tmp;

  return;
}

int main( ) {
  Array myArray;

  myArray.put(1, 2);
  myArray.put(4, 1);

  cout << "配列の中身: " << endl << "| ";
  for ( int i = 0; i < myArray.getSize(); i++ ) {
    cout << myArray.get(i) << " | ";
  }
  cout << endl;
  

  myArray.swap(0, 4);
  cout << "交換後の配列の中身: " << endl << "| ";
  for ( int i = 0; i < myArray.getSize(); i++ ) {
    cout << myArray.get(i) << " | ";
  }
  cout << endl;

  return 0;
}
