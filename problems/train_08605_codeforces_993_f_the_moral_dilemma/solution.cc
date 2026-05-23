#include <bits/stdc++.h>
using namespace std;
struct op {
  string ot;
  int conn1, conn2;
  int getConn(int idx) { return idx ? conn2 : conn1; }
};
int n, m, k;
int val[2][50];
vector<op> ops[2];
bool occ[50][4];
string neg(string ot) {
  if (ot[0] == 'n') return ot.substr(1, ((int)(ot).size()) - 1);
  return "n" + ot;
}
int apply(string ot, int b1, int b2, bool flip = false) {
  if (flip) ot = neg(ot);
  if (ot == "and") return b1 & b2;
  if (ot == "or") return b1 | b2;
  if (ot == "nand") return 1 ^ (b1 & b2);
  if (ot == "nor") return 1 ^ (b1 | b2);
}
op readOp(int connlen) {
  string ot, conns;
  cin >> ot >> conns;
  vector<int> v;
  for (int i = 0; i < (connlen); i++)
    if (conns[i] == 'x') v.push_back(i);
  return {ot, v[0], v[1]};
}
int eval(int idx, bool flip) {
  for (int i = 0; i < (2); i++) {
    int opidx = ops[1][idx].getConn(i);
    op o = ops[0][opidx];
    val[1][opidx] = apply(o.ot, val[0][o.conn1], val[0][o.conn2], flip);
  }
  op o = ops[1][idx];
  return apply(o.ot, val[1][o.conn1], val[1][o.conn2], flip);
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m >> k;
  for (int i = 0; i < (m); i++) ops[0].push_back(readOp(n));
  for (int i = 0; i < (k); i++) ops[1].push_back(readOp(m));
  bool has[2]{0, 0};
  int cnt[2]{0, 0};
  for (int i = 0; i < (k); i++) {
    set<int> inps;
    for (int a = 0; a < (2); a++)
      for (int b = 0; b < (2); b++)
        inps.insert(ops[0][ops[1][i].getConn(a)].getConn(b));
    vector<int> v((inps).begin(), (inps).end());
    for (int mask = 0; mask < (1 << ((int)(v).size())); mask++) {
      for (int j = 0; j < (((int)(v).size())); j++)
        val[0][v[j]] = (mask >> j) & 1;
      occ[i][(eval(i, false) << 1) | eval(i, true)] = 1;
    }
    if (occ[i][3]) continue;
    if (occ[i][1]) {
      cnt[0]++;
      if (!occ[i][0]) has[0] = 1;
    }
    if (occ[i][2]) {
      cnt[1]++;
      if (!occ[i][0]) has[1] = 1;
    }
  }
  int res = 0;
  for (int i = 0; i < (2); i++)
    if (has[i]) res = max(res, cnt[i]);
  if (res == 0)
    cout << -1 << endl;
  else
    cout << k - res << endl;
}
