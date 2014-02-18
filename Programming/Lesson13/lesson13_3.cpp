#include <iostream>
#include <vector>
#include <fstream>
#include <ctime>    // clock関数等を用いて時間を計るために必要
using namespace std;

class Array {
private:
  vector<int> array;
public:
  void insert( int value ){ array.push_back( value ); }
  int getSize( ){ return (int)array.size( ); }
  void selection_sort(  );
  void insertion_sort(  );
  void bubble_sort(  );
  void marge_sort(  ){ marge_sort( 0, (int)array.size( ) - 1 ); }
  void marge_sort( int left, int right );
  void marge( int left, int middle, int right );
  void quick_sort(  ){ quick_sort( 0, (int)array.size( ) - 1 ); }
  void quick_sort( int left, int right );
  int partition( int left, int right );
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

void Array::print(  ) {
  for ( int i = 0; i < (int)array.size( ); i++ ) {
    cout << array[i] << " ";
  }  
  cout << endl;
}

int main(  ) {
  int value;
  bool option;
  char filename[20];
  Array a1;

  cout << "データファイルを開きます. " << endl;
  cout << "ファイル名: ";
  cin >> filename;
  ifstream fin( filename );
  if ( !fin ) {
    cout << "データファイルを開くことができません. " << endl;
    return 1;
  }
  while ( !fin.eof( ) ) {
    fin >> value;
    a1.insert( value );
  }
  fin.close( );

  int sss = 0;
  cout <<"Select Sorting System"<< endl;
  cout <<"1.selection_sort 2.bubble_sort 3.insertion_sort 4.marge_sort 5.quick_sort"<< endl;
  cin  >> sss;

  if(sss == 0){
    cout <<"Invalid Number"<<endl;
    return 0;
  }

  cout << "要素数: " << a1.getSize( ) << endl;

  cout << "- ソート開始 -" << endl;
  clock_t starttime = clock( );
  
  if(sss == 1)
    a1.selection_sort(  );
  else if(sss == 2)
    a1.bubble_sort( );
  else if(sss == 3)
    a1.insertion_sort( );
  else if(sss == 4)
    a1.marge_sort( );
  else
    a1.quick_sort( );

  clock_t endtime = clock( );
  cout << "- ソート完了 -" << endl;

  double sec = endtime - starttime;
  sec /= CLOCKS_PER_SEC;  // CLOCKS_PER_SEC は，ctime で定義されている定数．関数 clock の結果を CLOCKS_PER_SEC で割ると秒になる．
  cout << "ソート時間: " << sec << " sec" << endl;

  cout << "ソート結果を表示しますか？　0: 表示しない, 1: 表示する > ";
  cin >> option;
  if( option ) {
    a1.print(  );
  }

  return 0;
}
