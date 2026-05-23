#include <bits/stdc++.h>
using namespace std;
map<string, long long int> sm;
char str[500005], nstr[500005];
vector<long long int> graph[500005], v;
long long int m, n;
long long int R[500005], RC[500005], LC[500005], ele;
long long int len[500005];
vector<long long int> dag[500005];
stack<long long int> stk, tstk;
long long int col[500005], dis[500005], low[500005], id[500005],
    elements[500005];
long long int node, edge, components, timer;
void dfs(long long int u) {
  long long int sz, v, i, tem;
  col[u] = 1;
  timer++;
  dis[u] = low[u] = timer;
  stk.push(u);
  sz = graph[u].size();
  for (i = 0; i < sz; i++) {
    v = graph[u][i];
    if (col[v] == 1) {
      low[u] = min(low[v], low[u]);
    } else if (col[v] == 0) {
      dfs(v);
      low[u] = min(low[u], low[v]);
    }
  }
  if (dis[u] == low[u]) {
    components++;
    do {
      tem = stk.top();
      tstk.push(tem);
      stk.pop();
      id[tem] = components;
      if (tem <= ele) elements[components]++;
      if (RC[components] == 0 && LC[components] == 0) {
        RC[components] = R[tem];
        LC[components] = len[tem];
      } else {
        if (RC[components] > R[tem]) {
          RC[components] = R[tem];
          LC[components] = len[tem];
        } else if (RC[components] == R[tem]) {
          LC[components] = min(LC[components], len[tem]);
        }
      }
      col[tem] = 2;
    } while (tem != u);
    while (!tstk.empty()) {
      tem = tstk.top();
      R[tem] = RC[components];
      len[tem] = LC[components];
      tstk.pop();
    }
  }
  return;
}
void scctarjan() {
  long long int i;
  for (i = 1; i <= node; i++) {
    if (col[i] == 0) {
      dfs(i);
    }
  }
  return;
}
void new_DAG_graph() {
  long long int i, j, u, v;
  long long int sz;
  for (i = 1; i <= node; i++) {
    sz = graph[i].size();
    for (j = 0; j < sz; j++) {
      u = id[i];
      v = id[graph[i][j]];
      if (u != v) {
        dag[u].push_back(v);
      }
    }
  }
  return;
}
void dfs2(long long int n) {
  long long int sz, i, j;
  col[n] = 1;
  sz = dag[n].size();
  for (i = 0; i < sz; i++) {
    j = dag[n][i];
    if (col[j] == 0) {
      dfs2(j);
      if (RC[n] == RC[j]) {
        LC[n] = min(LC[n], LC[j]);
      } else if (RC[n] > RC[j]) {
        RC[n] = RC[j];
        LC[n] = LC[j];
      }
    } else if (col[j] == 1 || col[j] == 2) {
      if (RC[n] == RC[j]) {
        LC[n] = min(LC[n], LC[j]);
      } else if (RC[n] > RC[j]) {
        RC[n] = RC[j];
        LC[n] = LC[j];
      }
    }
  }
  col[n] = 2;
  return;
}
int main() {
  long long int i, j, c, r, sz, l, ansr, ansl;
  c = 0;
  cin >> n;
  for (i = 1; i <= n; i++) {
    scanf("%s", str);
    l = strlen(str);
    r = 0;
    for (j = 0; j < l; j++) {
      str[j] = tolower(str[j]);
      if (str[j] == 'r') r++;
    }
    if (sm.find(str) == sm.end()) {
      c++;
      R[c] = r;
      len[c] = l;
      sm[str] = c;
    }
    v.push_back(sm[str]);
  }
  ele = c;
  cin >> m;
  for (i = 1; i <= m; i++) {
    scanf("%s %s", str, nstr);
    l = strlen(str);
    r = 0;
    for (j = 0; j < l; j++) {
      str[j] = tolower(str[j]);
      if (str[j] == 'r') r++;
    }
    if (sm.find(str) == sm.end()) {
      c++;
      R[c] = r;
      len[c] = l;
      sm[str] = c;
    }
    l = strlen(nstr);
    r = 0;
    for (j = 0; j < l; j++) {
      nstr[j] = tolower(nstr[j]);
      if (nstr[j] == 'r') r++;
    }
    if (sm.find(nstr) == sm.end()) {
      c++;
      R[c] = r;
      len[c] = l;
      sm[nstr] = c;
    }
    graph[sm[str]].push_back(sm[nstr]);
  }
  node = c;
  scctarjan();
  new_DAG_graph();
  memset(col, 0, sizeof(col));
  ansr = ansl = 0;
  sz = v.size();
  long long int tot = 0;
  for (i = 1; i <= components; i++) {
    tot += elements[i];
  }
  for (i = 1; i <= components; i++) {
    if (col[i] != 2) {
      dfs2(i);
    }
  }
  for (i = 0; i < sz; i++) {
    ansr += (RC[id[v[i]]]);
    ansl += (LC[id[v[i]]]);
  }
  cout << ansr << " " << ansl << endl;
  return 0;
}
