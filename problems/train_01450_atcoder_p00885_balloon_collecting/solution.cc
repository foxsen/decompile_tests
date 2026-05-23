#include <bits/stdc++.h>
using namespace std;

// よこ, たて
vector<pair<int, int>> v;
int ok=100000000;
int ng=-1;
void msearch(int i, int p, int bn, int t, int x, int move){
    if(move<ok){
        if(i==v.size()){
            if(ok>move+x){
                ok=move+x;
            }
        }else if(x==0){
            if(t+v[i].first>v[i].second){
                if(ng<p){
                    ng=p;
                }
            }else{
                t=v[i].second;
                x=v[i].first;
                move+=v[i].first;
                msearch(i+1, p+1, bn+1, t, x, move);
            }
        }else{
            //cout<<"x: "<<x<<" bn: "<<bn<<" vfront: "<<v[i].first<<" "<<v[i].second<<" t: "<<t<<endl;
            if(abs(x-v[i].first)*(bn+1)+t<=v[i].second && bn<3){
                msearch(i+1, p+1, bn+1, v[i].second, v[i].first, move+abs(x-v[i].first));
            }
            if(t+x*(bn+1)+v[i].first>v[i].second){
                if(ng<p){
                    ng=p;
                }
            }else{
                msearch(i+1, p+1, 1, v[i].second, v[i].first, move+x+v[i].first);
            }
        }
    }
}

int main(void){
    // Your code here!
    int n;
    while(cin>>n,n){
        v.resize(n);
        for(auto& a:v){
            cin>>a.first>>a.second;
        }
        msearch(0, 1, 0, 0, 0, (unsigned long long)0);
        if(ok==100000000){
            cout<<"NG "<<ng<<endl;
        }else{
            cout<<"OK "<<ok<<endl;
        }
        v.clear();
        ok=100000000;
        ng=-1;
    }
}

