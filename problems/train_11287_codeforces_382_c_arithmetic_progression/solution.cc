#include <bits/stdc++.h>
using namespace std;
template <class T>
inline T GCD(T a, T b) {
  return b ? GCD(b, a % b) : a;
}
template <class T>
inline T LCM(T a, T b) {
  if (a < 0) return LCM(-a, b);
  if (b < 0) return LCM(a, -b);
  return a * (b / GCD(a, b));
}
template <class T>
inline T POW1(T a, T b, T m) {
  long long x = 1, y = a;
  while (b > 0) {
    if (b % 2 == 1) {
      x = (x * y);
      if (x > m) x %= m;
    }
    y = (y * y);
    if (y > m) y %= m;
    b /= 2;
  }
  return x;
}
template <class T>
inline T INV(T n, T m) {
  return POW1(n, m - 2, m);
}
template <class T>
inline T SUB(T a, T b, T m) {
  return (a % m - b % m + m) % m;
}
template <class T>
inline T ADD(T a, T b, T m) {
  return (a % m + b % m) % m;
}
template <class T>
inline T MUL(T a, T b, T m) {
  return (a % m * b % m) % m;
}
template <class T>
inline T DIV(T a, T b, T m) {
  return (a % m * (INV(b, m)) % m) % m;
}
int main() {
  long long int n, x, ct, flag = 0;
  cin >> n;
  vector<long long int> a;
  for (long long int i = 0; i < n; i++) {
    cin >> x;
    a.push_back(x);
  }
  sort(a.begin(), a.end());
  long long int t = a[0], eflag = 1;
  for (long long int i = 0; i < n; i++) {
    if (a[i] == t) {
    } else {
      eflag = 0;
    }
  }
  long long int r = a[1] - a[0];
  for (long long int i = 1; i < n; i++) {
    r = min(r, a[i] - a[i - 1]);
  }
  if (n == 1) {
    ct = -1;
    cout << ct << endl;
    return 0;
  } else if (eflag == 1) {
    cout << "1\n" << a[0] << endl;
  } else if (n == 2) {
    if (r % 2 == 0) {
      cout << "3\n";
      cout << a[0] - r << " " << a[0] + r / 2 << " " << a[0] + r + r << endl;
    } else {
      cout << "2\n";
      cout << a[0] - r << " " << a[0] + r + r << endl;
    }
    return 0;
  } else {
    long long int temp = a[0], put, ind;
    for (long long int i = 0; i < n; i++) {
      if (a[i] == temp) {
      } else {
        flag++;
        put = temp;
        ind = i;
        temp += r;
      }
      temp += r;
    }
    if (flag >= 2) {
      cout << "0\n";
      return 0;
    } else if (flag == 1) {
      if ((a[ind] + a[ind - 1]) == 2 * put) {
        cout << "1\n";
        cout << put << endl;
      } else {
        cout << "0\n";
      }
      return 0;
    } else {
      cout << "2\n";
      cout << a[0] - r << " " << a[n - 1] + r << endl;
    }
  }
  return 0;
}
