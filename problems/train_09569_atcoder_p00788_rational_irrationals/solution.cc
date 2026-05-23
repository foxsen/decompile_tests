#include<iostream>
#include<algorithm>
#include<cmath>
 
using namespace std;
 
struct DATA{
  int x, y;
  double r;
  DATA(){}
  DATA(int x_, int y_){ x=x_; y=y_; r=(double)x/(double)y; }
  void set(int x_, int y_){ x=x_; y=y_; r=(double)x/(double)y; }
};
 
int main(){
  int n;
  double p, k;
  DATA a, b;
 
  while(1){
    cin >> p >> n;
    if(p == 0 && n == 0) break;
 
    p = sqrt(p);
    a.set((int)p, 1);
    b.set((int)p+1, 1);
 
    for(int i=b.x+1; i<=n; ++i){
      for(int j=2; j<i; ++j){
	k = (double)i/(double)j;
	if(k < a.r) break;
	if(k > b.r) continue;
	if(a.r < k && k <= p) a.set(i, j);
	else if(p < k && k < b.r) b.set(i, j);
      }
    }
    cout << b.x << "/" << b.y << " " << a.x << "/" << a.y << endl;
  }
  return 0;
}