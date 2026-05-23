#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<set>

#define MAX 60

using namespace std;

int N,ans[MAX],remain[14];
bool found;

void rec(int sum,int cnt)
{

  if(found)return;

  if(cnt >= N){
    for(int i=N-1;i>=0;i--){
      if(i != N-1)cout << " ";
      cout << ans[i];
    }
    cout << endl;

    found = true;

    return;
  }

  for(int i=1;i<=13;i++){
    if( remain[i] <= 0 )continue;
    if( ( sum - i ) % i == 0 ){

      remain[i]--;
      ans[cnt] = i;
      rec(sum-i,cnt+1);
      if(found)return;
      remain[i]++;

    }
  }
}

int main(){

  while(cin >> N,N){

    for(int i=0;i<14;i++)remain[i] = 0;

    int c[N+1],sum = 0;
    for(int i=0;i<N;i++){
      cin >> c[i];
      sum += c[i];
      remain[c[i]]++;
    }

    sort(c,c+N);

    found = false;
    rec(sum,0);

    if(!found){
      cout << "No" << endl;
    }
      
  }
  return 0;
}

/*
void rec(int sum,int limit,int *c,int cnt){

  if(found)return;

  if(limit <= 0){

    for(int i=N-1;i>=0;i--){
      if(i != N-1)cout << ' ';
      cout << ans[i];
    }
    cout << endl;

    found = true;

    return;
  }

  for(int i=0;i<limit;i++){
    if( (sum-c[i]) % c[i] == 0){
      ans[cnt] = c[i];

      int sub = c[i];
      swap(c[i],c[limit-1]);
      rec(sum-sub,limit-1,c,cnt+1);
      if(found)return;
      swap(c[i],c[limit-1]);

    }
  }
}
*/