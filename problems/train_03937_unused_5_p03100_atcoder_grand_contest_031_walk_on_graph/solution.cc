#include<cstdio>
#define K 1000001
#define M 50005
#define N 300003
inline int abv(int x){return x<0?-x:x;}
int gcd(int x,int y){return y?gcd(y,x%y):x;}
int a[M],b[M],c[M],f[N],h,i,j,k,m,n,o,p,q,s[N];bool g[2][K];
int find(int u){return f[u]==u?u:f[u]=find(f[u]);}
inline void merge(int u,int v){if((u=find(u))!=(v=find(v)))s[u]<s[v]?u^=v^=u^=v:0,s[f[v]=u]+=s[v];}
inline bool check(int u,int v,int w)
{
    for(j=0;j<2;j++)for(k=0;k<3;k++)if(g[j][(w+(3-k)*o)%p]&&find((u-1)*6)==find((v-1)*6+3*j+k))return true;
    return false;
}
int main()
{
    scanf("%d%d%d%d",&n,&m,&q,&p);
    for(i=1;i<=m;i++)scanf("%d%d%d",a+i,b+i,c+i),o=gcd(abv(c[i]-c[1]),o);
    for(i=1,o=!o?p:o,p=gcd(p,3*o),h=c[1]%o;i<=m;i++)c[i]=c[i]/o%3;
    for(i=0;i<6*n;i++)s[f[i]=i]=1;
    for(i=0,j=h%p;!g[i][j];j=(j<<1)%p,i^=1)g[i][j]=true;
    for(i=1;i<=m;i++)merge((a[i]-1)*6,(b[i]-1)*6+3+c[i]),merge((a[i]-1)*6+1,(b[i]-1)*6+3+(2+c[i])%3),merge((a[i]-1)*6+2,(b[i]-1)*6+3+(1+c[i])%3),merge((a[i]-1)*6+3,(b[i]-1)*6+c[i]),merge((a[i]-1)*6+4,(b[i]-1)*6+(2+c[i])%3),merge((a[i]-1)*6+5,(b[i]-1)*6+(1+c[i])%3);
    for(int u,v,w;q--;)scanf("%d%d%d",&u,&v,&w),puts(check(v,u,(w+h)%p)?"YES":"NO");
    return 0;
}