#include <iostream>
#include <iomanip>
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
using namespace std;

#define REP(i,n) for(int i=0;i<(int)n;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
#define chmax(a,b) (a<(b)?(a=b,1):0)
#define chmin(a,b) (a>(b)?(a=b,1):0)
#define valid(y,x,h,w) (0<=y&&y<h&&0<=x&&x<w)
const int INF = 1<<29;
const double EPS = 1e-8;
const double PI = acos(-1);
typedef pair<int,int> pii;
typedef long long ll;

ll count(ll X, int p) {
  ll t = (X&~((1LL<<p+1)-1));
  // cout << t << " " << bitset<3>(t) << endl;
  ll res = t/2;
  t |= 1LL<<p;
  res += max(0LL,X-t+1);
  return res;
}

int main() {
  int n;
  while(cin >> n, n) {
    ll k[n];
    REP(i,n) {
      cin >> k[i];
    }
    vector<pair<ll, ll> > ans;
    for (ll w=2*k[0]-1; w<=2*k[0]+1; ++w) {
      bool ng = 0;
      ll A=-1,B=0;
      for (int i=n-1; i>=0; --i) {
        if (k[i] == w) B |= 1LL<<i;
        else if (k[i] == 0) ;
        else if (k[i] > w) ng = 1;
        else {
          B |= 1LL<<i;
          B += k[i]-1;
          A = B-w+1;
          break;
        }
      }
      if (A == -1) {
        if (w != 1) continue;
        A = B;
      }
      if (A<=0 || A>1000000000000000000LL ||
          B<=0 || B>1000000000000000000LL) continue;
      // cout << w << " " << bitset<3>(A) << " " << bitset<3>(B) << " " << ng << endl;
      // cout << count(A-1,0) << endl;
      REP(i,n) {
        ng |= (count(B,i)-count(A-1,i)) != k[i];
      }
      if (!ng) {
        ans.push_back(make_pair(A,B));
      }
    }
    if (ans.size() == 0) puts("None");
    else if (ans.size() > 1) puts("Many");
    else {
      cout << ans[0].first << " " << ans[0].second << endl;
    }
  }
}