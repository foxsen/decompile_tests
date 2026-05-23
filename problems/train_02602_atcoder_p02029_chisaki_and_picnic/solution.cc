#include<bits/stdc++.h>
using namespace std;
using Int = long long;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

//INSERT ABOVE HERE
signed main(){
  Int n,m;
  cin>>n>>m;
  vector<Int> a(n),b(n);
  for(Int i=0;i<n;i++) cin>>a[i]>>b[i];
  vector<Int> c(m),d(m);
  for(Int i=0;i<m;i++) cin>>c[i]>>d[i];

  {
    vector<Int> x,y;
    x.emplace_back(c[0]);
    y.emplace_back(d[0]);
    for(Int i=1;i<m;i++){
      if(y.back()<=d[i]) continue;
      if(x.back()==c[i]){
        y.back()=d[i];
      }else{
        x.emplace_back(c[i]);
        y.emplace_back(d[i]);
      }      
    }
    m=x.size();
    c=x;d=y;
  }  

  priority_queue<Int, vector<Int>, greater<Int> > pq;    
  Int j=n-1;
  for(Int i=m-1;i>=0;i--){
    while(j>=0&&a[j]>=c[i]) pq.emplace(b[j--]);
    while((Int)pq.size()>=d[i]) pq.pop();
  }
  while(j>=0) pq.emplace(b[j--]);

  Int ans=0;
  while(!pq.empty()){
    ans+=pq.top();
    pq.pop();
  }
  
  cout<<ans<<endl;
  return 0;
}

