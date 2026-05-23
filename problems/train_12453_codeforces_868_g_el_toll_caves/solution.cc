#include <bits/stdc++.h>
long long n, k, p, mo, gc, t, c, answ;
int ttt;
long long gcd(long long x, long long y) {
  if (y == 0)
    return (x);
  else
    return (gcd(y, x % y));
}
long long mi(long long aa, long long bb) {
  long long s = 1;
  while (bb != 0) {
    if ((bb % 2) == 1) s = (s * aa) % mo;
    aa = (aa * aa) % mo;
    bb = bb / 2;
  }
  return (s);
}
void ask(long long ni, long long ki, long long x, long long y, long long xi,
         long long yi, long long sz, long long siz) {
  if (ki == 1) {
    long long li, ri, ai;
    li = mi(x, ni - 1);
    if ((x + mo) % mo == 1)
      ri = (ni - 1) * y % mo;
    else
      ri = (li - 1) * mi(x - 1, mo - 2) % mo * y % mo;
    ai = (xi * ri + yi) % mo * mi((1 - li * xi) % mo, mo - 2) % mo;
    if ((x + mo) % mo == 1) {
      answ = (answ + ni * ai % mo * siz) % mo;
      answ = (answ + ((ni - 1) * ni / 2) % mo * y % mo * siz) % mo;
    } else {
      answ = (answ + (li * x - 1) % mo * mi(x - 1, mo - 2) % mo *
                         (ai + (y * mi(x - 1, mo - 2)) % mo) % mo * siz) %
             mo;
      answ = (answ - ni * mi(x - 1, mo - 2) % mo * y % mo * siz) % mo;
    }
    answ = (answ - ai * (siz - sz)) % mo;
  } else {
    long long li, ri, mm = ni / ki, m = ni % ki, yy, sz1, sz2, aa, bb;
    li = mi(x, mm - 1);
    if ((x + mo) % mo == 1) {
      answ = (answ + ((mm + 1) * mm / 2) % mo * m % mo * y % mo * siz) % mo;
      answ =
          (answ + (mm * (mm - 1) / 2) % mo * (ki - m) % mo * y % mo * siz) % mo;
    } else {
      answ = (answ + (li * x - 1) % mo * mi(x - 1, 2 * mo - 4) % mo * (ki - m) %
                         mo * y % mo * siz) %
             mo;
      answ = (answ + ((li * x % mo) * x - 1) % mo * mi(x - 1, 2 * mo - 4) % mo *
                         m % mo * y % mo * siz) %
             mo;
      answ = (answ - ni * mi(x - 1, mo - 2) % mo * y % mo * siz) % mo;
    }
    if (x == 1) {
      sz1 = sz + mm * siz;
      sz2 = sz + (mm - 1) * siz;
    } else {
      sz1 = (sz + ((li * x % mo) * x - 1) % mo * siz % mo * mi(x - 1, mo - 2) -
             siz) %
            mo;
      sz2 = (sz + (li * x - 1) % mo * siz % mo * mi(x - 1, mo - 2) - siz) % mo;
    }
    if ((x + mo) % mo == 1) {
      ri = mm * y % mo;
      yy = (mm - 1) * y % mo;
    } else {
      ri = (li * x - 1) % mo * mi(x - 1, mo - 2) % mo * y % mo;
      ;
      yy = (li - 1) * mi(x - 1, mo - 2) % mo * y % mo;
    }
    aa = (li * xi % mo * x) % mo;
    bb = (li * xi) % mo;
    aa = mi(aa, mo - 2);
    bb = mi(bb, mo - 2);
    ask(ki, m, bb, (0 - yy * xi - yi) % mo * bb % mo, aa,
        (0 - ri * xi - yi) % mo * aa % mo, sz1, sz2);
  }
}
int main() {
  scanf("%d", &ttt);
  mo = 1000000007;
  p = (mo + 1) / 2;
  for (int iii = 1; iii <= ttt; iii++) {
    scanf("%I64d%I64d", &n, &k);
    gc = gcd(n, k);
    n = n / gc;
    k = k / gc;
    answ = 0;
    if (p != 1)
      ask(n, k, 1, 1, 1 - p, 1, 1, 1);
    else {
      t = n / k;
      answ = (t * (t + 1) / 2) % mo;
      answ = answ * k % mo;
      c = n % k;
      answ = (answ + c * (t + 1)) % mo;
    }
    answ = answ % mo;
    answ = (answ * mi(n, mo - 2)) % mo;
    answ = (answ + mo) % mo;
    printf("%I64d\n", answ);
  }
}
