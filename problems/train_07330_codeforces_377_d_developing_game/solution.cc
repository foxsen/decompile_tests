#include <bits/stdc++.h>
using namespace std;
template <typename T, typename U>
ostream& operator<<(ostream& os, const pair<T, U>& p) {
  os << "(" << p.first << "," << p.second << ")";
  return os;
}
template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
  os << "[";
  for (__typeof((v).begin()) i = (v).begin(); i != (v).end(); ++i) {
    if (i != v.begin()) os << ", ";
    os << *i;
  }
  os << "]";
  return os;
}
struct Event {
  int x, w;
  bool start;
  Event(int _x, bool _start, int _w) : x(_x), w(_w), start(_start) {}
};
bool operator<(const Event& u, const Event& v) {
  if (u.x != v.x) return u.x < v.x;
  return u.start && !v.start;
}
int S[2 * (1 << 19)], L[2 * (1 << 19)];
pair<int, int> M[2 * (1 << 19)];
void push_lazy(int x) {
  if (L[x]) {
    S[x] += L[x];
    M[x].first += L[x];
    if (x < (1 << 19)) {
      L[2 * x] += L[x];
      L[2 * x + 1] += L[x];
    }
    L[x] = 0;
  }
}
void add(int x, int a, int b, int c, int u, int v) {
  push_lazy(x);
  if (v <= a || b <= u) return;
  if (a <= u && v <= b) {
    L[x] += c;
    push_lazy(x);
  } else {
    add(2 * x, a, b, c, u, (u + v) / 2);
    add(2 * x + 1, a, b, c, (u + v) / 2, v);
    S[x] = S[2 * x] + S[2 * x + 1];
    M[x] = max(M[2 * x], M[2 * x + 1]);
  }
}
void add(int u, int v, int c) { add(1, u, v + 1, c, 0, (1 << 19)); }
pair<int, int> thickest() { return M[1]; }
int main() {
  for (int i = 0; i < (int)((1 << 19)); ++i)
    M[(1 << 19) + i] = pair<int, int>(0, i);
  for (int i = (int)((1 << 19) - 1); i >= (int)(1); --i)
    M[i] = max(M[2 * i], M[2 * i + 1]);
  int n;
  scanf("%d", &n);
  vector<int> A(n), B(n), C(n);
  for (int i = 0; i < (int)(n); ++i) scanf("%d%d%d", &A[i], &B[i], &C[i]);
  vector<Event> E;
  for (int i = 0; i < (int)(n); ++i) {
    E.push_back(Event(A[i], true, i));
    E.push_back(Event(B[i], false, i));
  }
  sort(E.begin(), E.end());
  int res = 0, best_el = 0, best_r = 0;
  for (__typeof((E).begin()) e = (E).begin(); e != (E).end(); ++e) {
    int w = e->w;
    if (e->start) {
      add(B[w], C[w], 1);
      pair<int, int> q = thickest();
      if (q.first > res) {
        res = q.first;
        best_el = e->x;
        best_r = q.second;
      }
    } else {
      add(B[w], C[w], -1);
    }
  }
  printf("%d\n", res);
  bool first = true;
  for (int i = 0; i < (int)(n); ++i)
    if (A[i] <= best_el && best_el <= B[i] && B[i] <= best_r &&
        best_r <= C[i]) {
      if (first) {
        first = false;
      } else {
        printf(" ");
      }
      printf("%d", i + 1);
    }
  printf("\n");
}
