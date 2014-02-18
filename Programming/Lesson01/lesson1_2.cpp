#include <iostream>
using namespace std;

class Complex{
private:
  float x;
  float y;
public:
  Complex(float a,float b);
  void printValue();
  void sum(float a,float b);
  void sub(float a,float b);
};

Complex::Complex(float a,float b){
  x=a;
  y=b;
}

void Complex::sum(float a, float b) {
  x+=a;
  y+=b;
}

void Complex::sub(float a, float b) {
  x-=a;
  y-=b;	
}

void Complex:: printValue( ) {
  cout << x <<" + "<< y <<" i "<<endl;
}

int main( )
{
  float a, b;
  int state;
	
  cout << "複素数: a + bi" << endl << "a = ";
  cin >> a;
  cout << "b = ";
  cin >> b;    
	
  Complex c(a,b);
	
  cout << "加算 = 0, 減算 = 1" << endl;
  cin >> state;
	
  cout << "複素数: a + bi" << endl << "a = ";
  cin >> a;
  cout << "b = ";
  cin >> b;  
	
  if (state == 0) {
    c.sum(a,b);		
  }
  else if (state == 1) {
    c.sub(a,b);		
  }
	
  cout << "答え = ";
	
  c.printValue();
	
  return 0;
}
