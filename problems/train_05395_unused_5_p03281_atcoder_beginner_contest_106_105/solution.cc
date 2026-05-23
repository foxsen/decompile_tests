#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,ans=0,cnt=0;
  cin >> N;
  for(int i=1;i<=N;i+=2){
    cnt=0;
    for(int j=1;j<=N;j++){
      if(i%j==0) cnt++;
    }
    if(cnt==8) ans++;
  }
  cout << ans << endl;
}