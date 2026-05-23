#include "bits/stdc++.h"
#define PB push_back
#define LB lower_bound
#define UB upper_bound
#define x first
#define y second
#define REP(x, l, u) for(ll x = l;x<u;x++)
#define mst(x, a) memset(x,a,sizeof(x))
#define all(a) begin(a),end(a)
#define PLL pair<ll,ll>
#define PII pair<int,int>
#define PLI pair<ll,int>
#define MP make_pair
#define sz(x) ((int)x.size())
#define INF 0x3f3f3f3f
typedef long long LL;
using namespace std;


const int N = 5010;
int w[N];
LL cur[N];
int n;

signed main() {
     int T;
     scanf("%d",&T);
     while(T--) {
          cin >> n;
          for(int i = 0; i<n; i++) cin >> w[i];
          LL ans = 0;
          memset(cur,0,sizeof cur);
          for(int i = 0; i<n; i++) {
            LL temp = cur[i];
            if(temp < w[i] - 1) {
                 ans += w[i] - 1 - temp;
                 temp += w[i] - 1 - temp;
            }
            cur[i+1] += temp - w[i] + 1;
            if(i + 2 < n)
               for(int j = i + 2; j<min(n,w[i] + i + 1) ; j++) cur[j]++;
       }
          cout << ans << endl;
     }
     return 0;
 }


 