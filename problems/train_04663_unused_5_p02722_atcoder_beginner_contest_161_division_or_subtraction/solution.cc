#include <bits/stdc++.h>
using namespace std;

int main(){
  int64_t N;
  cin >> N;

  unordered_set<int64_t> divs;

  // 2以上であるN-1の約数,
  // Nの約数の一部を(N自身とsqrt(N)以下のものを試して)追加
  divs.insert(N);
  if(N-1 > 1){ divs.insert(N-1); }
  int64_t div= 2;
  while(div*div <= N){
    int cnt= 0;
    int64_t tmp= N;
    while(tmp%div==0){
      cnt++;
      tmp/= div;
    }
    if(tmp%div==1){
      divs.insert(div);
      if(cnt==0){ divs.insert((N-1)/div); }
    }

    div++;
  }
  
  cout << divs.size() << endl;
}