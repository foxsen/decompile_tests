#include <bits/stdc++.h>
using namespace std;
void in(int &a) { scanf("%d", &a); }
void in(int &a, int &b) {
  in(a);
  in(b);
}
void in(int &a, int &b, int &c) {
  in(a);
  in(b);
  in(c);
}
void in(long long int &a) { scanf("%lld", &a); }
void in(long long int &a, long long int &b) {
  in(a);
  in(b);
}
void in(long long int &a, long long int &b, long long int &c) {
  in(a);
  in(b);
  in(c);
}
void out(int a) { printf("%d", a); }
void out(int a, int b) { printf("%d %d", a, b); }
void out(long long int a) { printf("%lld", a); }
void out(long long int a, long long int b) { printf("%lld %lld", a, b); }
void out(string s) {
  for (int i = 0; i < (int)s.length(); i++) printf("%c", s[i]);
}
void yn(bool b) { puts(b ? "YES" : "NO"); }
template <typename T>
void outar(T ar, int ln, char c) {
  for (int i = 0; i < ln; i++) printf("%d%c", ar[i], c);
}
int cx[] = {-1, 0, 0, 1};
int cy[] = {0, 1, -1, 0};
template <typename T>
T Max(T a, T b, T c) {
  return max(a, max(b, c));
}
template <typename T>
T Min(T a, T b, T c) {
  return min(a, min(b, c));
}
template <typename T>
T isPrime(T a) {
  if (a < 2) return false;
  for (T i = 2; i * i <= a; i++)
    if (a % i == 0) return false;
  return true;
}
void _Print(int a) { cerr << a; }
void _Print(long long int a) { cerr << a; }
void _Print(double a) { cerr << a; }
void _Print(char a) { cerr << '\'' << a << '\''; }
void _Print(const char *a) { cerr << '\"' << a << '\"'; }
void _Print(const string &a) { cerr << '\"' << a << '\"'; }
void _Print(bool a) { cerr << (a ? "true" : "false"); }
template <typename T, typename V>
void _Print(const pair<T, V> &x) {
  cerr << '{';
  _Print(x.first);
  cerr << ',';
  _Print(x.second);
  cerr << '}';
}
template <typename T>
void _Print(const T &x) {
  int f = 0;
  cerr << '{';
  for (auto &i : x) cerr << (f++ ? "," : ""), _Print(i);
  cerr << "}";
}
void Print() { cerr << "]\n"; }
template <typename T, typename... V>
void Print(T t, V... v) {
  _Print(t);
  if (sizeof...(v)) cerr << ", ";
  Print(v...);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t, n;
  long long int w, h, tmp;
  in(t);
  while (t--) {
    in(n);
    in(w);
    h = w / 2;
    if (w % (long long int)2 != (long long int)0) h++;
    vector<pair<long long int, int>> v;
    for (int i = 0; i < n; i++) {
      in(tmp);
      v.push_back({tmp, i + 1});
    }
    sort(v.begin(), v.end());
    int pos = 0;
    long long int total = 0;
    vector<int> ans;
    while (pos < n) {
      total += v[pos].first;
      ans.push_back(pos);
      pos++;
      if (total < h)
        continue;
      else if (total >= h and total <= w)
        break;
      else {
        while ((int)(v.size()) > 0 and total > w) {
          total -= v[ans[0]].first;
          ans.erase(ans.begin());
          if (total >= h and total <= w) goto lbl;
        }
      }
    }
  lbl:;
    if (total >= h and total <= w and (int)(ans.size()) > 0) {
      vector<int> p;
      for (auto x : ans) p.push_back(v[x].second);
      sort(p.begin(), p.end());
      out((int)(p.size()));
      printf("\n");
      for (int i = 0; i < (int)(p.size()); i++) printf("%d ", p[i]);
    } else
      out(-1);
    printf("\n");
  }
  return 0;
}
