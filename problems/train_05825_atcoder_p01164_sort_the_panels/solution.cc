#include <iostream>
#include <iomanip>
#include <vector>
#include <bitset>
#include <string>
#include <map>
#include <queue>
#include <functional>
#include <assert.h>
using namespace std;
inline int pack(int p, int ps, int n) {
  return (p << n) | ps;
}
int main(int argc, char *argv[])
{
  for(;;) {
    int n;
    cin >> n;
    if(n==0) break;
    string sa, sb;
    getline(cin, sa);
    getline(cin, sa);
    getline(cin, sb);
    auto conv = [n](string &s) {
      int r = 0;
      for(int i = 0; i < n; i++) {
        r = (r<<1) + (s[i] == 'W' ? 1 : 0); 
      }
      return r;
    };
    const int a = conv(sa);
    const int b = conv(sb);
    //cout << "a = " << static_cast<std::bitset<8> >(a) << endl;
    //cout << "b = " << static_cast<std::bitset<8> >(b) << endl;
    // better DP: state = (head-pos, difference)
    vector<int> ds(n<<n, -1);
    function<int(int)> rec = [&rec,&b,&n,&ds](const int v){
      if(ds[v] >= 0) return ds[v];
      const int p = v >> n;
      const int s = v & ((1<<n) - 1);
      if(s == 0) return 0;
      int e = 10000000;
      for(int i = 0; i < n; i++) {
        if((s & (1<<i)) == 0) continue;
        for(int j = 0; j < n; j++) {
          if(i == j) continue;
          if((s & (1<<j)) == 0) continue;
          if((((b>>i) ^ (b>>j))&1) == 0) continue;
          const int c = abs(i - p) + abs(j - i);
          const int u = pack(j, s ^ (1<<i) ^ (1<<j), n); // swap
          e = min(e, c + rec(u));
        }
      }
      ds[v] = e;
      return e;
    };
    int e = 10000000;
    for(int i = 0; i < n; i++) {
      e = min(e, rec(pack(i, a^b, n)));
    }
    cout << e << endl;
/*  // naive Dijkstra search: state = (head-pos, panels)
    vector<int> ds(n<<n, 100000000);
    priority_queue<pair<int,int>> que;
    for(int i = 0; i < n; i++) {
      int v = pack(i, a, n);
      ds[v] = 0;
      que.push(make_pair(-ds[v], v));
      
    }
    vector<bool> done(n, false);
    int rest = n;
    while(que.size() > 0) {
      auto dv = que.top(); que.pop();
      const int v = dv.second;
      const int d = -dv.first;
      const int p = v >> n;
      const int s = v & ((1<<n) - 1);
      //cout << "popped: " << static_cast<std::bitset<8> >(s) << " at " << p << " with cost " << d << endl;
      if(s == b) {
        if(!done[p]) {
          done[p] = true;
          rest--;
        }
        if(rest == 0) {
          int e = d;
          for(int i = 0; i < n; i++) {
            e = min(e, ds[pack(i, b, n)]);
          }
          cout << e << endl;
          break;
        }
      }
      // generate all possible transitions: marking i, and then j.
      for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
          if(i == j) continue;
          if((((s>>i) ^ (s>>j))&1) == 0) continue;
          const int c = abs(i - p) + abs(j - i);
          const int u = pack(j, s ^ (1<<i) ^ (1<<j), n); // swap
          if(ds[u] > d + c) {
            ds[u] = d + c;
            que.push(make_pair(-ds[u], u));
            //cout << " to " << i << " and " << j << " cost " << ds[u] << " for " << static_cast<std::bitset<8> >(u) << endl;
          }
        }
      }
    }
*/
  }
  return 0;
}