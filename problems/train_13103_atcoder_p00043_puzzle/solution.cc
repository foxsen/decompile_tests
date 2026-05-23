#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<ll> VL;
typedef vector<VL> VVL;
typedef pair<int, int> PII;

#define FOR(i, a, n) for (ll i = (ll)a; i < (ll)n; ++i)
#define REP(i, n) FOR(i, 0, n)
#define ALL(x) x.begin(), x.end()
#define MP make_pair
#define PB push_back
#define MOD 1000000007
#define INF (1LL << 30)
#define LLINF (1LL << 60)
#define PI 3.14159265359
#define EPS 1e-12
//#define int ll

bool f;
void dfs(int a[10], int n) {
  if (n == 1) {
    // FOR(i, 1, 10) cout << a[i] << " "; cout << endl;
    FOR(i, 1, 8) if (a[i] == 1 && a[i + 1] == 1 && a[i + 2] == 1) f = true;
    FOR(i, 1, 10) if (a[i] == 3) f = true;
    return;
  }

  //???????????¨??¨??????
  FOR(i, 1, 8) if (a[i] >= 1 && a[i + 1] >= 1 && a[i + 2] >= 1) {
    int tmp[10];
    REP(j, 10) tmp[j] = a[j];
    --tmp[i];
    tmp[i + 1]--;
    --tmp[i + 2];
    dfs(tmp, n - 1);
  }
  //???????????????
  FOR(i, 1, 10) if (a[i] >= 3) {
    int tmp[10];
    REP(j, 10) tmp[j] = a[j];
    tmp[i] -= 3;
    dfs(tmp, n - 1);
  }
}

signed main(void) {
  string s;
  while (cin >> s) {
    int cnt[10] = {0};
    REP(i, s.size()) cnt[s[i] - '0']++;
    VI ans;
    FOR(k, 1, 10) {
      bool g = false;
      if (cnt[k] < 4) {
        cnt[k]++;
        g = true;
      }
      f = false;
      // cout << k << endl;
      FOR(i, 1, 10) if (cnt[i] >= 2) {
        int tmp[10];
        REP(j, 10) tmp[j] = cnt[j];
        tmp[i] -= 2;
        dfs(tmp, 4);
      }
      if (g)
        cnt[k]--;
      if (f)
        ans.push_back(k);
    }

    if (ans.size() == 0)
      cout << 0;
    REP(i, ans.size()) {
      cout << ans[i];
      if (i != ans.size() - 1)
        cout << " ";
    }
    cout << endl;
  }

  return 0;
}