#include <bits/stdc++.h>
using namespace std;
 

template <typename T>
struct Pt {
  T x, y;
  Pt() : x(0), y(0) {}
  Pt(const T x, const T y) : x(x), y(y) {}
  template <class F> explicit operator Pt<F> () const {
    return Pt<F>((F)x, (F)y); }

  Pt operator+(const Pt b) const { return Pt(x + b.x, y + b.y); }
  Pt operator-(const Pt b) const { return Pt(x - b.x, y - b.y); }
  template <class F> Pt<F> operator* (const F fac) {
    return Pt<F>(x * fac, y * fac); }
  template <class F> Pt<F> operator/ (const F fac) {
    return Pt<F>(x / fac, y / fac); }

  T operator&(const Pt b) const { return x * b.x + y * b.y; }
  T operator^(const Pt b) const { return x * b.y - y * b.x; }

  bool operator==(const Pt b) const {
    return x == b.x and  y == b.y; }
  bool operator<(const Pt b) const {
    return x == b.x? y < b.y: x < b.x; }

  Pt operator-() const { return Pt(-x, -y); }
  T norm() const { return *this & *this; }
  Pt prep() const { return Pt(-y, x); }
};
template<class F> istream& operator>>(istream& is, Pt<F> &pt) {
  return is >> pt.x >> pt.y;
}
template<class F> ostream& operator<<(ostream& os, Pt<F> &pt) {
  return os << pt.x << ' ' << pt.y;
}





  
template <typename T, typename Real = double>
struct Line {
  Pt<T> st, ed;
  Pt<T> vec() const { return ed - st; }
  T ori(const Pt<T> p) const { return (ed - st)^(p - st); }
  Line(const Pt<T> x, const Pt<T> y) : st(x), ed(y) {}
  template<class F> operator Line<F> () const {
    return Line<F>((Pt<F>)st, (Pt<F>)ed);
  }

  // sort by arg, the left is smaller for parallel lines
  bool operator<(Line B) const {
    Pt<T> a = vec(), b = B.vec();
    auto sgn = [](const Pt<T> t) { return (t.y == 0? t.x: t.y) < 0; };
    if (sgn(a) != sgn(b)) return sgn(a) < sgn(b);
    if (abs(a^b) == 0) return B.ori(st) > 0;
    return (a^b) > 0;
  }

  // Regard a line as a function
  template<typename F> Pt<F> operator()(const F x) const {
    return Pt<F>(st) + vec() * x;
  }

  bool isSegProperIntersection(const Line l) const {
    return l.ori(st) * l.ori(ed) < 0 and ori(l.st) * ori(l.ed) < 0;
  }

  bool isPtOnSegProperly(const Pt<T> p) const {
    return ori(p) == 0 and ((st - p)&(ed - p)) < 0;
  }

  Pt<Real> getIntersection(const Line<Real> l) {
    Line<Real> h = *this;
    return l(((l.st - h.st)^h.vec()) / (h.vec()^l.vec()));
  }

  Pt<Real> projection(const Pt<T> p) const {
    return operator()(((p - st)&vec()) / (Real)(vec().norm()));
  }
};



bool bipartite(const vector<vector<int>> &g) {
  vector<int> vis(g.size(), -1);
  function<bool(int, int)> dfs = [&](int u, int c) {
    vis[u] = c;
    bool test = true;
    for (int v : g[u]) {
      if (vis[v] == -1) {
        test &= dfs(v, !c);
      } else {
        test &= vis[v] == !c;
      }
    }
    return test;
  };
  for (int i = 0; i < g.size(); ++i) if (vis[i] == -1) 
    if (not dfs(i, 0)) return false;
  return true;
}

int coloring(const vector<vector<int>> &g) {
  int n = g.size();
  vector<int> dp(1<<n, INT_MAX), indep;
  dp[0] = 0;
  for (int S = 0; S < (1<<n); ++S) {
    bool flag = true;
    for (int u = 0; u < n; ++u) for (int v : g[u]) {
      flag &= not (S&1<<u) or not (S&1<<v);
    }
    if (flag) indep.push_back(S);
  }
  for (int S = 0; S < (1<<n); ++S) if (dp[S] != INT_MAX) {
    for (auto T : indep) dp[S|T] = min(dp[S|T], dp[S] + 1);
  }
  return dp.back();
}

  
bool test(const vector<Line<int>> &A, const vector<Line<int>> &B) {
  for (auto a : A) for (auto b : B) {
    if ((a.vec()^b.vec()) == 0) {
      if (b.isPtOnSegProperly(a.st) or b.isPtOnSegProperly(a.ed)) return true;
      if (a.isPtOnSegProperly(b.st) or a.isPtOnSegProperly(b.ed)) return true;
      if (a.st == b.st and a.ed == b.ed) return true;
      if (a.ed == b.st and a.st == b.ed) return true;
    }
  }
  return false;
}



int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
  int n;
  while (cin >> n and n) {
    map<string, int> mp;
    vector<vector<Line<int>>> T;
    vector<int> country;
    for (int i = 0; i < n; ++i) {
      string s; cin >> s;
      int x, id = mp.count(s) ? mp[s] : mp.size();
      country.push_back(id);
      mp[s] = id;
      vector<Pt<int>> P;
      vector<Line<int>> L;
      while (cin >> x and x != -1) {
        int y; cin >> y;
        P.emplace_back(x, y);
      }
      for (int i = 0; i < P.size(); ++i) {
        L.emplace_back(P[i], P[(i + 1) % P.size()]);
      }
      T.push_back(L);
    }
    vector<vector<int>> g(mp.size());

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < i; ++j) {
        int a = country[i], b = country[j];
        if (a != b and test(T[i], T[j])) {
          g[a].push_back(b);
          g[b].push_back(a);
        }
      }
    }
    for (int i = 0; i < g.size(); ++i) {
      sort(g[i].begin(), g[i].end());
      g[i].erase(unique(g[i].begin(), g[i].end()), g[i].end());
    }
    cout << coloring(g) << '\n';
  }
}

