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
  return res;
}
int N, M, U, V, max_div_2, min_div_1, cnt;
bool used[100010];
vector<pair<int, int>> similars;
set<int> div_2, div_1, unused;
int main() {
  scanf("%d%d", &N, &M);
  for (auto i = 0; i < M; ++i) {
    scanf("%d%d", &U, &V);
    similars.emplace_back(U, V);
  }
  if (M == 0) {
    printf("%d", N - 1);
    return 0;
  }
  memset(used, false, sizeof(used));
  for (auto elem : similars) {
    int minim = min(elem.first, elem.second);
    int maxim = max(elem.first, elem.second);
    if (div_2.find(maxim) != div_2.end() || div_1.find(minim) != div_1.end()) {
      printf("0\n");
      return 0;
    }
    div_2.insert(minim);
    div_1.insert(maxim);
    used[minim] = used[maxim] = true;
  }
  for (auto i = 1; i <= N; ++i)
    if (!used[i]) unused.insert(i);
  max_div_2 = *div_2.rbegin();
  min_div_1 = *div_1.begin();
  if (max_div_2 > min_div_1) {
    printf("0\n");
    return 0;
  }
  for (auto elem : unused)
    if (elem > max_div_2 && elem < min_div_1) ++cnt;
  if (!div_2.empty() && !div_1.empty()) printf("%d\n", cnt + 1);
  return 0;
}
