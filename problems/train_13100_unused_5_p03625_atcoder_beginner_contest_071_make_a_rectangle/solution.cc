#include <bits/stdc++.h>
using namespace std;

long v[1<<20],n,e1=0;

int main(){
    cin>>n;
    for(int i=0;i < n;i++)
    {
        cin>>v[i];v[i]*=-1;
    }

    sort(v,v+n);

    for(int i=0;i < n-1;i++)
    {
        if(v[i]==v[i+1]){
            if(e1){
                cout<<e1*v[i];return 0;
            }else{
                e1=v[i];
                i++;
            }
        }
    }
    cout<<0<<endl;

}