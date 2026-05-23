#include <iostream>
using namespace std;

int main(){
  int n;
  int t[102];

  while(cin >> n, n){
    for(int i = 0; i < n; i++){
      cin >> t[i];
    }

    int x;
    cin >> x;

    int lo = 0;
    int hi = n - 1;
    int cnt = 0;

    while(lo <= hi){
      cnt++;
      int med = (lo + hi) / 2;

      if(t[med] == x) break;
      if(t[med] > x){
	hi = med - 1;
      }
      else{
	lo = med + 1;
      }
    }

    cout << cnt << endl;
  }
}