#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

typedef long long ll;
typedef pair<string,int> P;

ll A, B, MOD;
ll n;
ll bit[1000000];

ll sum(int i){
  ll res = 0;
  while(i > 0){
    res += bit[i];
    res %= MOD;
    i -= i & -i;
  }
  return res;
}

void add(int i, int x){
  while(i <= n){
    bit[i] += x;
    bit[i] %= MOD;
    i += i & -i;
  }
}

string itos(ll x){
  stringstream ss;
  ss << x;
  return ss.str();
}

int main(){
  while(cin >> A >> B >> MOD, A || B || MOD){
    vector<P> v;
    for(ll i = A; i <= B; i++){
      v.push_back(P(itos(i), i - A + 1));
    }
    sort(v.begin(), v.end());

    n = B - A + 1;
    memset(bit, 0, sizeof(bit));

    for(int i = 0; i < v.size(); i++){
      ll tmp = sum(v[i].second);
      add(v[i].second, tmp + 1);
    }

    cout << sum(n) << endl;
  }
}