#include<bits/stdc++.h>
using namespace std;
unordered_map<long long , int> um;

int main(){
  int N;cin >> N;
  vector<long long> V(N);
  for(auto&&e:V){
    cin >> e;
    um[e]++;
  }
  sort(V.begin(), V.end(), greater<long long>());
  int ans = 0;
  for(int i = 0; i < N; ++i){
    if(um[V[i]] < 1)continue;
    um[V[i]]--;
    long long nx = 1;
    while(nx <= V[i])nx<<=1;
    nx -= V[i];
    if(um.count(nx)==0)continue;
    int c = um[nx];
    if(c < 1)continue;
    um[nx]--;
    ans++;
  }
  cout << ans << endl;
  return 0;
}
