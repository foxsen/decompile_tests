#include <bits/stdc++.h>
using namespace std;
const int LEN = 1000;
const int YW = 8;
const int BAS = 100000000;
struct big {
  int a[LEN];
  int &operator[](int x) { return a[x]; }
  const int &operator[](int x) const { return a[x]; }
  big() {
    memset(a, 0, sizeof(a));
    ;
  }
  big operator=(const big &x) {
    for (int i = (int)(x[0] + 1); i <= (int)(a[0]); i++) a[i] = 0;
    for (int i = (int)(0); i <= (int)(x[0]); i++) a[i] = x[i];
    return *this;
  }
  big operator=(int x) {
    for (int i = (int)(a[0]); i >= (int)(0); i--) a[i] = 0;
    for (; x; x /= BAS) a[++a[0]] = x % BAS;
    return *this;
  }
  big(int x) {
    memset(a, 0, sizeof(a));
    ;
    *this = x;
  }
  int check(const big &a, const big &b) {
    if (a[0] != b[0]) return a[0] > b[0];
    for (int i = (int)(a[0]); i >= (int)(1); i--)
      if (a[i] != b[i]) return a[i] > b[i];
    return 2;
  }
  bool operator<(const big &b) { return check(*this, b) == 0; }
  bool operator>(const big &b) { return check(*this, b) == 1; }
  bool operator<=(const big &b) { return check(*this, b) != 1; }
  bool operator>=(const big &b) { return check(*this, b) != 0; }
  bool operator!=(const big &b) { return check(*this, b) != 2; }
  bool operator==(const big &b) { return check(*this, b) == 2; }
  big operator*(const big &b) {
    big c;
    c[0] = a[0] + b[0];
    for (int i = (int)(1); i <= (int)(a[0]); i++)
      for (int j = (int)(1); j <= (int)(b[0]); j++) {
        long long x = c[i + j - 1] + 1ll * a[i] * b[j];
        c[i + j] += x / BAS;
        c[i + j - 1] = x % BAS;
      }
    for (; c[0] && !c[c[0]]; c[0]--)
      ;
    return c;
  }
  big operator*(int x) {
    big c;
    long long v = 0;
    for (int i = (int)(1); i <= (int)(a[0] + 3); i++) {
      v = 1ll * x * a[i] + v;
      c[i] = v % BAS;
      v /= BAS;
    }
    c[0] = a[0] + 3;
    for (; c[0] && !c[c[0]]; c[0]--)
      ;
    return c;
  }
  big operator/(int x) {
    big c;
    long long v = 0;
    for (int i = (int)(a[0]); i >= (int)(1); i--) {
      v = v * BAS + a[i];
      c[i] = v / x;
      v %= x;
    }
    c[0] = a[0];
    for (; c[0] && !c[c[0]]; c[0]--)
      ;
    return c;
  }
  big operator/(const big &b) {
    if (!b[0] && !b[1]) {
      puts("error! divide by 0");
      exit(0);
    }
    int l1 = max(0, (a[0] - 1)) * YW;
    int l2 = max(0, (b[0] - 1)) * YW;
    int v1 = a[a[0]], v2 = b[b[0]];
    for (; v1; v1 /= 10, l1++)
      ;
    for (; v2; v2 /= 10, l2++)
      ;
    big c, chu = *this, B = b;
    for (int i = (int)(1); i <= (int)((l1 - l2) / YW); i++) B *= BAS;
    for (int i = (int)(1); i <= (int)((l1 - l2) % YW); i++) B *= 10;
    for (int i = (int)(l1 - l2); i >= (int)(0); i--) {
      int x = 0;
      for (; chu >= B; chu -= B, x++)
        ;
      c[i / YW + 1] = c[i / YW + 1] * 10 + x;
      B /= 10;
    }
    c[0] = (l1 - l2) / YW + 1;
    for (; c[0] && !c[c[0]]; c[0]--)
      ;
    return c;
  }
  big operator+(const big &b) {
    big c;
    c[0] = max(a[0], b[0]);
    for (int i = (int)(1); i <= (int)(c[0]); i++) c[i] = a[i] + b[i];
    for (int i = (int)(1); i <= (int)(c[0]); i++)
      c[i + 1] += c[i] / BAS, c[i] %= BAS;
    if (c[c[0] + 1]) c[0]++;
    return c;
  }
  big operator+(int x) {
    big c = *this;
    c[1] += x;
    for (int i = (int)(1); i <= (int)(c[0] + 1); i++)
      if (c[i] >= BAS) {
        c[i + 1] += c[i] / BAS;
        c[i] %= BAS;
      } else
        break;
    if (c[c[0] + 1]) c[0]++;
    return c;
  }
  big operator-(const big &b) {
    big c;
    c[0] = a[0];
    for (int i = (int)(1); i <= (int)(c[0]); i++) c[i] = a[i] - b[i];
    for (int i = (int)(1); i <= (int)(c[0]); i++)
      if (c[i] < 0) c[i] += BAS, c[i + 1]--;
    for (; c[0] && !c[c[0]]; c[0]--)
      ;
    return c;
  }
  big operator-(int x) {
    big c = *this;
    c[1] -= x;
    for (int i = (int)(1); i <= (int)(c[0] + 1); i++)
      if (c[i] < 0) {
        c[i + 1] += (c[i] + 1) / BAS - 1;
        c[i] = (c[i] + 1) % BAS + BAS - 1;
      } else
        break;
    for (; c[0] && !c[c[0]]; c[0]--)
      ;
    return c;
  }
  int operator%(int x) {
    long long ans = 0;
    for (int i = (int)(a[0]); i >= (int)(1); i--) ans = (ans * BAS + a[i]) % x;
    return ans;
  }
  big operator%(const big &b) {
    if (!b[0] && !b[1]) {
      puts("error! mod by 0");
      exit(0);
    }
    int l1 = max(0, (a[0] - 1)) * YW;
    int l2 = max(0, (b[0] - 1)) * YW;
    int v1 = a[a[0]], v2 = b[b[0]];
    for (; v1; v1 /= 10, l1++)
      ;
    for (; v2; v2 /= 10, l2++)
      ;
    big chu = *this, B = b;
    for (int i = (int)(1); i <= (int)((l1 - l2) / YW); i++) B *= BAS;
    for (int i = (int)(1); i <= (int)((l1 - l2) % YW); i++) B *= 10;
    for (int i = (int)(l1 - l2); i >= (int)(0); i--) {
      for (; chu >= B; chu -= B)
        ;
      B /= 10;
    }
    return chu;
  }
  big operator+=(const big &b) { return *this = (*this + b); }
  big operator-=(const big &b) { return *this = (*this - b); }
  big operator*=(const big &b) { return *this = (*this * b); }
  big operator/=(const big &b) { return *this = (*this / b); }
  big operator%=(const big &b) { return *this = (*this % b); }
  big operator+=(int x) { return *this = (*this + x); }
  big operator-=(int x) { return *this = (*this - x); }
  big operator*=(int x) { return *this = (*this * x); }
  big operator/=(int x) { return *this = (*this / x); }
  void read() {
    char c[LEN * YW + 10];
    scanf("%s", c);
    int len = strlen(c);
    memset((*this).a, 0, sizeof((*this).a));
    ;
    reverse(c, c + len);
    a[0] = (len - 1) / YW + 1;
    for (int i = (int)(len - 1); i >= (int)(0); i--)
      a[i / YW + 1] = a[i / YW + 1] * 10 + c[i] - '0';
  }
  void write() {
    printf("%d", a[a[0]]);
    for (int i = (int)(a[0] - 1); i >= (int)(1); i--) printf("%08d", a[i]);
  }
  void writeln() {
    write();
    puts("");
  }
};
big gcd(const big &a, const big &b) {
  big A = a, B = b, ans = 1;
  for (; !(A[1] & 1) && !(B[1] & 1); A /= 2, B /= 2, ans *= 2)
    ;
  for (;;) {
    if (A[0] == 0 && A[1] == 0) return B * ans;
    if (B[0] == 0 && B[1] == 0) return A * ans;
    for (; !(A[1] & 1); A /= 2)
      ;
    for (; !(B[1] & 1); B /= 2)
      ;
    A > B ? A -= B : B -= A;
  }
}
void YF(big &A, big &B) {
  big C = gcd(A, B);
  A /= C;
  B /= C;
}
big p, pp, q, qq;
int main() {
  int n;
  scanf("%d", &n);
  int T = 0;
  for (; !(n & 1); n /= 2, T++)
    ;
  if (n == 1) {
    printf("%d/%d", T, 1);
    exit(0);
  }
  p = 0;
  q = 1;
  pp = 1;
  qq = 1;
  for (int i = n + 1;;) {
    if (i > n) {
      (q % (i - n)) == 0 ? q /= i - n : p *= i - n;
      (qq % (i - n)) == 0 ? qq /= i - n : pp *= i - n;
      (p % i) == 0 ? p /= i : q *= i;
      (pp % i) == 0 ? pp /= i : qq *= i;
    } else
      p += q;
    if (i == 1) break;
    i & 1 ? i += n : i /= 2;
  }
  YF(p, q);
  p *= qq;
  q *= (qq - pp);
  p += q * T;
  YF(p, q);
  p.write();
  putchar('/');
  q.write();
}
