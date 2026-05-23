#include <bits/stdc++.h>
using namespace std;

int main() {
  string n;
  cin >> n;
  int ans = 0;
  int moveUp = 0;
  for(int i = n.length()-1; i >= 0; i--){
    int num = (int)n.at(i) -'0' + moveUp;
    if(num < 5){
      ans += num;
      moveUp = 0;
    }else if(num == 5){
      ans += num;
      moveUp = (((int)n[i-1] - '0' > 4) ? 1 : 0);
    }else{
      ans += 10 - num;
      moveUp = 1;
    }
  }
  cout << ans + moveUp << endl;
}
