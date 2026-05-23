#include <bits/stdc++.h>
using namespace std;
int N, band, p, mark[7005];
long long sol;
struct dos {
  long long a, b;
} A[7005];
bool comp(const dos &h, const dos &k) { return h.a < k.a; }
queue<int> Q;
vector<int> G[7005], S;
void bfs(int nod) {
  Q.push(nod);
  mark[nod] = 1;
  sol += A[nod].b;
  band = 0;
  while (!Q.empty()) {
    nod = Q.front();
    Q.pop();
    for (auto ady : G[nod]) {
      if (mark[ady]) continue;
      mark[ady] = 1;
      sol += A[ady].b;
      Q.push(ady);
    }
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> N;
  for (int i = 1; i <= N; i++) cin >> A[i].a;
  for (int i = 1; i <= N; i++) cin >> A[i].b;
  sort(A + 1, A + 1 + N, comp);
  for (int i = 2; i <= N; i++)
    if (A[i].a == A[i - 1].a) S.push_back(i);
  for (int i = 1; i <= N; i++)
    for (int j = 1; j <= N; j++)
      if (i != j && (A[i].a & A[j].a) == A[j].a) G[i].push_back(j);
  for (auto s : S) {
    if (mark[s]) continue;
    bfs(s);
  }
  cout << sol;
}
