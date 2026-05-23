#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const long double pi = acos(-1.0);
const string debug_line = "yolo";
const long double PI = acos((long double)-1.0);
const long double eps = 1e-6;
struct node {
  int u, v, x1, y1, c;
  node(int _u, int _v, int _x1, int _y1, int _c) {
    u = _u, v = _v, x1 = _x1, y1 = _y1, c = _c;
  }
};
vector<node> collect;
int n, m;
char s[1011][1011];
long long change1[1011][1011][26];
long long cost1[1011][1011];
long long counter1[1011][1011];
int getCost(int i, int j, char c) {
  long long answer1 = 0;
  for (int(k) = (0); (k) < (26); ++(k)) {
    answer1 = answer1 + change1[i][j][k] * (long long)abs(k - c + 'a');
  }
  return answer1;
}
void putValues(int i, int j, int mul, vector<long long> &res) {
  for (int(k) = (0); (k) < (26); ++(k)) {
    res[k] += mul * (long long)change1[i][j][k];
  }
}
void print(vector<int> res) {
  for (int(i) = (0); (i) < (res.size()); ++(i)) {
    printf("%d ", res[i]);
  }
  printf("\n");
}
long long getCost1(int i1, int j1, int i2, int j2) {
  i1--;
  j1--;
  long long answer1 = 0;
  if (i1 >= 0 && j1 >= 0) {
    answer1 += cost1[i1][j1];
  }
  if (i1 >= 0 && j2 >= 0) {
    answer1 -= cost1[i1][j2];
  }
  if (i2 >= 0 && j1 >= 0) {
    answer1 -= cost1[i2][j1];
  }
  answer1 += cost1[i2][j2];
  return answer1;
}
int main() {
  int k;
  scanf("%d%d%d", &n, &m, &k);
  for (int(i) = (0); (i) < (n); ++(i)) {
    scanf("%s", s[i]);
  }
  counter1[0][0] += k;
  for (int(i) = (0); (i) < (k); ++(i)) {
    int a1, b1, c1, d1;
    char e[2];
    scanf("%d%d%d%d%s", &a1, &b1, &c1, &d1, e);
    getchar();
    a1--, b1--, c1--, d1--;
    node n1 = {a1, b1, c1, d1, e[0] - 'a'};
    collect.push_back(n1);
    c1++, d1++;
    change1[a1][b1][e[0] - 'a']++;
    counter1[a1][b1]--;
    change1[a1][d1][e[0] - 'a']--;
    counter1[a1][d1]++;
    change1[c1][d1][e[0] - 'a']++;
    counter1[c1][d1]--;
    change1[c1][b1][e[0] - 'a']--;
    counter1[c1][b1]++;
  }
  for (int(i) = (0); (i) < (n + 1); ++(i)) {
    for (int(j) = (0); (j) < (m + 1); ++(j)) {
      for (int(k) = (0); (k) < (26); ++(k)) {
        if (i == 0 && j == 0) {
        } else if (i != 0 && j == 0) {
          change1[i][j][k] += change1[i - 1][j][k];
        } else if (i == 0 && j != 0) {
          change1[i][j][k] += change1[i][j - 1][k];
        } else if (i != 0 && j != 0) {
          change1[i][j][k] += change1[i - 1][j][k] + change1[i][j - 1][k] -
                              change1[i - 1][j - 1][k];
        }
      }
    }
  }
  for (int(i) = (0); (i) < (n + 1); ++(i)) {
    for (int(j) = (0); (j) < (m + 1); ++(j)) {
      if (i == 0 && j == 0) {
      } else if (i != 0 && j == 0) {
        counter1[i][j] += counter1[i - 1][j];
      } else if (i == 0 && j != 0) {
        counter1[i][j] += counter1[i][j - 1];
      } else if (i != 0 && j != 0) {
        counter1[i][j] +=
            counter1[i - 1][j] + counter1[i][j - 1] - counter1[i - 1][j - 1];
      }
    }
  }
  for (int(i) = (0); (i) < (n); ++(i)) {
    for (int(j) = (0); (j) < (m); ++(j)) {
      change1[i][j][s[i][j] - 'a'] += counter1[i][j];
    }
  }
  for (int(i) = (0); (i) < (n); ++(i)) {
    for (int(j) = (0); (j) < (m); ++(j)) {
      if (i == 0 && j == 0) {
        cost1[i][j] = getCost(i, j, s[i][j]);
      } else if (i != 0 && j == 0) {
        cost1[i][j] = cost1[i - 1][j] + getCost(i, j, s[i][j]);
      } else if (i == 0 && j != 0) {
        cost1[i][j] = cost1[i][j - 1] + getCost(i, j, s[i][j]);
      } else if (i != 0 && j != 0) {
        cost1[i][j] = cost1[i - 1][j] + cost1[i][j - 1] - cost1[i - 1][j - 1] +
                      getCost(i, j, s[i][j]);
      }
    }
  }
  for (int(i) = (0); (i) < (n + 1); ++(i)) {
    for (int(j) = (0); (j) < (m + 1); ++(j)) {
      for (int(k) = (0); (k) < (26); ++(k)) {
        if (i == 0 && j == 0) {
        } else if (i != 0 && j == 0) {
          change1[i][j][k] += change1[i - 1][j][k];
        } else if (i == 0 && j != 0) {
          change1[i][j][k] += change1[i][j - 1][k];
        } else if (i != 0 && j != 0) {
          change1[i][j][k] += change1[i - 1][j][k] + change1[i][j - 1][k] -
                              change1[i - 1][j - 1][k];
        }
      }
    }
  }
  long long answer1 = 10000000000000000LL;
  for (auto &(n1) : (collect)) {
    long long currentAnswer = 0;
    vector<long long> res;
    res.resize(26, 0);
    int u1 = n1.u - 1;
    int v1 = n1.v - 1;
    int x1 = n1.x1;
    int y1 = n1.y1;
    if (x1 >= 0 && y1 >= 0) putValues(x1, y1, 1, res);
    if (u1 >= 0 && y1 >= 0) putValues(u1, y1, -1, res);
    if (x1 >= 0 && v1 >= 0) putValues(x1, v1, -1, res);
    if (u1 >= 0 && v1 >= 0) putValues(u1, v1, 1, res);
    for (int(k) = (0); (k) < (26); ++(k)) {
      currentAnswer += (long long)res[k] * (long long)abs(k - n1.c);
    }
    currentAnswer += cost1[n - 1][m - 1];
    u1++, v1++;
    currentAnswer -= getCost1(u1, v1, x1, y1);
    answer1 = min(answer1, currentAnswer);
  }
  printf("%lld\n", answer1);
  return 0;
}
