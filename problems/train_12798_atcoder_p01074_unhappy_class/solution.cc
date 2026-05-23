#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>

#include <functional>
#include <cassert>

typedef long long ll;
using namespace std;

#define debug(x) cerr << #x << " = " << x << endl;


#define mod 1000000007 //1e9+7(prime number)
#define INF 1000000000 //1e9
#define LLINF 2000000000000000000LL //2e18
#define SIZE 60


int main(){
  int n,m,l;
  int d,a,k,t;
  vector<pair<int,int> > vec[8*5+10];
  
  
  scanf("%d%d%d",&n,&m,&l);

  for(int i=0;i<m;i++){
    scanf("%d%d%d%d",&d,&a,&k,&t);
    int s = (d*n) + (a-1);
    vec[s].push_back({k,t});
  }

  int dp[8*5+10][301] = {};
  
  for(int i=0;i<=5*n;i++){
    for(int j=0;j<=l;j++){
      dp[i][j] = -INF;
    }
  }
  
  dp[0][0] = 0;
  
  for(int i=0;i<5*n;i++){

    for(int j=0;j<vec[i].size();j++){
      for(int k=0;k<l;k++){
        dp[i + vec[i][j].first][k+1] = max(dp[i + vec[i][j].first][k+1], dp[i][k] + vec[i][j].second);
      }
    }
    for(int j=0;j<=l;j++){
      dp[i+1][j] = max(dp[i+1][j],dp[i][j]);
    }
  }

  int ans = 0;
  for(int i=0;i<=l;i++) ans = max(ans,dp[5*n][i]);
  
  printf("%d\n",ans);
  
  return 0;
}