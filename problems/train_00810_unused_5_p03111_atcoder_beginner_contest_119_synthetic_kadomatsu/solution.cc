#include <bits/stdc++.h>
using namespace std;

int INF=10000000;
int N,A,B,C;
vector<int> L;

int rec(int i, int a, int b, int c){
    if(i==N){
        if(!a||!b||!c) return INF;
        return abs(a-A)+abs(b-B)+abs(c-C);
    }
    
    int res=rec(i+1,a,b,c);
    res=min(res, rec(i+1, a + L[i], b, c) + (a ? 10 : 0));
    res=min(res, rec(i+1, a, b + L[i], c) + (b ? 10 : 0));
    res=min(res, rec(i+1, a, b, c + L[i]) + (c ? 10 : 0));
    
    return res;
}



int main(void){
    cin>>N>>A>>B>>C;
    L.resize(N);
    for(int i=0;i<N;i++) cin>>L[i];
    
    cout<<rec(0,0,0,0)<<endl;
    
}