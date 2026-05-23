#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
const long long int mod = 1e9 + 7;
void _print(long long int t) { cerr << t; }
void _print(int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(long double t) { cerr << t; }
void _print(double t) { cerr << t; }
void _print(unsigned long long t) { cerr << t; }
template <class T, class V>
void _print(pair<T, V> p);
template <class T>
void _print(vector<T> v);
template <class T>
void _print(set<T> v);
template <class T, class V>
void _print(map<T, V> v);
template <class T>
void _print(multiset<T> v);
template <class T, class V>
void _print(pair<T, V> p) {
  cerr << "{";
  _print(p.first);
  cerr << ",";
  _print(p.second);
  cerr << "}";
}
template <class T>
void _print(vector<T> v) {
  cerr << "[ ";
  for (T i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T>
void _print(set<T> v) {
  cerr << "[ ";
  for (T i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T>
void _print(multiset<T> v) {
  cerr << "[ ";
  for (T i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T, class V>
void _print(map<T, V> v) {
  cerr << "[ ";
  for (auto i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
void dhoom_Machale() {
  long long int a, b, c;
  cin >> a >> b >> c;
  long long int m;
  cin >> m;
  vector<pair<long long int, long long int>> v;
  for (long long int i = 0; i < m; ++i) {
    long long int cost;
    cin >> cost;
    ;
    string label;
    cin >> label;
    if (label[0] == 'U')
      v.push_back({cost, 1});
    else
      v.push_back({cost, 2});
  }
  sort(v.begin(), v.end());
  long long int expenditure = 0, items = 0;
  for (int i = 0; i < m; ++i) {
    if (v[i].second == 1 && a) {
      ++items;
      expenditure += v[i].first;
      --a;
      continue;
    } else if (v[i].second == 2 && b) {
      ++items;
      expenditure += v[i].first;
      --b;
      continue;
    } else if (c) {
      ++items;
      expenditure += v[i].first;
      --c;
      continue;
    }
  }
  cout << items << " " << expenditure;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  dhoom_Machale();
}
