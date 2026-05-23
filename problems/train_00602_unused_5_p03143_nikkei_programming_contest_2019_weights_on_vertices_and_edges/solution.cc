#include <iostream>
#include <cstdio> 
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;
const int N=100010;
bool w[N];
int fa[N],pa[N];
vector <int> q[N];
long long a[N],b[N];
inline int gi() {
    int x=0,o=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') ch=='-'?o=-1:0,ch=getchar();
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*o;
}
struct Dat {
    int x,y,z;
    inline bool operator < (const Dat &A) const {return z<A.z;}
} g[N];
inline int find(int x) {return fa[x]==x?x:fa[x]=find(fa[x]);}
inline int get(int x) {return pa[x]==x?x:pa[x]=get(pa[x]);}
int main() {
    int n,m,ans;
    cin>>n>>m,ans=m;
    for(int i=1;i<=n;i++) a[i]=b[i]=gi(),fa[i]=pa[i]=i;
    for(int i=1;i<=m;i++) g[i].x=gi(),g[i].y=gi(),g[i].z=gi();
    sort(g+1,g+1+m);
    for(int i=1;i<=m;i++) {
	int x=find(g[i].x),y=find(g[i].y);
	if(x!=y) {
	    if(q[x].size()<q[y].size()) swap(x,y);
	    ++w[i],q[x].push_back(i);
	    fa[y]=x,a[x]+=a[y];
	    for(auto j:q[y]) q[x].push_back(j);
	    if(a[x]>=g[i].z) {
		for(auto j:q[x]) {
		    int X=get(g[j].x),Y=get(g[j].y);
		    pa[Y]=X,b[X]+=b[Y],--ans;
		}
		q[x].clear();
	    }
	}
    }
    for(int i=1;i<=m;i++)
	if(!w[i]&&b[get(g[i].x)]>=g[i].z) --ans;
    cout<<ans;
    return 0;
}