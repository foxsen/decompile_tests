#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
inline int getint() {
  char c = getchar();
  int x = 0, mi = 1;
  while (c != EOF && c != '-' && !isdigit(c)) c = getchar();
  if (c == '-') {
    mi = -1;
    c = getchar();
  }
  while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
  return x * mi;
}
inline long long getll() {
  long long x;
  scanf("%lld", &x);
  return x;
}
inline double getdb() {
  static double x;
  scanf("%lf", &x);
  return x;
}
void pr(const char* s = " ") { printf("%s", s); }
void pr(char const& x) { putchar(x); }
void pr(bool const& x) { printf("%d", x); }
void pr(int const& x) { printf("%d", x); }
void pr(long long const& x) { printf("%lld", x); }
void pr(double const& x) { printf("%.2f", x); }
void pr(long double const& x) { printf("%.2f", (double)x); }
template <typename T, typename R>
void pr(pair<T, R> x) {
  pr("(");
  pr(x.first);
  pr(",");
  pr(x.second);
  pr(")");
}
template <typename T>
void pr(T const t[], int l, int r, const char* h = "", const char* c = "\n") {
  printf("%s", h);
  for (decltype(r) i = l, lim__lim = (r); i <= lim__lim; i++) pr(t[i]), pr();
  printf("%s", c);
}
template <typename T>
void updmax(
    T& a, T const& b, function<void(void)> f = []() {}) {
  if (a < b) {
    a = b;
    f();
  }
}
template <typename T>
void updmin(
    T& a, T const& b, function<void(void)> f = []() {}) {
  if (a > b) {
    a = b;
    f();
  }
}
template <typename T>
int descr(T* from, T* to) {
  sort(from, to);
  return (int)(unique(from, to) - from);
}
template <typename T>
int lBound(T* from, T* to, T const& val) {
  return (int)(lower_bound(from, to, val) - from);
}
template <typename T>
int uBound(T* from, T* to, T const& val) {
  return (int)(upper_bound(from, to, val) - from);
}
time_point<system_clock> timing;
void TBegin() { timing = system_clock::now(); }
double TEnd(const char* c = "time: ") {
  auto end = system_clock::now();
  auto d = duration_cast<microseconds>(end - timing);
  auto dt =
      double(d.count()) * microseconds::period::num / microseconds::period::den;
  printf("%s%.10f", c, dt);
  return dt;
}
void TTick(const char* c = "time:") {
  TEnd(c);
  TBegin();
}
template <typename T>
void fill(T a[], unsigned char v, int l, int r) {
  memset(&a[l], v, sizeof(a[0]) * (r - l + 1));
}
const int mxn = 5e3 + 50;
const int mxm = 1e3 + 50;
unsigned char v[mxm][mxn];
int l[mxn], op[mxn], r[mxn], cnt[mxm], opc;
unsigned char val[mxn];
unordered_map<string, int> name2id;
string id2name[mxn];
enum { CONST = 0, AND = 1, OR = 2, XOR = 3 };
int ansl[mxm], ansr[mxn];
char inp[30];
int main() {
  int n = getint();
  int m = getint();
  name2id[string("?")] = 0;
  id2name[0] = string("?");
  for (decltype(n) i = 1, lim__lim = (n); i <= lim__lim; i++) {
    scanf("%s", inp);
    string name = inp;
    name2id[name] = i;
    id2name[i] = name;
    scanf("%s", inp);
    scanf("%s", inp);
    if (inp[0] == '0' || inp[0] == '1') {
      for (decltype(m - 1) t = 0, lim__lim = (m - 1); t <= lim__lim; t++)
        v[t][i] = inp[t] - '0';
      op[i] = CONST;
    } else {
      l[i] = name2id[string(inp)];
      scanf("%s", inp);
      op[i] = inp[0] == 'A' ? AND : inp[0] == 'O' ? OR : XOR;
      scanf("%s", inp);
      r[i] = name2id[string(inp)];
    }
  }
  for (decltype(m - 1) t = 0, lim__lim = (m - 1); t <= lim__lim; t++) {
    auto calc = [&](int c) {
      fill(val, 0, 0, n + 1);
      val[0] = c;
      for (decltype(n) i = 1, lim__lim = (n); i <= lim__lim; i++) {
        if (op[i] == CONST)
          val[i] = v[t][i];
        else if (op[i] == AND)
          val[i] = val[l[i]] & val[r[i]];
        else if (op[i] == OR)
          val[i] = val[l[i]] | val[r[i]];
        else if (op[i] == XOR)
          val[i] = val[l[i]] ^ val[r[i]];
      }
      int res = 0;
      for (decltype(n) i = 1, lim__lim = (n); i <= lim__lim; i++)
        res += val[i] == 1;
      return res;
    };
    int a = calc(0);
    int b = calc(1);
    if (a > b) {
      ansl[t] = 1;
      ansr[t] = 0;
    } else if (a < b) {
      ansl[t] = 0;
      ansr[t] = 1;
    } else {
      ansl[t] = ansr[t] = 0;
    }
  }
  for (decltype(m - 1) i = 0, lim__lim = (m - 1); i <= lim__lim; i++)
    pr(ansl[i]);
  pr('\n');
  for (decltype(m - 1) i = 0, lim__lim = (m - 1); i <= lim__lim; i++)
    pr(ansr[i]);
  pr('\n');
  return 0;
}
