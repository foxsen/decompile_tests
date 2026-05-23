//#include <bits/stdc++.h>
#include <string>
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <utility>
#include <climits>

using namespace std;
using ll=long long;

void solve(){
  while(true){
    string str;
    cin >> str;
    if(str=="#")return;
    int y,m,d;
    cin >> y >> m >> d;
    if(y<31||(y==31&&m<5))
      cout << "HEISEI " << y << " " << m << " " << d << endl;
    else
      cout << "? " << y-30 << " " << m << " " << d << endl;
    
    

  }
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}

