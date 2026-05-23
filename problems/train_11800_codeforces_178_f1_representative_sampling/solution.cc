#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 2000 + 10;
const int MAX_K = 500 + 10;
string Arr[MAX_N];
pair<long long, long long> T[2 * MAX_N][12];
long long Dist(const string &a, const string &b) {
  long long sz = (int)min(a.size(), b.size());
  int i;
  for (i = 0; i < sz; i++)
    if (a[i] != b[i]) return i;
  return i;
}
vector<long long> Solve(int x, int y) {
  if (x == y) return vector<long long>(2, 0);
  long long len = y - x;
  long long t = 0;
  long long p = 1;
  while ((p *= 2) <= len) t++;
  pair<long long, long long> MN = min(T[x][t], T[y - (1 << t)][t]);
  vector<long long> A = Solve(x, MN.second);
  vector<long long> B = Solve(MN.second + 1, y);
  vector<long long> Ret(y - x + 2, 0);
  for (long long i = 0; i <= y - x + 1; i++)
    for (long long j = 0; j <= min((MN.second - x + 1), i); j++) {
      long long k = i - j;
      if (k > y - MN.second) continue;
      Ret[i] = max(Ret[i], A[j] + B[k] + (j * k * MN.first));
    }
  return Ret;
}
int main() {
  ios::sync_with_stdio(false);
  int N, K;
  cin >> N >> K;
  for (int i = 0; i < N; i++) cin >> Arr[i];
  sort(Arr, Arr + N);
  for (int i = 0; i < 2 * MAX_N; i++)
    for (int j = 0; j < 12; j++) T[i][j] = make_pair(1LL << 60, 0);
  for (int j = 0; j < 12; j++) {
    for (int i = 0; i < N - 1; i++) {
      if (j == 0) {
        T[i][0] = make_pair(Dist(Arr[i], Arr[i + 1]), i);
        continue;
      }
      T[i][j] = min(T[i][j - 1], T[i + (1 << (j - 1))][j - 1]);
    }
  }
  cout << Solve(0, N - 1)[K] << endl;
  return 0;
}
