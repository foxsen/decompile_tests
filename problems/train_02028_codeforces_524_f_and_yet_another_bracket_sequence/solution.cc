#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 5;
char s[N];
int tp[N], rak[N], sa[N], tax[N], sl, m, cnt[N], lg[N], f[N][20], rr[N];
void radixSort() {
  for (int i = 1; i <= m; i++) tax[i] = 0;
  for (int i = 1; i <= sl; i++) tax[rak[i]]++;
  for (int i = 1; i <= m; i++) tax[i] += tax[i - 1];
  for (int i = sl; i; i--) sa[tax[rak[tp[i]]]--] = tp[i];
}
void build_sa() {
  m = 125;
  for (int i = 1; i <= sl; i++) rak[i] = s[i], tp[i] = i;
  radixSort();
  for (int p = 0, w = 1; p < sl; w <<= 1, m = p) {
    p = 0;
    for (int i = 1; i <= w; i++) tp[++p] = sl - w + i;
    for (int i = 1; i <= sl; i++)
      if (sa[i] > w) tp[++p] = sa[i] - w;
    radixSort();
    swap(tp, rak);
    rak[sa[1]] = p = 1;
    for (int i = 2; i <= sl; i++)
      rak[sa[i]] =
          (tp[sa[i]] == tp[sa[i - 1]] && tp[sa[i] + w] == tp[sa[i - 1] + w])
              ? p
              : ++p;
  }
}
void make_st() {
  int range = lg[sl];
  if (cnt[sl] > 0) {
    for (int i = 1; i <= sl; i++) f[i][0] = cnt[i];
    for (int i = 1; i <= range; i++)
      for (int j = 1; j + (1 << i) - 1 <= sl; j++)
        f[j][i] = min(f[j][i - 1], f[j + (1 << (i - 1))][i - 1]);
  } else {
    for (int i = 1; i <= sl; i++) f[i][0] = rr[i];
    for (int i = 1; i <= range; i++)
      for (int j = 1; j + (1 << i) - 1 <= sl; j++)
        f[j][i] = max(f[j][i - 1], f[j + (1 << (i - 1))][i - 1]);
  }
}
int query(int l, int r) {
  int range = lg[r - l + 1];
  if (cnt[sl] > 0)
    return min(f[l][range], f[r - (1 << range) + 1][range]);
  else
    return max(f[l][range], f[r - (1 << range) + 1][range]);
}
int main() {
  scanf("%s", s + 1);
  sl = strlen(s + 1);
  for (int i = 1; i <= sl; i++) s[i + sl] = s[i];
  sl <<= 1;
  build_sa();
  for (int i = 1; i <= sl; i++) cnt[i] = cnt[i - 1] + ((s[i] == '(') ? 1 : -1);
  for (int i = sl; i; i--) rr[i] = rr[i + 1] + ((s[i] == '(') ? 1 : -1);
  for (int i = 2; i <= sl; i++)
    lg[i] = lg[i - 1] + (i == (1 << (lg[i - 1] + 1)));
  make_st();
  int l_cnt = 0, r_cnt = 0, ans_pos;
  for (int i = 1; i <= sl; i++) {
    int p = sa[i];
    if (p > sl / 2) continue;
    int res = query(p, p + sl / 2 - 1);
    if (cnt[sl] > 0) {
      if (res - cnt[p - 1] < 0) continue;
      r_cnt = abs(cnt[sl] / 2);
      ans_pos = p;
      break;
    } else {
      if (res - rr[p + sl / 2] > 0) continue;
      l_cnt = abs(cnt[sl] / 2);
      ans_pos = p;
      break;
    }
  }
  for (int i = 1; i <= l_cnt; i++) printf("(");
  for (int i = ans_pos; i <= ans_pos + sl / 2 - 1; i++) printf("%c", s[i]);
  for (int i = 1; i <= r_cnt; i++) printf(")");
  return 0;
}
