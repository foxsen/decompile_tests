#include <bits/stdc++.h>
using namespace std;
int main() {
  map<char, long long> m;
  string s;
  cin >> s;
  long long sum = 0;
  for (long long i = 0; i < s.length(); i++) {
    char c = s[i];
    m[c]++;
  }
  map<char, long long>::iterator i;
  for (i = m.begin(); i != m.end(); i++) {
    long long temp = i->second;
    temp = temp * temp;
    sum += temp;
  }
  cout << sum << endl;
  return 0;
}
