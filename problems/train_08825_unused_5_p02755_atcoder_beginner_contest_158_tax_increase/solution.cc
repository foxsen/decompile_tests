#include <bits/stdc++.h>
using namespace std;
int main() {
  int a,b;cin>>a>>b;
  for (int i=1;i<=10000;i++){
    if (i*8/100==a&&i*10/100==b){
      cout<<i<<endl;
      return 0;
    }
  }
  cout<<-1<<endl;
  
}