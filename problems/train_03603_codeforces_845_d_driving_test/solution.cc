#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
using ll = long long;
using vll = vector<ll>;
using vpi = vector<pair<int, int>>;
int main() {
  ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  int speedlim = 301;
  bool overtake = true;
  int speed = -1;
  int noovertakes = 0;
  vi speedsigns(302, 0);
  int ignore = 0;
  for (int i = 0; i < n; ++i) {
    int t;
    cin >> t;
    switch (t) {
      case 1:
        int newspeed;
        cin >> newspeed;
        assert(newspeed <= 300 && newspeed >= 1);
        if (newspeed > speed && newspeed > speedlim) {
          ignore += speedsigns[newspeed];
          for (int i = newspeed + 1; i < speedsigns.size(); ++i) {
            speedsigns[i] -= speedsigns[newspeed];
          }
          for (int i = 0; i <= newspeed; ++i) {
            speedsigns[i] = 0;
          }
        }
        speed = newspeed;
        break;
      case 2:
        if (!overtake) {
          ignore += noovertakes;
          noovertakes = 0;
        }
        break;
      case 3:
        int newspeedlim;
        cin >> newspeedlim;
        assert(newspeedlim <= 300 && newspeedlim >= 1);
        if (newspeedlim < speed)
          ++ignore;
        else {
          for (int i = 0; i <= newspeedlim; ++i) speedsigns[i] = 0;
          for (int i = newspeedlim + 1; i < speedsigns.size(); ++i)
            ++speedsigns[i];
        }
        speedlim = newspeedlim;
        break;
      case 4:
        overtake = true;
        noovertakes = 0;
        break;
      case 5:
        speedlim = 301;
        for (int& si : speedsigns) si = 0;
        break;
      case 6:
        overtake = false;
        ++noovertakes;
        break;
    }
  }
  cout << ignore << "\n";
}
