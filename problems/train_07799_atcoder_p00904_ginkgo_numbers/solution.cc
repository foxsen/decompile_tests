#include<iostream>
using namespace std;int x[1<<23],p,q,n,i,j;
int main(){
for(i=0;i<1000;i++){for(j=0;j<1000;j++){x[i*i+j*j]++;}}
cin>>n;
for(i=0;i<n;i++){
cin>>p>>q;int r=p*p+q*q,s=0;
for(j=1;j<=r;j++){
    if(r%j==0){s+=x[j]*x[r/j];}
}
if(s==8){cout<<'P'<<endl;}else{cout<<'C'<<endl;}
}
}