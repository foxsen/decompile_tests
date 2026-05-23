#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1.0);
const double eps = 1e-11;
template <class T>
inline void checkmin(T &a, T b) {
  if (b < a) a = b;
}
template <class T>
inline void checkmax(T &a, T b) {
  if (b > a) a = b;
}
template <class T>
inline T sqr(T x) {
  return x * x;
}
template <class T>
inline string bin(T n, int pos = 62) {
  string s;
  T i, one = 1, two = 2;
  for (i = (one << (pos - 1)); i > 0; i = (i >> 1)) s += ((n & i) ? "1" : "0");
  return s;
}
int lsb(unsigned int v) {
  int r;
  static const int MultiplyDeBruijnBitPosition[32] = {
      0,  1,  28, 2,  29, 14, 24, 3, 30, 22, 20, 15, 25, 17, 4,  8,
      31, 27, 13, 23, 21, 19, 16, 7, 26, 12, 18, 6,  11, 5,  10, 9};
  r = MultiplyDeBruijnBitPosition[((uint32_t)((v & -v) * 0x077CB531U)) >> 27];
  return r + 1;
}
template <class T>
inline int msb(T n) {
  return (n == 0) ? 0 : (1 + msb(n >> 1));
}
template <class T>
inline T getbit(T n, int pos) {
  return ((n & (1 << pos)) ? 1 : 0);
}
template <class T>
inline int countbit(T n) {
  return (n == 0) ? 0 : (1 + countbit(n & (n - 1)));
}
template <class T>
inline void setbit(T &n, int p) {
  n = n | (1LL << p);
}
template <class T>
inline T gcd(T a, T b) {
  if (a < 0) return gcd(-a, b);
  if (b < 0) return gcd(a, -b);
  return (b == 0) ? a : gcd(b, a % b);
}
bool isequal(vector<int> a, vector<int> b) {
  for (int i = 0; i < (a.size()); i++)
    if (a[i] != b[i]) return false;
  return true;
}
template <class T>
bool allequal(vector<T> a) {
  sort(a.begin(), a.end());
  return a[0] == a[a.size() - 1];
}
template <class T1, class T2>
void printpairs(vector<pair<T1, T2>> p) {
  for (auto t : p) {
    cout << "(" << t.first << " " << t.second << ")  ";
  }
  cout << endl;
}
template <class T>
void printvec(vector<T> a) {
  for (int i = 0; i < (a.size()); i++) cout << a[i] << " ";
  cout << endl;
}
void printarray(int *a, int n) {
  for (int i = 0; i < (n); i++) cout << *(a + i) << " ";
  cout << endl;
}
template <typename T>
void printmatrix(vector<vector<T>> a, int n, int m, int width = 5) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cout << setw(width) << a[i][j];
    }
    cout << endl;
  }
}
template <typename T>
void readmatrix(vector<vector<T>> &a, int n, int m) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
    }
  }
}
template <class T>
void printsubarray(vector<T> a, int start, int end) {
  if (start < 0 or end > a.size() - 1) cout << "Out of bounds" << endl;
  for (int i = start; i <= end; i++) cout << a[i] << " ";
  cout << endl;
}
bool isprime(int n) {
  if (n < 2) return false;
  if (n == 2) return true;
  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0) return false;
  }
  return true;
}
void split(const string &s, char c, vector<string> &result) {
  stringstream ss(s);
  string x;
  while (getline(ss, x, c)) result.push_back(x);
}
void err(vector<string>::iterator it) {}
template <typename T, typename... Args>
void err(vector<string>::iterator it, T a, Args... args) {
  cerr << it->substr((*it)[0] == ' ', it->length()) << " = " << a << ' ';
  err(++it, args...);
}
void yup() { cout << "Yes" << endl; }
void nope() { cout << "No" << endl; }
void Yup() { cout << "YES" << endl; }
void Nope() { cout << "NO" << endl; }
template <typename T>
void readvec(vector<T> &a, int size) {
  T tmp;
  a.clear();
  for (int i = 0; i < (size); i++) {
    cin >> tmp;
    a.push_back(tmp);
  }
}
int diff(vector<string> s, int m) {
  int best = 0;
  int n = s.size();
  for (int i = 0; i < n - 1; i++)
    for (int j = i + 1; j < n; j++) {
      int diff = 0;
      for (int l = 0; l < m; l++)
        if (s[i][l] != s[j][l]) diff++;
      if (best < diff) best = diff;
    }
  return best;
}
pair<int, int> finder(vector<string> s, int m) {
  int n = s.size();
  for (int i = 0; i < n - 1; i++)
    for (int j = i + 1; j < n; j++) {
      int diff = 0;
      for (int l = 0; l < m; l++)
        if (s[i][l] != s[j][l]) diff++;
      if (diff == 2) {
        return {i, j};
      }
    }
  return {0, 0};
}
bool check(string c, vector<string> s, int m) {
  int n = s.size();
  for (int i = 0; i < n; i++) {
    int diff = 0;
    for (int l = 0; l < m; l++)
      if (s[i][l] != c[l]) diff++;
    if (diff > 1) return false;
  }
  return true;
}
void solvecase() {
  int n, m;
  cin >> n >> m;
  vector<string> s(n);
  for (int i = 0; i < n; i++) cin >> s[i];
  int dif = diff(s, m);
  {
    vector<string> _v;
    split("dif", ',', _v);
    err(_v.begin(), dif);
    cerr << endl;
  };
  if (dif == 0 or dif == 1) {
    cout << s[0] << endl;
    return;
  }
  if (dif > 2) {
    cout << -1 << endl;
    return;
  }
  if (dif == 2) {
    pair<int, int> p = finder(s, m);
    string s1 = s[p.first];
    string s2 = s[p.second];
    int pos1, pos2;
    string c1(s1), c2(s2);
    for (int l = 0; l < m; l++)
      if (s1[l] != s2[l]) {
        c1[l] = s2[l];
        break;
      }
    for (int l = 0; l < m; l++)
      if (s1[l] != s2[l]) {
        c2[l] = s1[l];
        break;
      }
    if (check(c1, s, m)) {
      cout << c1 << endl;
      return;
    }
    if (check(c2, s, m)) {
      cout << c2 << endl;
      return;
    }
    {
      vector<string> _v;
      split("s1, s2, c1, c2", ',', _v);
      err(_v.begin(), s1, s2, c1, c2);
      cerr << endl;
    };
  }
  cout << -1 << endl;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int cases = 1;
  cin >> cases;
  while (cases--) {
    solvecase();
  }
  return 0;
}
