#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  int ans[100000] = {0};
  for(int i = 1;i*i<=n;i++){
    for(int j = 1;j*j<=n;j++){
      for(int k = 1;k*k<=n;k++){
        int total = i*i+k*k+j*j+i*j+i*k+j*k;
        ans[total]++;
      }
    }
  }
  for(int i = 1; i <=n;i++){
    cout << ans[i] << endl;
  }
}
