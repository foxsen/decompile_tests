#include<iostream>
#include<algorithm>
using namespace std;
int main(){
  int n, m;
  cin >> n >> m;
  int r=n, l=1, a, b;
  for(int i=0;i<m;i++){
    cin >> a >> b;
    l=l>a?l:a;
    r=r>b?b:r;
  }
  cout << max(r-l+1,0) << endl;
}