#include <bits/stdc++.h>
using namespace std;
int n, m;
const int P = 10000000;
struct Long {
  vector<int> arr;
  Long(int x = 0) {
    if (x == 0) {
      arr.push_back(0);
      return;
    }
    while (x > 0) {
      arr.push_back(x % P);
      x /= P;
    }
  }
  void Fill(int n) { arr.assign(n, 0); }
  void Clear() {
    while (arr.size() > 1 && arr.back() == 0) arr.pop_back();
  }
  void Print() {
    cout << arr.back();
    for (int i = (int)(arr.size()) - 2; i >= 0; i--) printf("%07d", arr[i]);
  }
};
Long operator+(const Long &a, const Long &b) {
  Long c;
  c.Fill(2 + max(a.arr.size(), b.arr.size()));
  for (int i = 0; i < c.arr.size() - 1; i++) {
    if (i < a.arr.size()) c.arr[i] += a.arr[i];
    if (i < b.arr.size()) c.arr[i] += b.arr[i];
    c.arr[i + 1] += c.arr[i] / P;
    c.arr[i] %= P;
  }
  c.Clear();
  return c;
}
bool operator<(const Long &a, const Long &b) {
  if (a.arr.size() != b.arr.size()) return a.arr.size() < b.arr.size();
  int x = a.arr.size() - 1;
  while (x >= 0) {
    if (a.arr[x] != b.arr[x]) return a.arr[x] < b.arr[x];
    x--;
  }
  return false;
}
Long two[2001];
int main() {
  int n;
  cin >> n;
  vector<pair<bool, int> > arr(n);
  string s;
  for (int i = 0; i < n; i++) {
    cin >> s >> arr[i].second;
    arr[i].first = s == "win";
  }
  two[0] = Long(1);
  for (int i = 1; i < 2001; i++) two[i] = two[i - 1] + two[i - 1];
  vector<Long> dp(2002);
  dp[2001] = Long(0);
  vector<bool> ex(2001, false);
  for (int i = 0; i < n; i++) {
    if (arr[i].first) {
      dp[arr[i].second] = dp[2001];
      ex[arr[i].second] = true;
    } else {
      if (!ex[arr[i].second]) continue;
      Long k = dp[arr[i].second] + two[arr[i].second];
      if (dp[2001] < k) dp[2001] = k;
    }
  }
  dp[2001].Print();
  return 0;
}
