#include<deque>
#include<list>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<vector>
#include<algorithm>
#include<string>
#include<iostream>
#include<sstream>
#include<cmath>
#include<cstdio>
using namespace std;
struct S{
  char s[11];
};
int b[10],n,m;
vector<int> a[10],x,y,q,r;
char t[11],u[11];
vector<S> s;
int fi(int p){
  int i,j;
  if(p==n){
    for(i=0;i<m;++i){
      if(q[i]!=x[i]||r[i]!=y[i])
	break;
    }
    if(i==m){
      if(u[0]=='\0')
	copy(t,t+11,u);
      else
	return 1;
    }
  }else{
    for(i=0;i<10;++i){
      if(b[i]){
	int fl=-1;
	for(j=0;j<m;++j){
	  if(0){
	  }else if(s[j].s[p]-'0'==i){
	    ++q[j];
	    if(q[j]>x[j])
	      fl=0;
	  }else if(a[i][j]){
	    ++r[j];
	    if(r[j]>y[j])
	      fl=0;
	  }
	}
	if(fl){
	  b[i]=0;
	  t[p]='0'+i;
	  if(fi(p+1))
	    return 1;
	  b[i]=-1;
	}
	for(j=0;j<m;++j){
	  if(0){
	  }else if(s[j].s[p]-'0'==i){
	    --q[j];
	  }else if(a[i][j]){
	    --r[j];
	  }
	}
      }
    }
  }
  return 0;
}
int main(){
  int i,j;
  while(cin>>n>>m,n||m){
    S c;
    s.assign(m,c);
    x.assign(m,0);
    y.assign(m,0);
    for(i=0;i<10;++i)
      a[i].assign(m,0);
    for(i=0;i<m;++i){
      cin>>s[i].s>>x[i]>>y[i];
      for(j=0;j<n;++j)
	a[s[i].s[j]-'0'][i]=-1;
    }
    fill(b,b+10,-1);
    fill(t,t+11,0);
    fill(u,u+11,0);
    q.assign(m,0);
    r.assign(m,0);
    if(fi(0)||u[0]=='\0')
      cout<<"NO"<<endl;
    else
      cout<<u<<endl;
  }
  return 0;
}