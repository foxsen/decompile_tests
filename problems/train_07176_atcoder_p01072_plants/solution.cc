#include <iostream>
using namespace	std;
int main(){

  int w,h,t0,p,a[50][50]={},r=0;
  cin>>w>>h>>t0>>p;
  for(int i=0,x,y,t;i<p&&cin>>x>>y>>t;i++) if(t<=t0) a[y][x]++;
  for(int i=0,tmp;i<h;i++) for(int j=0;j<w&&cin>>tmp;j++) if(tmp) r+=a[i][j];
  cout<<r<<endl;
  return 0;

}