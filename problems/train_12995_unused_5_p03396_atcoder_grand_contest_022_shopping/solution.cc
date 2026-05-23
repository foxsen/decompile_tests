#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<vector>
#include<cstdio>
#include<queue>
#include<map>
#include<set>
#define MN 300000
#define ll long long
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int n,L,x[MN+5],t[MN+5],pre[MN+5],suf[MN+5];
priority_queue<int> q;
bool Solve(int s)
{
    while(q.size()) q.pop();
    memset(pre,0,sizeof(pre));memset(suf,0,sizeof(suf));
    int P=0,S=0;
    for(int i=1;i<=n;++i)
    {
        int a=(t[i]-1)/(2*L),b=(t[i]-1)%(2*L)+1;s-=a;
        int end1=2*(L-x[i])>=b?2:1;
        int end2=2*x[i]>=b?1:2;
        if(end1==end2)
        {
            if(end1==1) ++P,--pre[i];
            else ++suf[i];
        }
        else
        {
            if(end1==1) ++P,--pre[i],++suf[i];
            else ++P,--pre[i],q.push(i);
        }
    }
    for(int i=0;i<=n;++i)
    {
        P+=pre[i];S+=suf[i];
        while((P&&P+S>s-1)||S>s)
        {
            if(q.empty()||q.top()<=i) return false;
            int x=q.top();q.pop();//cout<<"Get"<<x<<endl;
            --P;++pre[x];++suf[x];
        }
    }
    return true;
}
int main()
{
    n=read();L=read();
    for(int i=1;i<=n;++i) x[i]=read();
    for(int i=1;i<=n;++i) t[i]=read();
    int l=1,r=1e9,mid,res;
    while(l<=r)
    {
        mid=l+r>>1;
        if(Solve(mid)) res=mid,r=mid-1;
        else l=mid+1;
    }
    printf("%lld\n",1LL*res*L*2);
    return 0;
}