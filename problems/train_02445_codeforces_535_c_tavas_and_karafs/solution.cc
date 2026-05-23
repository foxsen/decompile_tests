#include <bits/stdc++.h>
using namespace std;
void imprimirVector(vector<int> v) {
  if (!v.empty()) {
    int p = v.size();
    cout << "[";
    for (int i = 0; i < (int)(p - 1); i++) cout << v[i] << ",";
    cout << v[p - 1] << "]" << endl;
  } else
    cout << "[]" << endl;
}
long long cuadratica(double a, double b, double c) {
  long long res = floor((-b + sqrt(b * b - 4 * a * c)) / (2 * a));
  return res;
}
int query(long long A, long long B, long long l, long long t, long long m) {
  if (t < (A + (l - 1) * B))
    return -1;
  else
    return min(cuadratica(B, (2 * A - B),
                          2 * (1 - l) * (A + B * l) - 2 * B + B * l * l +
                              B * l - 2 * m * t),
               (t - A + B) / B);
}
int main() {
  long long n, A, B;
  cin >> A >> B >> n;
  for (int i = 0; i < (int)(n); i++) {
    long long l, t, m;
    cin >> l >> t >> m;
    cout << query(A, B, l, t, m) << endl;
  }
  return 0;
}
