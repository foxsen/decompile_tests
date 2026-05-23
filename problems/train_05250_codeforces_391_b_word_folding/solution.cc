#include <bits/stdc++.h>
using namespace std;
template <typename A, typename B>
inline bool mina(A &x, B y) {
  return (x > y) ? (x = y, 1) : 0;
}
template <typename A, typename B>
inline bool maxa(A &x, B y) {
  return (x < y) ? (x = y, 1) : 0;
}
char S[1004];
vector<pair<int, int> > P[26];
int main() {
  cin >> S;
  for (int _b = (strlen(S)), i = (0); i < _b; ++i) {
    int a = S[i] - 'A';
    P[a].push_back(pair<int, int>(i, 1));
  }
  int sol = 1;
  for (int _b = (26), i = (0); i < _b; ++i)
    for (pair<int, int> &p : P[i]) {
      for (pair<int, int> q : P[i]) {
        if (q.first == p.first) break;
        if ((p.first ^ q.first) & 1) {
          maxa(p.second, q.second + 1);
          maxa(sol, p.second);
        }
      }
    }
  cout << sol << endl;
  return 0;
}
