#include <bits/stdc++.h>
using namespace std;
int N;
long long V[100010];
char use[100010][61];
vector<bitset<100001> > sys;
vector<int> sel, sol;
int diff0(bitset<100001>& w) {
  for (int i = 0; i < N; ++i)
    if (w[i]) return i;
  return N;
}
void add(int bit, int to) {
  sys.push_back(bitset<100001>());
  sel.push_back(-1);
  bitset<100001>& T = sys.back();
  for (int i = 0; i < N; ++i)
    if (use[i][bit]) T[i] = 1;
  T[N] = to;
}
void rem() {
  sys.pop_back();
  sel.pop_back();
}
bool OK() {
  if (sys.empty()) return true;
  bitset<100001>& T = sys.back();
  for (int i = 0; i < ((int)(sys).size()) - 1; ++i) {
    if (sel[i] == -1) continue;
    if (T[sel[i]]) T ^= sys[i];
  }
  int pos = diff0(T);
  if (pos < N) {
    sel.back() = pos;
    return true;
  }
  if (T[N] != 0) return false;
  return true;
}
int main() {
  scanf("%d", &N);
  long long XOR = 0;
  for (int i = 0; i < N; ++i) scanf("%Ld", &V[i]), XOR ^= V[i];
  for (int i = 0; i < N; ++i)
    for (int j = 0; j < 60; ++j)
      if (V[i] & (1LL << j)) use[i][j] = 1;
  for (int j = 59; j >= 0; --j) {
    if ((XOR & (1LL << j)) != 0) continue;
    add(j, 1);
    if (!OK()) rem();
  }
  for (int j = 59; j >= 0; --j) {
    if ((XOR & (1LL << j)) == 0) continue;
    add(j, 0);
    if (!OK()) rem();
  }
  sol.resize(N, 0);
  for (int i = ((int)(sys).size()) - 1; i >= 0; --i) {
    if (sel[i] == -1) continue;
    for (int j = i + 1; j < ((int)(sys).size()); ++j)
      if (sel[j] != -1 && sys[i][sel[j]] && sol[sel[j]])
        sys[i][N] = ((int)sys[i][N]) ^ sol[sel[j]];
    sol[sel[i]] = sys[i][N];
  }
  for (int i = 0; i < N; ++i)
    printf("%d%c", sol[i] ? 1 : 2, (i + 1 == N ? '\n' : ' '));
  return 0;
}
