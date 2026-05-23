#include <bits/stdc++.h>
using namespace std;
class myistream {
  static const int maxsize = 1000007, tmpsize = 50;
  char *s, *tmp;
  char *cur, *upperbound;
  FILE *fp;
  bool last_read;
  bool end_of_file;
  bool to_return;
  void upd() {
    int num = fread(s, sizeof(char), maxsize, fp);
    if (num < maxsize) last_read = true, upperbound = s + num;
    if (!num) end_of_file = true;
    cur = s;
  }
  char scan() {
    if (cur >= upperbound) {
      if (last_read)
        end_of_file = true;
      else
        upd();
    }
    return *cur++;
  }
  bool isspace(char c) {
    return c == ' ' || c == '\n' || c == '\r' || c == '\t';
  }

 public:
  myistream(FILE *_fp)
      : last_read(false), end_of_file(false), to_return(false), fp(_fp) {
    s = new char[maxsize + 2];
    tmp = new char[tmpsize + 2];
    upperbound = s + maxsize;
    cur = s + maxsize;
  }
  ~myistream() {
    delete[] s;
    delete[] tmp;
    fclose(fp);
  }
  operator void *() const { return to_return ? 0 : (void *)this; }
  bool operator!() const { return to_return; }
  myistream &operator>>(int &a) {
    if (!end_of_file) {
      char c = scan();
      while (isspace(c) && !end_of_file) c = scan();
      if (end_of_file) {
        to_return = true;
        return *this;
      }
      a = 0;
      bool nega = false;
      if (c == '-') nega = true, c = scan();
      while (!isspace(c) && !end_of_file) {
        a = a * 10 + (((int)c) & 15);
        c = scan();
      }
      if (nega) a = -a;
    } else
      to_return = true;
    return *this;
  }
  myistream &operator>>(long long &a) {
    if (!end_of_file) {
      char c = scan();
      while (isspace(c) && !end_of_file) c = scan();
      if (end_of_file) {
        to_return = true;
        return *this;
      }
      a = 0;
      bool nega = false;
      if (c == '-') nega = true, c = scan();
      while (!isspace(c) && !end_of_file) {
        a = a * 10 + (((long long)c) & 15);
        c = scan();
      }
      if (nega) a = -a;
    } else
      to_return = true;
    return *this;
  }
  myistream &operator>>(char &c) {
    if (!end_of_file) {
      c = scan();
      while (isspace(c) && !end_of_file) c = scan();
    }
    if (end_of_file) to_return = true;
    return *this;
  }
  myistream &operator>>(bool &b) {
    if (!end_of_file) {
      char c = scan();
      while (isspace(c) && !end_of_file) c = scan();
      b = (c == '1');
    }
    if (end_of_file) to_return = true;
    return *this;
  }
  myistream &operator>>(char *s) {
    if (!end_of_file) {
      char c = scan();
      while (isspace(c) && !end_of_file) c = scan();
      if (end_of_file) {
        to_return = true;
        return *this;
      }
      while (!isspace(c) && !end_of_file) *s++ = c, c = scan();
      *s = '\0';
    } else
      to_return = true;
    return *this;
  }
  myistream &operator>>(string &s) {
    s.clear();
    if (!end_of_file) {
      char c = scan();
      while (isspace(c) && !end_of_file) c = scan();
      if (end_of_file) {
        to_return = true;
        return *this;
      }
      while (!isspace(c) && !end_of_file) s.push_back(c), c = scan();
    } else
      to_return = true;
    return *this;
  }
  myistream &operator>>(double &d) {
    if (!end_of_file) {
      char *tp = tmp;
      char c = scan();
      while (isspace(c) && !end_of_file) c = scan();
      if (end_of_file) {
        to_return = true;
        return *this;
      }
      while (!isspace(c) && !end_of_file) *tp++ = c, c = scan();
      *tp = '\0';
      sscanf(tmp, "%lf", &d);
    } else
      to_return = true;
    return *this;
  }
};
class myostreamEndlType {};
class myostreamSetPrecisionType {
 public:
  int precision;
  myostreamSetPrecisionType(int _precision) : precision(_precision) {}
};
class myostream {
  static const int maxsize = 1000007, tmpsize = 50;
  char *s, *upperbound, *cur, *tmp;
  FILE *fp;
  int numberAfterPoint;
  char doubleFormat[20];
  void write(char c) {
    if (cur >= upperbound) {
      fwrite(s, sizeof(char), maxsize, fp);
      cur = s;
    }
    *cur++ = c;
  }

 public:
  myostream(FILE *_fp) : fp(_fp) {
    s = new char[maxsize];
    tmp = new char[tmpsize + 2];
    upperbound = s + maxsize;
    cur = s;
    precision(6);
  }
  ~myostream() {
    fwrite(s, sizeof(char), cur - s, fp);
    fclose(fp);
    delete[] s;
  }
  void precision(int x) {
    numberAfterPoint = x;
    sprintf(doubleFormat, "%%.%dlf", x);
  }
  int precision(void) { return numberAfterPoint; }
  myostream &operator<<(const myostreamSetPrecisionType &p) {
    precision(p.precision);
    return *this;
  }
  myostream &operator<<(const char &c) {
    write(c);
    return *this;
  }
  myostream &operator<<(const myostreamEndlType &e) {
    write('\n');
    return *this;
  }
  myostream &operator<<(const bool &b) {
    write(b ? '1' : '0');
    return *this;
  }
  myostream &operator<<(const char *c) {
    for (const char *p = c; *p; p++) write(*p);
    return *this;
  }
  myostream &operator<<(const string &c) { return *this << c.c_str(); }
  myostream &operator<<(const size_t &a) { return *this << int(a); }
  myostream &operator<<(const int &a) {
    if (a == 0) {
      write('0');
      return *this;
    }
    int s = a;
    if (s < 0) write('-'), s = -s;
    char *tp = tmp;
    while (s > 0) {
      *tp++ = char((s % 10) | 48);
      s /= 10;
    }
    for (--tp; tp >= tmp; --tp) write(*tp);
    return *this;
  }
  myostream &operator<<(const long long &a) {
    if (a == 0) {
      write('0');
      return *this;
    }
    long long s = a;
    if (s < 0) write('-'), s = -s;
    char *tp = tmp;
    while (s > 0) {
      *tp++ = char((s % 10) | 48);
      s /= 10;
    }
    for (--tp; tp >= tmp; --tp) write(*tp);
    return *this;
  }
  myostream &operator<<(const double &d) {
    sprintf(tmp, doubleFormat, d);
    *this << tmp;
    return *this;
  }
};
template <class T1, class T2>
struct ReadArrayType {
  T1 *toread1;
  T2 *toread2;
  int count;
  int *save;
  ReadArrayType(T1 *_toread1, T2 *_toread2, int _count, int *_save)
      : toread1(_toread1), toread2(_toread2), count(_count), save(_save) {}
};
template <class T>
ReadArrayType<T, int> RA(int &save, T *toread) {
  return ReadArrayType<T, int>(toread, NULL, -1, &save);
}
template <class T>
ReadArrayType<T, int> RA(T *toread, int count = -1) {
  return ReadArrayType<T, int>(toread, NULL, count, NULL);
}
template <class T1, class T2>
ReadArrayType<T1, T2> RA(int &save, T1 *toread1, T2 *toread2) {
  return ReadArrayType<T1, T2>(toread1, toread2, -1, &save);
}
template <class T1, class T2>
ReadArrayType<T1, T2> RA(T1 *toread1, T2 *toread2, int count = -1) {
  return ReadArrayType<T1, T2>(toread1, toread2, count, NULL);
}
template <class T1, class T2>
istream &operator>>(istream &in, const ReadArrayType<T1, T2> &r) {
  int count = r.count;
  if (count == -1) in >> count;
  if (r.toread2 == NULL)
    for (int i = 0; i < (count); ++i) in >> r.toread1[i];
  else
    for (int i = 0; i < (count); ++i) in >> r.toread1[i] >> r.toread2[i];
  if (r.save != NULL) *r.save = count;
  return in;
}
template <class T1, class T2>
istream &operator>>(istream &in, pair<T1, T2> &p) {
  in >> p.first >> p.second;
  return in;
}
template <class T>
istream &operator>>(istream &in, vector<T> &v) {
  int sz;
  in >> sz;
  v.resize(sz);
  for (int i = 0; i < (sz); ++i) cin >> v[i];
  return in;
}
template <class T1, class T2>
myistream &operator>>(myistream &in, const ReadArrayType<T1, T2> &r) {
  int count = r.count;
  if (count == -1) in >> count;
  if (r.toread2 == NULL)
    for (int i = 0; i < (count); ++i) in >> r.toread1[i];
  else
    for (int i = 0; i < (count); ++i) in >> r.toread1[i] >> r.toread2[i];
  if (r.save != NULL) *r.save = count;
  return in;
}
template <class T1, class T2>
myistream &operator>>(myistream &in, pair<T1, T2> &p) {
  in >> p.first >> p.second;
  return in;
}
template <class T>
myistream &operator>>(myistream &in, vector<T> &v) {
  int sz;
  in >> sz;
  v.resize(sz);
  for (int i = 0; i < (sz); ++i) cin >> v[i];
  return in;
}
template <class T>
struct ReadVectorType {
  vector<T> &vec;
  int count;
  ReadVectorType(vector<T> &_vec, int _count) : vec(_vec), count(_count) {}
};
template <class T>
ReadVectorType<T> RV(vector<T> &vec, int count) {
  return ReadVectorType<T>(vec, count);
}
template <class T>
istream &operator>>(istream &in, const ReadVectorType<T> &r) {
  r.vec.resize(r.count);
  for (int i = 0; i < (r.count); ++i) in >> r.vec[i];
  return in;
}
template <class T>
myistream &operator>>(myistream &in, const ReadVectorType<T> &r) {
  r.vec.resize(r.count);
  for (int i = 0; i < (r.count); ++i) in >> r.vec[i];
  return in;
}
myostreamEndlType myendl;
myistream mycin(stdin);
myostream mycout(stdout);
const int maxn = 100050;
int n, k;
long long b;
pair<int, int> a[maxn];
int bb[maxn];
bool used[maxn];
bool judge(int x) {
  int maxV = 0, toGet = -1;
  for (int i = 0; i < (x + 1); ++i)
    if (maxV < bb[i]) maxV = bb[toGet = i];
  long long sum = maxV;
  int c = k - 1, i = 0;
  while (c > 0) {
    if (a[i].second == toGet) {
      ++i;
      continue;
    }
    sum += a[i].first;
    ++i;
    --c;
  }
  return sum > b;
}
int main(void) {
  mycin >> n >> k >> b;
  for (int i = 0; i < (n); ++i)
    mycin >> a[i].first, a[i].second = i, bb[i] = a[i].first;
  sort(a, a + n - 1, greater<pair<int, int> >());
  int left = 0, right = n - 1;
  while (left < right) {
    int mid = (left + right) >> 1;
    if (judge(mid))
      right = mid;
    else
      left = mid + 1;
  }
  mycout << left + 1 << myendl;
}
