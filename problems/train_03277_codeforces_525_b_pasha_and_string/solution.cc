#include <bits/stdc++.h>
using namespace std;
long long rev[(long long)2e5];
int main() {
  char* s = (char*)malloc(sizeof(char) * ((long long)2e5 + 1));
  cin >> s;
  long long len = strlen(s);
  long long d;
  cin >> d;
  for (long long i = 0; i < d; i++) {
    long long j;
    cin >> j;
    rev[j - 1]++;
  }
  bool r = false;
  for (long long i = 0; i <= len / 2 - 1; i++) {
    r = (r + rev[i]) % 2;
    if (r) {
      char temp = s[i];
      s[i] = s[len - i - 1];
      s[len - i - 1] = temp;
    }
  }
  cout << s;
  return 0;
}
