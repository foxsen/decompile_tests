#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;
  while(n--){
    int x=0,y=0,mx=-1000,my=0,md=0;
    while(1){
      int dx,dy;
      cin >>dx >>dy;
      if(dx==0 && dy==0) break;
      x+=dx,y+=dy;
      if(x*x+y*y>md) mx=x,my=y,md=x*x+y*y;
      else if(x*x+y*y==md && mx<x) mx=x,my=y,md=x*x+y*y;
    }
    cout << mx <<" "<<my<<endl;
  }
  return 0;
}