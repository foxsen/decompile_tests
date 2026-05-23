#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N; cin >> N;
    vector<int> sum(N,0),Min(N,0);
    int Sum=0;
    for (int i=0;i<N;++i){
        string S; cin >> S;
        for (int j=0;j<S.size();++j){
            sum[i]+=(S[j]=='('?1:-1);
            Min[i]=min(Min[i],sum[i]);
        }
        Sum+=sum[i];
    }
    int ans=1;
    if (Sum!=0) ans=0;
    vector<pair<int,int>> v1,v2;
    Sum=0;
    for (int i=0;i<N;++i){
        if (Min[i]>=0) Sum+=sum[i];
        else if (sum[i]>=0) v1.emplace_back(-Min[i],sum[i]);
        else v2.emplace_back(Min[i]-sum[i],Min[i]);
    }
    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());
    for (auto p:v1){
        if (Sum-p.first<0) ans=0;
        Sum+=p.second;
    }
    for (auto p:v2){
        int M=p.second,s=M-p.first;
        if (Sum+p.second<0) ans=0;
        Sum+=p.second-p.first;
    }
    cout << (ans?"Yes":"No") << '\n';
}