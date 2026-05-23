#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
using namespace std;

int n,m,W,k,kt,w;
int weight[17];
int load[10001];
int memo[1<<17];

void memoize() {
    for(int i=1; i<(1<<k); ++i) {
        memo[i] = 1<<29;
        int sumw = 0;
        for(int j=0; j<k; ++j)
            if((i>>j)&1) sumw += weight[j];
        if(sumw <= W) {
            memo[i] = 1;
            continue;
        }

        for(int T=i&-i; T; T = (T-i)&i) {
            memo[i] = min(memo[T]+memo[i-T],memo[i]);
        }
    }
    memo[0] = 0;
    return;
}

int main() {
    cin>>n>>m>>W; m--;
    k = 0;
    for(int i=0; i<n; ++i) {
        cin>>kt;
        for(int j=0; j<kt; ++j) {
            cin>>weight[k+j];
            load[i] |= 1<<(k+j);
        }
        k += kt;
    }
    memoize();

    int have = 0,ans = 0,maxfloor = 0;
    for(int i=0; i<n; ++i)
        if(load[i] > 0) maxfloor = i;
    if(maxfloor == 0 ) {
        cout<<0<<endl;
        return 0;
    }

    ans += abs(m-maxfloor);
    for(int i=maxfloor; i>0; --i) {
        have |= load[i];
        ans += memo[have]*2-1;
    }
    cout<<ans<<endl;
    return 0;
}