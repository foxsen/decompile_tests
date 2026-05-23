#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  int k=0;
  for(int i=0;i<n;i++){
    int a;
    cin >> a;
    if(a%2) k++;
  }
  if(k%2) cout << "NO" << endl;
  else cout << "YES" << endl;
}