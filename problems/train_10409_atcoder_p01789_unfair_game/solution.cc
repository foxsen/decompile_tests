#include <bits/stdc++.h>
#define int long long
#define N 100010
using namespace std;
const int INF = 1LL<<55;
int Max(int &a,int b){return a=max(a,b);}
int Min(int &a,int b){return a=min(a,b);}
int n,A,B,stone[N];
 
signed main(){
  cin>>n>>A>>B;
  for(int i=0;i<n;i++) cin>>stone[i];
  sort(stone,stone+n);
 
  int ans = 0;
  if( A == B || stone[n-1]<=min(A,B)) for(int i=0;i<n;i++) ans ^= stone[i]%(A+1);
  else if( A > B ) ans = 1;
  else if(stone[n-1]-A > A || stone[n-2] > A || n == 1) ans = 0;
  else {
    int sum = 0;
    for(int i=0;i<n-1;i++) sum ^= stone[i];
    if(sum == 0) sum = A;
    int x = stone[n-1] - sum;
    ans = sum >= stone[n-1]-A && stone[n-1]-x <= A;

  }
  
  cout<<(ans? "Hanako":"Jiro")<<endl;
  return 0;
}