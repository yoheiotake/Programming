#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class Array {
private:
  vector<T> array;
public:
  void insert( T value ){ array.push_back( value ); }
  void insertion_sort(  );
  void print(  );
};

template<typename T>
void Array<T>::insertion_sort( ) {
  for ( typename vector<T>::iterator itr1 = array.begin() + 1; itr1 != array.end(); itr1++ ) {
    T tmp = *itr1;    
    typename vector<T>::iterator itr2 = itr1 - 1;
    while ( itr2 >= array.begin() && *itr2 > tmp ) {
      *(itr2 + 1) = *itr2;
      itr2--;
    }
    *(itr2 + 1) = tmp;
  }
}

template<typename T>
void Array<T>::print(  ) {
  for (typename vector<T>::iterator itr = array.begin(); itr != array.end( ); itr++ ) {
    cout << *itr << " ";
  }  
  cout << endl;
}

int main(  ) { 
  Array<string> a1;

  a1.insert( "pteb" );
  a1.insert( "rufe" );
  a1.insert( "bxnx" );
  a1.insert( "fhcq" );
  a1.insert( "qmnt" );
  a1.insert( "bwvd" );
  a1.insert( "micw" );
  a1.insert( "tejg" );
  a1.insert( "uakx" );
  a1.insert( "rysm" );
  a1.insert( "khti" );
  a1.insert( "usnf" );
  a1.insert( "ntut" );
  a1.insert( "qjbt" );
  a1.insert( "nntp" );
  a1.insert( "ajxw" );
  a1.insert( "krwo" );
  a1.insert( "wkvk" );
  a1.insert( "xuts" );
  a1.insert( "kpaj" );
    
  cout << "ソート前: ";
  a1.print(  );
    
  a1.insertion_sort( );

  cout << "ソート後: ";
  a1.print(  );     
    
  return 0;
}
