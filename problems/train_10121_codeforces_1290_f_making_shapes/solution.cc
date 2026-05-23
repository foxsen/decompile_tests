#include <bits/stdc++.h>
using namespace std;
constexpr int mod = 998244353;
int x[5], y[5];
int px[32], nx[32], py[32], ny[32];
int dp[32][20][20][20][20][2][2];
void add(int& x, const int& y) {
  x += y;
  if (x >= mod) x -= mod;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i += 1) cin >> x[i] >> y[i];
  for (int mask = 0; mask < (1 << n); mask += 1)
    for (int i = 0; i < n; i += 1)
      if ((mask >> i) & 1) {
        (x[i] > 0 ? px : nx)[mask] += abs(x[i]);
        (y[i] > 0 ? py : ny)[mask] += abs(y[i]);
      }
  dp[0][0][0][0][0][0][0] = 1;
  for (int i = 0; i < (30); i += 1)
    for (int cpx = 0; cpx < (20); cpx += 1)
      for (int cnx = 0; cnx < (20); cnx += 1)
        for (int cpy = 0; cpy < (20); cpy += 1)
          for (int cny = 0; cny < (20); cny += 1)
            for (int bx = 0; bx < (2); bx += 1)
              for (int by = 0; by < (2); by += 1)
                for (int mask = 0; mask < (1 << n); mask += 1)
                  if (dp[i][cpx][cnx][cpy][cny][bx][by]) {
                    if (0)
                      cout << i << " " << cpx << " " << cny << " " << cpy << " "
                           << cny << " " << bx << " " << by << " "
                           << dp[i][cpx][cnx][cpy][cny][bx][by] << endl;
                    int npx = cpx + px[mask], nnx = cnx + nx[mask],
                        npy = cpy + py[mask], nny = cny + ny[mask];
                    if ((npx ^ nnx) & 1) continue;
                    if ((npy ^ nny) & 1) continue;
                    int cx = npx & 1, mx = (m >> i) & 1;
                    int cy = npy & 1, my = (m >> i) & 1;
                    add(dp[i + 1][npx >> 1][nnx >> 1][npy >> 1][nny >> 1]
                          [cx != mx ? (cx > mx) : bx]
                          [cy != my ? (cy > my) : by],
                        dp[i][cpx][cnx][cpy][cny][bx][by]);
                  }
  cout << (dp[30][0][0][0][0][0][0] + mod - 1) % mod;
  return 0;
}
