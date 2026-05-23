#include <bits/stdc++.h>
using namespace std;
struct node {
  int mod;
  int bit;
  string s;
  node(){};
  node(int m, int b, string ss) { mod = m, bit = b, s = ss; }
};
bool v[501][5001];
string bfs(int d, int s) {
  queue<node> q;
  q.push(node(0, 0, ""));
  v[0][0] = true;
  while (!q.empty()) {
    node buf = q.front();
    q.pop();
    if (buf.bit <= s) {
      if (buf.mod == 0 && buf.bit == s) return buf.s;
      for (int i = 0; i < 10; i++) {
        int bmod = (buf.mod * 10 + i) % d;
        int bbit = buf.bit + i;
        if (!v[bmod][bbit]) {
          v[bmod][bbit] = true;
          q.push(node(bmod, bbit, buf.s + (char)(i + '0')));
        }
      }
    }
  }
  return "-1";
}
int main() {
  int s, d;
  cin >> d >> s;
  cout << bfs(d, s) << endl;
  return 0;
}
