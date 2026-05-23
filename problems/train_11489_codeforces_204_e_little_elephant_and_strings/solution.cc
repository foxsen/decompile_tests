#include <bits/stdc++.h>
using namespace std;
struct SAComp {
  const int h, *g;
  SAComp(int h, int* g) : h(h), g(g) {}
  bool operator()(int a, int b) {
    return a == b ? false : g[a] != g[b] ? g[a] < g[b] : g[a + h] < g[b + h];
  }
};
int* buildSA(const char* t, int n) {
  int g[n + 1], b[n + 1], *v = new int[n + 1];
  for (int i = 0; i < (int)n + 1; ++i) v[i] = i, g[i] = t[i];
  b[0] = 0;
  b[n] = 0;
  sort(v, v + n + 1, SAComp(0, g));
  for (int h = 1; b[n] != n; h *= 2) {
    SAComp comp(h, g);
    sort(v, v + n + 1, comp);
    for (int i = 0; i < (int)n; ++i) b[i + 1] = b[i] + comp(v[i], v[i + 1]);
    for (int i = 0; i < (int)n + 1; ++i) g[v[i]] = b[i];
  }
  return v;
}
class SuffixArray : public vector<int> {
  struct By {
    const int sp, *sr;
    By(int sp, const vector<int>& sr) : sp(sp), sr(&sr[0]) {}
    bool operator()(int a, int b) const {
      return sr[a] != sr[b] ? sr[a] < sr[b] : sr[a + sp] < sr[b + sp];
    }
  };

 public:
  template <typename RanIt>
  SuffixArray(RanIt bg, RanIt ed) {
    const int N = ed - bg;
    vector<int> sort_rank(N + 1);
    this->resize(N + 1);
    for (int i = 0; i < N + 1; ++i) {
      (*this)[i] = i;
      sort_rank[i] = i < N ? *(bg + i) : 0x7fffffff;
    }
    sort(begin(), end(), By(0, sort_rank));
    for (int sorted_prefix = 1; sorted_prefix < N + 1; sorted_prefix *= 2) {
      By cmp(sorted_prefix, sort_rank);
      sort(begin(), end(), cmp);
      vector<int> block_id(N + 1);
      for (int i = 1; i < N + 1; ++i)
        block_id[i] =
            block_id[i - 1] + (cmp((*this)[i - 1], (*this)[i]) ? 1 : 0);
      for (int i = 0; i < N + 1; ++i) sort_rank[(*this)[i]] = block_id[i];
    }
  }
};
int* buildLCP(const char* t, int n, int* a) {
  int h = 0, b[n + 1], *lcp = new int[n + 1];
  for (int i = 0; i < (int)n + 1; ++i) b[a[i]] = i;
  for (int i = 0; i < (int)n + 1; ++i) {
    if (b[i]) {
      for (int j = a[b[i] - 1]; j + h < n && i + h < n && t[j + h] == t[i + h];
           ++h)
        ;
      lcp[b[i]] = h;
    } else
      lcp[b[i]] = -1;
    if (h > 0) --h;
  }
  return lcp;
}
template <typename T>
struct RMQ {
  vector<vector<int> > rm;
  vector<T> d;
  RMQ(const vector<T>& d) : d(d) {
    int n = d.size();
    rm.push_back(vector<int>(n));
    for (int x = 0; x < n; ++x) rm[0][x] = x;
    for (int k = 1; (1 << k) <= n; ++k) {
      rm.push_back(rm[k - 1]);
      for (int x = 0; x + (1 << k - 1) < n; ++x)
        if (d[rm[k][x]] > d[rm[k - 1][x + (1 << k - 1)]])
          rm[k][x] = rm[k - 1][x + (1 << k - 1)];
    }
  }
  int operator()(int L, int R) const {
    int k = 0;
    for (; L + (1 << k) < R - (1 << k) + 1; ++k) {
    }
    int i = rm[k][L];
    int j = rm[k][R - (1 << k) + 1];
    return (d[i] <= d[j] ? i : j);
  }
  vector<int> all(int L, int R) const {
    vector<int> ans;
    int minValue = d[(*this)(L, R)];
    while (L <= R) {
      int C = (*this)(L, R);
      if (minValue < d[C]) break;
      ans.push_back(C);
      L = C + 1;
    }
    return ans;
  }
  int rightmost_less_than_X(int L, int R, T X) const {
    if (L > R) return -1;
    int k = 0;
    for (; L + (1 << k) < R - (1 << k) + 1; ++k) {
    }
    int i = rm[k][L];
    int j = rm[k][R - (1 << k) + 1];
    if (!(d[i] < X || d[j] < X)) return -1;
    if (d[j] < X) L = R - (1 << k) + 1;
    for (; k; --k) {
      i = rm[k - 1][L];
      j = rm[k - 1][L + (1 << k - 1)];
      if (d[j] < X) L += 1 << k - 1;
    }
    return L;
  }
  int leftmost_less_than_X(int L, int R, T X) const {
    if (L > R) return -1;
    int k = 0;
    for (; L + (1 << k) < R - (1 << k) + 1; ++k) {
    }
    int i = rm[k][L];
    int j = rm[k][R - (1 << k) + 1];
    if (!(d[i] < X || d[j] < X)) return -1;
    if (!(d[i] < X)) L = R - (1 << k) + 1;
    for (; k; --k) {
      i = rm[k - 1][L];
      j = rm[k - 1][L + (1 << k - 1)];
      if (!(d[i] < X)) L += 1 << k - 1;
    }
    return L;
  }
};
void solve(const vector<string>& SS, int K) {
  string S;
  vector<int> sep;
  for (int i = 0; i < SS.size(); ++i) {
    if (i) S += '$';
    S += SS[i];
    sep.push_back(S.size());
  }
  SuffixArray sa(S.c_str(), S.c_str() + S.size() + 1);
  int* lcp = buildLCP(S.c_str(), S.size(), &sa[0]);
  int sa_start = 0;
  while (S.c_str()[sa[sa_start]] < 'A') ++sa_start;
  int sa_end = S.size() + 1;
  vector<int> blk_of(sa_end, -1);
  for (int i = sa_start; i < sa_end; ++i) {
    int blk = lower_bound(sep.begin(), sep.end(), sa[i]) - sep.begin();
    blk_of[i] = blk;
  }
  vector<int> first_index_of_K_diff_blocks(sa_end, 0x7fffffff);
  map<int, int> blk_set;
  for (int i = sa_start, k = sa_start; i < sa_end; ++i) {
    for (; blk_set.size() < K && k < sa_end; ++k) blk_set[blk_of[k]]++;
    if (blk_set.size() == K) first_index_of_K_diff_blocks[i] = k - 1;
    if (--blk_set[blk_of[i]] == 0) blk_set.erase(blk_of[i]);
  }
  RMQ<int> rmq(vector<int>(lcp, lcp + sa_end));
  vector<long long> total(SS.size());
  for (int s = sa_start; s < sa_end; ++s) {
    int len_L = 1, len_R = sep[blk_of[s]] - sa[s];
    int possible_len = 0;
    while (len_L <= len_R) {
      int len_C = (len_L + len_R) / 2;
      int l = rmq.rightmost_less_than_X(sa_start, s, len_C);
      if (l == -1) l = sa_start;
      int r = rmq.leftmost_less_than_X(s + 1, sa_end - 1, len_C);
      if (r == -1)
        r = sa_end - 1;
      else
        r--;
      if (first_index_of_K_diff_blocks[l] <= r) {
        possible_len = len_C;
        len_L = len_C + 1;
      } else
        len_R = len_C - 1;
    }
    total[blk_of[s]] += possible_len;
  }
  for (int i = 0; i < total.size(); ++i) cout << (i ? " " : "") << total[i];
  cout << endl;
}
int main() {
  for (int N, K; cin >> N >> K;) {
    vector<string> SS(N);
    for (int i = 0; i < SS.size(); ++i) cin >> SS[i];
    solve(SS, K);
  }
}
