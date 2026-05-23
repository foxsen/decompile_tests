#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define REP(i,n) for(int i=0,_n=(int)(n);i<_n;++i)
#define ALL(v) (v).begin(),(v).end()
#define CLR(t,v) memset(t,(v),sizeof(t))
template<class T1,class T2>ostream& operator<<(ostream& os,const pair<T1,T2>&a){return os<<"("<<a.first<<","<<a.second<< ")";}
template<class T>void pv(T a,T b){for(T i=a;i!=b;++i)cout<<(*i)<<" ";cout<<endl;}
template<class T>void chmin(T&a,const T&b){if(a>b)a=b;}
template<class T>void chmax(T&a,const T&b){if(a<b)a=b;}


int nextInt() { int x; scanf("%d", &x); return x;}
ll nextLong() { ll x; scanf("%lld", &x); return x;}

const int MAX_N = 305;

vector<int> g[MAX_N];
int e[MAX_N][MAX_N];
int flip[MAX_N];
bool vis[MAX_N];

int ans = 1001001001;
int dfs(int N, int b, int cur, int prev, int &cost) {
  if (cost > ans) { throw -1; }
  if (vis[cur]) { throw -1; }
  vis[cur] = true;
  int res = 1;

  if (cur == b) {
    REP(nxt, N) if (nxt != prev && e[cur][nxt] * flip[cur] * flip[nxt] > 0) {
      cost += abs(e[cur][nxt]);
      res += dfs(N, b, nxt, cur, cost);
    }
  } else {

    {
      int nxt = b;
      if (nxt != prev && e[cur][nxt] * flip[cur] * flip[nxt] > 0) {
        cost += abs(e[cur][nxt]);
        res += dfs(N, b, nxt, cur, cost);
      }
    }
    for(int nxt : g[cur]) if (nxt != prev && nxt != b && e[cur][nxt] * flip[cur] * flip[nxt] > 0) {
      cost += abs(e[cur][nxt]);
      res += dfs(N, b, nxt, cur, cost);
    }

  }
  return res;
}

int main2(int N) {
  CLR(e, 0);
  ans = 1001001001;
  for (int i = 0; i < N; i++) {
    for (int j = i + 1; j < N; j++) {
      e[i][j] = e[j][i] = nextInt();
    }
  }
  for (int a = 0; a < N; a++) {
    REP(i, N) g[i].clear();
    REP(i, N) flip[i] = 1;

    // a の周りの辺を全て消す
    for (int x = 0; x < N; x++) if (x != a) {
      if (e[a][x] > 0) { flip[x] = -1; }
    }
    // この状態で g を作成
    REP(i, N) {
      vector<int> v;
      REP(j, N) if (e[i][j] * flip[i] * flip[j] > 0) v.push_back(j);
      g[i] = v;
    }

    for (int b = 0; b < N; b++) if (a != b) {
      // a が葉, b が a に唯一接続している頂点
      flip[b] *= -1;
      try {
        CLR(vis, 0);
        int cost = 0;
        int c = dfs(N, b, 0, -1, cost);
        if (c == N) {
          if (ans > cost) {
            ans = cost;
          }
        }
      } catch (int e) {}
      flip[b] *= -1;
    }
  }

  if (ans == 1001001001)
    cout << -1 << endl;
  else
    cout << ans << endl;

  return 0;
}

int main() {
  for (;;) {
    int N = nextInt();
    if (N == 0) break;
    main2(N);
  }
  return 0;
}
