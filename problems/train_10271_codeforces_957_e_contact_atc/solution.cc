#include <bits/stdc++.h>
using namespace std;
class frac {
 public:
  long long int a, b;
  frac() {}
  frac(long long int aa, long long int bb) {
    a = aa;
    b = bb;
  }
  bool operator<(const frac q) const {
    long long int aa = a, bb = b, qa = q.a, qb = q.b;
    if (bb < 0) {
      aa = -aa;
      bb = -bb;
    }
    if (qb < 0) {
      qa = -qa;
      qb = -qb;
    }
    return (aa * qb < bb * qa);
  }
  void operator=(const frac q) {
    a = q.a;
    b = q.b;
    return;
  }
  bool operator==(const frac q) const {
    long long int aa = a, bb = b, qa = q.a, qb = q.b;
    if (bb < 0) {
      aa = -aa;
      bb = -bb;
    }
    if (qb < 0) {
      qa = -qa;
      qb = -qb;
    }
    return (aa * qb == bb * qa);
  }
  void print() { cout << a << "/" << b << endl; }
};
long long int ans;
class info {
 public:
  int id;
  frac ab;
  info() {}
  info(int ii, frac abab) { id = ii, ab = abab; }
  void operator=(const info q) {
    id = q.id;
    ab = q.ab;
    return;
  }
};
bool cmp(info pp, info qq) {
  if (pp.ab < qq.ab) return 1;
  if (qq.ab < pp.ab) return 0;
  if (pp.ab.a * qq.ab.a < 0) {
    return pp.ab.a < 0;
  } else
    return pp.ab.a > qq.ab.a;
}
void msort(info *arr, int r) {
  if (1 == r) return;
  int mid = (r) / 2, i, j, k;
  msort(arr, mid);
  msort(arr + mid, r - mid);
  info *temp = new info[r];
  j = 0;
  k = mid;
  for (i = 0; i < r; i++) {
    if (j == mid) {
      temp[i] = arr[k];
      k++;
    } else if (k == r) {
      temp[i] = arr[j];
      j++;
    } else if (arr[j].ab < arr[k].ab) {
      temp[i] = arr[j];
      j++;
    } else {
      ans += (mid - j);
      temp[i] = arr[k];
      k++;
    }
  }
  for (i = 0; i < r; i++) {
    arr[i] = temp[i];
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int n, w, i, idd;
  long long int first, vv;
  info *a = new info[100000];
  frac *plusw = new frac[100000];
  frac minw, nfrac;
  ans = 0;
  cin >> n >> w;
  for (i = 0; i < n; i++) {
    cin >> first >> vv;
    minw = frac(first, vv - w);
    a[i] = info(i, minw);
    plusw[i] = frac(first, vv + w);
  }
  if (w == 0) {
    sort(plusw, plusw + n);
    i = 0;
    while (i < n) {
      long long int tt = 0;
      frac cc;
      cc = plusw[i];
      i++;
      while (i < n && plusw[i] == cc) {
        tt++;
        i++;
      }
      ans += (tt * (tt + 1) / 2);
    }
    cout << ans << endl;
    return 0;
  }
  sort(a, a + n, cmp);
  for (i = 0; i < n; i++) {
    idd = a[i].id;
    a[i].ab = plusw[idd];
  }
  msort(a, n);
  cout << ans << endl;
  return 0;
}
