#include <bits/stdc++.h>
using namespace std;
const int di[] = {-1, 0, 1, 0};
const int dj[] = {0, 1, 0, -1};
const long long MOD = 1e9 + 7;
const long long INF = 1e9;
const double EPS = 1e-5;
int main() {
  ios::sync_with_stdio(false), cin.tie(0);
  int n;
  cin >> n;
  deque<int> num(n);
  for (int i = 0; i < n; i++) num[i] = i + 1;
  for (int shft = 2; shft <= n; shft++) {
    int last = num[0];
    for (int i = shft; i < n; i += shft) swap(num[i], last);
    num.pop_front();
    num.push_back(last);
  }
  for (int i = 0; i < n; i++) cout << num[i] << " \n"[i == n - 1];
  cin.ignore(), cin.get();
}
