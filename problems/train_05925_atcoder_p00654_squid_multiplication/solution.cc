#include<cstdio>
#include<algorithm>
#include<vector>
#include<cmath>

#define MAXX 65555

unsigned long long gcd(const unsigned long long &a,const unsigned long long &b)
{
    return b?gcd(b,a%b):a;
}

unsigned long long n,i,j,k,m;
unsigned long long num[MAXX],g;
std::vector<unsigned long long>ev,od;

int main()
{
    ev.reserve(MAXX);
    od.reserve(MAXX);
    while(scanf("%llu",&n),n)
    {
        m=n*(n+1)/2;
        ev.resize(0);
        od.resize(0);
        for(i=0;i<m;++i)
        {
            scanf("%llu",num+i);
            if(!(num[i]&1))
                ev.push_back(num[i]);
            else
                od.push_back(num[i]);
        }
        std::sort(ev.begin(),ev.end());
        std::sort(od.begin(),od.end());
        g=ev[0];
        for(i=1;i<ev.size();++i)
            g=gcd(g,ev[i]);
        k=od[0]/(ev[0]/g)/(ev[1]/g);
        g/=sqrt(k);
        printf("%llu\n%llu",g,ev[0]/g);
        for(i=1;i<ev.size();++i)
            printf(" %llu",ev[i]/g);
        puts("");
    }
    return 0;
}