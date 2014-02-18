#include <iostream>
#include <fstream>
#include<limits.h>
#include <string>
using namespace std;

int main()
{
  ifstream ifs("test.txt");
  ofstream ofs("test_out.txt");

  if(!ifs || !ofs){
    cout <<"Invalid FileName"<<endl;
    return 1;
  }

  int num=0;
  while(true){
    cout <<"Input Number from 1 to 3"<<endl;
    cin >> num;
    if(1<= num || num<=3)
      break;
    cout<<"Invalid Number"<<endl;
    cin.clear();
    cin.ignore(INT_MAX,'\n');
  }

  int p=0;
  string s(" ");
  if(num==1){
    while(true){
      if(ifs >> p == false)
       break;
      if(p % 3 == 0)
       ofs << p << s;
    }
  }

  else if(num==2){
    int c=0;
    while(!ifs.eof()){
      ifs >> p;
      c++;
      cout << p <<' '<< c <<endl;
      if(p % 3 == 0){
       ofs << p << s;
      }
    }
  }

  else{
    int c=0;
    while(true){
      ifs >> p;
      if(ifs.eof())
       break;
      c++;
      cout << p <<' '<< c <<endl;
      if(p % 3 == 0){
       ofs << p << s;
      }
    }
  }
  ifs.close();
  ofs.close();

  return 0;
}


/***************************************

<num==1の場合>
入力ファイルに文字などがある場合、
そこから先のデータは読み込めない。

<num==2の場合>
入力ファイルに文字などがある場合、
無限ループになる。
また、eof()メンバ関数は最後の値に2度
アクセスするため、
最後のデータが3の倍数のとき
同じ値を2度書き出してしまう。

<num==3の場合>
num==2の改良版で2度目のアクセスを防ぐ。
eof()関数は最後の値の次まで読み込み（
終端の判断）最後の値で返す。

***************************************/


