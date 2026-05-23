#include <bits/stdc++.h>

using namespace std;

#define int long long

using vint = vector<int>;

const int inf = 1LL<<55;

int V, E, K;
vector<vint> A;

vector<vint> calc(int m) {
  vector<vint> B = A;
  vector<vint> res(V, vint(V, -inf));
  for(int i = 0; i < V; ++i) res[i][i] = 0;
  while(m > 0) {
    if(m&1) {
      vector<vint> tmp(V, vint(V, -inf));
      for(int i = 0; i < V; ++i) tmp[i][i] = 0;
      for(int k = 0; k < V; ++k) {
	for(int i = 0; i < V; ++i) {
	  for(int j = 0; j < V; ++j) {
	    tmp[i][j] = max(tmp[i][j], res[i][k]+B[k][j]);
	  }
	}
      }
      res = tmp;
    }
    vector<vint> tmp(V, vint(V, -inf));
    for(int i = 0; i < V; ++i) tmp[i][i] = 0;
    for(int k = 0; k < V; ++k) {
      for(int i = 0; i < V; ++i) {
	for(int j = 0; j < V; ++j) {
	  tmp[i][j] = max(tmp[i][j], B[i][k]+B[k][j]);
	}
      }
    }
    B = tmp;
    m >>= 1;
  }
  return res;
}


int check(int m) {
  vector<vint> B = calc(m);
  int res = 0;
  for(int i = 0; i < V; ++i) {
    for(int j = 0; j < V; ++j) {
      res = max(res, B[i][j]);
    }
  }
  return res;
}

signed main() {
  cin >> V >> E >> K;
  A.resize(V, vint(V, -inf));
  for(int i = 0; i < V; ++i) A[i][i] = 0;
  for(int i = 0; i < E; ++i) {
    int u, v, c;
    cin >> u >> v >> c;
    A[u][v] = max(A[u][v], c);
  }
  int lb = -1, ub = 1111111;
  while(lb+1 < ub) {
    int mb = (lb+ub)/2;
    if(check(mb) >= K) ub = mb;
    else lb = mb;
  }
  if(ub == 1111111) {
    cout << -1 << endl;
    return 0;
  }
  cout << ub << endl;
  int ans = check(ub);
  if(ub <= 100) {
    vector<vint> rev(ub+1, vint(V, -1));
    vector<vint> dp(ub+1, vint(V, 0));
    for(int i = 0; i < ub; ++i) {
      for(int j = 0; j < V; ++j) {
	for(int k = 0; k < V; ++k) {
	  if(dp[i+1][k] < dp[i][j]+A[j][k]) {
	    dp[i+1][k] = dp[i][j]+A[j][k];
	    rev[i+1][k] = j;
	  }
	}
      }
    }
    int idx = -1;
    for(int i = 0; i < V && idx == -1; ++i) {
      if(ans == dp[ub][i]) idx = i;
    }
    vint vec;
    for(int l = ub; l >= 0; --l) {
      vec.push_back(idx);
      idx = rev[l][idx];
    }
    reverse(vec.begin(), vec.end());
    for(int i = 0; i < (int)vec.size(); ++i) {
      cout << vec[i] << " \n"[i==(int)vec.size()-1];
    }
  }


  return 0;
}

