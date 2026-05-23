#include <bits/stdc++.h>
using namespace std;
double PI = acos(-1);
int dx[] = {0, 1, 0, -1, 1, 1, -1, -1};
int dy[] = {1, 0, -1, 0, 1, -1, 1, -1};
void file() {
  std::ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
}
int main() {
  file();
  int t;
  cin >> t;
  while (t--) {
    long long n, x;
    cin >> n >> x;
    if (n == 1) {
      cout << 1 << '\n';
      continue;
    }
    n -= 2;
    cout << ceil(n * 1.0 / x) + 1 << '\n';
  }
  return 0;
}
