#include <iostream>
using namespace std;

// クラスの宣言
class Complex {
private:
  float re;
  float im;
public:
  Complex();
  Complex( float a, float b );
  void sum( Complex value );
  void sub( Complex value );
  void printValue( );
};

Complex::Complex(){
  re=0;
  im=0;
}

// コンストラクタの定義
Complex::Complex( float a, float b ) {
  re = a;
  im = b;
}

// 複素数 re + im i に複素数 value を加算する関数
void Complex::sum( Complex value ) {
  re = re + value.re;
  im = im + value.im;
}

// 複素数 re + im i から複素数 value を減算する関数
void Complex::sub( Complex value ) {
  re = re - value.re;
  im = im - value.im;
}

// 複素数 re + im i を表示する関数
void Complex::printValue( ) {
  cout << re << " + " << im << " i" << endl;
}

int main( )
{
  float a, b;
  int state;

  cout << "複素数: a + bi" << endl << "a = ";
  cin >> a;
  cout << "b = ";
  cin >> b;

  Complex value1(a, b);

  cout << "加算 = 0, 減算 = 1" << endl;
  cin >> state;

  cout << "複素数: a + bi" << endl << "a = ";
  cin >> a;
  cout << "b = ";
  cin >> b;

  Complex value2(a, b);
  Complex value;
  value = value1;

  if (state == 0) {
    value.sum(value2);
  }
  else if (state == 1) {
    value.sub(value2);
  }

  cout << "答え = ";
  value1.printValue( );
// value.printValue( );   正しく表示される

  return 0;
}
