#include <iostream>
#include <vector>
using namespace std;

class Array {
private:
  vector<int> array;
public:
  void insert( int value ){ array.push_back( value ); }
  void insertion_sort(  );
  void print(  );
};

// 挿入ソートを行う関数
void Array::insertion_sort( ) {
  for ( vector<int>::iterator itr1 = array.begin() + 1; itr1 != array.end(); itr1++ ) {
    int tmp = *itr1;    
    vector<int>::iterator itr2 = itr1 - 1;
    while ( itr2 >= array.begin() && *itr2 > tmp ) {
      *(itr2 + 1) = *itr2;
      itr2--;
    }
    *(itr2 + 1) = tmp;
  }
}

//配列の内容を表示する関数
void Array::print(  ) {
  for ( vector<int>::iterator itr = array.begin(); itr != array.end( ); itr++ ) {
    cout << *itr << " ";
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
    
  cout << "ソート前: ";
  a1.print(  );
    
  a1.insertion_sort( );
    
  cout << "ソート後: ";
  a1.print(  );       
    
  return 0;
}
