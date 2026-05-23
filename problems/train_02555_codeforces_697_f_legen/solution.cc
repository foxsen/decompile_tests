#include <bits/stdc++.h>
const long long N = 1e5 + 10, alpha = 128;
using namespace std;
long long n, q, m, k, x, y, a[N], mx = -1, mn = 1e9, sum[N];
string s, s1, s2;
long long trie[N][alpha], ndcnt, ids[N], fail[N], sz[N], nxtid[N], myids[N];
char children[N][alpha];
void addnode() {
  memset(trie[ndcnt], -1, sizeof(trie[ndcnt]));
  ids[ndcnt] = -1;
  sz[ndcnt] = 0;
  ndcnt++;
  return;
}
long long insert(string str, long long id) {
  long long cur, i;
  for (cur = 0, i = 0; i < str.size(); i++) {
    if (trie[cur][str[i]] == -1) {
      trie[cur][str[i]] = ndcnt;
      addnode();
      children[cur][sz[cur]++] = str[i];
    }
    cur = trie[cur][str[i]];
  }
  if (ids[cur] == -1) ids[cur] = id;
  sum[ids[cur]] += a[x];
  return ids[cur];
}
long long getnxt(long long f, char c) {
  while (trie[f][c] == -1) f = fail[f];
  f = trie[f][c];
  return f;
}
void buildfail() {
  queue<long long> qu;
  for (long long i = 0; i < alpha; i++) {
    long long r = trie[0][i];
    if (r != -1) {
      fail[r] = 0;
      nxtid[r] = 0;
      qu.push(r);
    } else
      trie[0][i] = 0;
  }
  while (qu.size()) {
    long long cur = qu.front();
    qu.pop();
    for (long long i = 0; i < sz[cur]; i++) {
      char c = children[cur][i];
      nxtid[trie[cur][c]] = fail[trie[cur][c]] = getnxt(fail[cur], c);
      qu.push(trie[cur][c]);
    }
  }
}
long long getnxtid(long long cur) {
  if (cur == 0) return 0;
  long long &nxt = nxtid[cur];
  if (ids[nxt] != -1) return nxt;
  return nxt = getnxtid(nxt);
}
void init() {
  ndcnt = 0;
  addnode();
}
const long long SZ = 205;
struct matrix {
  long long a[SZ][SZ];
  matrix() {
    for (long long i = 0; i < SZ; i++)
      for (long long j = 0; j < SZ; j++) a[i][j] = -1e9;
  }
  matrix operator*(matrix other) {
    matrix ret;
    for (long long i = 0; i < SZ; i++) {
      for (long long j = 0; j < SZ; j++) {
        for (long long k = 0; k < SZ; k++) {
          ret.a[i][k] = max(ret.a[i][k], a[i][j] + other.a[j][k]);
        }
      }
    }
    return ret;
  }
  matrix POW(long long b) {
    matrix res, a = (*this);
    for (long long i = 0; i < SZ; i++) res.a[i][i] = 0;
    while (b) {
      if (b & 1) res = res * a;
      a = a * a;
      b /= 2;
    }
    return res;
  }
};
int32_t main() {
  init();
  cin >> n >> k;
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (long long i = 0; i < n; i++) {
    cin >> s1;
    x = i;
    myids[i] = insert(s1, i);
  }
  buildfail();
  matrix ans;
  for (long long i = 0; i < ndcnt; i++) {
    for (char c = 'a'; c <= 'z'; c++) {
      long long nxt = getnxt(i, c), cnt = 0;
      for (long long j = nxt; j; j = getnxtid(j))
        if (ids[j] != -1) cnt += sum[ids[j]];
      ans.a[nxt][i] = max(ans.a[nxt][i], cnt);
    }
  }
  ans = ans.POW(k);
  for (long long i = 0; i < SZ; i++) {
    mx = max(mx, ans.a[i][0]);
  }
  cout << mx << endl;
}
