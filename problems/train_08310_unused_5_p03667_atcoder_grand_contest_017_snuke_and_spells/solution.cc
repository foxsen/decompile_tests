#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
const int M = 2e5 + 10;
int a[M] , vis[M] , cnt[M];
int main() {
    int n , m;
    scanf("%d%d" , &n , &m);
    int ans = n;
    for(int i = 1 ; i <= n ; i++) {
        scanf("%d" , &a[i]);
        cnt[a[i]]++;
        int pos = a[i] - cnt[a[i]];
        if(pos >= 0) {
            if(!vis[pos]) ans--;
            vis[pos]++;
        }
    }
    while(m--) {
        int x , y;
        scanf("%d%d" , &x , &y);
        int pos = a[x] - cnt[a[x]];
        if(pos >= 0) {
            vis[pos]--;
            if(!vis[pos]) ans++;
        }
        cnt[a[x]]--;
        a[x] = y;
        cnt[a[x]]++;
        pos = a[x] - cnt[a[x]];
        if(pos >= 0) {
            if(!vis[pos]) ans--;
            vis[pos]++;
        }
        printf("%d\n" , ans);
    }
    return 0;
}