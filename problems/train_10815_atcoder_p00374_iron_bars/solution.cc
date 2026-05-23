#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[6001][6001],b[6001];
int n,m,x,y,mn;
unordered_set<ll> st;

bool check(int A,int B,int C){
  for(int i=0;i<=min(mn,a[A][B]);i++)
    for(int j=0;i+j<=min(mn,a[B][C]+i);j++){
      int k=x-i-j;
      if(i+k>4||j+k>4||a[A][C]<k)continue;
      if(A==C&&(a[A][A]<x||b[A]<12-2*(i+j+k)))continue;
      if(A==B&&(a[A][C]<j+k||b[A]<8-(2*i+j+k)))continue;
      if(B==C&&(a[A][B]<i+k||b[B]<8-(i+2*j+k)))continue;
      if(b[A]>=4-i-k&&b[B]>=4-i-j&&b[C]>=4-j-k)return 1;
    }
  return 0;
}

int main(){
  int t[6000],v[6000];
  cin>>n>>m>>x>>y;
  for(int i=0;i<n;i++){
    cin>>t[i];
    if(i>=m)b[t[i]]++;
  }
  for(int i=0;i<m;i++){
    cin>>v[i];
    int p=t[i]-v[i];
    if(v[i]>p)swap(v[i],p);
    a[v[i]][p]++;
  }
  if(x){
    ll M=6001;
    mn=min(4,x);
    for(int i=0;i<m;i++)
      for(int j=1;j<=6000;j++){
	ll p1=v[i],p2=t[i]-v[i],p3=j;
	if(p2>p3)swap(p2,p3);
	if(p1>p2)swap(p1,p2);
	ll s=p1*M*M+p2*M+p3;
	if(!st.count(s)&&check(p1,p2,p3))st.insert(s);
      }
    cout<<st.size()<<endl;
  }
  else{
    ll c4=0,c8=0,c12=0;
    for(int i=1;i<=6000;i++){
      if(b[i]>=4)c4++;
      if(b[i]>=8)c8++;
      if(b[i]>=12)c12++;
    }
    cout<<c4*(c4-1)*(c4-2)/6+c8*(c4-1)+c12<<endl;
  }
  return 0;
}