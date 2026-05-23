#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
char S[MAXN];
int main(void) {
  int N;
  scanf("%d", &N);
  scanf("%s", S);
  int ans = 1;
  int curr = 0;
  static vector<int> vec;
  for (int i = 1; i < N; ++i) {
    if (S[i] != S[i - 1]) {
      vec.push_back(i - curr);
      curr = i;
    }
  }
  vec.push_back(N - curr);
  ans = (int)vec.size();
  if (vec[0] > 1 || vec.back() > 1) ans = max(ans, (int)vec.size() + 1);
  for (int i = 0; i < (int)vec.size(); ++i)
    if (vec[i] > 2) ans = max(ans, (int)vec.size() + 2);
  int cnt = 0;
  for (int i = 0; i < (int)vec.size(); ++i) {
    if (vec[i] > 1) ++cnt;
  }
  if (cnt > 1) ans = (int)vec.size() + 2;
  if (cnt > 0) ans = max(ans, (int)vec.size() + 1);
  printf("%d\n", ans);
  return 0;
}
