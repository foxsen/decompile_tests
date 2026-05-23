#include <bits/stdc++.h>
using namespace std;
template <typename T, typename T1>
ostream &operator<<(ostream &out, pair<T, T1> obj) {
  out << "(" << obj.first << "," << obj.second << ")";
  return out;
}
template <typename T, typename T1>
ostream &operator<<(ostream &out, map<T, T1> cont) {
  typename map<T, T1>::const_iterator itr = cont.begin();
  typename map<T, T1>::const_iterator ends = cont.end();
  for (; itr != ends; ++itr) out << *itr << " ";
  out << endl;
  return out;
}
template <typename T>
ostream &operator<<(ostream &out, set<T> cont) {
  typename set<T>::const_iterator itr = cont.begin();
  typename set<T>::const_iterator ends = cont.end();
  for (; itr != ends; ++itr) out << *itr << " ";
  out << endl;
  return out;
}
template <typename T>
ostream &operator<<(ostream &out, multiset<T> cont) {
  typename multiset<T>::const_iterator itr = cont.begin();
  typename multiset<T>::const_iterator ends = cont.end();
  for (; itr != ends; ++itr) out << *itr << " ";
  out << endl;
  return out;
}
template <typename T,
          template <typename ELEM, typename ALLOC = allocator<ELEM>> class CONT>
ostream &operator<<(ostream &out, CONT<T> cont) {
  typename CONT<T>::const_iterator itr = cont.begin();
  typename CONT<T>::const_iterator ends = cont.end();
  for (; itr != ends; ++itr) out << *itr << " ";
  out << endl;
  return out;
}
template <typename T, unsigned int N, typename CTy, typename CTr>
typename enable_if<!is_same<T, char>::value, basic_ostream<CTy, CTr> &>::type
operator<<(basic_ostream<CTy, CTr> &out, const T (&arr)[N]) {
  for (auto i = 0; i < N; ++i) out << arr[i] << " ";
  out << endl;
  return out;
}
template <typename T>
T gcd(T a, T b) {
  T min_v = min(a, b);
  T max_v = max(a, b);
  while (min_v) {
    T temp = max_v % min_v;
    max_v = min_v;
    min_v = temp;
  }
  return max_v;
}
template <typename T>
T lcm(T a, T b) {
  return (a * b) / gcd(a, b);
}
template <typename T>
T fast_exp_pow(T base, T exp, T mod) {
  long long res = 1;
  while (exp) {
    if (exp & 1) {
      res *= base;
      res %= mod;
    }
    exp >>= 1;
    base *= base;
    base %= mod;
  }
  return res % mod;
}
int A, B;
int A_b, B_b;
int base, len;
int main() {
  scanf("%d%d", &A, &B);
  int tmp = A;
  while (tmp) {
    base = max(base, tmp % 10);
    tmp /= 10;
  }
  tmp = B;
  while (tmp) {
    base = max(base, tmp % 10);
    tmp /= 10;
  }
  ++base;
  tmp = A;
  int Tpow = 1;
  while (tmp) {
    A_b += Tpow * (tmp % 10);
    tmp /= 10;
    Tpow *= base;
  }
  tmp = B;
  Tpow = 1;
  while (tmp) {
    B_b += Tpow * (tmp % 10);
    tmp /= 10;
    Tpow *= base;
  }
  int sum = A_b + B_b;
  while (sum) {
    ++len;
    sum /= base;
  }
  printf("%d\n", len);
  return 0;
}
