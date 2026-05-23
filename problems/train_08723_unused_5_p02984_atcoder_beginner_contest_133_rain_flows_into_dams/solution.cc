#include <bits/stdc++.h>
using namespace std;

int main(){
  int n; cin>>n;
  vector<long long> a(n);
  long long x=0LL;
  for(int i=0; i<n; ++i){
    cin>>a[i];
    if(i%2==0)x+=a[i];
    else x-=a[i];
  }
  cout<<x<<" ";
  x/=2;
  for(int i=0; i<n-1; ++i){
    x=a[i]-x;
    cout<<x*2<<" ";
  }
  cout<<endl;
  
}
