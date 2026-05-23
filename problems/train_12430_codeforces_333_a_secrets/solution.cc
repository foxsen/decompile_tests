#include <bits/stdc++.h>
using namespace std;
void io_in_data() {
  freopen("data.in", "r", stdin);
  freopen("data1.out", "w", stdout);
}
template <class T>
void show(T *a, int n) {
  for (int i = 0; i < n; i++) cout << a[i] << "  ";
  puts("");
}
int inLR(int a, int L, int R) { return a >= L && a <= R; }
int movR[] = {1, -1, 0, 0};
int movC[] = {0, 0, 1, -1};
const int MAXN = 200007;
int main() {
  long long n;
  while (cin >> n) {
    long long s = 1;
    while (n % s == 0) s *= 3;
    cout << (n + s - 1) / s << endl;
  }
  return 0;
}
