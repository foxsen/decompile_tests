#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)
#define all(a) (a).begin(), (a).end()

string s, t;
int n, m;
const int R = 256;
vector<vector<int>> dfa;
vector<int> match;
vector<int> L;

void kmp() {
  dfa.resize(R, vector<int>(m+1));
  dfa[t[0]][0] = 1;
  for(int x = 0, j = 1; j <= m; j++) {
    for(int c = 0; c < R; c++) {
      dfa[c][j] = dfa[c][x];
    }
    dfa[t[j]][j] = (j+1)%(m+1);
    x = dfa[t[j]][x];
  }
}

int pathLength(int i) {
  if(!match[i]) return 0;
  if(L[i] != -1) return L[i];

  return L[i] = pathLength((i+m)%n) + 1;
}

bool hasLoop() {
  rep(i,m) {
    bool loop = true;
    for(int j = 0; j < n + m; j += m) {
      if(!match[(i+j)%n]) loop = false;
    }
    if(loop) return true;
  }
  return false;
}

int main () {
  cin >> s >> t;
  n = s.size(), m = t.size();
  match.resize(n);
  L.resize(n, -1);

  kmp();
  for(int i = 0, j = 0; i < n + m - 1; i++) {
    j = dfa[s[i%n]][j];
    if(j == m) match[i-m+1] = 1;
  }

  if(hasLoop()) {
    cout << - 1 << endl;
    return 0;
  }

  int ans = 0;
  rep(i,n) {
    if(match[i]) ans = max(ans, pathLength(i));
  }
  cout << ans << endl;

  return 0;
}
