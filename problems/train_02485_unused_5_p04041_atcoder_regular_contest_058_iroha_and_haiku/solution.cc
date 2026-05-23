#include <iostream>
#include <cstring>
using namespace std;

typedef int state_t;

const int Mod = 1e9 + 7, MaxN = 41, StateLen = 5 + 7 + 5;
int N, X, Y, Z, p[MaxN], f[MaxN][1 << StateLen];
state_t end_state;

state_t dp(int i, int j) {
  if (i == N) {
    return 0;
  }
  if (~f[i][j]) {
    return f[i][j];
  }
  long long res = 0;
  for (int k = 1; k <= 10; ++k) {
    int next_state = (j << k) | 1;
    if ((next_state & end_state) == end_state) {
      res += p[N - 1 - i];
    } else {
      res += dp(i + 1, next_state & ((1 << 17) - 1));
    }
  }
  return f[i][j] = res % Mod;
}

int main() {
  ios_base::sync_with_stdio(false);
  memset(f, 0xff, sizeof f);
  cin.tie(0);
  cin >> N >> X >> Y >> Z;
  p[0] = 1;
  for (int i = 1; i < MaxN; ++i) {
    p[i] = p[i - 1] * 10LL % Mod;
  }
  end_state = (1 << X) | (1 << (X + Y)) | (1 << (X + Y + Z));
  cout << dp(0, 1) << endl;
  return 0;
}
