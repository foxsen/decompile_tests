#include <bits/stdc++.h>
using namespace std;

priority_queue<int, vector<int>, greater<int> > a;
priority_queue<int, vector<int>, greater<int> > b;
int main(){
  int h, w;
  cin >> h >> w;
  int tmp;
  for(int i = 0;i < h;i++){
    cin >> tmp;
    a.push(tmp);
  }

  for(int i = 0;i < w;i++){
    cin >> tmp;
    b.push(tmp);
  }

  long long ans = 0;
  while(!a.empty() && !b.empty()){
    if(a.top() < b.top()){
      ans += a.top() * (long long)(b.size());
      a.pop();
    }else{
      ans += b.top() * (long long)(a.size());
      b.pop();
    }
  }

  cout << ans << endl;
  return 0;
}

