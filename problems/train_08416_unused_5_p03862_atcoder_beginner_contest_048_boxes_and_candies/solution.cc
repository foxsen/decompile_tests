#include <bits/stdc++.h>
using namespace std;
 
int main() {
  long long N,x;
  cin >> N >> x;
  vector<long long> a(100010);
  for(long long i=0;i<N;i++){cin >> a[i];}
  long long count=0;
  if(a[0]>x){count+=a[0]-x; a[0]=x;}
  for(long long i=1;i<N;i++){
    if(a[i-1]+a[i]>x){
      count+=a[i-1]+a[i]-x;
      a[i]-=a[i-1]+a[i]-x;
    }
  }
  cout << count << endl;
}