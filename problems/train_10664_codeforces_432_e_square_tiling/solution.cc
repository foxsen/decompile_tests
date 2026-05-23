#include <bits/stdc++.h>
using namespace std;
template <typename T>
bool MinPlace(T &a, const T &b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}
template <typename T>
bool MaxPlace(T &a, const T &b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}
template <typename S, typename T>
ostream &operator<<(ostream &out, const pair<S, T> &p) {
  out << "{" << p.first << ", " << p.second << "}";
  return out;
}
template <typename T>
ostream &operator<<(ostream &out, const vector<T> &v) {
  out << "[";
  for (int i = 0; i < (int)v.size(); i++) {
    out << v[i];
    if (i != (int)v.size() - 1) out << ", ";
  }
  out << "]";
  return out;
}
char mex(int i, int j, vector<string> &t) {
  int n = t.size(), m = t[0].size();
  set<char> hood;
  vector<pair<int, int> > diff(
      {make_pair(-1, 0), make_pair(0, -1), make_pair(1, 0), make_pair(0, 1)});
  for (auto pd : diff) {
    int ni = i + pd.first, nj = j + pd.second;
    if (ni >= 0 and ni < n and nj >= 0 and nj < m) hood.insert(t[ni][nj]);
  }
  for (char c = 'A'; c < 'F'; c++)
    if (!hood.count(c)) return c;
  return 'E';
}
bool isClear(int i, int j, vector<string> &t, int c) {
  int n = t.size(), m = t[0].size(), ii, jj;
  if (i + c >= n || j - c < 0) return false;
  for (ii = i + 1; ii <= i + c; ii++)
    if (t[ii][j] != ' ') break;
  for (jj = j - 1; jj >= j - c; jj--)
    if (t[i + c][jj] != ' ') break;
  return (ii == i + c + 1 && jj == j - c - 1 &&
          (i && j
               ? (t[i - 1][j] != t[i][j - 1] && t[i - 1][j - 1] != t[i][j - 1])
               : true));
}
void fill(int i, int j, vector<string> &t, int rc, char ch) {
  for (int ii = i; ii <= i + rc; ii++) t[ii][j] = ch;
  for (int jj = j - 1; jj >= j - rc; jj--) t[i + rc][jj] = ch;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int i, j, n, m;
  cin >> n >> m;
  vector<string> t(n, string(m, ' '));
  for (int i = 0; i < n; i++) {
    for (int j = 0, c = 0; j < m; j++) {
      if (t[i][j] != ' ') continue;
      char ch = mex(i, j, t);
      if (j && t[i][j - 1] < ch && isClear(i, j, t, c))
        ch = t[i][j - 1];
      else
        c = 0;
      fill(i, j, t, c, ch);
      c++;
    }
  }
  for (int i = 0; i < n; i++) cout << t[i] << "\n";
}
