#include <bits/stdc++.h>
using namespace std;
template <class T>
string tostring(T x) {
  ostringstream out;
  out << x;
  return out.str();
}
long long toint(string s) {
  istringstream in(s);
  long long x;
  in >> x;
  return x;
}
int dx[8] = {0, 0, 1, -1, 1, 1, -1, -1};
int dy[8] = {1, -1, 0, 0, -1, 1, -1, 1};
int kx[8] = {1, 1, -1, -1, 2, 2, -2, -2};
int ky[8] = {2, -2, 2, -2, 1, -1, 1, -1};
int main() {
  int n, m, a, b;
  scanf("%d%d%d%d", &n, &m, &a, &b);
  a--, b--;
  int firstBlock = a / m;
  int lastBlock = b / m;
  if (b == n - 1) b = lastBlock * m + m - 1;
  if (firstBlock == lastBlock)
    printf("1\n");
  else if (a % m == 0 && b % m == m - 1)
    printf("1\n");
  else {
    if (firstBlock + 1 == lastBlock || (b % m + 1 == a % m))
      printf("2\n");
    else if (a % m == 0 || b % m == m - 1)
      printf("2\n");
    else
      printf("3\n");
  }
  return 0;
}
