#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int N;
int a[100001];
int Min,ans;
int main(){
  
  cin >> N;
  for(int i=0;i<N;i++)cin >> a[i];
  sort(a,a+N);
  ans=a[0];
  Min=a[N-1];
  for(int i=0;i<N-1;i++){
    int z=abs((a[N-1]-a[i]) - (a[N-1]+1)/2);
    if(z<=Min) {Min=z;ans=a[i];}
  }
  printf("%d %d\n",a[N-1],ans);
  return 0;
}
