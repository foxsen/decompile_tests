#include <bits/stdc++.h>
using namespace std;
struct debugger {
  template <typename T>
  debugger& operator,(const T& v) {
    cerr << v << " ";
    return *this;
  }
} dbg;
inline long long gcd(long long a, long long b) {
  a = ((a) < 0 ? -(a) : (a));
  b = ((b) < 0 ? -(b) : (b));
  while (b) {
    a = a % b;
    swap(a, b);
  }
  return a;
}
long long ext_gcd(long long A, long long B, long long* X, long long* Y) {
  long long x2, y2, x1, y1, x, y, r2, r1, q, r;
  x2 = 1;
  y2 = 0;
  x1 = 0;
  y1 = 1;
  for (r2 = A, r1 = B; r1 != 0;
       r2 = r1, r1 = r, x2 = x1, y2 = y1, x1 = x, y1 = y) {
    q = r2 / r1;
    r = r2 % r1;
    x = x2 - (q * x1);
    y = y2 - (q * y1);
  }
  *X = x2;
  *Y = y2;
  return r2;
}
inline long long modInv(long long a, long long m) {
  long long x, y;
  ext_gcd(a, m, &x, &y);
  x %= m;
  if (x < 0) x += m;
  return x;
}
inline long long bigmod(long long a, long long p, long long m) {
  long long res = 1 % m, x = a % m;
  while (p) {
    if (p & 1) res = (res * x) % m;
    x = (x * x) % m;
    p >>= 1;
  }
  return res;
}
const long long inf = 2147383647;
const long long mod = 1000000007;
const double pi = 2 * acos(0.0);
const double eps = 1e-11;
stack<int> myStack;
vector<int> myVec;
int main() {
  while (!myStack.empty()) {
    myStack.pop();
  }
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    myVec.push_back(a);
  }
  int flag = 1;
  int mx = -1;
  for (int i = 0; i < myVec.size(); i++) {
    int curr = myVec[i];
    if (myStack.empty()) {
      myStack.push(curr);
    } else {
      int top = myStack.top();
      if (top == curr) {
        myStack.pop();
        if (curr > mx) {
          mx = curr;
        }
      } else if (top > curr) {
        myStack.push(curr);
      } else {
        flag = 0;
        break;
      }
    }
  }
  if (!flag) {
    cout << "NO\n";
  } else if (myStack.size() > 1) {
    cout << "NO\n";
  } else {
    if (myStack.size() == 0) {
      cout << "YES\n";
    } else if (myStack.size() == 1 && myStack.top() >= mx) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
  return 0;
}
