#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <complex>
#include <cstring>
#include <cstdlib>
#include <string>
#include <cmath>
#include <cassert>
#include <queue>
#include <set>
#include <map>
#include <valarray>
#include <bitset>
#include <stack>
#include <iomanip>
#include <fstream>
using namespace std;

#define REP(i,n) for(int i=0;i<(int)(n);++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
#define chmax(a,b) (a<b?(a=b,1):0)
#define chmin(a,b) (a>b?(a=b,1):0)
#define valid(y,x,h,w) (0<=y&&y<h&&0<=x&&x<w)
const int INF = 1<<29;
const double EPS = 1e-8;
const double PI = acos(-1);
typedef long long ll;
typedef pair<int,int> pii;

int e[100];
int c[100];
int h[100];
int a[100];
int dp[101][101];
int dp_tr[101][101];            // [i][j] = i種類のトレーニングを行って，体力j消費するときの消費カロリーの最大
int dp_d[10000];             // [i] = カロリーがi以下なドーナツの食べ方の最大幸福度

int main() {
  int S,T,U,N,O,D;
  while(cin>>S>>T>>U>>N>>O>>D) {
    REP(i,T) {
      cin >> e[i] >> c[i];
    }
    REP(i,N) {
      cin >> h[i] >> a[i];
    }
    memset(dp_tr,-1,sizeof(dp_tr));
    dp_tr[0][0] = 0;
    REP(i,T) {
      for (int j=T-1; j>=0; --j) {
        REP(k,101) {
          if (dp_tr[j][k] == -1) continue;
          if (k+e[i] <= 100) {
            chmax(dp_tr[j+1][k+e[i]], dp_tr[j][k]+c[i]);
          }
        }
      }
    }
    memset(dp_d,0,sizeof(dp_d));
    REP(i,N) {
      REP(k,10001) {
        if (k+a[i] <= 10000) {
          chmax(dp_d[k+a[i]], dp_d[k] + h[i]);
        }
      }
    }
    // REP(i,21) {
    //   cout << i << " " << dp_tr[U][i] << " " << dp_d[i] << endl;
    // }
    memset(dp,-1,sizeof(dp));
    dp[0][S] = 0;
    REP(i,D) {
      REP(j,S+1) {
        if (dp[i][j] == -1) continue;
        REP(k,j+1) {
          if (dp_tr[U][k] == -1) continue;
          chmax(dp[i+1][min(S,j-k+O)], dp[i][j] + dp_d[dp_tr[U][k]]);
        }
      }
    }
    cout << *max_element(dp[D],dp[D]+S+1) << endl;
  }
}