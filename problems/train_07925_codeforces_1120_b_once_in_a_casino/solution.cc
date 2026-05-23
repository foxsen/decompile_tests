#include <bits/stdc++.h>
using namespace std;
int n;
long long total;
string s, t;
vector<int> a, b;
vector<pair<int, int> > res;
void answer() {
  cout << total << endl;
  for (auto it : res) cout << it.first << " " << it.second << endl;
  exit(0);
}
void add(int i);
void take(int i);
void add(int i) {
  if (i >= n - 1) {
    cout << -1 << endl;
    exit(0);
  }
  if (s[i + 1] == '9') take(i + 1);
  s[i]++;
  s[i + 1]++;
  res.push_back({i + 1, 1});
  if (res.size() == 100000) answer();
}
void take(int i) {
  if (i >= n - 1) {
    cout << -1 << endl;
    exit(0);
  }
  if (s[i + 1] == '0') add(i + 1);
  s[i]--;
  s[i + 1]--;
  res.push_back({i + 1, -1});
  if (res.size() == 100000) answer();
}
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> s >> t;
  for (char c : s) a.push_back(c - '0');
  for (char c : t) b.push_back(c - '0');
  for (int i = 0; i < n - 1; i++) {
    if (a[i] == b[i]) continue;
    int diff = a[i] - b[i];
    total += abs(diff);
    a[i + 1] -= diff;
  }
  if (a[n - 1] != b[n - 1]) return !(cout << -1 << endl);
  for (int i = 0; i < n - 1; i++) {
    while (s[i] > t[i]) take(i);
    while (s[i] < t[i]) add(i);
  }
  answer();
}
