#include <bits/stdc++.h>
using namespace std;
int n, fst, lst, l1, l2;
char s1[1005], s2[1000005];
int solve() {
  int pos1 = 0, ans = -1;
  for (int i = 0; i <= l2; i++) {
    if (s1[pos1] == s2[i]) pos1++;
    if (pos1 == l1) {
      ans = i;
      break;
    }
  }
  return ans;
}
int main() {
  scanf("%s", s1);
  scanf("%s", s2);
  l1 = strlen(s1);
  l2 = strlen(s2);
  fst = solve();
  if (fst == -1) {
    puts("0");
    return 0;
  }
  for (int i = 0; i < l1 >> 1; i++) swap(s1[i], s1[l1 - 1 - i]);
  for (int i = 0; i < l2 >> 1; i++) swap(s2[i], s2[l2 - 1 - i]);
  lst = solve();
  if (l2 - lst - 1 - fst < 0)
    cout << 0 << endl;
  else
    cout << l2 - lst - fst - 1 << endl;
}
