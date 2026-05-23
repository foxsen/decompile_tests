#include <bits/stdc++.h>
#define REP(i, a, n) for(ll i = ((ll) a); i < ((ll) n); i++)
using namespace std;
typedef long long ll;

ll N;
char S[256][256];
bool visited[256][256];

bool isin(ll y, ll x) { return 0 <= y && y < N && 0 <= x && x < N; }

void dfs(ll y, ll x) {
  ll dd[5] = { 0, 1, 0, -1, 0 };
  if(visited[y][x]) return;
  visited[y][x] = true;
  REP(i, 0, 4) if(isin(y + dd[i], x + dd[i + 1])) dfs(y + dd[i], x + dd[i + 1]);
}

int main(void) {
  cin >> N;
  REP(i, 0, N) REP(j, 0, N) cin >> S[i][j];

  REP(i, 0, N) REP(j, 0, N) visited[i][j] = S[i][j] == 'x';

  ll cnt = 0;
  REP(i, 0, N) REP(j, 0, N) {
    if(!visited[i][j]) {
      cnt++;
      dfs(i, j);
    }
  }
  cout << (cnt - 1) / 3 << endl;
}