#include <bits/stdc++.h>
using namespace std;
constexpr int pDec[]={1,10,100,1000,10000,100000,1000000,10000000,100000000};
constexpr int fct[]={40320,5040,720,120,24,6,2,1};
constexpr int dif[]={-1,1,-3,3};
int makeHash(int num){
    int ans=0;
    int f=0;
    for(int i=0;i<8;i++){
        int tmp=num%10;
        // auto index=lower_bound(vDigit.begin(),vDigit.end(),tmp);
        // ans+=(index-vDigit.begin())*fct[i];
        //vDigit.erase(index);
        
        ans+=(tmp-__builtin_popcount(f&(1<<tmp)-1))*fct[i];
        f|=(1<<tmp);
        num/=10;
    }
    return ans;
}

int main(void){
    // cout<<makeHash(305147826)<<endl;
    // return 0;
    vector<int> vDigit{0,1,2,3,4,5,6,7,8};
    
    // int count=0;
    // do{
    //     int num=0;
    //     for(int i=9;i>0;i--){
    //         num+=pDec[i-1]*vDigit[9-i];
    //     }
    //     mp.emplace(num,count++);
    // }while(next_permutation(vDigit.begin(),vDigit.end()));
    // Your code here!
    int h,v;
    while(cin>>h>>v,h||v){
        int hv[]={h,h,v,v};
        int st=0;
        int end=0;
        int a;
        vector<bool> visited(362880,false);
        cin>>st;
        for(int i=0;i<8;i++){
            st*=10;
            cin>>a;
            st+=a;
        }
        cin>>end;
        for(int i=0;i<8;i++){
            end*=10;
            cin>>a;
            end+=a;
        }
        priority_queue<pair<int,int>> q;
        q.emplace(0,st);
        while(1){
            int pos=q.top().second;
            int cost=q.top().first;
            if(pos==end){
                cout<<-cost<<endl;
                break;
            }
            q.pop();
            int hash=makeHash(pos);
            if(visited[hash]){
                continue;
            }
            visited[hash]=true;
            int zero=to_string(pos+1000000000).find('0')-1;
            for(int i=0;i<4;i++){
                int s=pos,t=8-((zero+dif[i]+9)%9);
                int tmp=(pos/pDec[t])%10;
                s+=(pDec[8-zero]*tmp-pDec[t]*tmp);
                //cout<<tmp<<" "<<pos<<" "<<s<<endl;
                q.emplace(cost-hv[i],s);
            }
        }
    }
    return 0;
}

