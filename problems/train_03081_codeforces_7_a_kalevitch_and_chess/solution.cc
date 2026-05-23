#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:50000000")
using namespace std;
const long long mod = 1000000007;
const long long md = 1234567891;
const char aa = 'a';
const double eps = 1E-9;
const int mil = 1000000;
const int ths = 1000;
const int maxn = 1001;
const int dr[] = {0, -1, 0, 1};
const int dc[] = {1, 0, -1, 0};
const int mxx = 32;
const int inf = (int)1E9;
template <typename T>
void printV(vector<T>& v) {
  for (int i = 0; i < (int)(v.size()); i++) cout << v[i] << " ";
  cout << endl;
}
template <typename T>
void printVs(vector<vector<T> >& v) {
  for (int i = 0; i < (int)(v.size()); i++) printV(v[i]);
}
vector<string> bd(8);
int main() {
  for (int r = 0; r < (int)(8); r++) cin >> bd[r];
  int nr = 0, nc = 0;
  for (int c = 0; c < (int)(8); c++) {
    bool ok = 1;
    for (int r = 0; r < (int)(8); r++)
      if (bd[r][c] == 'W') ok = 0;
    nc += ok;
  }
  for (int r = 0; r < (int)(8); r++) nr += bd[r] == "BBBBBBBB";
  if (nr == 8 || nc == 8)
    cout << 8 << endl;
  else
    cout << nr + nc << endl;
}
