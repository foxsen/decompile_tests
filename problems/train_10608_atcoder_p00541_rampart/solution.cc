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

#define mod 1000000007 //1e9+7
#define INF 1000000000 //1e9
#define LLINF 2000000000000000000LL //2e18
#define SIZE 4010

struct BIT{

  int data[SIZE];
  int size;
  
  void init(int n){
    for(int i=1;i<=n;i++) data[i] = 0;
    size = n;
  }

  void add(int k,int x){

    while(k<=size){
      data[k] += x;
      k += k&(-k);
    }

  }

  int sum(int k){
    int ret = 0;

    while(k>0){
      ret += data[k];
      k -= k&(-k);
    }

    return ret;
  }
};

int ul_max[SIZE][SIZE],dr_max[SIZE][SIZE];
bool castle[SIZE][SIZE];
BIT bit;
priority_queue<pair<int,int> > pq;

int h,w,l,p;

int calc(int t){
  int ret = 0,s;

  bit.init(h);

  while(pq.size()) pq.pop();
  
  for(int i=1;i<=h;i++){
    if(t+i <= 0 || t+i>w) continue;
    pq.push({-(i-ul_max[i][t+i]+1),i});
  }

  for(int i=1;i<=h;i++){

    while(pq.size() && -pq.top().first <= i){
      bit.add(pq.top().second,1);
      pq.pop();
    }

    if(t+i <= 0 || t+i > w ) continue;

    s = dr_max[i][t+i];
    
    if(s >= l && i+(l-1) <= h){
      
      int add = bit.sum(i+(s-1))-bit.sum(i+(l-2));
      
      ret += add;
    }
  }    

  return ret;
}

int main(){
  int a,b;
  int dp[SIZE];
  
  scanf("%d%d%d%d",&h,&w,&l,&p);
  
  for(int i=0;i<p;i++){
    scanf("%d%d",&a,&b);
    castle[a][b] = true;
  }
  
  for(int i=h;i>=1;i--){
    dp[w+1] = 0;
    for(int j=w;j>=1;j--){
      if(castle[i][j]){
	dp[j] = 0;
      }else{
	dp[j] = dp[j+1]+1;
      }
      dr_max[i][j] = dp[j];
    }
  }

  for(int i=w;i>=1;i--){
    dp[h+1] = 0;
    for(int j=h;j>=1;j--){
      if(castle[j][i]){
	dp[j] = 0;
      }else{
	dp[j] = dp[j+1]+1;
      }
      dr_max[j][i] = min(dr_max[j][i],dp[j]);
    }
  }

  
  for(int i=1;i<=h;i++){
    dp[0] = 0;
    for(int j=1;j<=w;j++){
      if(castle[i][j]){
	dp[j] = 0;
      }else{
	dp[j] = dp[j-1]+1;
      }
      ul_max[i][j] = dp[j];
    }
  }

  for(int i=1;i<=w;i++){
    dp[0] = 0;
    for(int j=1;j<=h;j++){
      if(castle[j][i]){
	dp[j] = 0;
      }else{
	dp[j] = dp[j-1]+1;
      }
      ul_max[j][i] = min(ul_max[j][i],dp[j]);
    }
  }

  ll ans = 0;
  
  for(int i=-h;i<=w-1;i++){
    ans += calc(i);
  }

  printf("%lld\n",ans);
  
  return 0;
}