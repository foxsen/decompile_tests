#include<iostream>

using namespace std;

int main(){
  int n,m;
  while(cin>>n>>m, n+m){
    int (*b)[1300]=new int[10002][1300];
    int r,q;
    for(cin>>r;r>0;r--){
      int t,p,s,l;
      cin >> t >> p >> s >> l;
      while(t<1280) b[s][t++]+=(l!=0?l:-1);
    }
    for(cin>>q;q>0;q--){
      int t1,t2,m,a=0;
      cin >> t1 >> t2 >> m;
      while(t1<t2) a+=(b[m][t1++]>0?1:0);
      cout << a << endl;
    }
    delete [] b;
  }
  return 0;
}