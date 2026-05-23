#include <bits/stdc++.h>
using namespace std;
int n, q, lt, rt, a, b, place, arabayeri[1000009], sol[1000009], sag[1000009],
    temp2;
set<pair<int, pair<int, int> > > A;
pair<int, int> temp;
pair<int, pair<int, int> > f(int l, int r) {
  if (!l and r == n + 1) return make_pair(-1e9, make_pair(1, n + 1));
  if (!l) return make_pair(-r + 1, make_pair(1, r));
  if (r == n + 1) return make_pair(-n + l, make_pair(n, n + 1));
  return make_pair(-(r - l) / 2, make_pair((r + l) / 2, r));
}
int main() {
  cin >> n >> q;
  A.insert(f(0, n + 1));
  sag[0] = n + 1;
  sol[n + 1] = 0;
  for (int i = 1; i <= q; i++) {
    cin >> a >> b;
    if (a == 1) {
      temp = A.begin()->second;
      A.erase(A.begin());
      place = temp.first;
      rt = temp.second;
      lt = sol[rt];
      sol[place] = lt;
      sag[place] = rt;
      sol[rt] = sag[lt] = place;
      cout << place << endl;
      arabayeri[b] = place;
      A.insert(f(lt, place));
      A.insert(f(place, rt));
    }
    if (a == 2) {
      temp2 = arabayeri[b];
      lt = sol[temp2];
      rt = sag[temp2];
      sol[rt] = lt;
      sag[lt] = rt;
      A.erase(f(lt, temp2));
      A.erase(f(temp2, rt));
      A.insert(f(lt, rt));
    }
  }
}
