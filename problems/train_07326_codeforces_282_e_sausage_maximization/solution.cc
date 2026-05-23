#include <bits/stdc++.h>
using namespace std;
vector<int> v1;
pair<int, int> p1;
int a[10234567];
string s;
int dp[1001];
long long a1[1000001], l1[1000001];
long long pow1(long long x, long long y) {
  if (y == 0) return 1;
  long long temp = pow1(x, y / 2) % 1000000007;
  if (y % 2 == 0)
    return (temp * temp) % 1000000007;
  else
    return (((temp * temp) % 1000000007) * x) % 1000000007;
}
int trie[10000001][2];
int sz = 1;
void insert(long long n) {
  int idx = 0;
  for (long long i = 41; i >= 0; i--) {
    bool p = n & (1ll << i);
    if (p != 0) p = 1;
    if (trie[idx][p] == -1) trie[idx][p] = sz++;
    a[trie[idx][p]]++;
    idx = trie[idx][p];
  }
}
void remove(long long n) {
  int idx = 0, togo;
  for (long long i = 41; i >= 0; i--) {
    bool p = n & (1ll << i);
    if (p != 0) p = 1;
    a[trie[idx][p]]--;
    togo = trie[idx][p];
    if (a[trie[idx][p]] == 0) trie[idx][p] = -1;
    idx = togo;
  }
}
long long query(long long n) {
  int idx = 0;
  long long ans = 0;
  for (long long i = 41; i >= 0; i--) {
    bool p = n & (1ll << i);
    if (p != 0) p = 1;
    if (trie[idx][1 - p] != -1) {
      idx = trie[idx][1 - p];
      ans = ans * 2 + 1;
    } else if (trie[idx][p] != -1) {
      ans *= 2;
      idx = trie[idx][p];
    } else
      while (1) {
      }
  }
  return ans;
}
int main() {
  int t;
  int n, i, j, k, m, l;
  memset(trie, -1, sizeof(trie));
  scanf("%d", &n);
  insert(0);
  for (i = 1; i < n + 1; i++) {
    cin >> a1[i];
    l1[i] = l1[i - 1] ^ a1[i];
    insert(l1[i]);
  }
  long long max1 = 0;
  for (i = 1; i < n + 1; i++) max1 = max(max1, l1[i]);
  long long r1 = 0;
  for (i = n; i >= 1; i--) {
    remove(l1[i]);
    r1 ^= a1[i];
    max1 = max(max1, query(r1));
  }
  cout << max1 << "\n";
  return 0;
}
