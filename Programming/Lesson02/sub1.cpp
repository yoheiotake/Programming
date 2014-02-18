#include <iostream>
#include <limits.h>  
using namespace std;


class Array {
private:
  const static int size = 10;
  int array[size];
  int *p;       
public:
  Array( );
  int  getSize( );
  void put( int index, int data );
  int  get( int index );
  void extract( int *resultArray, int index1, int index2 );
};


Array::Array( ) {
  p = array;                         
  for(int c = 0; c < size; c++,p++)  
    *p = 0;		     
}


int Array::getSize( ) {
  return size;
}


void Array::put( int index, int data ) {
  p = array;          
  p[index] = data;    
}


int Array::get( int index ) {
  p = array;
  return p[index];	
}



void Array::extract( int *resultArray, int index1, int index2 ) {
  p = array;
  for(int c = 0; c < (index2 - index1 + 1); c++, resultArray++ ) 
    *resultArray = 0;                                           

  for(resultArray -= 1; index1 <= index2; resultArray--, index2--) 
    *resultArray = p[index2];                                   

  return;
}


int main( ) {
  int start, end;
  Array myArray;

  myArray.put(0, 23);
  myArray.put(1, 2);
  myArray.put(3, 11);
  myArray.put(4, 1);
  myArray.put(5, 8);    
  myArray.put(7, 17);
  myArray.put(8, 20);
  myArray.put(9, 6);

  cout << "配列の中身: " << endl << "| ";
  for ( int i = 0; i < myArray.getSize(); i++ )
    cout << myArray.get(i) << " | ";
  cout << endl;

  bool flag = 0;                     
  while(true){                       
    if(flag == 0){                      
      cout << "抽出開始位置: ";
      cin >> start;
      if(!cin || start < 0 || start > 9){
       cout << "Invalid Number" << endl;
       cin.clear();                     
       cin.ignore(INT_MAX,'\n');   
       continue;
      }
      flag = 1;                      
    }
    cout << "抽出終了位置: ";
    cin >> end;
    if(!cin || end < 0 || end > 9){      
      cout << "Invalid Number" << endl;
      cin.clear();                       
      cin.ignore(INT_MAX,'\n');          
      continue;                          
    }
    if( start > end ){                   
      cout << "Invalid Combination" << endl;
      flag = 0;                          
      continue;
    }
    cin.clear();                        
    cin.ignore(INT_MAX,'\n');           
    break;                               
  }

  int result[end - start + 1];            
	
  myArray.extract(result,start,end);      
	
  cout << "抽出された要素: " << endl << "| ";
  for ( int i = 0; i < (end - start + 1); i++ )
    cout << result[i] << " | ";
  cout << endl;

  return 0;
}
