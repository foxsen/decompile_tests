#include <bits/stdc++.h>
using namespace std;
template <typename T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;
template <typename T>
using max_heap = priority_queue<T>;
struct custom_hash {
  static uint64_t splitmix64(uint64_t x) {
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }
  size_t operator()(uint64_t x) const {
    static const uint64_t FIXED_RANDOM =
        chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(x + FIXED_RANDOM);
  }
};
long long binpow(long long base, long long exp) {
  long long mod = 1000000007LL;
  long long res = 1;
  while (exp > 0) {
    if (exp % 2 == 1) res = (res * base) % mod;
    exp = exp >> 1;
    base = (base * base) % mod;
  }
  return res;
}
long long mod(long long x) {
  return ((x % 1000000007LL + 1000000007LL) % 1000000007LL);
}
long long add(long long a, long long b) { return mod(mod(a) + mod(b)); }
long long mul(long long a, long long b) { return mod(mod(a) * mod(b)); }
bool isPrime(long long n) {
  if (n <= 1) return false;
  for (long long i = 2; i * i <= n; i++)
    if (n % i == 0) return false;
  return true;
}
const long long N = (long long)1e6;
void sieve(long long N) {
  bool prime[N + 1];
  memset(prime, true, sizeof(prime));
  for (long long p = 2; p * p <= N; p++) {
    if (prime[p] == true) {
      for (long long i = p * p; i <= N; i += p) prime[i] = false;
    }
  }
}
long long fact(long long n) {
  long long res = 1;
  for (long long i = 1; i <= n; i++) {
    res = res * 1ll * i % 1000000007LL;
  }
  return res;
}
long long C(long long n, long long k) {
  return fact(n) * 1ll * binpow(fact(k), 1000000007LL - 2) % 1000000007LL *
         1ll * binpow(fact(n - k), 1000000007LL - 2) % 1000000007LL;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long n;
  cin >> n;
  long long mini = -1;
  unordered_map<long long, vector<pair<long long, long long>>> adj;
  map<pair<long long, long long>, set<long long>> st;
  long long idx;
  for (long long i = 0; i < n; i++) {
    long long qi;
    cin >> qi;
    if (qi > mini) {
      mini = qi;
      idx = i + 1;
    }
  }
  long long m;
  cin >> m;
  while (m--) {
    long long a, b, c;
    cin >> a >> b >> c;
    st[{a, b}].insert(c);
  }
  for (auto x : st) {
    adj[x.first.first].push_back({x.first.second, *x.second.begin()});
  }
  st.clear();
  vector<long long> vis(n + 1, -1);
  vector<long long> dis(n + 1, 1000000007LL);
  vector<long long> par(n + 1, -1);
  min_heap<pair<long long, long long>> pq;
  par[idx] = -1;
  pq.push({0, idx});
  dis[idx] = 0;
  while (pq.empty() == false) {
    auto x = pq.top();
    pq.pop();
    long long currVert = x.second;
    if (vis[currVert] == -1) {
      vis[currVert] = 1;
      for (auto y : adj[currVert]) {
        long long vertex = y.first;
        long long wt = y.second;
        if (dis[vertex] > wt) {
          dis[vertex] = wt;
          par[vertex] = currVert;
          pq.push({wt, vertex});
        }
      }
    }
  }
  long long sum = 0;
  long long cnt = 0;
  for (long long i = 1; i <= n; i++) {
    if (par[i] == -1) {
      cnt++;
    } else {
      sum += dis[i];
    }
  }
  if (cnt > 1) {
    cout << -1;
  } else {
    cout << sum;
  }
  return 0;
}
