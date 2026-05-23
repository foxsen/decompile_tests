#include <bits/stdc++.h>
using namespace std;
char t[101], s[200000];
bool del[200001];
int num[26], le[26];
int Len;
int tree[26][200001];
void update(int index, int pos, int value) {
  for (; pos <= Len; pos += pos & -pos) tree[index][pos] += value;
}
int findKth(int index, int k) {
  int ret = 0;
  for (int i = 20; i >= 0; i--) {
    ret |= 1 << i;
    if (ret <= Len && tree[index][ret] < k)
      k -= tree[index][ret];
    else
      ret ^= 1 << i;
  }
  return ret + 1;
}
int main() {
  int k, m;
  scanf("%d%s%d", &k, t, &m);
  int len = strlen(t);
  Len = len * k;
  for (int i = 0, p = 0; i < k; i++)
    for (int j = 0; j < len; j++, p++) {
      s[p] = t[j];
      update(t[j] - 'a', p + 1, 1);
    }
  for (int i = 0; i < m; i++) {
    int a;
    char c;
    scanf("%d %c", &a, &c);
    int ret = findKth(c - 'a', a);
    update(c - 'a', ret, -1);
    del[ret - 1] = 1;
  }
  for (int i = 0; i < Len; i++)
    if (!del[i]) printf("%c", s[i]);
  return 0;
}
