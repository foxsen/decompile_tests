#include<algorithm>
#include<iostream>
#include<vector>
#include<set>
#include<cassert>
#include<cmath>
using namespace std;
typedef long long lint;
typedef vector<int>vi;
typedef pair<int,int>pii;
typedef pair<lint,lint>pll;
typedef pair<pll,lint>pplll;
#define rep(i,n)for(int i=0;i<(int)(n);++i)

pll fundamental_unit(lint d){
  vi ans;
  lint x=0,y=1,z=1;//(x+y*sqrt(d))/z
  double sqrtd=sqrt(d);
  set<pplll>seen;
  while(1){
    if(seen.count(pplll(pll(x,y),z)))break;
    seen.insert(pplll(pll(x,y),z));
    lint q=floor((x+sqrtd*y)/z);
    if(0){
      cerr<<"x,y,z=("<<x<<"+"<<y<<"*sqrt(d))/"<<z<<endl;
      cerr<<"q="<<q<<endl;
    }
    ans.push_back(q);
    x-=q*z;
    lint norm=x*x-d*y*y;
    y=-y;
    z=norm/z;
    if(z<0){
      x=-x;y=-y;z=-z;
    }
  }
  // recover
  lint num=0,den=1;
  for(int i=(int)ans.size()-2;i>=0;--i){
    lint z=num+ans[i]*den;
    num=den;den=z;
  }
  if(den*den-d*num*num==-1){
    lint x=den*den+d*num*num;
    lint y=2*den*num;
    den=x;num=y;
  }
  assert(den*den-d*num*num==1);
  return pll(den,num);
}

pll solve(lint n){
  rep(i,200)
    if(i*i==2*n)
      return pll(i,1);
  return fundamental_unit(2*n);
}

int main(){
  for(int t=1;;++t){
    lint n;
    cin>>n;
    if(n==0)break;
    pll ans=solve(n);
    cout<<"Case "<<t<<": "<<ans.first<<" "<<ans.second<<endl;
  }
}

