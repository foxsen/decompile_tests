#include <bits/stdc++.h>
const int N = 100010;
const int inf = 0x3f3f3f3f;
using namespace std;
int k, n, m, q;
map<string, int> mp;
map<int, string> pm;
struct data {
  vector<int> a, b;
} da[N];
map<int, int> p[N];
int main() {
  scanf("%d%d%d%d", &k, &n, &m, &q);
  for (int i = 0; i < n; i++) {
    string str;
    cin >> str;
    mp[str] = i + 1;
    pm[i + 1] = str;
  }
  string str;
  getline(cin, str);
  for (int i = 0; i < m; i++) {
    string str, tmp = "";
    getline(cin, str);
    stringstream sin;
    sin << str;
    sin >> str;
    for (int j = 0; j < ((str).size()) - 1; j++) tmp += str[j];
    mp[tmp] = i + 1 + n;
    pm[i + 1 + n] = tmp;
    int d;
    while (sin >> str >> d) {
      da[i].a.push_back(mp[str]);
      da[i].b.push_back(d);
      sin >> str;
    }
  }
  for (int i = 0; i < q; i++) {
    int a, b;
    string tmp;
    cin >> a >> tmp;
    b = mp[tmp];
    p[a][b]++;
    for (int k = 0; k < m; k++) {
      bool f = 1;
      for (int j = 0; j < ((da[k].a).size()); j++)
        if (p[a][da[k].a[j]] < da[k].b[j]) f = 0;
      if (!f) continue;
      p[a][k + 1 + n]++;
      for (int j = 0; j < ((da[k].a).size()); j++)
        p[a][da[k].a[j]] -= da[k].b[j];
    }
  }
  for (int id = 1; id <= k; id++) {
    vector<pair<string, int> > ret;
    for (map<int, int>::iterator it = p[id].begin(); it != p[id].end(); it++) {
      if (!it->second) continue;
      ret.push_back(make_pair(pm[it->first], it->second));
    }
    sort(ret.begin(), ret.end());
    cout << ((ret).size()) << endl;
    for (int i = 0; i < ((ret).size()); i++)
      cout << ret[i].first << " " << ret[i].second << endl;
  }
  return 0;
}
