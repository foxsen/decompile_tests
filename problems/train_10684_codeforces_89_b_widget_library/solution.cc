#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/STACK:160000000")
const int L = 1111;
const int N = 111;
string s;
map<string, int> M;
long long x[N];
long long y[N];
vector<int> v[N];
long long sp[N];
long long brd[N];
int t[N];
bool color[N];
int K = 0;
void dfs(int u) {
  color[u] = 1;
  if (t[u] == 0 || v[u].size() == 0) return;
  x[u] = y[u] = brd[u] * 2;
  int val = sp[u] * ((int)v[u].size() - 1);
  if (t[u] == 1)
    y[u] += val;
  else
    x[u] += val;
  for (int i = 0; i < v[u].size(); ++i) {
    if (!color[v[u][i]]) dfs(v[u][i]);
    if (t[u] == 1) {
      y[u] += y[v[u][i]];
      x[u] = max(x[u], brd[u] * 2 + x[v[u][i]]);
    } else {
      x[u] += x[v[u][i]];
      y[u] = max(y[u], brd[u] * 2 + y[v[u][i]]);
    }
  }
}
int main() {
  int n;
  scanf("%d ", &n);
  for (int i = 0; i < n; ++i) {
    cin >> s;
    if (s[0] == 'W') {
      cin >> s;
      int pos = 0;
      int l = s.length();
      for (pos = 0; pos < l; ++pos) {
        if (s[pos] == '(') {
          break;
        }
      }
      M[s.substr(0, pos)] = K;
      t[K] = 0;
      x[K] = 0;
      y[K] = 0;
      ++pos;
      while (s[pos] >= '0' && s[pos] <= '9') {
        x[K] = x[K] * 10 + s[pos] - '0';
        ++pos;
      }
      ++pos;
      while (s[pos] >= '0' && s[pos] <= '9') {
        y[K] = y[K] * 10 + s[pos] - '0';
        ++pos;
      }
      ++K;
    } else if (s[0] == 'V') {
      cin >> s;
      M[s] = K;
      t[K] = 1;
      ++K;
    } else if (s[0] == 'H') {
      cin >> s;
      M[s] = K;
      t[K] = 2;
      ++K;
    } else {
      int pos = 0;
      int l = s.length();
      for (pos = 0; pos < l; ++pos) {
        if (s[pos] == '.') {
          break;
        }
      }
      string n1 = s.substr(0, pos);
      ++pos;
      if (s[pos] == 'p') {
        string n2 = s.substr(pos + 5, l - pos - 6);
        v[M[n1]].push_back(M[n2]);
      } else if (s[pos + 4] == 'b') {
        pos += 11;
        int k = M[n1];
        brd[k] = 0;
        while (s[pos] >= '0' && s[pos] <= '9') {
          brd[k] = brd[k] * 10 + s[pos] - '0';
          ++pos;
        }
      } else {
        pos += 12;
        int k = M[n1];
        sp[k] = 0;
        while (s[pos] >= '0' && s[pos] <= '9') {
          sp[k] = sp[k] * 10 + s[pos] - '0';
          ++pos;
        }
      }
    }
  }
  for (int i = 0; i < K; ++i) {
    if (!color[i]) {
      dfs(i);
    }
  }
  for (map<string, int>::iterator i = M.begin(); i != M.end(); i++) {
    cout << i->first << " " << x[i->second] << " " << y[i->second] << endl;
  }
  return 0;
}
