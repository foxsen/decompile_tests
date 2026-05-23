#include<bits/stdc++.h>

using namespace std;

int N, K;
int X[10000], Y[10000];

void beet() {
  cin >> K;
  vector< int > vs;
  for(int i = 0; i < N; i++) {
    cin >> X[i] >> Y[i];
    vs.push_back(Y[i]);
  }
  double sq3 = sqrt(3);
  vector< int > latte(N), malta(N);
  iota(begin(latte), end(latte), 0);
  iota(begin(malta), end(malta), 0);
  sort(begin(latte), end(latte), [&](int a, int b) {
    return X[a] - Y[a] / sq3 < X[b] - Y[b] / sq3;
  });
  sort(begin(malta), end(malta), [&](int a, int b) {
    return X[a] + Y[a] / sq3 < X[b] + Y[b] / sq3;
  });

  int need1 = N - K;
  sort(begin(vs), end(vs));
  vs.erase(unique(begin(vs), end(vs)), end(vs));
  double ret = 1e30;
  for(int y_0 : vs) {
    vector< pair< double, int > > hidari;
    vector< pair< double, int > > migi;
    for(auto &i : latte) {
      if(y_0 > Y[i]) {}
      else if(Y[i] == y_0) {
        hidari.emplace_back(X[i], i);
      } else {
        double dist = Y[i] - y_0;
        hidari.emplace_back(X[i] - dist / sq3, i);
      }
    }
    for(auto &i : malta) {
      if(y_0 > Y[i]) {}
      else if(Y[i] == y_0) {
        migi.emplace_back(X[i], i);
      } else {
        double dist = Y[i] - y_0;
        migi.emplace_back(X[i] + dist / sq3, i);
      }
    }

    vector< int > st(N), inner(N);
    int ptr = 0;
    double last = -1e9;
    int add = 0;
    for(int i = 0; i < hidari.size(); i++) {
      st[hidari[i].second] = true;
    }

    for(int i = 0; i < hidari.size(); i++) {

      while(ptr < migi.size() && add < need1) {
        if(st[migi[ptr].second]) {
          inner[migi[ptr].second] = true;
          last = migi[ptr].first;
          ++add;
        }
        ++ptr;
      }


      if(add >= need1) {
        ret = min(ret, last - hidari[i].first);
      }

      if(inner[hidari[i].second]) {
        inner[hidari[i].second] = false;
        --add;
      }
      st[hidari[i].second] = false;
    }
  }
  cout << fixed << setprecision(15) << ret * 3 << endl;
}

int main() {
  while(cin >> N, N) beet();
}
