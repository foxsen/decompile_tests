#include <bits/stdc++.h>
using namespace std;
long long marray[8];
pair<long long, long long> p;
long long n1, n2, n3;
long long mat[8][8];
void recurse(long long ind) {
  if (ind > 7) {
    vector<long long> v[4];
    for (long long i = 1; i <= 7; i++) {
      if (marray[i] == 1) {
        v[marray[i]].push_back(i);
      }
      if (marray[i] == 2) {
        v[marray[i]].push_back(i);
      }
      if (marray[i] == 3) {
        v[marray[i]].push_back(i);
      }
    }
    if (v[1].size() * v[2].size() * v[3].size() != 0) {
      long long x = n1 / v[1].size(), y = n2 / v[2].size(),
                z = n3 / v[3].size();
      long long fir;
      fir = max({abs(x - y), abs(y - z), abs(z - x)});
      long long tot = 0;
      for (long long i = 0; i < v[1].size(); i++) {
        for (long long j = i + 1; j < v[1].size(); j++) {
          long long a, b;
          a = v[1][i];
          b = v[1][j];
          if (mat[a][b] == 1) {
            tot++;
          }
          if (mat[b][a] == 1) {
            tot++;
          }
        }
      }
      for (long long i = 0; i < v[2].size(); i++) {
        for (long long j = i + 1; j < v[2].size(); j++) {
          long long a, b;
          a = v[2][i];
          b = v[2][j];
          if (mat[a][b] == 1) {
            tot++;
          }
          if (mat[b][a] == 1) {
            tot++;
          }
        }
      }
      for (long long i = 0; i < v[3].size(); i++) {
        for (long long j = i + 1; j < v[3].size(); j++) {
          long long a, b;
          a = v[3][i];
          b = v[3][j];
          if (mat[a][b] == 1) {
            tot++;
          }
          if (mat[b][a] == 1) {
            tot++;
          }
        }
      }
      if (fir < p.first) {
        p.first = fir;
        p.second = tot;
      } else if (fir == p.first) {
        if (tot > p.second) {
          p.second = tot;
        }
      }
    }
    return;
  }
  marray[ind] = 1;
  recurse(ind + 1);
  marray[ind] = 2;
  recurse(ind + 1);
  marray[ind] = 3;
  recurse(ind + 1);
}
int32_t main() {
  long long n;
  cin >> n;
  map<string, long long> mp;
  mp["Anka"] = 1;
  mp["Chapay"] = 2;
  mp["Cleo"] = 3;
  mp["Troll"] = 4;
  mp["Dracul"] = 5;
  mp["Snowy"] = 6;
  mp["Hexadecimal"] = 7;
  memset(mat, 0, sizeof(mat));
  for (long long i = 0; i < n; i++) {
    string x, y, z;
    cin >> x >> y >> z;
    long long a, b;
    a = mp[x];
    b = mp[z];
    mat[a][b] = 1;
  }
  cin >> n1 >> n2 >> n3;
  p = make_pair(INT_MAX, 0);
  recurse(1);
  cout << p.first << " " << p.second << "\n";
  return 0;
}
