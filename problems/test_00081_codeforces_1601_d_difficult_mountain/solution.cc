#include <bits/stdc++.h>
#pragma warning(disable : 4996)
#pragma comment(linker, "/STACK:16777216")
using namespace std;
const int INF = 1000000000 + 1e8;
const long long LINF = 2000000000000000000;
struct elem {
  int s, a;
};
void solve() {
  int n, d;
  cin >> n >> d;
  vector<elem> good, bad;
  for (int i = 0; i < n; i++) {
    int si, ai;
    cin >> si >> ai;
    if (si < d) {
      continue;
    }
    if (si >= ai)
      good.push_back({si, ai});
    else
      bad.push_back({si, ai});
  }
  auto cmp = [](elem x, elem y) {
    return x.a < y.a || x.a == y.a && x.s < y.s;
  };
  sort((good).begin(), (good).end(), cmp);
  sort((bad).begin(), (bad).end(), cmp);
  good.insert(good.begin(), {INF, d});
  good.push_back({INF, INF});
  vector<int> suffMin(int(good.size()));
  suffMin[int(good.size()) - 1] = good.back().s;
  for (int i = int(good.size()) - 2; i >= 0; i--)
    suffMin[i] = min(suffMin[i + 1], good[i].s);
  int ans = int(good.size()) - 2;
  int j = 0;
  vector<elem> res;
  int curA = d;
  for (int i = 0; i < int(good.size()) - 1; i++) {
    curA = max(good[i].a, curA);
    for (; j < int(bad.size()) && bad[j].a <= suffMin[i + 1]; j++) {
      if (bad[j].s >= curA) {
        ans++;
        curA = max(curA, bad[j].a);
        res.push_back(bad[j]);
      }
    }
  }
  cout << ans;
}
int main() {
  srand(time(0));
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int tst = 1;
  while (tst--) {
    solve();
  }
}
