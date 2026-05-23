#include <iostream>
#include <numeric>
#include <vector>
#include <cstring>

#define ALL(v) v.begin(), v.end()

const int N = 51;
const int M = (N * (N - 1)) / 2 + 5;

int f[N][M];
int s[N][M];
int t[N];
int answer[N];

int n, mod;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin >> n >> mod;

  f[0][0] = 1;
  for (int i = 1; i < N; i++)
    for (int j = 0; j < M; j++)
      for (int k = j - (i - 1); k <= j; k++)
        if (k >= 0)
          f[i][j] = (f[i][j] + f[i - 1][k]) % mod;

  for (int i = 0; i < N; i++) {
    s[i][0] = f[i][0];
    for (int j = 1; j < M; j++)
      s[i][j] = (s[i][j - 1] + f[i][j]) % mod;
  }

  for (int i = 1; i < N; i++)
    for (int j = 1; j <= i; j++)
      for (int k = j + 1; k <= i; k++)
        for (int w = k - j + 1; w < M; w++) {
          long long add = (1LL * f[i - 1][w] * s[i - 1][w - (k - j) - 1]) % mod;
          t[i] = (t[i] + add) % mod;
        }
  for (int i = 1; i < N; i++) {
    answer[i] = (1LL * i * answer[i - 1]) % mod;
    answer[i] = (answer[i] + t[i]) % mod;
  }
  std::cout << answer[n] << "\n";
  return 0;
}
