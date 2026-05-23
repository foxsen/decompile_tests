#include<bits/stdc++.h>
using namespace std;
using Int = long long;
const Int OFS = 50000;
const Int MAX = 1e6 + 2 * OFS;
Int s[MAX],d[MAX],f[MAX];
Int u[MAX];

signed main(){
  Int n,m;
  while(cin>>n>>m,n||m){
    m--;    
    vector<Int> a(m),x(m);
    for(Int i=0;i<m;i++) cin>>a[i]>>x[i];

    memset(s,0,sizeof(s));
    memset(d,0,sizeof(d));
    memset(f,0,sizeof(f));
    
    for(Int i=0;i<m;i++){
      x[i]--;
      x[i]+=OFS;
      if(a[i]==1){
	s[x[i]]++;
	s[x[i]+1]--;
	continue;
      }
      Int c=sqrt(a[i])+1;
      while((c+1)*(c+1)< a[i]) c++;
      while(c*c>=a[i]) c--;
      //cout<<a[i]<<":"<<c<<endl;
      Int l=x[i]-c,r=x[i]+c;
      f[l]  +=-2;
      f[r-1]-=-2;
      d[l]  +=2*c-1;
      d[r]  +=2*c-1;
      s[l]  +=a[i]-c*c;
      s[r+1]-=a[i]-c*c;
    }
    
    for(Int i=0;i+1<MAX;i++) f[i+1]+=f[i];
    for(Int i=0;i+1<MAX;i++) d[i+1]+=d[i]+f[i];
    for(Int i=0;i+1<MAX;i++) s[i+1]+=s[i]+d[i];

    if(0){
      for(Int i=OFS-10;i<OFS+n+10;i++) cout<<f[i]<<" ";cout<<endl;
      for(Int i=OFS-10;i<OFS+n+10;i++) cout<<d[i]<<" ";cout<<endl;
      for(Int i=OFS-10;i<OFS+n+10;i++) cout<<s[i]<<" ";cout<<endl;
    }
    Int t;
    cin>>t;
    // cout<<t<<endl;

    auto check=[&](Int x)->Int{
      memset(u,0,sizeof(u));
      Int cnt=0;
      for(Int i=OFS;i<OFS+n;i++){
	Int d=x-s[i];
	if(d<=0) continue;
	if(d>t) return 0;
	Int c=sqrt(t-d)+1;
	//cout<<d<<" "<<t<<" "<<c<<endl;
	while(d<=t-(c+1)*(c+1)) c++;
	while(d>t-c*c) c--;
	assert(d<=t-c*c);
	assert(d>t-(c+1)*(c+1));
	Int l=i-c,r=i+c;
	//cout<<l<<" "<<r<<":"<<c<<endl;
	//assert(l>=0);
	//l=max(0LL,l);
	//r=min(MAX-1,r);
	u[l]++;
	u[r+1]--;
	cnt++;
      }
      for(Int i=1;i<MAX;i++) u[i]+=u[i-1];
      return *max_element(u,u+MAX)==cnt;
    };
    
    Int l=0,r=*max_element(s,s+MAX)+t+1;
    //cout<<l<<" "<<r<<endl;
    while(l+1<r){
      Int m=(l+r)>>1;
      //cout<<l<<" "<<r<<":"<<m<<endl;
      if(check(m)) l=m;
      else r=m;
    }
    cout<<l<<endl;
  }
  return 0;
}

