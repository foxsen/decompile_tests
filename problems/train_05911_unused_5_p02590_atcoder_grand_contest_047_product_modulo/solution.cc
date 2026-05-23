#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int mod=200003,G=5,N=8e5+50;
const double pi=acos(-1);
int n,id[N],r[N],lim=1,val[N];LL ans;
struct node{
    double x,y;
    node friend operator +(node a,node b){return node{a.x+b.x,a.y+b.y};}
    node friend operator -(node a,node b){return node{a.x-b.x,a.y-b.y};}
    node friend operator *(node a,node b){return node{a.x*b.x-a.y*b.y,a.x*b.y+a.y*b.x};}
}c[N];
void FFT(node *a,int n,int op){
    for(int i=0;i<n;i++)r[i]=r[i>>1]>>1^(i&1?n>>1:0);
    for(int i=0;i<n;i++)if(i<r[i])swap(a[i],a[r[i]]);
    for(int i=1;i<n;i<<=1){
        node Wn=node{cos(pi/i),sin(pi/i)};
        for(int j=0;j<n;j+=i<<1){
            node w=node{1,0};
            for(int k=0;k<i;k++,w=w*Wn){
                node x=a[j+k],y=a[i+j+k]*w;
                a[j+k]=x+y;a[i+j+k]=x-y;
            }
        }
    }
    if(op==-1){
        reverse(a+1,a+n);
        for(int i=0;i<n;i++)a[i].x/=n;
    }
}
int power(int x,int y){
    int z=1;
    for(;y;y>>=1,x=1ll*x*x%mod)if(y&1)z=1ll*z*x%mod;
    return z;
}
int main(){
    for(int i=1,j=0;j<mod-1;i=1ll*i*G%mod,j++)id[i]=j,val[j]=i;
    scanf("%d",&n);
    for(int i=1,x;i<=n;i++){
        scanf("%d",&x);
        ans-=1ll*x*x%mod;
        if(x)c[id[x]].x++;
    }
    while(lim<mod*2)lim<<=1;
    FFT(c,lim,1);
    for(int i=0;i<lim;i++)c[i]=c[i]*c[i];
    FFT(c,lim,-1);
    for(int i=0;i<mod*2;i++)
        ans+=(LL)(c[i].x+0.5)*val[i%(mod-1)];
    cout<<ans/2;
    return 0;
}