#include<bits/stdc++.h>
#define X first
#define Y second
#define pb emplace_back
#define FOR(i,a,b) for(int (i)=(a);i<(b);++(i))
#define EFOR(i,a,b) for(int (i)=(a);i<=(b);++(i))
#define rep(X,Y) for (int (X) = 0;(X) < (Y);++(X))
#define REP rep
#define rrep(X,Y) for (int (X) = (Y)-1;(X) >=0;--(X))
#define all(X) (X).begin(),(X).end()
#define eb emplace_back

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef ll LL;
typedef pii PII;
typedef pll PLL;
const ll MOD=1e9+7;

#define rall(X) (X).rbegin(),(X).rend()
#define UNIQUE(X) (X).erase(unique(all(X)),(X).end())
#define reps(X,S,Y) for (int (X) = S;(X) < (Y);++(X))
#define rreps(X,S,Y) for (int (X) = (Y)-1;(X) >= (S);--(X))
template<class T> inline bool MX(T &l,const T &r){return l<r?l=r,1:0;}
template<class T> inline bool MN(T &l,const T &r){return l>r?l=r,1:0;}

const LL INF = 1LL << 61;

int N;
LL L[5145];
LL R[5145];
LL W[5145];
LL dp[2][5145];
int Llast[2][5145];
int Rlast[2][5145];
vector<int> ps;

LL Solve(LL x) {
  rep(i, N) {
    L[i] -= x;
    R[i] += x;
  }

  int src = 0;
  int dst = 1;
  fill(dp[src], dp[src+1], INF);
  dp[src][0] = 0;
  rep(i, N) {
    fill(dp[dst], dp[dst+1], INF);

    int idx = ps[i];
    rep(j, i+1) {
      if (MN(dp[dst][j+1], dp[src][j] + j*W[idx] + R[idx])) {
        Llast[dst][j+1] = idx;
        Rlast[dst][j+1] = Rlast[src][j];
      }

      if (MN(dp[dst][j], dp[src][j] + (i-j)*W[idx] + L[idx])) {
        Llast[dst][j] = Llast[src][j];
        Rlast[dst][j] = idx;
      }
    }

    swap(src, dst);
  }

  LL ret = INF;
  if (N%2 == 0) {
    ret = dp[src][N/2];
  } else {
    int l = N/2;
    int idx = Rlast[src][l];
    MN(ret, dp[src][l] - (N-l)*L[idx] + l*L[idx]);
    idx = Llast[src][l+1];
    MN(ret, dp[src][l+1] - (l+1)*R[idx] + (N-1-l)*R[idx]);
  }

  rep(i, N) {
    L[i] += x;
    R[i] -= x;
  }

  return ret;
}

signed main(){
  ios_base::sync_with_stdio(false);
  cout<<fixed<<setprecision(0);

  cin >> N;

  LL ml = INF;
  LL mr = INF;
  rep(i, N) {
    cin >> L[i] >> R[i];
    W[i] = L[i] + R[i];
    ps.eb(i);
    MN(ml, L[i]);
    MN(mr, R[i]);
  }
  sort(all(ps), [&](int a, int b){return W[a] > W[b];});

  LL ans = INF;
  ans = Solve(0);
  //LL low = -ml-1;
  //LL high = mr+1;
  //while (high - low > 10) {
  //  LL lmid = (high+low*2)/3;
  //  LL rmid = (high*2+low)/3;
  //  LL lval = Solve(lmid);
  //  LL rval = Solve(rmid);
  //  if (lval < rval) high = rmid;
  //  else low = lmid;
  //}

  //for (LL i=low; i<high+1; i++) {
  //  if (i < -ml || mr < i) continue;
  //  MN(ans, Solve(i));
  //}
  cout << ans << endl;
}
