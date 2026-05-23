#include <iostream>
#include <set>
#define REP(i, a, n) for(int i = a; i <= n; i++)
using namespace std;
 
 
const int SIZE = 200001;
int N, a[SIZE], pos[SIZE];
long ans;
set<int> s;
 
int main(void) {
  cin >> N;
  REP(i, 1, N) {
    cin >> a[i];
    pos[a[i]] = i;
  }
 
  s.insert(0);
  s.insert(N + 1);
  ans = 0;
 
  REP(i, 1, N) {
    set<int>::iterator itr = s.lower_bound(pos[i]);
    int r = *itr - pos[i];
    int l = pos[i] - *(--itr);
    ans += (long) i * r * l;
    s.insert(pos[i]);
  }
 
  cout << ans << endl;
 
  return 0;
}