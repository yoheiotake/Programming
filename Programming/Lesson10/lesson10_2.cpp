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
  bool putQueen( int x );
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

bool Board::putQueen( int x ) {
  if(x == size)
    return true;
  for( int y = 0; y < size ; y++ ){
    if( isFree(x,y) == true ){
      array[x][y] = true;
      if( putQueen(x + 1) == true )
        return true;
    }
    else
      array[x][y] = false;
  }
  return false;
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
  if( board.putQueen( 0 ) == true ) {
    board.print(  );     
  }
  else {
    cout << "解は存在しません．" << endl;
  }
  return 0;
}
