#include <bits/stdc++.h>
using namespace std;
 typedef long long ll;


int main(){
ll N,M;
cin>>N>>M;
vector<pair<ll, ll>> a(N);
for(int i = 0;i<N;i++){
ll A, B;
cin >> A >> B;
a[i].first=A;
a[i].second=B;
}
sort(a.begin(),a.end());
ll ans = 0;
for(int i = 0;i<N&&M>0;i++){
ans+=a[i].first*min(M,a[i].second);
M-=a[i].second;
}
cout<<ans<<endl;

}