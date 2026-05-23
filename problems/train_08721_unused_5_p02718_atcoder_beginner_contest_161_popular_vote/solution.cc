#include <bits/stdc++.h>
using namespace std;
int main()
  {int N, M; cin >> N >> M;
  vector<int> As(N); for (auto &A : As) cin >> A;
  int c = 0, s = accumulate(As.begin(), As.end(), 0);
  for (auto A : As)
    {if (4 * M * A >= s) ++c;}
  puts(M <= c ? "Yes" : "No");}