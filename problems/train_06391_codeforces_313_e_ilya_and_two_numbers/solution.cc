#include <bits/stdc++.h>
using namespace std;
long long n, m;
multiset<long long> Nums, FG, SG;
void input() {
  cin >> n >> m;
  for (long long i = 1; i <= n; i++) {
    long long a;
    cin >> a;
    FG.insert(a % m);
  }
  for (long long i = 1; i <= n; i++) {
    long long b;
    cin >> b;
    SG.insert(b % m);
  }
}
void solve() {
  for (long long i = 1; i <= n; i++) {
    long long FGF = *FG.rbegin();
    long long SGF = *SG.rbegin();
    multiset<long long>::iterator FGM = FG.lower_bound(m - SGF);
    multiset<long long>::iterator SGM = SG.lower_bound(m - FGF);
    if (FGM != FG.begin()) FGM--;
    if (SGM != SG.begin()) SGM--;
    if ((FGF + SGF) % m >= (FGF + *SGM) % m) {
      if ((SGF + FGF) % m >= (SGF + *FGM) % m) {
        Nums.insert((SGF + FGF) % m);
        FG.erase(FG.find(FGF));
        SG.erase(SG.find(SGF));
      } else {
        Nums.insert((SGF + *FGM) % m);
        FG.erase(FG.find(*FGM));
        SG.erase(SG.find(SGF));
      }
    } else {
      Nums.insert((FGF + *SGM) % m);
      FG.erase(FG.find(FGF));
      SG.erase(SG.find(*SGM));
    }
  }
}
void Ans() {
  for (multiset<long long>::reverse_iterator it = Nums.rbegin();
       it != Nums.rend(); ++it)
    cout << *it << " ";
  return;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  input();
  solve();
  Ans();
  return 0;
}
