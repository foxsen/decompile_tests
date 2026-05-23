#include <bits/stdc++.h>
using namespace std;
//#include <atcoder/all>
//using namespace atcoder;
using ll=long long;
using Graph=vector<vector<int>>;
using pp=pair<ll,pair<ll,ll>>;
#define MAX 1000000
#define MOD 998244353
#define INF 1000000000000000000

int main(){
  int N;
  cin>>N;
  vector<pair<pair<int,int>,int>> xy(N);
  for(int i=0;i<N;i++){
    cin>>xy[i].first.first>>xy[i].first.second;
    xy[i].second=i;
  }
  sort(xy.begin(),xy.end());

  vector<int> m(N),M(N);
  m[0]=xy[0].first.second;
  for(int i=1;i<N;i++){
    m[i]=min(m[i-1],xy[i].first.second);
  }
  M[N-1]=xy[N-1].first.second;
  for(int i=N-2;i>=0;i--){
    M[i]=max(M[i+1],xy[i].first.second);
  }
  vector<int> cnt(N,1);
  for(int i=1;i<N;i++){
    if(m[i-1]<M[i]){
      cnt[i]=cnt[i-1]+1;
    }
  }
  vector<int> ans(N);
  int count=cnt[N-1];
  ans[xy[N-1].second]=count;
  for(int i=N-2;i>=0;i--){
    if(cnt[i+1]==1){
      count=cnt[i];
    }
    ans[xy[i].second]=count;
  }
  for(int i=0;i<N;i++){
    cout<<ans[i]<<endl;
  }
}
