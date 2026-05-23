#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int p = 1e9 + 7;
inline void add(int &x, int y) {
  x += y;
  if (x >= p) {
    x -= p;
  }
}
inline void dec(int &x, int y) {
  x -= y;
  if (x < 0) {
    x += p;
  }
}
inline int qpow(int value, int n) {
  int result = 1;
  for (; n; n >>= 1, value = (ll)value * value % p) {
    if (n & 1) {
      result = (ll)result * value % p;
    }
  }
  return result;
}
int main() {
  do {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
  } while (false);
  int a, b, c, A, B, C;
  cin >> a >> b >> c >> A >> B >> C;
  if (A % a || B % b || C % c) {
    puts("0");
  } else {
    auto calc = [&] (int n, int N, int m, int M) {
      int result = 0;
      add(result, (ll)m * qpow(n, M / m) % p);
      add(result, (ll)n * qpow(m, N / n) % p);
      dec(result, (ll)n * m % p);
      return result;
    };
    int answer = 0;
    add(answer, (ll)a * qpow(calc(b, B, c, C), A / a) % p);
    add(answer, (ll)b * qpow(calc(a, A, c, C), B / b) % p);
    add(answer, (ll)c * qpow(calc(a, A, b, B), C / c) % p);
    dec(answer, (ll)a * b % p * qpow(c, A / a * B / b) % p);
    dec(answer, (ll)a * c % p * qpow(b, A / a * C / c) % p);
    dec(answer, (ll)b * c % p * qpow(a, B / b * C / c) % p);
    add(answer, (ll)a * b * c % p);
    int limit = max(A / a, B / b);
    vector<vector<int> > binom(limit + 1, vector<int>(limit + 1));
    for (int i = 0; i <= limit; i++) {
      binom[i][0] = binom[i][i] = 1;
      for (int j = 1; j < i; j++) {
        binom[i][j] = (binom[i - 1][j] + binom[i - 1][j - 1]) % p;
      }
    }
    vector<vector<int> > dp(A / a + 1, vector<int>(B / b + 1));
    for (int i = A / a; i > 0; i--) {
      for (int j = B / b; j > 0; j--) {
        dp[i][j] = (ll)binom[A / a][i] * binom[B / b][j] % p * qpow(c, (A / a - i) * (B / b - j)) % p;
        for (int x = i; x <= A / a; x++) {
          for (int y = j; y <= B / b; y++) {
            if (x != i || y != j) {
              dec(dp[i][j], (ll)dp[x][y] * binom[x][i] % p * binom[y][j] % p);
            }
          }
        }
        if (i != A / a || j != B / b) {
          int result = 0;
          add(result, qpow(qpow(b, i) + qpow(a, j) - 1, C / c));
          dec(result, qpow(qpow(b, i), C / c));
          dec(result, qpow(qpow(a, j), C / c));
          add(result, 1);
          add(answer, (ll)result * a * b * c % p * dp[i][j] % p);
        }
      }
    }
    cout << answer << endl;
  }
  return 0;
}
