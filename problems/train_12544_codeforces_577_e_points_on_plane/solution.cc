#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2000000;
const int MAXM = 2000;
const long double EPS = 1e-4;
int N, M;
pair<pair<int, int>, int> pts[MAXN];
int main() {
  cout.sync_with_stdio(false);
  cin >> N;
  int first, second;
  for (int i = 1; i <= N; ++i) {
    cin >> first >> second;
    first /= 1000;
    if (first % 2) {
      pts[i] = make_pair(make_pair(first, -second), i);
    } else {
      pts[i] = make_pair(make_pair(first, second), i);
    }
  }
  sort(pts + 1, pts + N + 1);
  for (int i = 1; i <= N; ++i) {
    cout << pts[i].second << ' ';
  }
  return 0;
}
