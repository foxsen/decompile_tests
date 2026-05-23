#include <bits/stdc++.h>
using namespace std;
const int MAXN = 50 + 10;
const int MAXM = 1000 + 10;
const int INF = 1000000001;
const int MOD = 1000000007;
int c[300];
bool A(bool a, bool b) { return a ^ b; }
bool B(bool a, bool b) { return a | b; }
bool C(bool a, bool b) { return a & b; }
int main(int argc, char* argv[]) {
  ios::sync_with_stdio(false);
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  int e = A(a, b);
  int f = B(c, d);
  int g = C(b, c);
  int h = A(a, d);
  int i = C(e, f);
  int j = B(g, h);
  cout << A(i, j) << endl;
  return 0;
}
