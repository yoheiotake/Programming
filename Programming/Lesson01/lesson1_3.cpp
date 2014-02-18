#include <iostream>
using namespace std;

class Complex{
private:
  float x;
  float y;
public:
  Complex(Complex *p);
  Complex(float a,float b);
  void printValue();
  void def(float a,float b);
  void sum(Complex *p);
  void sub(Complex *p);
};

Complex::Complex(Complex *p){
  x=p->x;
  y=p->y;
}

Complex::Complex(float a,float b){
  x=a;
  y=b;
}

void Complex::def(float a, float b) {
  x=a;
  y=b;
}

void Complex::sum(Complex *p){
  x+=p->x;
  y+=p->y;
}

void Complex::sub(Complex *p){
  x-=p->x;
  y-=p->y;
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
  Complex *p =&c;
  Complex d(p);
	
  cout << "加算 = 0, 減算 = 1" << endl;
  cin >> state;
	
  cout << "複素数: a + bi" << endl << "a = ";
  cin >> a;
  cout << "b = ";
  cin >> b;  
	
  if (state == 0) {
    c.def(a,b);		
    d.sum(p);
  }
  else if (state == 1) {
    c.def(a,b);		
    d.sub(p);
  }
	
  cout << "答え = ";
	
  d.printValue();
	
  return 0;
}
