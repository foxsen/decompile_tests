#include <iostream>
#include <algorithm>
using namespace std;


int main() {
  int M, N;
  int W[101];
  while(cin >> M >> N && (M|N)) {
    for(int i = 0; i < N; ++i) cin >> W[i];
    int l = W[0];
    for(int i = 1; i < N; ++i) l = max(l,W[i]);
    int r = 1500000;
    int ans = r;
    while(l < r) {
      int m = (l+r)/2;
      int h = 1;
      for(int i = 0, space = 0; i < N; ++i) {
	if(space+W[i] > m) {
	  ++h;
	  space = W[i];
	} else {
	  space += W[i];
	}
      }
      if(h <= M) {
	ans = m;
	r = m;
      } else {
	l = m+1;
      }
    }
    cout << ans << endl;
  }
  return 0;
}