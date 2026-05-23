#include <bits/stdc++.h>
using namespace std;
struct ip {
  int x1, x2, x3, x4;
  ip(int X1 = 0, int X2 = 0, int X3 = 0, int X4 = 0) {
    x1 = X1;
    x2 = X2;
    x3 = X3;
    x4 = X4;
  }
};
string its(int a) {
  string ans = "";
  if (a == 0) return "00000000";
  while (a) {
    ans = (char)('0' + (a % 2)) + ans;
    a /= 2;
  }
  while (ans.size() < 8) ans = '0' + ans;
  return ans;
}
string ip_to_bin(ip a) {
  return (its(a.x1) + its(a.x2) + its(a.x3) + its(a.x4));
}
int sti(string S) {
  int ans = 0;
  int st = 1;
  for (int i = S.size() - 1; i >= 0; i--) {
    ans += (S[i] - '0') * st;
    st *= 2;
  }
  return ans;
}
ip str_to_ip(string S) {
  string S1 = "";
  string S2 = "";
  string S3 = "";
  string S4 = "";
  for (int i = 0; i < 32; i++) {
    if (i / 8 == 0)
      S1 += S[i];
    else if (i / 8 == 1)
      S2 += S[i];
    else if (i / 8 == 2)
      S3 += S[i];
    else
      S4 += S[i];
  }
  return (ip(sti(S1), sti(S2), sti(S3), sti(S4)));
}
string bit(string a, string b) {
  string ans = "";
  for (int i = 0; i < a.size(); i++) {
    if (a[i] == b[i] && a[i] == '1')
      ans += '1';
    else
      ans += '0';
  }
  return ans;
}
int main() {
  int n, k;
  cin >> n >> k;
  string A[n];
  char c;
  for (int i = 0; i < n; i++) {
    int x1, x2, x3, x4;
    scanf("%d.%d.%d.%d", &x1, &x2, &x3, &x4);
    A[i] = ip_to_bin(ip(x1, x2, x3, x4));
  }
  string mask = "00000000000000000000000000000000";
  string bit1[n];
  for (int i = 0; i < n; i++) {
    bit1[i] = bit(mask, A[i]);
  }
  for (int i = 0; i < 31; i++) {
    mask[i] = '1';
    set<string> Set;
    for (int j = 0; j < n; j++) {
      if (A[j][i] == mask[i] && mask[i] == '1')
        bit1[j][i] = '1';
      else
        bit1[j][i] = '0';
      Set.insert(bit1[j]);
    }
    if (Set.size() == k) {
      ip ip = str_to_ip(mask);
      cout << ip.x1 << "." << ip.x2 << "." << ip.x3 << "." << ip.x4 << endl;
      return 0;
    }
  }
  cout << -1;
  return 0;
}
