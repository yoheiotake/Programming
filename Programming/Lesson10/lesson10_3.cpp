#include <iostream>
#include <vector>
using namespace std;

class Board {
private:
  vector< vector<bool> > array;
  int size;
public:
  Board( int _size );
  bool isFree( int x, int y );
  int putQueen( int x );
  void print(  );
};

Board::Board( int _size ) {
  size = _size;
  array.resize( size );
  for ( int i = 0; i < size; i++ ) {
    array[i].resize( size );
  }
}

bool Board::isFree( int x, int y ) {
  for(int z = 0; z < x ; z++ ){
    if(array[z][y] == true)
      return false;
    int ul = y - x + z;
    if( ul >= 0 && array[z][ul] )
      return false;
    int dl = y + x - z;
    if( dl < size && array[z][dl] )
      return false;
  }
  return true;
}

int Board::putQueen( int x ) {
  if(x == size){
    print();
    return 1;
  }
  int solution = 0;
  for( int y = 0; y < size; y++){
    if(isFree(x,y) == true){
      array[x][y] = true;
      solution += putQueen( x + 1 );

      array[x][y] = false;
    }
  }
  return solution;
}

void Board::print( ) {
  cout <<"解"<< endl;
  for(int y = 0; y < size ; y++){
    for(int x = 0; x < size; x++){
      if(array[x][y] == true)
        cout << 'Q' ;
      else
        cout <<'-';
    }
    cout << endl;
  }

}

int main(  ) {
  int n;
  cout << "N クイーン問題の解を求めます．盤面のサイズを入力してください: ";
  cin >> n;
  Board board( n );
  int solution = board.putQueen(0);
  if( solution > 0) {
    cout << solution <<" 通りの解があります．"<< endl;     
  }
  else {
    cout << "解は存在しません．" << endl;
  }
  return 0;
}
