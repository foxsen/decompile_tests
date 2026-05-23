#include <bits/stdc++.h>
using namespace std;
const int MAX = 4e5 + 9;
int jdg;
struct Word {
  int count[26];
  int len;
  Word(char *str) {
    len = 0;
    for (int i = 0; i < 26; i++) count[i] = 0;
    for (; str[len] != 0; len++) {
      count[str[len] - 'a']++;
    }
  }
  Word() {}
  inline int value() { return count[jdg] * 2 - len; }
};
int wordcmp(const void *v1, const void *v2) {
  Word *w1 = (Word *)v1, *w2 = (Word *)v2;
  return -w1->value() + w2->value();
}
void solve() {
  int n;
  scanf("%d", &n);
  Word words[n];
  for (int i = 0; i < n; i++) {
    char str[MAX] = {0};
    scanf("%s", str);
    words[i] = Word(str);
  }
  int maxchosen = 0;
  for (jdg = 0; jdg < 26; jdg++) {
    qsort(words, n, sizeof(Word), wordcmp);
    int ch = 0;
    int t = 0, len = 0;
    for (ch = 0; ch < n; ch++) {
      if (2 * (t + words[ch].count[jdg]) > len + words[ch].len) {
        t += words[ch].count[jdg];
        len += words[ch].len;
      } else
        break;
    }
    maxchosen = max(ch, maxchosen);
  }
  printf("%d\n", maxchosen);
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) solve();
}
