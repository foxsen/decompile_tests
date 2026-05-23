#include <bits/stdc++.h>
using namespace std;
int n;
tuple<int, int, int> ar[5005];
int h[] = {0, 0, 0};
int nonzero[] = {0, 0, 0};
bool ok(int s, int i) {
  switch (s) {
    case 500:
      return (nonzero[i] * 2) > n && ((nonzero[i] - h[i]) * 2 <= 2 * n);
      break;
    case 1000:
      return (nonzero[i] * 4) > n && ((nonzero[i] - h[i]) * 4 <= 2 * n);
      break;
    case 1500:
      return (nonzero[i] * 8) > n && ((nonzero[i] - h[i]) * 8 <= 2 * n);
      break;
    case 2000:
      return (nonzero[i] * 16) > n && ((nonzero[i] - h[i]) * 16 <= 2 * n);
      break;
    case 2500:
      return (nonzero[i] * 32) > n && ((nonzero[i] - h[i]) * 32 <= 2 * n);
      break;
    case 3000:
      return ((nonzero[i] - h[i]) * 32 <= n);
      break;
  }
}
int okk(int s, int i) {
  int k;
  switch (s) {
    case 500:
      k = n;
      break;
    case 1000:
      k = n / 2;
      break;
    case 1500:
      k = n / 4;
      break;
    case 2000:
      k = n / 8;
      break;
    case 2500:
      k = n / 16;
      break;
    case 3000:
      k = n / 32;
      break;
  }
  return min(max(0, nonzero[i] - k), h[i]);
}
int bok(int s, int i) {
  int k;
  switch (s) {
    case 500:
      k = n / 2 + 1;
      break;
    case 1000:
      k = n / 4 + 1;
      break;
    case 1500:
      k = n / 8 + 1;
      break;
    case 2000:
      k = n / 16 + 1;
      break;
    case 2500:
      k = n / 32 + 1;
      break;
    case 3000:
      k = 0;
      break;
  }
  return min(max(0, nonzero[i] - k), h[i]);
}
struct Node {
  int a;
  int b;
  int c;
  int score;
  bool cana, canb, canc;
};
Node arr[5005];
int score(int s, int t) {
  if (!t) return 0;
  t = abs(t);
  int a = s / 250;
  a = a * (250 - t);
  return a;
}
void createarr(int s1, int s2, int s3) {
  for (int i = 0; i < (int)(n); i++) {
    int a, b, c;
    tie(a, b, c) = ar[i];
    arr[i].a = score(s1, a);
    arr[i].b = score(s2, b);
    arr[i].c = score(s3, c);
    arr[i].score = arr[i].a + arr[i].b + arr[i].c;
    arr[i].cana = (a < 0);
    arr[i].canb = (b < 0);
    arr[i].canc = (c < 0);
  }
  sort(arr + 1, arr + n, [](Node n1, Node n2) { return n1.score > n2.score; });
}
int UP, mh[3];
int mnh[3];
int myscore;
bool push(int i, bool a, bool b, bool c) {
  int s = arr[i].score;
  if (a != 0 && arr[i].cana) {
    s -= arr[i].a;
  }
  if (b != 0 && arr[i].canb) {
    s -= arr[i].b;
  }
  if (c != 0 && arr[i].canc) {
    s -= arr[i].c;
  }
  if (s <= myscore) {
    return true;
  }
  return false;
}
int dp[2][91][91][91];
void solve() {
  cin >> n;
  for (int i = 0; i < (int)(n); i++) {
    int a, b, c;
    cin >> a >> b >> c;
    ar[i] = tuple<int, int, int>(a, b, c);
    if (a < 0) h[0]++;
    if (b < 0) h[1]++;
    if (c < 0) h[2]++;
    if (a) nonzero[0]++;
    if (b) nonzero[1]++;
    if (c) nonzero[2]++;
  }
  if (h[0] + h[1] + h[2] >= 90) {
    cout << 1;
    return;
  }
  int aa = 2 * n;
  for (int i = 1; i <= 6; i++) {
    for (int j = 1; j <= 6; j++) {
      for (int k = 1; k <= 6; k++) {
        int s1 = 500 * i;
        int s2 = 500 * j;
        int s3 = 500 * k;
        if (ok(s1, 0) && ok(s2, 1) && ok(s3, 2)) {
          mnh[0] = okk(s1, 0);
          mnh[1] = okk(s2, 1);
          mnh[2] = okk(s3, 2);
          mh[0] = bok(s1, 0);
          mh[1] = bok(s2, 1);
          mh[2] = bok(s3, 2);
          int maximumhacks = mh[0] + mh[1] + mh[2];
          createarr(s1, s2, s3);
          myscore = arr[0].score + 100 * maximumhacks;
          UP = 0;
          for (int i = 1; i < n; i++) {
            if (arr[i].score > myscore) UP++;
          }
          memset(dp, 0, sizeof(dp));
          ;
          for (int w = 1; w <= UP; w++) {
            for (int x = 0; x <= mh[0]; x++) {
              for (int y = 0; y <= mh[1]; y++) {
                for (int z = 0; z <= mh[2]; z++) {
                  int ww = w & 1;
                  int a = dp[!ww][x][y][z];
                  for (int i = 1; i < 8; i++) {
                    int xx = (bool)(i & 1);
                    int yy = (bool)(i & 2);
                    int zz = (bool)(i & 4);
                    if (x >= xx && y >= yy && z >= zz && push(w, xx, yy, zz)) {
                      a = max(a, 1 + dp[!ww][x - xx][y - yy][z - zz]);
                    }
                  }
                  dp[ww][x][y][z] = a;
                }
              }
            }
            for (int x = 0; x < (int)(mh[0] + 1); x++) {
              for (int y = 0; y < (int)(mh[1] + 1); y++) {
                for (int z = 0; z < (int)(mh[2] + 1); z++) {
                }
              }
            }
          }
          int ww = UP & 1;
          int ans = -2 * n;
          for (int x = mnh[0]; x <= mh[0]; x++) {
            for (int y = mnh[1]; y <= mh[1]; y++) {
              for (int z = mnh[2]; z <= mh[2]; z++) {
                ans = max(ans, dp[ww][x][y][z]);
              }
            }
          }
          ans = UP - ans + 1;
          aa = min(aa, ans);
        }
      }
    }
  }
  cout << aa << '\n';
}
int main() {
  cin.tie(0);
  cout.tie(0);
  cin.sync_with_stdio(0);
  cout.sync_with_stdio(0);
  int TC = 1;
  for (int ZZ = 1; ZZ <= TC; ZZ++) {
    clock_t start = clock();
    solve();
    clock_t end = clock();
    cerr << "Time: " << (double)(end - start) / CLOCKS_PER_SEC << " seconds"
         << '\n';
  }
  return 0;
}
