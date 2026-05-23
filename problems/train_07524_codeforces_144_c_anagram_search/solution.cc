#include <bits/stdc++.h>
using namespace std;
int xx[] = {1, 1, 1, 0, -1, -1, -1, 0};
int yy[] = {-1, 0, 1, 1, 1, 0, -1, -1};
long long int gcd(long long int a, long long int b) {
  return ((a % b == 0) ? b : gcd(b, a % b));
}
int main() {
  char s[100005], p[100005];
  int need[30] = {0}, has[30] = {0}, lens, lenp, i, j;
  bool flag = false;
  cin >> s;
  cin >> p;
  lens = strlen(s);
  lenp = strlen(p);
  if (lenp > lens) {
    printf("0\n");
    return 0;
  }
  for (i = 0; i < lenp; i++) {
    if (s[i] != '?') has[s[i] - 'a']++;
    need[p[i] - 'a']++;
  }
  int ans = 0;
  for (i = 0; i < lens; i++) {
    flag = true;
    for (j = 0; j < 26; j++) {
      if (has[j] > need[j]) {
        flag = false;
        break;
      }
    }
    if (flag) ans++;
    if (s[i] != '?') has[s[i] - 'a']--;
    if (i + lenp >= lens) break;
    if (s[i + lenp] != '?') has[s[i + lenp] - 'a']++;
  }
  cout << ans << endl;
  return 0;
}
