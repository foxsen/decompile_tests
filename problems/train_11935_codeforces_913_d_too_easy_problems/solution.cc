#include <bits/stdc++.h>
using namespace std;
istream& in = cin;
long long n, T;
vector<pair<int, pair<int, int> > > all;
void input() {
  in >> n >> T;
  for (int i = 1; i <= n; ++i) {
    int a, b;
    in >> a >> b;
    all.push_back(make_pair(b, make_pair(a, i)));
  }
}
bool ok(int m) {
  long long sum = 0;
  long long num = 0;
  for (pair<int, pair<int, int> > p : all) {
    if (p.second.first >= m) {
      sum += p.first;
      num++;
      if (sum > T) {
        return 0;
      }
      if (num >= m) {
        return 1;
      }
    }
  }
  return 0;
}
int main() {
  int TEST_CASE = 1;
  while (TEST_CASE-- > 0) {
    input();
    sort(all.begin(), all.end());
    int L = 0, R = n + 1, ans = 0;
    while (L <= R) {
      int mid = (L + R) / 2;
      if (ok(mid)) {
        ans = mid;
        L = mid + 1;
      } else {
        R = mid - 1;
      }
    }
    printf("%d\n", ans);
    printf("%d\n", ans);
    int num = ans;
    for (pair<int, pair<int, int> > p : all) {
      if (num <= 0) {
        break;
      }
      if (p.second.first >= ans) {
        printf("%d ", p.second.second);
        num--;
      }
    }
    cout << endl;
  }
  return 0;
}
