#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");
int gcd(int a, int b) {
  while (a && b) a > b ? a %= b : b %= a;
  return a + b;
}
int val(char c) {
  if (c >= '0' && c <= '9')
    return (int)c - '0';
  else
    return (int)c - 'A' + 10;
}
long long pows(int a, int b) {
  long long res = 1;
  for (int i = 0; i < b; ++i) {
    res *= a;
  }
  return res;
}
long long logx(long long base, long long num) {
  int cnt = 0;
  while (num != 1) {
    num /= base;
    ++cnt;
  }
  return cnt;
}
long long divisibles(long long a, long long b, long long m) {
  if (a % m == 0)
    return (b / m) - (a / m) + 1;
  else
    return (b / m) - (a / m);
}
vector<int> vis(100001, 0);
vector<int> adj[100001];
int main() {
  std::ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
    int h, n;
    cin >> h >> n;
    vector<int> vec;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      int x;
      cin >> x;
      vec.push_back(x);
    }
    for (int i = 0; i < n; ++i) {
      int cnt = 1;
      int j = i;
      if (vec[i] == 1) break;
      if (i + 1 < n) {
        while (vec[i] - vec[i + 1] == 1) {
          ++cnt;
          ++i;
          if (i + 1 >= n) break;
        }
      }
      if (j == 0 && cnt % 2 == 0 && vec[i] != 1) {
        ++ans;
      } else if (j > 0 && cnt % 2 && vec[i] != 1) {
        ++ans;
      }
    }
    cout << ans << "\n";
  }
}
