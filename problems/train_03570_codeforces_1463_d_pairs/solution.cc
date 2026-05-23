#pragma GCC optimize (3)
#include<vector>
#include<stack>
#include<bitset>
#include<cstdlib>
#include<cmath>
#include<set>
#include<list>
#include<deque>
#include<map>
#include<queue>
#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<functional>
#include<cassert>
#include<numeric>
#include<algorithm>
#include<cctype>
#include<ctime>
#include<unordered_map>
/*#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/hash_policy.hpp>
#include<ext/pb_ds/trie_policy.hpp>
#include<ext/pb_ds/priority_queue.hpp>*/
//#include<ext/rope>
#define ll long long
#define ull unsigned long long
#define INFI 2147483647
#define INFL 9223372036854775807
#define INFU 18446744073709551615
#define maxn 200005
using namespace std;
//using namespace __gnu_pbds;
//using namespace __gnu_cxx;
const double PI=acos(-1.0);
const double eps=1e-6;
bool vis[2*maxn];
int a[maxn];
inline int read()
{
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0' || ch>'9'){
        if(ch=='-') f=-1;
        ch=getchar();
    }
    while(ch>='0' && ch<='9'){
        x=x*10+ch-'0';
        ch=getchar();
    }
    return x*f;
}
signed main()
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    //cout.tie(0);
    int T=read();
    while(T--){
        int n=read();
        for(int i=0;i<=2*n+1;i++) vis[i]=0;
        for(int i=1;i<=n;i++){
            a[i]=read();
            vis[a[i]]=1;
        }
        if(n==1){
            cout<<1<<endl;
            continue;
        }
        int s=0,mx=0,mn=0;
        for(int i=1;i<=2*n;i++){
            if(vis[i]) s++;
            else s--;
            mx=max(mx,s);
            mn=min(mn,s);
        }
        cout<<n-(mx-mn)+1<<endl;
    } 
    return 0;
}