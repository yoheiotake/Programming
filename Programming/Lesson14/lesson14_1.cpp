#include<iostream>
#include<string>
using namespace std;

class Shape{
private:
  double x;
  double y;
public:
  Shape(double _x, double _y);
  double getLocationX(){return x;};
  double getLocationY(){return y;};
};

class Circle:public Shape{ // Circle(サブクラス)はShape(スーパークラス)を継承する
private:
  double radius;
  static const double pi = 3.1415; // インスタンス変数の定数化は静的に行う
//Static const string ShapeName = "円";  // Semantic Error
public:
  Circle(double _x, double _y, double _r);
  string getShapeType(){return "円";};
  double calcArea(){return pi*radius*radius;};
};

class Square:public Shape{
private:
  double size;
public:
  Square(double _x, double _y, double _s);
  string getShapeType(){return "正方形";};
  double calcArea(){return size*size;};
};


Shape::Shape( double _x, double _y ){
  x = _x;
  y = _y;
}

Circle::Circle( double _x, double _y, double _r ):Shape(_x,_y){ // サブクラスのパラメータを引数としてスーパクラスのオブジェクトを生成する
  radius = _r;
}
Square::Square( double _x, double _y, double _s ):Shape(_x,_y){
  size = _s;
}



int main( ) {
    
  Circle c1(1.0, 2.0, 3.0);   // 引数は順に，位置の x 座標，位置の y 座標，円の半径
  Square s1(2.0, 1.0, 2.0);   // 引数は順に，位置の x 座標，位置の y 座標，一辺の長さ
  Circle c2(3.0, 2.0, 2.0);   // 引数は順に，位置の x 座標，位置の y 座標，円の半径
    
  cout << c1.getShapeType( ) << endl;
  cout << "位置: ( x, y ) = ( " << c1.getLocationX( ) << ", " << c1.getLocationY( ) << " )" << endl;
  cout << "面積: " << c1.calcArea( ) <<  endl;
  cout << endl;
    
  cout << s1.getShapeType( ) << endl;
  cout << "位置: ( x, y ) = ( " << s1.getLocationX( ) << ", " << s1.getLocationY( ) << " )" << endl;
  cout << "面積: " << s1.calcArea( ) <<  endl;
  cout << endl;

  cout << c2.getShapeType( ) << endl;
  cout << "位置: ( x, y ) = ( " << c2.getLocationX( ) << ", " << c2.getLocationY( ) << " )" << endl;
  cout << "面積: " << c2.calcArea( ) <<  endl;    
  cout << endl; 
    
  return 0;
}



/**********************************************************************************************
<継承の方法>
class サブクラス名:アクセス指定子 スーパークラス名{

}

<アクセス指定子>
private   :サブクラスはスーパークラスのpublicメンバを非公開メンバとして継承する
protected :スーパークラスのメンバを非公開にしたまま、サブクラスからアクセス可能
public    :スーパークラスのpublicメンバを公開メンバとして継承し、外部からアクセス可能

privateの場合はサブクラスからはスーパークラスのメンバにアクセスできない.
protectedの場合はサブクラスのインスタンスメソッドの内部からはアクセスすることができる.
publicの場合はサブクラスとサブクラスの外部からスーパークラスのpublicメンバにアクセスできる.
上のプログラムだとprotectedだとエラーになる．getLocation()はサブクラスであるSquare及びCircle
のオブジェクトをパイプしてクラスの外からスーパークラスのメンバを呼び出しているためエラーになる．


**********************************************************************************************/
