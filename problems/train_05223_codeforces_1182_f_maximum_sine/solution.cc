#include <bits/stdc++.h>
using namespace std;
long long mod_sub(long long a, long long b, long long p) {
  if (a >= b) return a - b;
  return p + a - b;
}
tuple<long long, long long> closest_under(long long p, long long q, long long n,
                                          long long T);
tuple<long long, long long> closest_over(long long p, long long q, long long n,
                                         long long T) {
  if (T == 0) T = q;
  if (n <= 0) return make_tuple(0, q - T);
  if (p == 0 || T == q) {
    return make_tuple(0, q - T);
  }
  if (p * n < q) {
    if (p * n >= T) {
      long long ans = (T - 1) / p + 1;
      return make_tuple(ans, p * ans - T);
    }
    return make_tuple(0, q - T);
  }
  long long min_around = (q - 1) / p + 1;
  long long full_cycles = (n * p) / q;
  tuple<long long, long long> recursive =
      closest_over((p * min_around) - q, p, full_cycles - 1, T % p);
  if (get<0>(recursive) > 0) {
    get<0>(recursive) = (get<0>(recursive) * q - 1) / p + 1;
    long long rec_head = p * get<0>(recursive) % q;
    if (rec_head < T) get<0>(recursive) += (T - rec_head - 1) / p + 1;
  } else {
    if (p * (min_around - 1) >= T) {
      get<0>(recursive) = (T - 1) / p + 1;
      get<1>(recursive) = p * get<0>(recursive) - T;
    }
  }
  long long max_around = (full_cycles * q - 1) / p + 1;
  long long tail_head = (p * max_around) % q;
  tuple<long long, long long> tail;
  if (tail_head + p * (n - max_around) < T) {
    tail = make_tuple(0, q - T);
  } else if (tail_head >= T) {
    tail = make_tuple(max_around, tail_head - T);
  } else {
    long long local_val = (T - tail_head - 1) / p + 1;
    tail = make_tuple(max_around + local_val, tail_head + p * local_val - T);
  }
  if (get<1>(recursive) <= get<1>(tail)) {
    if (get<1>(recursive) < q - T)
      return recursive;
    else
      return make_tuple(0, q - T);
  }
  if (get<1>(tail) < q - T) return tail;
  return make_tuple(0, q - T);
}
tuple<long long, long long> bf_over(long long p, long long q, long long n,
                                    long long T) {
  int smallest = q - T;
  int smallest_idx = 0;
  for (int i = 0; i <= n; i++) {
    long long val = (i * p) % q;
    if (val >= T && val - T < smallest) {
      smallest = val - T;
      smallest_idx = i;
    }
  }
  return make_tuple(smallest_idx, smallest);
}
tuple<long long, long long> closest_under(long long p, long long q, long long n,
                                          long long T) {
  if (n <= 0) return make_tuple(0, T);
  if (p == 0 || T == 0) {
    return make_tuple(0, T);
  }
  if (p > q / 2) return closest_over(q - p, q, n, q - T);
  if (p * n < q) {
    if (p * n <= T) {
      return make_tuple(n, T - p * n);
    }
    return make_tuple(T / p, T - p * (T / p));
  }
  long long min_around = (q - 1) / p + 1;
  long long full_cycles = (n * p) / q;
  tuple<long long, long long> recursive =
      closest_under((p * min_around) - q, p, full_cycles - 1, T % p);
  if (get<0>(recursive) > 0)
    get<0>(recursive) = (get<0>(recursive) * q - 1) / p + 1;
  long long rec_head = p * get<0>(recursive) % q;
  get<0>(recursive) += (T - rec_head) / p;
  long long max_around = (full_cycles * q - 1) / p + 1;
  long long tail_head = (p * max_around) % q;
  tuple<long long, long long> tail;
  if (tail_head + p * (n - max_around) <= T) {
    tail = make_tuple(n, T - tail_head - p * (n - max_around));
  } else if (tail_head > T) {
    tail = make_tuple(0, T);
  } else {
    long long local_val = (T - tail_head) / p;
    tail = make_tuple(max_around + local_val, T - tail_head - p * local_val);
  }
  if (get<1>(recursive) <= get<1>(tail)) return recursive;
  return tail;
}
tuple<long long, long long> closest(long long p, long long q, long long n,
                                    long long T) {
  auto t1 = closest_under(p, q, n, T);
  auto t2 = closest_under(q - p, q, n, q - T);
  if (get<1>(t1) < get<1>(t2)) return t1;
  if (get<1>(t2) < get<1>(t1)) return t2;
  if (get<0>(t1) < get<0>(t2)) return t1;
  return t2;
}
int dist(int a, int b, int p) {
  if (a > b) return dist(b, a, p);
  return min(b - a, p - b + a);
}
tuple<int, int> bf(long long p, long long q, int n, int T) {
  int min = q + 10;
  int min_idx = 0;
  for (int i = 0; i <= n; i++) {
    int val = dist((p * i) % q, T, q);
    if (val < min) {
      min = val;
      min_idx = i;
    }
  }
  return make_tuple(min_idx, min);
}
int main() {
  long long p, q, a, b, n, T;
  int t;
  cin >> t;
  for (int iter = 0; iter < t; iter++) {
    cin >> a >> b >> p >> q;
    p = p % q;
    long long T = (2 * a * p) % (2 * q);
    T = mod_sub(q, T, 2 * q);
    auto t = closest(2 * p, 2 * q, b - a, T);
    auto tru = bf(2 * p, 2 * q, b - a, T);
    cout << a + get<0>(t) << endl;
  }
}
