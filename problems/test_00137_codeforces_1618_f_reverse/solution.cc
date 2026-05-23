#include <bits/stdc++.h>
const long long mod = 1e9 + 7;
const long long N = 2e5 + 10;
using namespace std;
inline void read(long long &ans) {
  ans = 0;
  bool f = 0;
  char a;
  while (a = getchar(), a == ' ' || a == '\n')
    ;
  if (a == '-')
    f = 1;
  else
    ans = (a - '0');
  while (a = getchar(), a != '\n' && a != ' ') ans = ans * 10 + (a - '0');
  if (f) ans *= -1;
}
inline void read(long long &a, long long &b) {
  read(a);
  read(b);
}
inline void read(long long &a, long long &b, long long &c) {
  read(a);
  read(b);
  read(c);
}
bool cmpde(long long a, long long b) { return a > b; }
long long merge_sort(long long arr[], long long l, long long r) {
  if (l >= r) return 0;
  long long mid = l + r >> 1, cnt = 0;
  cnt += merge_sort(arr, l, mid);
  cnt += merge_sort(arr, mid + 1, r);
  long long i = l, j = mid + 1, temp[r - l + 1], k = 0;
  while (i <= mid && j <= r) {
    if (arr[i] <= arr[j])
      temp[k++] = arr[i++];
    else {
      temp[k++] = arr[j++];
      cnt += (mid - i + 1);
    }
  }
  while (i <= mid) temp[k++] = arr[i++];
  while (j <= r) temp[k++] = arr[j++];
  i = l;
  j = 0;
  while (i <= r) arr[i++] = temp[j++];
  return cnt;
}
long long qpow(long long a, long long n) {
  long long ans = 1;
  while (n) {
    if (n & 1) {
      ans *= a;
      ans %= mod;
    }
    n >>= 1;
    a = a * a;
    a %= mod;
  }
  return ans;
}
signed main() {
  ios::sync_with_stdio();
  cin.tie();
  cout.tie();
  long long t = 1;
  while (t--) {
    long long x, y;
    read(x, y);
    string str1 = "", str2 = "";
    long long tp1 = x, tp2 = y;
    long long cnt1 = 0, cnt2 = 0;
    while (tp1) {
      if (tp1 & 1) {
        str1 += '1';
        cnt1++;
      } else
        str1 += '0';
      tp1 >>= 1;
    }
    while (tp2) {
      if (tp2 & 1) {
        str2 += '1';
        cnt2++;
      } else
        str2 += '0';
      tp2 >>= 1;
    }
    if (cnt1 > cnt2) {
      cout << "NO" << '\n';
    } else if (cnt1 == cnt2) {
      if (str1 == str2) {
        cout << "YES" << '\n';
      } else {
        string tps1 = "";
        long long len1 = str1.size();
        long long i1 = 0;
        while (str1[i1] == '0') {
          i1++;
        }
        for (long long i = i1; i < len1; i++) {
          tps1 += str1[i];
        }
        string tps2 = tps1;
        reverse(tps1.begin(), tps1.end());
        if (tps1 == str2 || tps2 == str2) {
          cout << "YES" << '\n';
        } else
          cout << "NO" << '\n';
      }
    } else {
      bool f = 0;
      string str3 = "1";
      str3 += str1;
      string str5 = str3;
      reverse(str5.begin(), str5.end());
      string str7 = "", str8 = "";
      for (long long i = 0; i <= cnt2 - cnt1 - 1; i++) {
        str7 = "", str8 = "";
        for (long long j = 1; j <= i; j++) {
          str7 += '1';
        }
        str7 += str3;
        for (long long j = i + 1; j <= cnt2 - cnt1 - 1; j++) {
          str7 += '1';
        }
        if (str7 == str2) {
          f = 1;
          break;
        }
      }
      for (long long i = 0; i <= cnt2 - cnt1 - 1; i++) {
        str7 = "", str8 = "";
        for (long long j = 1; j <= i; j++) {
          str8 += '1';
        }
        str8 += str5;
        for (long long j = i + 1; j <= cnt2 - cnt1 - 1; j++) {
          str8 += '1';
        }
        if (str8 == str2) {
          f = 1;
          break;
        }
      }
      string tps1 = "";
      long long len1 = str1.size();
      long long i1 = 0;
      while (str1[i1] == '0') {
        i1++;
      }
      for (long long i = i1; i < len1; i++) {
        tps1 += str1[i];
      }
      string tps2 = tps1;
      reverse(tps2.begin(), tps2.end());
      str7 = "", str8 = "";
      for (long long i = 0; i <= cnt2 - cnt1; i++) {
        str7 = "", str8 = "";
        for (long long j = 1; j <= i; j++) {
          str7 += '1';
        }
        str7 += tps1;
        for (long long j = i + 1; j <= cnt2 - cnt1; j++) {
          str7 += '1';
        }
        if (str7 == str2) {
          f = 1;
          break;
        }
      }
      for (long long i = 0; i <= cnt2 - cnt1; i++) {
        str7 = "", str8 = "";
        for (long long j = 1; j <= i; j++) {
          str8 += '1';
        }
        str8 += tps2;
        for (long long j = i + 1; j <= cnt2 - cnt1; j++) {
          str8 += '1';
        }
        if (str8 == str2) {
          f = 1;
          break;
        }
      }
      if (f)
        cout << "YES" << '\n';
      else
        cout << "NO" << '\n';
    }
  }
  return 0;
}
