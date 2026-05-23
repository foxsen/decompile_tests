#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define debug(x) cout<<#x<<" : "<<x<<'\n';
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) {
        int n,k;
        cin>>n;
        vector<vector<int> > a(n+1);
        map<int,int > Q;
        int tot=0;
        for(int i=0;i<n;i++) {
            cin>>k;
            a[i].resize(k);
            int flag=0;
            for(int j=0;j<k;j++) {
                int tmp;
                cin>>tmp;
                if(Q[tmp]!=0) {
                    a[i][j] = Q[tmp];
                } else {
                    a[i][j] = ++tot;
                    Q[tmp] = tot;
                }
            }
            sort(a[i].begin(),a[i].end());
        }
        vector<vector<int > > f(tot+1);
        for(int i=0;i<n;i++) {
            for(auto it:a[i]) {
                f[it].push_back(i);
            }
        }
        int ff=0;
        vector<int > pos(tot+1,-1);
        vector<int > last(tot+1,-1);
        for(int i=1;i<=tot;i++) { //针对每个, 所包含的每个集合都已经有一个联系
            for(auto it:f[i]) {   
                if(a[it].size()>100) continue; //处理小集合
                for(int j=0;a[it][j]<i;j++) {
                    if(last[a[it][j]] == i) {  //是否能再建立一个联系 类似离散化？
                        cout<< pos[a[it][j]]+1 << " " << it+1 << "\n";
                        ff=1;
                        break;
                    }else {
                        last[a[it][j]] = i;
                        pos[a[it][j]] = it;
                    }
                }
                if(ff) break;
            }
            if(ff) break;
        }
        if(ff) continue;
        vector<bool > vis(tot+1);
        //大范围暴力
        for(int i=0;i<n;i++) {
            if(a[i].size()<=100) continue;
            for(auto it:a[i]) vis[it]=1;
            for(int j=0;j<n;j++) {
                if(i==j) continue;
                int num=0;
                for(auto it:a[j]) {
                    num+=vis[it];
                }
                if(num>=2) {
                    cout<< i+1 <<" "<<j+1<<"\n";
                    ff=1;
                    break;
                }
            }
            if(ff) break;
            for(auto it:a[i]) vis[it]=0;
        }
        if(!ff) cout<<"-1\n";
    }
}