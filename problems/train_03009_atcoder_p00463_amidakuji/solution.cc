#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>

using namespace std;

#define FOR(i,k,n) for(int i=(k); i<(int)n; ++i)
#define REP(i,n) FOR(i,0,n)
#define FORIT(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
typedef pair<int,int> P;

int main(){
  int n,m,h,k;
  while(cin>>n>>m>>h>>k,n){
    vector<int> s(n);
    vector<P> stc(m);
    REP(i,n)cin>>s[i];
    REP(i,m){
      int a,b;
      cin>>a>>b;
      stc[i] = P(b,a-1);
    }
    sort(stc.begin(),stc.end());
    int memo[100000][2];
    int now[100000];
    int point[1000];
    REP(i,n)now[i] = i;
    REP(i,m){
      memo[i][0] = now[stc[i].second];
      memo[i][1] = now[stc[i].second+1];
      swap(now[stc[i].second], now[stc[i].second+1]);
    }
    int fstans = 0;
    int subans = 0;
    REP(i,n)point[now[i]] = s[i];
    REP(i,k)fstans+=point[i];
    REP(i,m){
      if(memo[i][0]<k&&memo[i][1]>=k){
        subans = min(subans, -point[memo[i][0]]+point[memo[i][1]]);
      }
      if(memo[i][1]<k&&memo[i][0]>=k){
        subans = min(subans, -point[memo[i][1]]+point[memo[i][0]]);
      }
    }
    cout<<fstans+subans<<endl;
  }
  return 0;
}