#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:100000000000")
bool ascending(int i, int j) { return (i < j); }
bool descending(int i, int j) { return (i > j); }
using namespace std;
int dp[5000][5000];
int A[5000];
int n, x, y, c;
bool f(unsigned long long level) {
  unsigned long long ret = 0;
  ret = (level > 1 ? level * (level - 1) * 2 : 0) + 1;
  ret -= level > x ? (level - x) * (level - x) : 0;
  ret -= level > y ? (level - y) * (level - y) : 0;
  ret -= level > n - x + 1 ? (level - n + x - 1) * (level - n + x - 1) : 0;
  ret -= level > n - y + 1 ? (level - n + y - 1) * (level - n + y - 1) : 0;
  ret += level > x + y ? (level - x - y) * (level - x - y + 1) / 2 : 0;
  ret += level > n + 1 - x + y
             ? (level - n - 1 + x - y) * (level - n + x - y) / 2
             : 0;
  ret += level > n + 1 + x - y
             ? (level - x - n - 1 + y) * (level - x - n + y) / 2
             : 0;
  ret += level > n + 1 - x + n + 1 - y
             ? (level - n - 1 + x - n - 1 + y) * (level - n - 1 + x - n + y) / 2
             : 0;
  return ret >= c;
}
int main() {
  cin >> n >> x >> y >> c;
  int left = 0;
  int right = 2 * n + 1;
  while (left < right - 1) {
    int mid = (left + right) / 2;
    if (f(mid))
      right = mid;
    else
      left = mid;
  }
  cout << left << endl;
}
