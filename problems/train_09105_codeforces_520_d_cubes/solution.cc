#include <bits/stdc++.h>
#pragma GCC optimize("Ofast", "inline", "-ffast-math")
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
using namespace std;
template <typename T>
void read(T &x) {
  x = 0;
  char ch = getchar();
  int fh = 1;
  while (ch < '0' || ch > '9') {
    if (ch == '-') fh = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
  x *= fh;
}
template <typename T>
void write(T x) {
  if (x < 0) x = -x, putchar('-');
  if (x > 9) write(x / 10);
  putchar(x % 10 + '0');
}
template <typename T>
void writeln(T x) {
  write(x);
  puts("");
}
int m;
map<pair<int, int>, int> mp;
int val[100005];
bool del[100005];
bool ins[100005];
set<pair<int, pair<int, int>>> st;
long long ans = 0;
long long qpow(long long a, long long b) {
  long long res = 1;
  while (b) {
    if (b & 1) res = res * a % 1000000009;
    a = a * a % 1000000009;
    b >>= 1;
  }
  return res;
}
signed main() {
  read(m);
  for (int i = 0; i < m; ++i) {
    int x, y;
    read(x);
    read(y);
    mp[make_pair(x, y)] = i;
  }
  for (auto i : mp) {
    if (i.first.second == 0)
      val[i.second] = 1000000007;
    else {
      if (mp.count(make_pair(i.first.first - 1, i.first.second - 1)))
        val[i.second]++;
      if (mp.count(make_pair(i.first.first, i.first.second - 1)))
        val[i.second]++;
      if (mp.count(make_pair(i.first.first + 1, i.first.second - 1)))
        val[i.second]++;
    }
  }
  for (auto i : mp) {
    bool flag = true;
    if (mp.count(make_pair(i.first.first - 1, i.first.second + 1)))
      if (val[mp[make_pair(i.first.first - 1, i.first.second + 1)]] == 1)
        flag = false;
    if (mp.count(make_pair(i.first.first, i.first.second + 1)))
      if (val[mp[make_pair(i.first.first, i.first.second + 1)]] == 1)
        flag = false;
    if (mp.count(make_pair(i.first.first + 1, i.first.second + 1)))
      if (val[mp[make_pair(i.first.first + 1, i.first.second + 1)]] == 1)
        flag = false;
    if (flag) {
      st.insert(make_pair(i.second, i.first));
      ins[i.second] = 1;
    }
  }
  for (int i = 0; i < m; ++i) {
    int id, x, y;
    while (1) {
      set<pair<int, pair<int, int>>>::iterator it;
      if (i & 1)
        it = st.begin();
      else {
        it = st.end();
        it--;
      }
      if (!del[(*it).first] && ins[(*it).first]) {
        id = (*it).first;
        x = (*it).second.first;
        y = (*it).second.second;
        st.erase(it);
        break;
      }
      st.erase(it);
    }
    ans += qpow(m, m - i - 1) * id % 1000000009;
    ans %= 1000000009;
    del[id] = 1;
    if (mp.count(make_pair(x - 1, y + 1)))
      if (!del[mp[make_pair(x - 1, y + 1)]]) {
        val[mp[make_pair(x - 1, y + 1)]]--;
        if (mp.count(make_pair(x - 2, y)))
          if (!del[mp[make_pair(x - 2, y)]]) {
            bool flag = true;
            if (mp.count(make_pair(x - 3, y + 1)))
              if (!del[mp[make_pair(x - 3, y + 1)]])
                if (val[mp[make_pair(x - 3, y + 1)]] == 1) flag = false;
            if (mp.count(make_pair(x - 2, y + 1)))
              if (!del[mp[make_pair(x - 2, y + 1)]])
                if (val[mp[make_pair(x - 2, y + 1)]] == 1) flag = false;
            if (mp.count(make_pair(x - 1, y + 1)))
              if (!del[mp[make_pair(x - 1, y + 1)]])
                if (val[mp[make_pair(x - 1, y + 1)]] == 1) flag = false;
            if (flag) {
              st.insert(
                  make_pair(mp[make_pair(x - 2, y)], make_pair(x - 2, y)));
              ins[mp[make_pair(x - 2, y)]] = 1;
            } else
              ins[mp[make_pair(x - 2, y)]] = 0;
          }
        if (mp.count(make_pair(x - 1, y)))
          if (!del[mp[make_pair(x - 1, y)]]) {
            bool flag = true;
            if (mp.count(make_pair(x - 2, y + 1)))
              if (!del[mp[make_pair(x - 2, y + 1)]])
                if (val[mp[make_pair(x - 2, y + 1)]] == 1) flag = false;
            if (mp.count(make_pair(x - 1, y + 1)))
              if (!del[mp[make_pair(x - 1, y + 1)]])
                if (val[mp[make_pair(x - 1, y + 1)]] == 1) flag = false;
            if (mp.count(make_pair(x, y + 1)))
              if (!del[mp[make_pair(x, y + 1)]])
                if (val[mp[make_pair(x, y + 1)]] == 1) flag = false;
            if (flag) {
              st.insert(
                  make_pair(mp[make_pair(x - 1, y)], make_pair(x - 1, y)));
              ins[mp[make_pair(x - 1, y)]] = 1;
            } else
              ins[mp[make_pair(x - 1, y)]] = 0;
          }
        if (mp.count(make_pair(x, y)))
          if (!del[mp[make_pair(x, y)]]) {
            bool flag = true;
            if (mp.count(make_pair(x - 1, y + 1)))
              if (!del[mp[make_pair(x - 1, y + 1)]])
                if (val[mp[make_pair(x - 1, y + 1)]] == 1) flag = false;
            if (mp.count(make_pair(x, y + 1)))
              if (!del[mp[make_pair(x, y + 1)]])
                if (val[mp[make_pair(x, y + 1)]] == 1) flag = false;
            if (mp.count(make_pair(x + 1, y + 1)))
              if (!del[mp[make_pair(x + 1, y + 1)]])
                if (val[mp[make_pair(x + 1, y + 1)]] == 1) flag = false;
            if (flag) {
              st.insert(make_pair(mp[make_pair(x, y)], make_pair(x, y)));
              ins[mp[make_pair(x, y)]] = 1;
            } else
              ins[mp[make_pair(x, y)]] = 0;
          }
      }
    if (mp.count(make_pair(x, y + 1)))
      if (!del[mp[make_pair(x, y + 1)]]) {
        val[mp[make_pair(x, y + 1)]]--;
        if (mp.count(make_pair(x - 1, y)))
          if (!del[mp[make_pair(x - 1, y)]]) {
            bool flag = true;
            if (mp.count(make_pair(x - 2, y + 1)))
              if (!del[mp[make_pair(x - 2, y + 1)]])
                if (val[mp[make_pair(x - 2, y + 1)]] == 1) flag = false;
            if (mp.count(make_pair(x - 1, y + 1)))
              if (!del[mp[make_pair(x - 1, y + 1)]])
                if (val[mp[make_pair(x - 1, y + 1)]] == 1) flag = false;
            if (mp.count(make_pair(x, y + 1)))
              if (!del[mp[make_pair(x, y + 1)]])
                if (val[mp[make_pair(x, y + 1)]] == 1) flag = false;
            if (flag) {
              st.insert(
                  make_pair(mp[make_pair(x - 1, y)], make_pair(x - 1, y)));
              ins[mp[make_pair(x - 1, y)]] = 1;
            } else
              ins[mp[make_pair(x - 1, y)]] = 0;
          }
        if (mp.count(make_pair(x, y)))
          if (!del[mp[make_pair(x, y)]]) {
            bool flag = true;
            if (mp.count(make_pair(x - 1, y + 1)))
              if (!del[mp[make_pair(x - 1, y + 1)]])
                if (val[mp[make_pair(x - 1, y + 1)]] == 1) flag = false;
            if (mp.count(make_pair(x, y + 1)))
              if (!del[mp[make_pair(x, y + 1)]])
                if (val[mp[make_pair(x, y + 1)]] == 1) flag = false;
            if (mp.count(make_pair(x + 1, y + 1)))
              if (!del[mp[make_pair(x + 1, y + 1)]])
                if (val[mp[make_pair(x + 1, y + 1)]] == 1) flag = false;
            if (flag) {
              st.insert(make_pair(mp[make_pair(x, y)], make_pair(x, y)));
              ins[mp[make_pair(x, y)]] = 1;
            } else
              ins[mp[make_pair(x, y)]] = 0;
          }
        if (mp.count(make_pair(x + 1, y)))
          if (!del[mp[make_pair(x + 1, y)]]) {
            bool flag = true;
            if (mp.count(make_pair(x, y + 1)))
              if (!del[mp[make_pair(x, y + 1)]])
                if (val[mp[make_pair(x, y + 1)]] == 1) flag = false;
            if (mp.count(make_pair(x + 1, y + 1)))
              if (!del[mp[make_pair(x + 1, y + 1)]])
                if (val[mp[make_pair(x + 1, y + 1)]] == 1) flag = false;
            if (mp.count(make_pair(x + 2, y + 1)))
              if (!del[mp[make_pair(x + 2, y + 1)]])
                if (val[mp[make_pair(x + 2, y + 1)]] == 1) flag = false;
            if (flag) {
              st.insert(
                  make_pair(mp[make_pair(x + 1, y)], make_pair(x + 1, y)));
              ins[mp[make_pair(x + 1, y)]] = 1;
            } else
              ins[mp[make_pair(x + 1, y)]] = 0;
          }
      }
    if (mp.count(make_pair(x + 1, y + 1)))
      if (!del[mp[make_pair(x + 1, y + 1)]]) {
        val[mp[make_pair(x + 1, y + 1)]]--;
        if (mp.count(make_pair(x, y)))
          if (!del[mp[make_pair(x, y)]]) {
            bool flag = true;
            if (mp.count(make_pair(x - 1, y + 1)))
              if (!del[mp[make_pair(x - 1, y + 1)]])
                if (val[mp[make_pair(x - 1, y + 1)]] == 1) flag = false;
            if (mp.count(make_pair(x, y + 1)))
              if (!del[mp[make_pair(x, y + 1)]])
                if (val[mp[make_pair(x, y + 1)]] == 1) flag = false;
            if (mp.count(make_pair(x + 1, y + 1)))
              if (!del[mp[make_pair(x + 1, y + 1)]])
                if (val[mp[make_pair(x + 1, y + 1)]] == 1) flag = false;
            if (flag) {
              st.insert(make_pair(mp[make_pair(x, y)], make_pair(x, y)));
              ins[mp[make_pair(x, y)]] = 1;
            } else
              ins[mp[make_pair(x, y)]] = 0;
          }
        if (mp.count(make_pair(x + 1, y)))
          if (!del[mp[make_pair(x + 1, y)]]) {
            bool flag = true;
            if (mp.count(make_pair(x, y + 1)))
              if (!del[mp[make_pair(x, y + 1)]])
                if (val[mp[make_pair(x, y + 1)]] == 1) flag = false;
            if (mp.count(make_pair(x + 1, y + 1)))
              if (!del[mp[make_pair(x + 1, y + 1)]])
                if (val[mp[make_pair(x + 1, y + 1)]] == 1) flag = false;
            if (mp.count(make_pair(x + 2, y + 1)))
              if (!del[mp[make_pair(x + 2, y + 1)]])
                if (val[mp[make_pair(x + 2, y + 1)]] == 1) flag = false;
            if (flag) {
              st.insert(
                  make_pair(mp[make_pair(x + 1, y)], make_pair(x + 1, y)));
              ins[mp[make_pair(x + 1, y)]] = 1;
            } else
              ins[mp[make_pair(x + 1, y)]] = 0;
          }
        if (mp.count(make_pair(x + 2, y)))
          if (!del[mp[make_pair(x + 2, y)]]) {
            bool flag = true;
            if (mp.count(make_pair(x + 1, y + 1)))
              if (!del[mp[make_pair(x + 1, y + 1)]])
                if (val[mp[make_pair(x + 1, y + 1)]] == 1) flag = false;
            if (mp.count(make_pair(x + 2, y + 1)))
              if (!del[mp[make_pair(x + 2, y + 1)]])
                if (val[mp[make_pair(x + 2, y + 1)]] == 1) flag = false;
            if (mp.count(make_pair(x + 3, y + 1)))
              if (!del[mp[make_pair(x + 3, y + 1)]])
                if (val[mp[make_pair(x + 3, y + 1)]] == 1) flag = false;
            if (flag) {
              st.insert(
                  make_pair(mp[make_pair(x + 2, y)], make_pair(x + 2, y)));
              ins[mp[make_pair(x + 2, y)]] = 1;
            } else
              ins[mp[make_pair(x + 2, y)]] = 0;
          }
      }
    if (mp.count(make_pair(x - 1, y - 1)))
      if (!del[mp[make_pair(x - 1, y - 1)]]) {
        bool flag = true;
        if (mp.count(make_pair(x - 2, y)))
          if (!del[mp[make_pair(x - 2, y)]])
            if (val[mp[make_pair(x - 2, y)]] == 1) flag = false;
        if (mp.count(make_pair(x - 1, y)))
          if (!del[mp[make_pair(x - 1, y)]])
            if (val[mp[make_pair(x - 1, y)]] == 1) flag = false;
        if (mp.count(make_pair(x, y)))
          if (!del[mp[make_pair(x, y)]])
            if (val[mp[make_pair(x, y)]] == 1) flag = false;
        if (flag) {
          st.insert(
              make_pair(mp[make_pair(x - 1, y - 1)], make_pair(x - 1, y - 1)));
          ins[mp[make_pair(x - 1, y - 1)]] = 1;
        } else
          ins[mp[make_pair(x - 1, y - 1)]] = 0;
      }
    if (mp.count(make_pair(x, y - 1)))
      if (!del[mp[make_pair(x, y - 1)]]) {
        bool flag = true;
        if (mp.count(make_pair(x - 1, y)))
          if (!del[mp[make_pair(x - 1, y)]])
            if (val[mp[make_pair(x - 1, y)]] == 1) flag = false;
        if (mp.count(make_pair(x, y)))
          if (!del[mp[make_pair(x, y)]])
            if (val[mp[make_pair(x, y)]] == 1) flag = false;
        if (mp.count(make_pair(x + 1, y)))
          if (!del[mp[make_pair(x + 1, y)]])
            if (val[mp[make_pair(x + 1, y)]] == 1) flag = false;
        if (flag) {
          st.insert(make_pair(mp[make_pair(x, y - 1)], make_pair(x, y - 1)));
          ins[mp[make_pair(x, y - 1)]] = 1;
        } else
          ins[mp[make_pair(x, y - 1)]] = 0;
      }
    if (mp.count(make_pair(x + 1, y - 1)))
      if (!del[mp[make_pair(x + 1, y - 1)]]) {
        bool flag = true;
        if (mp.count(make_pair(x, y)))
          if (!del[mp[make_pair(x, y)]])
            if (val[mp[make_pair(x, y)]] == 1) flag = false;
        if (mp.count(make_pair(x + 1, y)))
          if (!del[mp[make_pair(x + 1, y)]])
            if (val[mp[make_pair(x + 1, y)]] == 1) flag = false;
        if (mp.count(make_pair(x + 2, y)))
          if (!del[mp[make_pair(x + 2, y)]])
            if (val[mp[make_pair(x + 2, y)]] == 1) flag = false;
        if (flag) {
          st.insert(
              make_pair(mp[make_pair(x + 1, y - 1)], make_pair(x + 1, y - 1)));
          ins[mp[make_pair(x + 1, y - 1)]] = 1;
        } else
          ins[mp[make_pair(x + 1, y - 1)]] = 0;
      }
  }
  writeln(ans);
  return 0;
}
