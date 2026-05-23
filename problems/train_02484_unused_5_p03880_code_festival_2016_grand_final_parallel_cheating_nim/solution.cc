#include <iostream>
#include <vector>
using namespace std;

bool exist[200];
int a[100005];
vector<int> b;
int ans;
int main() {
  int n;
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> a[i];
  }

  int tmp = 0;
  for(int i = 0; i < n; i++) {
    tmp ^= a[i];
    int k = 0;
    int t = a[i];
    while(t % 2 == 0) {
      t /= 2;
      k++;
    }
 
    exist[k] = true;
  }

  while(tmp > 0) {
    b.push_back(tmp % 2);
    // cout << tmp % 2 << endl;
    tmp /= 2;
  }

  int i = b.size() - 1;
  while(i >= 0) {
    //cout << "iii = "<<i<<endl;
    if(exist[i]) ans++;
    else {
      cout << -1 << endl;
      return 0;
    }
    while(i >= 0 && b[i] == 1) {
      i--;
    }
    if(i < 0) break;
    // cout << "i = "<<i<<endl;
    if(exist[i]) ans++;
    else {
      cout << -1 << endl;
      return 0;
    }
    while(i >= 0 && b[i] == 0) {
      i--;
    }
    if(i < 0) break;
  }

  cout << ans << endl;
}
    
