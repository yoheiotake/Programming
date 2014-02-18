#include <iostream>
using namespace std;

class Complex {
private:
  float re;
  float im;
public:
  Complex( float a, float b );
  void sum( Complex value );
  void sub( Complex value );
  void printValue( );
};


Complex::Complex( float a, float b ) {
  re = a;
  im = b;
}


void Complex::sum( Complex value ) {
  re = re + value.re;
  im = im + value.im;
}


void Complex::sub( Complex value ) {
  re = re - value.re;
  im = im - value.im;
}


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
	
  if (state == 0) {
    value1.sum(value2);
  }
  else if (state == 1) {
    value1.sub(value2);
  }
	
  cout << "答え = ";
  value1.printValue( );
  
  return 0;
}

