#include <bits/stdc++.h>
using namespace std;
int MAX(int m1 = INT_MIN, int m2 = INT_MIN, int m3 = INT_MIN, int m4 = INT_MIN,
        int m5 = INT_MIN, int m6 = INT_MIN, int m7 = INT_MIN, int m8 = INT_MIN,
        int m9 = INT_MIN, int m10 = INT_MIN) {
  return max(max(max(max(m1, m2), max(m3, m4)), max(m5, m6)),
             max(max(m7, m8), max(m9, m10)));
}
int MIN(int m1 = INT_MAX, int m2 = INT_MAX, int m3 = INT_MAX, int m4 = INT_MAX,
        int m5 = INT_MAX, int m6 = INT_MAX, int m7 = INT_MAX, int m8 = INT_MAX,
        int m9 = INT_MAX, int m10 = INT_MAX) {
  return min(min(min(min(m1, m2), min(m3, m4)), min(m5, m6)),
             min(min(m7, m8), min(m9, m10)));
}
long long power(long long x, long long n) {
  long long f = 1;
  while (n) {
    if (n & 1) {
      f = f * x % 1000000007;
    }
    x = x * x % 1000000007;
    n >>= 1;
  }
  return f;
}
long long per(long long x, long long n) {
  long long f = 1;
  while (n > 0) {
    if (n % 2 == 1) {
      f *= x;
    }
    x *= x;
    n /= 2;
  }
  return f;
}
void cin_vector(vector<char>& v, int n) {
  for (int i = 0; i < n; i++) {
    char num;
    cin >> num;
    v.emplace_back(num);
  }
}
void cin_deque(deque<int>& d, int n) {
  for (int i = 0; i < n; i++) {
    int num;
    cin >> num;
    d.emplace_back(num);
  }
}
void cin_list(list<int>& l, int n) {
  for (int i = 0; i < n; i++) {
    int num;
    cin >> num;
    l.emplace_back(num);
  }
}
void cin_flist(forward_list<int>& fl, int n) {
  for (int i = 0; i < n; i++) {
    int num;
    cin >> num;
    fl.emplace_front(num);
  }
  fl.reverse();
}
void cin_set(set<int>& st, int n) {
  for (int i = 0; i < n; i++) {
    int num;
    cin >> num;
    st.emplace(num);
  }
}
void cin_map(map<int, string>& m, int n) {
  for (int i = 0; i < n; i++) {
    int k;
    cin >> k;
    ;
    string s;
    cin >> s;
    m.emplace(k, s);
  }
}
void cin_2d_vector(vector<vector<char>>& v) {
  for (int i = 0; i < v.size(); i++) {
    for (int j = 0; j < v[i].size(); j++) {
      cin >> v[i][j];
    }
  }
}
void cin_2d_deque(deque<deque<long long>>& d) {
  for (int i = 0; i < d.size(); i++) {
    for (int j = 0; j < d[i].size(); j++) {
      cin >> d[i][j];
    }
  }
}
void cc_set(set<set<char>>& st, int r, int c) {
  for (int i = 0; i < r; i++) {
    set<char> row;
    for (int j = 0; j < c; j++) {
      char n;
      cin >> n;
      row.insert(n);
    }
    st.insert(row);
  }
  for (auto const& s : st) {
    for (auto const& i : s) {
      cout << i << " ";
    }
    cout << endl;
  }
}
long long int mod = 1e9 + 7;
long long int INF = 1e18;
char alphabet[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I',
                     'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R',
                     'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
string A = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
string a = "abcdefghijklmnopqrstuvwxyz";
int arr[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int leap[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
double PI = 3.1415926535897932384626;
int maxint = INT_MAX;
int maxarr = 1000005;
bool btn = 0;
int count = 0;
int cnt = 0;
int sum = 0;
int const md = 998244853;
int const q = 1e7;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long q;
  cin >> q;
  while (q--) {
    long long n;
    cin >> n;
    btn = 0;
    vector<char> v, v2;
    cin_vector(v, n);
    cin_vector(v2, n);
    vector<char> sv(v), sv2(v2);
    auto it = sv.end();
    sort(sv.begin(), it);
    it = sv2.end();
    sort(sv2.begin(), it);
    for (int i = 0; i < n; i++) {
      if (sv[i] != sv2[i]) {
        btn = 1;
        cout << "NO" << endl;
        break;
      }
    }
    if (btn == 1) {
      continue;
    }
    sv2.clear();
    for (int i = 0; i < n - 1; i++) {
      if (sv[i] == sv[i + 1]) {
        btn = 1;
        cout << "YES" << endl;
        break;
      }
    }
    if (btn == 1) {
      continue;
    }
    sv.clear();
    vector<long long> a(100), b(100);
    long long ca = 0, cb = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < v[i] - 'a'; j++) {
        ca += a[j];
      }
      a[v[i] - 'a']++;
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < v2[i] - 'a'; j++) {
        cb += b[j];
      }
      b[v2[i] - 'a']++;
    }
    if (ca % 2 == cb % 2) {
      cout << "YES" << endl;
      continue;
    }
    cout << "NO" << endl;
  }
  return 0;
}
