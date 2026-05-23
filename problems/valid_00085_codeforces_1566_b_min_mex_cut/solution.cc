#include <bits/stdc++.h>
using namespace std;
const long long int MOD = 1e9 + 7;
const long long int N = 2e5 + 5;
void test(long long int t) {
  cin >> t;
  while (t--) {
  }
}
void read(vector<long long int>& v, long long int n) {
  for (long long int i = 0; i < n; i++) {
    long long int x;
    cin >> x;
    v.push_back(x);
  }
}
void write(vector<string> v) {
  for (long long int i = 0; i < v.size(); i++) cout << v[i] << '\n';
  cout << '\n';
}
long long int len(string s) {
  long long int x = s.length();
  return x;
}
long long int gcd(long long int a, long long int b) {
  if (b > a) {
    return gcd(b, a);
  }
  if (b == 0) {
    return a;
  }
  return gcd(b, a % b);
}
void swap(long long int* a, long long int* b) {
  long long int temp = *a;
  *a = *b;
  *b = temp;
}
long long int prime_factors(long long int n) {
  if (n == 1) {
    return 0;
  }
  long long int count = 0;
  while (n % 2 == 0) {
    count++;
    n = n / 2;
  }
  for (long long int i = 3; i <= sqrt(n); i += 2) {
    while (n % i == 0) {
      count++;
      n = n / i;
    }
  }
  if (n > 2) {
    count++;
  }
  return count;
}
bool compare(pair<long long int, long long int> p1,
             pair<long long int, long long int> p2) {
  if (p1.second != p2.second) {
    return p1.second < p2.second;
  }
  return p1.first > p2.first;
}
long long int nextgreaterele(long long int arr[], long long int n,
                             long long int x) {
  long long int lo = 0;
  long long int hi = n - 1;
  while (hi >= lo) {
    long long int mid = (lo + hi) / 2;
    if (arr[mid] == x) {
      return arr[mid + 1];
    } else if (arr[mid] > x) {
      hi = mid - 1;
    } else {
      lo = mid + 1;
    }
  }
  return -1;
}
long long int lb(long long int v[], long long int n, long long int k) {
  long long int lo = 0;
  long long int hi = n - 1;
  while (hi - lo > 1) {
    long long int mid = (lo + hi) >> 1;
    if (v[mid] < k) {
      lo = mid + 1;
    } else if (v[mid] >= k) {
      hi = mid;
    }
  }
  if (v[lo] >= k) return lo;
  if (v[hi] >= k) return hi;
  return -1;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) {
    long long int ans = 0;
    string s;
    cin >> s;
    for (long long int i = 1; i < len(s); i++) {
      if (s[i] != s[i - 1]) {
        if (s[i - 1] == '0') {
          ans++;
        }
      }
    }
    if (s[len(s) - 1] == '0') {
      ans++;
    }
    cout << min(2LL, ans) << '\n';
  }
}
