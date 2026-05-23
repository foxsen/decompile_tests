#include <bits/stdc++.h>
using namespace std;
template <class T>
inline T euclide(T a, T b, T& x, T& y) {
  if (a < 0) {
    T d = euclide(-a, b, x, y);
    x = -x;
    return d;
  }
  if (b < 0) {
    T d = euclide(a, -b, x, y);
    y = -y;
    return d;
  }
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  } else {
    T d = euclide(b, a % b, x, y);
    T t = x;
    x = y;
    y = t - (a / b) * y;
    return d;
  }
}
template <class T>
inline void checkmin(T& a, T b) {
  if (b < a) a = b;
}
template <class T>
inline void checkmax(T& a, T b) {
  if (b > a) a = b;
}
template <class T>
T Abs(T x) {
  return x > 0 ? x : -x;
}
template <class T>
inline T sqr(T x) {
  return x * x;
}
template <class T>
inline bool isPrime(T n) {
  if (n <= 1) return false;
  for (T i = 2; i * i <= n; i++)
    if (n % i == 0) return false;
  return true;
}
template <class T>
inline T Mod(T n, T m) {
  return (n % m + m) % m;
}
template <class T>
string toString(T n) {
  ostringstream oss;
  oss << n;
  oss.flush();
  return oss.str();
}
int toInt(string s) {
  int r = 0;
  istringstream sin(s);
  sin >> r;
  return r;
}
long long toLl(string s) {
  long long r = 0;
  istringstream sin(s);
  sin >> r;
  return r;
}
unsigned long long toLlu(string s) {
  unsigned long long r = 0;
  istringstream sin(s);
  sin >> r;
  return r;
}
template <class T>
void debug(const T& e) {
  cout << e << endl;
}
template <class T1, class T2>
void debug(const T1& e1, const T2& e2) {
  cout << e1 << "\t" << e2 << endl;
}
template <class T1, class T2, class T3>
void debug(const T1& e1, const T2& e2, const T3& e3) {
  cout << e1 << "\t" << e2 << "\t" << e3 << endl;
}
template <class T1, class T2, class T3, class T4>
void debug(const T1& e1, const T2& e2, const T3& e3, const T4& e4) {
  cout << e1 << "\t" << e2 << "\t" << e3 << "\t" << e4 << endl;
}
template <class T1, class T2, class T3, class T4, class T5>
void debug(const T1& e1, const T2& e2, const T3& e3, const T4& e4,
           const T5& e5) {
  cout << e1 << "\t" << e2 << "\t" << e3 << "\t" << e4 << "\t" << e5 << endl;
}
template <class T>
void debug(vector<T>& e) {
  int i;
  for (i = 0; i < (int)e.size(); i++) cout << e[i] << " ";
  cout << endl;
}
template <class T>
void debug(vector<basic_string<T> >& e) {
  int i, j;
  for (i = 0; i < (int)e.size(); i++) {
    for (j = 0; j < (int)e[i].size(); j++) cout << e[i][j];
    cout << endl;
  }
  cout << endl;
}
template <class T>
void debug(vector<vector<T> >& e, int row, int col) {
  int i, j;
  for (i = 0; i < row; i++) {
    for (j = 0; j < col; j++) cout << e[i][j] << "\t";
    cout << endl;
  }
  cout << endl;
}
template <class T>
void debug(T e[100][100], int row, int col) {
  int i, j;
  for (i = 0; i < row; i++) {
    for (j = 0; j < col; j++) cout << e[i][j] << " ";
    cout << endl;
  }
}
long long Pow(int B, int P) {
  long long R = 1;
  while (P > 0) {
    if (P % 2 == 1) R = (R * B);
    P /= 2;
    B = (B * B);
  }
  return R;
}
int BigMod(long long B, long long P, long long M) {
  long long R = 1;
  while (P > 0) {
    if (P % 2 == 1) {
      R = (R * B) % M;
    }
    P /= 2;
    B = (B * B) % M;
  }
  return (int)R;
}
struct data {
  string name;
  long long width, height, border, spacing, inside_element, type;
  vector<string> inside;
} D[110];
pair<long long, long long> res[110];
long long calculated[110];
char str[1000];
map<string, long long> MAP;
pair<long long, long long> calculate_Size(string name) {
  long long ind = MAP[name];
  long long h, v, i;
  pair<long long, long long> tmp;
  if (calculated[ind]) return res[ind];
  if (D[ind].type == 0) {
    res[ind] = make_pair(D[ind].width, D[ind].height);
  } else if (D[ind].type == 1) {
    h = v = 0;
    for (i = 0; i < D[ind].inside.size(); i++) {
      if (i) h = h + D[ind].spacing;
      tmp = calculate_Size(D[ind].inside[i]);
      v = (v > tmp.second ? v : tmp.second);
      h = h + tmp.first;
    }
    if (D[ind].inside.size()) {
      v = v + (D[ind].border * 2);
      h = h + (D[ind].border * 2);
    }
    res[ind] = make_pair(h, v);
  } else {
    h = v = 0;
    for (i = 0; i < D[ind].inside.size(); i++) {
      if (i) v = v + D[ind].spacing;
      tmp = calculate_Size(D[ind].inside[i]);
      h = (h > tmp.first ? h : tmp.first);
      v = v + tmp.second;
    }
    if (D[ind].inside.size()) {
      v = v + (D[ind].border * 2);
      h = h + (D[ind].border * 2);
    }
    res[ind] = make_pair(h, v);
  }
  calculated[ind] = 1;
  return res[ind];
}
int main() {
  long long i, j, Case = 1, test, N, cnt, ind;
  vector<string> Names;
  string s, name;
  pair<long long, long long> tmp;
  while (cin >> N) {
    getchar();
    MAP.clear();
    Names.clear();
    memset(calculated, 0, sizeof(calculated));
    cnt = 1;
    while (N--) {
      gets(str);
      for (i = 0; str[i]; i++)
        if (!isalnum(str[i]) && str[i] != '_') str[i] = ' ';
      istringstream iss(str);
      vector<string> V;
      while (iss >> s) V.push_back(s);
      if (V[0] == "Widget") {
        name = V[1];
        MAP[name] = cnt;
        Names.push_back(name);
        D[cnt].name = name;
        D[cnt].width = toLl(V[2]);
        D[cnt].height = toLl(V[3]);
        D[cnt].type = 0;
        cnt++;
      } else if (V[0] == "HBox" || V[0] == "VBox") {
        name = V[1];
        MAP[name] = cnt;
        Names.push_back(name);
        D[cnt].name = name;
        D[cnt].height = D[cnt].width = 0;
        D[cnt].inside_element = D[cnt].border = D[cnt].spacing = 0;
        D[cnt].inside.clear();
        if (V[0] == "HBox")
          D[cnt].type = 1;
        else
          D[cnt].type = 2;
        cnt++;
      } else if (V[1] == "set_border") {
        ind = MAP[V[0]];
        D[ind].border = toLl(V[2]);
      } else if (V[1] == "set_spacing") {
        ind = MAP[V[0]];
        D[ind].spacing = toLl(V[2]);
      } else if (V[1] == "pack") {
        ind = MAP[V[0]];
        D[ind].inside.push_back(V[2]);
      }
    }
    sort(Names.begin(), Names.end());
    for (i = 0; i < Names.size(); i++) {
      tmp = calculate_Size(Names[i]);
      cout << Names[i] << " " << tmp.first << " " << tmp.second << endl;
    }
  }
  return 0;
}
