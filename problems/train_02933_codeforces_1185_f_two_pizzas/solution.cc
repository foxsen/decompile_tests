#include <bits/stdc++.h>
using namespace std;
const int QQ = 3e5 + 10;
const int N = 1e4 + 10;
const int module = 1e9 + 7;
long long rand(long long l, long long r) {
  return 1LL * (1LL * rand() * RAND_MAX + rand()) % (r - l + 1) + l;
}
void doc() {}
void solve() {
  int n, m;
  cin >> n >> m;
  int Mask[n];
  for (int i = 0; i < n; i++) {
    int f;
    cin >> f;
    int mask = 0;
    while (f--) {
      int x;
      cin >> x;
      x--;
      mask |= (1 << x);
    }
    Mask[i] = mask;
  }
  int SL[1 << 9];
  memset(SL, 0, sizeof(SL));
  for (int mask = 0; mask < (1 << 9); mask++) {
    for (int i = 0; i < n; i++) {
      if ((Mask[i] & mask) == Mask[i]) SL[mask]++;
    }
  }
  vector<pair<int, int> > VL[1 << 9];
  cerr << "error" << '\n';
  for (int id = 0; id < m; id++) {
    int c, r;
    cin >> c >> r;
    int mask = 0;
    while (r--) {
      int x;
      cin >> x;
      x--;
      mask |= (1 << x);
    }
    VL[mask].push_back(pair<int, int>(c, id + 1));
  }
  cerr << "error" << '\n';
  for (int mask = 0; mask < (1 << 9); mask++)
    sort(VL[mask].begin(), VL[mask].end());
  int Res = -1;
  int Pos1 = 0;
  int Pos2 = 0;
  int Value = 2e9;
  cerr << "error" << '\n';
  for (int mask1 = 1; mask1 < (1 << 9); mask1++) {
    for (int mask2 = 1; mask2 < (1 << 9); mask2++) {
      int value = SL[mask1 | mask2];
      if (value > Res) {
        if (mask1 == mask2) {
          if ((int)VL[mask1].size() <= 1) continue;
          Res = value;
          Value = VL[mask1][0].first + VL[mask1][1].first;
          Pos1 = VL[mask1][0].second;
          Pos2 = VL[mask2][1].second;
        } else {
          if ((int)VL[mask1].size() == 0 || (int)VL[mask2].size() == 0)
            continue;
          Res = value;
          Value = VL[mask1][0].first + VL[mask2][0].first;
          Pos1 = VL[mask1][0].second;
          Pos2 = VL[mask2][0].second;
        }
      } else {
        if (value == Res) {
          if (mask1 == mask2) {
            if ((int)VL[mask1].size() <= 1) continue;
            Res = value;
            if (VL[mask1][0].first + VL[mask1][1].first < Value) {
              Value = VL[mask1][0].first + VL[mask2][1].first;
              Pos1 = VL[mask1][0].second;
              Pos2 = VL[mask2][1].second;
            }
          } else {
            if ((int)VL[mask1].size() == 0 || (int)VL[mask2].size() == 0)
              continue;
            if (VL[mask1][0].first + VL[mask2][0].first < Value) {
              Value = VL[mask1][0].first + VL[mask2][0].first;
              Pos1 = VL[mask1][0].second;
              Pos2 = VL[mask2][0].second;
            }
          }
        }
      }
    }
  }
  cout << Pos1 << " " << Pos2;
}
int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  cout.tie(nullptr);
  doc();
  solve();
  return 0;
}
