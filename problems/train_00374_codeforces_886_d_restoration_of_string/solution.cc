#include <bits/stdc++.h>
using namespace std;
char str[100010];
bool line[27][27];
bool p[27], vis[27];
int in[27], out[27];
string ans;
bool dfs(int value);
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%s", str);
    int len = strlen(str);
    for (int i = 0; i < len - 1; i++) {
      if (str[i] == str[i + 1]) {
        printf("NO\n");
        return 0;
      }
      line[str[i] - 'a'][str[i + 1] - 'a'] = true;
    }
    if (len == 1) p[str[0] - 'a'] = true;
  }
  ans = "";
  for (int i = 0; i < 26; i++) {
    for (int j = 0; j < 26; j++)
      if (line[i][j]) {
        out[i]++;
        in[j]++;
      }
  }
  for (int i = 0; i < 26; i++)
    if (in[i] > 1 || out[i] > 1) {
      printf("NO\n");
      return 0;
    }
  for (int i = 0; i < 26; i++) {
    if (out[i] != 0 && in[i] == 0)
      if (!dfs(i)) {
        printf("NO\n");
        return 0;
      }
    if (p[i] && in[i] == 0 && out[i] == 0) ans += (i + 'a');
  }
  for (int i = 0; i < 26; i++)
    if (in[i] != 0 && out[i] != 0 && !vis[i]) {
      printf("NO\n");
      return 0;
    }
  cout << ans << endl;
  return 0;
}
bool dfs(int value) {
  vis[value] = true;
  ans += (value + 'a');
  for (int i = 0; i < 26; i++) {
    if (line[value][i]) {
      return dfs(i);
    }
  }
  return true;
}
