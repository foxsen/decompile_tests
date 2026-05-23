#include <bits/stdc++.h>
using namespace std;
int Int() {
  int x;
  scanf("%d", &x);
  return x;
}
long long Long() {
  long long x;
  scanf("%lld", &x);
  return x;
}
double Double() {
  double x;
  scanf("%lf", &x);
  return x;
}
float Float() {
  float x;
  scanf("%f", &x);
  return x;
}
const int N = 1e5 + 5;
vector<string> split(const string& s, char c) {
  vector<string> v;
  stringstream ss(s);
  string x;
  while (getline(ss, x, c)) v.emplace_back(x);
  return move(v);
}
void err(vector<string>::iterator it) {}
template <typename T, typename... Args>
void err(vector<string>::iterator it, T a, Args... args) {
  cout << it->substr((*it)[0] == ' ', it->length()) << " = " << a << "  ";
  err(++it, args...);
}
int a;
int b;
struct order {
  int pre;
  int post;
} tree[2 * N];
int last = 2 * (int)(1e5);
order query(int idx) {
  order res;
  res.pre = 0;
  res.post = 0;
  while (idx > 0) {
    res.pre += tree[idx].pre;
    res.post += tree[idx].post;
    idx -= (idx & -idx);
  }
  return res;
}
void update(int idx, int x) {
  order p = query(idx);
  order q = query(idx - 1);
  int pp = min(b - (p.pre - q.pre), x);
  int qq = min(a - (p.post - q.post), x);
  while (idx <= last) {
    tree[idx].pre += pp;
    tree[idx].post += qq;
    idx += (idx & -idx);
  }
}
int main() {
  int n = Int(), k = Int();
  a = Int(), b = Int();
  int q = Int();
  for (int i = 0; i < q; i++) {
    int ty = Int();
    if (ty == 1) {
      int id = Int(), x = Int();
      update(id, x);
    } else {
      int id = Int();
      order ans1 = query(id - 1);
      order ans2 = query(last);
      order ans3 = query(id + k - 1);
      cout << ans1.pre + ans2.post - ans3.post << "\n";
    }
  }
  return 0;
}
