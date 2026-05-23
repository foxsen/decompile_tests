#include <bits/stdc++.h>
using namespace std;
bool isSubSequence(char s[], char s1[], int m, int n) {
  int j = 0;
  for (int i = 0; i < n && j < m; i++)
    if (s[j] == s1[i]) j++;
  return (j == m);
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  t = 1;
  while (t--) {
    char s1[1000], s[6] = "heidi";
    cin >> s1;
    int m = strlen(s);
    int n = strlen(s1);
    isSubSequence(s, s1, m, n) ? cout << "YES" : cout << "NO";
  }
  cerr << "Time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
  return 0;
}
