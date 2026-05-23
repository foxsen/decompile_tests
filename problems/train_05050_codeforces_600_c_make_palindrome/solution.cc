#include <bits/stdc++.h>
using namespace std;
const long long LINF = 0x3f3f3f3f3f3f3f3f;
const long long NLINF = 0xf7f7f7f7f7f7f7f7;
const int INF = 0x3f3f3f3f, NINF = 0xf7f7f7f7;
const int MOD1 = 1e9 + 7, MOD2 = 1e9 + 9;
const int N = 2e5 + 10;
int n, freq[30], mark[30];
vector<char> odd, ch;
char s[N], r[N];
int main() {
  scanf("%s", &s), n = strlen(s);
  for (int i = 0; i < n; i++) {
    freq[s[i] - 'a']++;
  }
  for (int i = 0; i < n; i++) {
    if (freq[s[i] - 'a'] % 2 == 0) ch.push_back(s[i]);
    if (freq[s[i] - 'a'] % 2 && !mark[s[i] - 'a'])
      odd.push_back(s[i]), mark[s[i] - 'a'] = 1;
  }
  sort(odd.begin(), odd.end());
  for (int i = 0; i < odd.size(); i++) {
    if (odd.size() % 2 && i == odd.size() / 2)
      while (freq[odd[i] - 'a']--) ch.push_back(odd[i]);
    else if (i >= odd.size() / 2) {
      freq[odd[i] - 'a']--;
      while (freq[odd[i] - 'a']--) ch.push_back(odd[i]);
    } else {
      freq[odd[i] - 'a']++;
      while (freq[odd[i] - 'a']--) ch.push_back(odd[i]);
    }
  }
  sort(ch.begin(), ch.end());
  assert(ch.size() == n);
  bool par = 1;
  for (int i = 0, lo = 0, hi = n - 1; i < n; i++) {
    if (i % 2 == par)
      r[hi--] = ch[i];
    else if (ch[i] == ch[i + 1])
      r[lo++] = ch[i];
    else
      par = !par, r[n / 2] = ch[i];
  }
  printf("%s\n", r);
}
