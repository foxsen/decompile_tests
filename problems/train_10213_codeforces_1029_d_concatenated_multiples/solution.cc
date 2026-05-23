#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target("tune=corei7-avx")
using namespace std;
template <class A>
void addlog(A a) {
  cerr << a << '\n';
}
template <class A, class... B>
void addlog(A a, B... b) {
  cerr << a << ' ';
  addlog(b...);
}
template <class T>
ostream &operator<<(ostream &out, vector<T> v) {
  for (T &e : v) {
    out << e << ' ';
  }
  return out << '\n';
}
namespace HashTable {
using Key = int32_t;
using Value = int32_t;
static constexpr Key EMPTY = -123456789;
static constexpr Value DEFAULT = 0;
uint32_t hash(Key x) { return (x * 2654435771U); }
struct FixedHashMap {
  uint32_t len, used;
  Key *keys;
  Value *values;
  void clear() {
    fill(keys, keys + len, EMPTY);
    fill(values, values + len, DEFAULT);
  }
  FixedHashMap(uint32_t l)
      : len(l), used(0), keys(new Key[l]), values(new Value[l]) {
    clear();
  }
  ~FixedHashMap() {
    delete[] keys;
    delete[] values;
  }
  Value &operator[](Key k) {
    uint32_t h = hash(k) & (len - 1);
    for (uint32_t i = h; i < len; ++i) {
      if (keys[i] == EMPTY) {
        keys[i] = k;
        values[i] = DEFAULT;
        ++used;
        return values[i];
      } else if (keys[i] == k) {
        return values[i];
      }
    }
    for (uint32_t i = 0; i < h; ++i) {
      if (keys[i] == EMPTY) {
        keys[i] = k;
        values[i] = DEFAULT;
        ++used;
        return values[i];
      } else if (keys[i] == k) {
        return values[i];
      }
    }
    assert(false);
    return values[0];
  }
};
class HashMap {
 private:
  FixedHashMap *fhm;

 public:
  void clear() { fhm->clear(); }
  HashMap(uint32_t start = 131072U) { fhm = new FixedHashMap(start); }
  Value &operator[](Key k) {
    if (fhm->used * 4 > fhm->len) {
      uint32_t newLen = fhm->len * 2;
      FixedHashMap *nfhm = new FixedHashMap(newLen);
      for (uint32_t i = 0; i < fhm->len; ++i) {
        if (fhm->keys[i] != EMPTY) {
          (*nfhm)[fhm->keys[i]] = fhm->values[i];
        }
      }
      delete fhm;
      fhm = nfhm;
    }
    return fhm->operator[](k);
  }
  ~HashMap() { delete fhm; }
};
}  // namespace HashTable
int32_t len(int32_t x) {
  if (x <= 99999) {
    if (x <= 9) return 1;
    if (x <= 99) return 2;
    if (x <= 999) return 3;
    if (x <= 9999) return 4;
    return 5;
  } else {
    if (x <= 999999) return 6;
    if (x <= 9999999) return 7;
    if (x <= 99999999) return 8;
    if (x <= 999999999) return 9;
    return 10;
  }
}
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie();
  cout.tie();
  int32_t n, k;
  cin >> n >> k;
  vector<int32_t> a(n);
  vector<int64_t> ten(20);
  vector<HashTable::HashMap> h(15);
  ten[0] = 1;
  for (int32_t i = 0; i < 15; ++i) {
    h[i].clear();
  }
  for (int32_t i = 1; i < 20; ++i) {
    ten[i] = (ten[i - 1] * 10) % k;
  }
  int64_t ans = 0;
  for (int32_t i = 0; i < n; ++i) {
    cin >> a[i];
  }
  for (int32_t i = 0; i < n; ++i) {
    for (int32_t l = 1; l <= 10; ++l) {
      int32_t self = int32_t((ten[l] * a[i]) % k);
      int32_t need = (k - self) % k;
      ans += h[l][need];
    }
    ++h[len(a[i])][a[i] % k];
  }
  reverse(begin(a), end(a));
  for (int32_t i = 0; i < 15; ++i) {
    h[i].clear();
  }
  for (int32_t i = 0; i < n; ++i) {
    for (int32_t l = 1; l <= 10; ++l) {
      int32_t self = int32_t((ten[l] * a[i]) % k);
      int32_t need = (k - self) % k;
      ans += h[l][need];
    }
    ++h[len(a[i])][a[i] % k];
  }
  cout << ans << '\n';
  return 0;
}
