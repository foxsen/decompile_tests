#include <bits/stdc++.h>
using namespace std;

int main(){
  while(1){
    long long n,m;
    cin>>n>>m;
    if(!n&&!m)break;
    string ans;
    long long c=1,d=1;
    n--;
    while(n-9*c*d>=0) n-=9*c*d,c++,d*=10;

    d=n/c+d;
    while((int)ans.size()<m+n%c+10){
      long long t=d;
      string a;
      while(t)a+=(t%10+'0'),t/=10;
      reverse(a.begin(),a.end());
      ans+=a;
      d++;
    }
    for(int i=n%c;i<m+n%c;i++) cout <<ans[i];
    cout <<endl;
  }
  return 0;
}