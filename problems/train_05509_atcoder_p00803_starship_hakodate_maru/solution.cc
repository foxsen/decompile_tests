#include<iostream>
#define r(i,n) for(int i=0;i<n;i++)
using namespace std;
int a[160000],n;
int main(){
  r(j,1e9){
    int t=j*j*j;
    if(t>=160000)break;
    a[t]++;
    r(i,1e9){
      int p=i*(i+1)*(i+2)/6;
      if(p<160000)a[p]++;
      else break;
      if(p+t<160000)a[p+t]++;
    }
  }
  r(i,160000){
    if(a[i])a[i]=i;
    else a[i]=a[i-1];
  }
  while(cin>>n,n) cout<<a[n]<<endl;
}