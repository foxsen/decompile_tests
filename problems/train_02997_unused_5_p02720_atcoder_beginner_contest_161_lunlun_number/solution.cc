#include <bits/stdc++.h>
using namespace std;

int main(){
  int k;
  cin >> k;
  queue<long long> lun;
  for(int i=1;i<10;i++){
    lun.push(i);
  }
  for(int i=1;i<k;i++){
    long long x=lun.front();
    lun.pop();
    if(x%10!=0) lun.push(x*10+x%10-1);
    lun.push(x*10+x%10);
    if(x%10!=9) lun.push(x*10+x%10+1);
  }
  cout << lun.front() << endl;
}