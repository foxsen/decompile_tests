#include <bits/stdc++.h>
using namespace std;
const int maxn = 5205;
int n;
int sum[maxn][maxn];
char a;
char cs[] = "0123456789ABCDEF";
map<char, int> cidic;
void init() {
  for (int i = 0; i < 16; i++) {
    cidic[cs[i]] = i;
  }
}
void update(int i, int j) {
  sum[i][j] += (i > 0 ? sum[i - 1][j] : 0) + (j > 0 ? sum[i][j - 1] : 0) -
               (i > 0 && j > 0 ? sum[i - 1][j - 1] : 0);
}
bool check(int k) {
  for (int i = 0; i < n; i += k) {
    for (int j = 0; j < n; j += k) {
      int c_sum = sum[i + k - 1][j + k - 1] -
                  (j > 0 ? sum[i + k - 1][j - 1] : 0) -
                  (i > 0 ? sum[i - 1][j + k - 1] : 0) +
                  (i > 0 && j > 0 ? sum[i - 1][j - 1] : 0);
      if (c_sum != 0 && c_sum != k * k) return false;
    }
  }
  return true;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  init();
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n / 4; j++) {
      cin >> a;
      int ms = cidic[a];
      sum[i][j * 4] = (ms >> 3) & 1;
      update(i, j * 4);
      sum[i][j * 4 + 1] = (ms >> 2) & 1;
      update(i, j * 4 + 1);
      sum[i][j * 4 + 2] = (ms >> 1) & 1;
      update(i, j * 4 + 2);
      sum[i][j * 4 + 3] = ms & 1;
      update(i, j * 4 + 3);
    }
  }
  int k = 1;
  while (k != n && !check(n / k)) {
    k++;
    while (n % k != 0) {
      k++;
    }
  }
  cout << n / k << endl;
  return 0;
}
