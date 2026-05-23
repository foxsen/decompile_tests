#include <bits/stdc++.h>
#define LL long long 
using namespace std;
const int maxn=1e5+5;
struct node
{
    LL a, b, c;
    bool operator <(const node & A) const
    {
        return (a-b)<A.a-A.b;
    }
}p[maxn];
LL lef[maxn];

priority_queue<LL, vector<LL>, greater<LL> >q;



int main()
{
    int x, y, z;
    cin>>x>>y>>z;
    int i, j, n=x+y+z;
    LL base=0;
    for(i=1; i<=n; i++)
    {
        scanf("%lld%lld%lld", &p[i].a, &p[i].b, &p[i].c);
        base+=p[i].c;
    }
    sort(p+1, p+1+n);
    LL ans=0, sum=0;
    for(i=1; i<=y; i++)
    {
        sum+=p[i].b-p[i].c;
        q.push(p[i].b-p[i].c);
    }
    for(i=y+1; i<=n-x+1; i++)
    {
        lef[i]=sum;
        sum+=p[i].b-p[i].c;
        q.push(p[i].b-p[i].c);   
        sum-=q.top();
        q.pop();
    }

    while(q.empty()==0)q.pop();
    sum=0;
    for(i=n; i>=n-x+1; i--)
    {
        sum+=p[i].a-p[i].c;
        q.push(p[i].a-p[i].c);
    }

    for(; i>=y; i--)
    {
        ans=max(ans, base+lef[i+1]+sum);
   //     printf("%d %lld %lld %lld\n", i, base, lef[i+1], sum);
        sum+=p[i].a-p[i].c;
        q.push(p[i].a-p[i].c);
        sum-=q.top();
        q.pop();
    }
    printf("%lld\n", ans);
}
