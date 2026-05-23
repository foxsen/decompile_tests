#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long n;
  cin >> n;
  vector<long long> v;
  vector<long long> ind(n);
  for (long long i = 0; i < n; i++) {
    long long x;
    cin >> x;
    ind[i] = x;
    if (i == 0) {
      v.push_back(x);
      continue;
    }
    if (x != v.back()) {
      v.push_back(x);
    }
  }
  if (v.size() < 3) {
    cout << 0;
    return 0;
  }
  vector<long long> ans;
  if (v[1] > v[0]) {
    bool chk = true;
    for (long long i = 1; i < v.size(); i++) {
      if (v[i] < v[i - 1]) {
        chk = false;
      }
    }
    if (chk) {
      cout << 0;
      return 0;
    }
    ans.push_back(v[0]);
    ans.push_back(v[1]);
    for (long long i = 2; i < v.size(); i++) {
      if (v[i] > ans.back()) {
        ans.pop_back();
        ans.push_back(v[i]);
      } else {
        ans.push_back(v[i]);
        break;
      }
    }
    cout << 3 << "\n";
    cout << 1 << " ";
    long long curr = 1;
    for (long long i = 1; i < n; i++) {
      if (curr >= 3) {
        break;
      }
      if (ind[i] == ans[curr]) {
        cout << i + 1 << " ";
        curr++;
      }
    }
  } else {
    bool chk = true;
    for (long long i = 1; i < v.size(); i++) {
      if (v[i] > v[i - 1]) {
        chk = false;
      }
    }
    if (chk) {
      cout << 0;
      return 0;
    }
    ans.push_back(v[0]);
    ans.push_back(v[1]);
    for (long long i = 2; i < v.size(); i++) {
      if (v[i] < ans.back()) {
        ans.pop_back();
        ans.push_back(v[i]);
      } else {
        ans.push_back(v[i]);
        break;
      }
    }
    cout << 3 << "\n";
    cout << 1 << " ";
    long long curr = 1;
    for (long long i = 1; i < n; i++) {
      if (curr >= 3) {
        break;
      }
      if (ind[i] == ans[curr]) {
        cout << i + 1 << " ";
        curr++;
      }
    }
  }
}
