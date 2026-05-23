#include <bits/stdc++.h>
#pragma GCC optimize("O2,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,mmx,avx,avx2")
using namespace std;
const long double PI = 3.14159265358979323846;
const long double E = 2.71828182845904523536;
const long long LINF = (long long)2e18;
const int INF = (1 << 30);
const long double eps = 1e-10;
const int MAXN = 2e5 + 5;
int a[MAXN];
int b[MAXN];
int l[MAXN];
int s[MAXN], f[MAXN];
int inq[MAXN];
int n;
vector<int> ans;
int idx = 1;
bool remove(int s, int f, vector<int>& skip) {
  if (s == 0 && f == n - 1 && !skip.size()) {
    return false;
  }
  int tct = 0;
  for (int i = s; i <= f; i++) {
    b[i] = 1;
    tct++;
  }
  idx++;
  queue<int> q;
  if (s != 0) {
    q.push(s - 1);
    inq[s - 1] = idx;
  }
  if (f != n - 1) {
    q.push(f - 1);
    inq[f - 1] = idx;
  }
  for (int i : skip) {
    if (inq[i - 1] != idx) {
      q.push(i - 1);
      inq[i - 1] = idx;
    }
    b[i] = 0;
    tct--;
  }
  for (int i = s; i <= f; i++) {
    if (a[i] == 0 && b[i] != 0) {
      a[i + 1] = 1;
      ans.push_back(i);
    }
  }
  while (q.size()) {
    int k = q.front();
    q.pop();
    int ct = 0;
    if (b[k]) {
      ct++;
    }
    if (b[k + 1]) {
      ct++;
    }
    if (b[k + 2]) {
      ct++;
    }
    if (ct != 2) {
      continue;
    }
    tct -= 2;
    b[k] = 0;
    b[k + 1] = 0;
    b[k + 2] = 0;
    ans.push_back(k + 1);
    if (inq[k - 1] != idx && k - 1 >= 0 && k - 1 <= n - 1) {
      inq[k - 1] = idx;
      q.push(k - 1);
    };
    if (inq[k + 1] != idx && k + 1 >= 0 && k + 1 <= n - 1) {
      inq[k + 1] = idx;
      q.push(k + 1);
    };
    if (inq[k - 2] != idx && k - 2 >= 0 && k - 2 <= n - 1) {
      inq[k - 2] = idx;
      q.push(k - 2);
    };
    if (inq[k + 2] != idx && k + 2 >= 0 && k + 2 <= n - 1) {
      inq[k + 2] = idx;
      q.push(k + 2);
    };
  }
  return !tct;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  std::cout << std::fixed << std::setprecision(20);
  int qr;
  for (cin >> qr; qr; qr--) {
    cin >> n;
    ans.clear();
    int ct = 0;
    bool ok = 0;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      ct ^= a[i];
      ok |= !a[i];
    }
    if (ct || !ok) {
      cout << "NO\n";
      continue;
    }
    a[n] = 0;
    int ptr = 0;
    for (int i = 0; i < n;) {
      int j = i;
      l[ptr] = 0;
      s[ptr] = i;
      while (j < n && a[j] == a[i]) {
        l[ptr]++;
        j++;
      }
      f[ptr] = j - 1;
      i = j;
      ptr++;
    }
    for (int i = 0; i < ptr;) {
      if (!a[s[i]]) {
        i++;
        continue;
      }
      int temp = l[i];
      vector<int> skip;
      int j = i;
      while (temp & 1) {
        int k0 = j + 1;
        temp += l[k0] - (l[k0] & 1);
        if (l[k0] & 1) {
          skip.push_back(f[k0]);
        }
        int k1 = j + 2;
        if (k1 == ptr || k0 == ptr) {
          cout << "NO\n";
          goto done;
        }
        temp += l[k1];
        j += 2;
      }
      if (!remove(s[i], f[j], skip)) {
        cout << "NO\n";
        goto done;
      }
      i = j + 1;
    }
    cout << "YES\n";
    cout << ans.size() << '\n';
    for (int i : ans) {
      cout << i << ' ';
    }
    cout << '\n';
  done:;
  }
}
