#include <bits/stdc++.h>
using namespace std;

#define rep(i, j, n) for(int i=j;i<n;++i)
#define all(i) i.begin(),i.end()
#define rall(i) i.rbegin(),i.rend()
#define INF 1e9
const int mod = 1e9 + 7;

typedef long long i64;
typedef pair<int, int> pi;

template <class T> using vt = vector<T>;
template <class T> using vvt = vector<vector<T>>;

i64 gcd(i64 n, i64 m) {return (m == 0? n : gcd(m, n % m));}
i64 lcm(i64 n, i64 m) {return (n / gcd(n, m) * m);}
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int def(string ma, string mi) {
  rep(i, 0, 8) {
    if(ma == mi) return i;
    mi[mi.size() - 1]++;
      for(int j = mi.size() - 1; j >= 0; --j) {
        if(mi[j] != '9' + 1) break;
        else if(j - 1 > 0) mi[j - 1]++;
        else mi.insert(0, "1");
      }
  }
  if(ma == mi) return 8;
  return 9;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  string s;
  cin >> s;

  int sz = s.size();
  int ans = INF;
  {
    rep(i, 1, sz) {
      if(sz % i) continue;

      string Max, Min;
      Max = Min = s.substr(0, i);
      for(int j = 0; j < sz; j += i) {
        Max = max(Max, s.substr(j, i));
        Min = min(Min, s.substr(j, i));
      }

      ans = min(ans, def(Max, Min));
    }
  }
  {
    int Max = 0, Min = 10;
    int i = 0, num;
    while(i < sz) {
      num = s[i] - '0';
      if(s[i] == '1' && i + 1 < sz) {
        i++;
        num = 10 + (s[i] - '0');
      }

      i++;
      Max = max(Max, num);
      Min = min(Min, num);
    }
    if(Max != 0) ans = min(ans, Max - Min);
  }
  cout << ans << endl;
}

