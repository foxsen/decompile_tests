#include<bits/stdc++.h>
using namespace std;

int main() {
    int N, x;
    cin>>N>>x;
    vector<int> a(N);
    for(int i=0; i<N; i++) cin>>a[i];
    sort(a.begin(), a.end());
    int n;
    for(n=0; n<N && x>0; n++) x-=a[n];
    if(x!=0) n-=1;
    cout<<n<<endl;

    return 0;
}