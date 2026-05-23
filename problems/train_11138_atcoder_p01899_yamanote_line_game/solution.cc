#include<iostream>
using namespace std;
int main(){
  int a,n,d,c=0;
  cin >> n >> d;
  for(int i=0;i<n;i++) {
    cin >> a;
    if(a>d)c+=a-d;
  }
  if(c==0)cout << "kusoge" << endl;
  else cout << c << endl;
  return 0;
}