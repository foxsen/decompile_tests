#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <sstream>
#include <vector>
using namespace std;

#define REP2(i, m, n) for(int i = (int)(m); i < (int)(n); i++)
#define REP(i, n) REP2(i, 0, n)
#define ALL(c) (c).begin(), (c).end()
#define FOREACH(i, c) for(auto i = (c).begin(); i != (c).end(); ++i)
#define BIT(n, m) (((n) >> (m)) & 1)

typedef long long ll;
typedef pair<int, int> PI;

const ll inf = 1e15;
const ll mod = 1000 * 1000 * 1000 + 7;
const double eps = 1e-9;

template <typename S, typename T> ostream &operator<<(ostream &out, const pair<S, T> &p) {
  out << "(" << p.first << ", " << p.second << ")";
  return out;
}

template <typename T> ostream &operator<<(ostream &out, const vector<T> &v) {
  out << "[";
  REP(i, v.size()){
    if (i > 0) out << ", ";
    out << v[i];
  }
  out << "]";
  return out;
}

void solve(int R, int C){
  vector<PI> U;
  vector<int> SR(R), SC(C);
  
  REP(i, R + 1) REP(j, C + 1){
    string str;
    cin >> str;
    if (str == "?"){
      U.push_back(PI(i, j));
    } else {
      int value = atoi(str.c_str());
      if (i < R) SR[i] += (j == C ? value : -value);
      if (j < C) SC[j] += (i == R ? value : -value);
    }
  }

  if (U.size() > SR.size() + SC.size()) {
    cout << "NO" << endl;
  } else {
    int n = U.size();
    vector<vector<double> > M(R + C, vector<double>(n + 1, 0));
    REP(i, R) M[i + 0][n] = SR[i];
    REP(i, C) M[i + R][n] = SC[i];
    REP(i, n) M[U[i].first][i] = M[U[i].second + R][i] = 1;

    REP(i, n){
      int pivot = i;
      REP2(j, i, R + C) if (abs(M[j][i]) > abs(M[pivot][i])) pivot = j;
      
      if (abs(M[pivot][i]) < eps) {
        cout << "NO" << endl;
        return;
      }

      swap(M[pivot], M[i]);
      REP(j, R + C) REP2(k, i + 1, n + 1) if (j != i){
        M[j][k] -= M[j][i] / M[i][i] * M[i][k];
      }
      REP2(k, i + 1, n + 1) M[i][k] /= M[i][i];
      REP(j, R + C) M[j][i] = j == i;
    }
    
    REP(i, n) cout << (int)(M[i][n] > 0 ? M[i][n] + 0.5 : M[i][n] - 0.5) << endl;
  }
}


int main(){
  int R, C, T = 0;
  while (cin >> R >> C){
    if (T > 0) cout << endl;
    solve(R, C);
    T++;
  }
  return 0;
}