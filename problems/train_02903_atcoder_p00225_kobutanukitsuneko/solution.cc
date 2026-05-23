#include<bits/stdc++.h>
using namespace std;

int N;
string s[10000];


//UnionFind-----------------------------
int par[26],sz[26];
void init(){
    for(int i=0;i<26;i++){
        par[i]=i;
        sz[i]=1;
    }
}
int find(int x){
    return x==par[x]?x:par[x]=find(par[x]);
}
void unite(int x,int y){
    x=find(x);y=find(y);
    if(x==y)return;

    if(sz[x]<sz[y])swap(x,y);
    par[y]=x;
    sz[x]+=sz[y];
}
//--------------------------------------


void solve(){
    int in[26]={0};
    int out[26]={0};

    init();
    for(int i=0;i<N;i++){
        int o=s[i][0]-'a';
        int e=s[i][s[i].size()-1]-'a';

        in[o]++;
        out[e]++;
        unite(o,e);
    }

    int cnt=0;

    for(int i=0;i<26;i++){
        if(in[i]!=out[i]){
            cout<<"NG"<<endl;
            return;
        }

        if(in[i]&&i==par[i])cnt++;
    }

    if(cnt>1){
        cout<<"NG"<<endl;
        return;
    }
    cout<<"OK"<<endl;

}

int main(){
    cin.tie();
    ios_base::sync_with_stdio(false);
    
    while(cin>>N,N){
        for(int i=0;i<N;i++)cin>>s[i];
        solve();
    }
    return 0;
}