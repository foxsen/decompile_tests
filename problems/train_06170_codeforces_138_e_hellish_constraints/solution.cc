#include <bits/stdc++.h>
using namespace std;
struct query {
  int c, l, r;
};
const int MAX_LEN = 100010;
const int MAX_QUERY = 510;
const int MAX_ALPHABET = 30;
string s;
int S[MAX_LEN];
int k, L, R;
query qs[MAX_QUERY];
vector<int> let_pos[MAX_ALPHABET];
int cnt[MAX_LEN];
int cpl[MAX_QUERY], cpr[MAX_QUERY];
int cp[MAX_ALPHABET];
int let_cnt[MAX_ALPHABET];
int curr_good = 0;
long long ans = 0;
int main() {
  cin >> s;
  for (int i = 0; i < MAX_ALPHABET; i++) let_pos[i].push_back(-1);
  for (int i = 0; i < s.length(); i++) {
    S[i] = s[i] - 'a';
    let_pos[S[i]].push_back(i);
  }
  cin >> k >> L >> R;
  for (int i = 0; i < k; i++) {
    char ch;
    cin >> ch;
    qs[i].c = ch - 'a';
    cin >> qs[i].l >> qs[i].r;
  }
  for (int pos = 0; pos < s.length(); ++pos) {
    int c = S[pos];
    ++let_cnt[c];
    ++cp[c];
    for (int qp = 0; qp < k; qp++)
      if (qs[qp].c == S[pos] && qs[qp].l <= 1 && qs[qp].r >= 1)
        ++cnt[pos];
      else if (qs[qp].c != S[pos] && qs[qp].l == 0)
        ++cnt[pos];
    if (cnt[pos] >= L && cnt[pos] <= R) ++curr_good;
    for (int qp = 0; qp < k; qp++) {
      if (qs[qp].c == S[pos]) {
        if (let_cnt[c] == qs[qp].l) {
          cpl[qp] = 0;
          for (int tp = 0; tp <= let_pos[S[pos]][1]; tp++)
            if (tp < pos) {
              ++cnt[tp];
              if (cnt[tp] == L) ++curr_good;
              if (cnt[tp] == R + 1) --curr_good;
            }
          cpr[qp] = 1;
        } else if (let_cnt[c] > qs[qp].l) {
          if (let_cnt[c] > qs[qp].r) {
            for (int tp = let_pos[c][cpl[qp]] + 1;
                 tp <= let_pos[c][cpl[qp] + 1]; tp++)
              if (tp < pos) {
                --cnt[tp];
                if (cnt[tp] == R) ++curr_good;
                if (cnt[tp] == L - 1) --curr_good;
              }
            ++cpl[qp];
          }
          if (qs[qp].l > 0) {
            for (int tp = let_pos[c][cpr[qp]] + 1;
                 tp <= let_pos[c][cpr[qp] + 1]; tp++)
              if (tp < pos) {
                ++cnt[tp];
                if (cnt[tp] == L) ++curr_good;
                if (cnt[tp] == R + 1) --curr_good;
              }
            ++cpr[qp];
          }
        }
      }
    }
    ans += curr_good;
  }
  cout << ans << endl;
}
