#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i ,n) for(int i = 0; i < (int)(n); i++)

int main(){
  int N;
  string S;
  cin >> N >> S;
  
  int cnt = 0;
  rep(i,1000){
    int c[3] = {i/100, (i/10)%10, i%10};
    int f = 0;
    rep(j,N){
      if(S[j] == ('0' + c[f])) f++;
      if(f == 3){
        cnt++;
        break;
      }
    }
  }
  
  cout << cnt << endl;  
}