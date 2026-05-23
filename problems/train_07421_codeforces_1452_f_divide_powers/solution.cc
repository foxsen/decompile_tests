#include<iostream>
#include<cstdio>
#include<set>
#include<map>
#include<vector>
#include<cstring>
#include<string>
#include<cstdlib>
#include<algorithm>
#include<queue>
#include<iomanip>
#include<stack>
#include<cmath>

 
using namespace std;
 
 
#ifndef POJ
    #define Cpp11
#endif
 
#ifdef Cpp11
    #define _for(i,a,b) for(auto i = (a);i<(b);++i)
    #define _rep(i,a,b) for(auto i = (a);i<=(b);++i)
    #define _dep(i,a,b) for(auto i = (a);i>=(b);--i)
    #define mt(a,b,c) make_tuple(a,b,c) 
    #include<ctime>
    #include<random>
    #include<chrono>
    #include<limits>
    #include<complex>
    #include<unordered_set>
    #include<unordered_map>
    #include<cassert>
    #include<functional>
    #include<bitset>
    #define IO ios::sync_with_stdio(false);cout.tie(nullptr);cin.tie(nullptr);
#endif
 
#ifndef Cpp11
    #define _for(i,a,b) for(int i = (a);i<(b);++i)
    #define _rep(i,a,b) for(int i = (a);i<=(b);++i)
    #define _dep(i,a,b) for(int i = (a);i>=(b);--i)
    #define IO ios::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL);
#endif
 
 
using namespace std;


 
#define fr first
#define sc second
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
#define sci(x) scanf("%d",&(x))
#define scl(x) scanf("%lld",&(x))
#define debugline fprintf(stderr,"-----------------------\n");
#define szint(x) ((int)(x).size())

 
#ifdef I128IO
typedef __int128 SPLL;
char buff[200];
template<typename T>
void read(T& o)
{
    o = 0;
    scanf("%s",buff);
    //printf("%s\n",buff);
    T f = 1;
    int i = 0;
 
    if(buff[0]=='-')i++,f = -1;
    for(;buff[i];++i)
    {
        o*=10,o+=buff[i]-'0';
    }
    o*=f;
}
 
template<typename T>
void write(T o)
{
    int len = 0;
    buff[0] = '0';
    if(o==0)
    {
        putchar('0');
        return;
    }
    int f = 1;
    if(o<0) f = -1;
    o*=f;
    for(;o;o/=10) buff[len++] = o%10+'0';
    if(f==-1) buff[len++] = '-';
    reverse(buff,buff+len);
    buff[len++] ='\0';
    printf("%s",buff);
}
#endif
 
#ifdef FIO
char buff[100];
template<typename T>
void read(T& o)
{
    o = 0;
    scanf("%s",buff);
    //printf("%s\n",buff);
    T f = 1;
    int i = 0;
    if(buff[0]=='-')i++,f = -1;
    for(;buff[i];++i)
    {
        o*=10,o+=buff[i]-'0';
    }
    o*=f;
}
template<typename T>
void write(T o)
{
    int len = 0;
    buff[0] = '0';
    if(o==0)
    {
        putchar('0');
        return;
    }
    int f = 1;
    if(o<0) f = -1;
    o*=f;
    for(;o;o/=10) buff[len++] = o%10+'0';
    if(f==-1) buff[len++] = '-';
    reverse(buff,buff+len);
    buff[len++] ='\0';
    printf("%s",buff);
}
#endif

#define OIreader


#ifdef OIreader
inline int read(){
    char ch; bool sign=0; int res=0;
    while(!isdigit(ch=getchar()))if(ch=='-')sign=1;
    while(isdigit(ch))res=res*10+(ch^48),ch=getchar();
    if(sign)return -res; else return res;
}
#endif

#ifdef _Random_
    mt19937 __MT(chrono::system_clock::now().time_since_epoch().count());
#endif
 
#ifndef BigNumber
    typedef unsigned long long uLL;
    typedef long long LL;
    typedef long long ll;
    typedef pair<LL,LL> pLL;
    typedef vector<LL> vL;
    typedef vector<vL> vLL;
#endif


typedef unsigned int uit; 
typedef vector<int> vi;
typedef vector<vi> vii;
typedef vector<vii> viii;
typedef pair<int,int> pii;
typedef vector<uit> vuit;


// Sorry I must be yellow!!!!!


const int maxn = 30+10;
const LL MAXN = 100000;
const LL inf = 1e18;
const int MAXM = 3;
const int maxm = 400000+10;
const LL MOD[] = {469762049,998244353,1004535809,1000000007};// For triple NTT
const LL mod = 1e9+7;
const int apsz = 26;

LL cnt[maxn],n;



LL dfs(LL need,LL d)
{
    if(need<=0||d==0)return 0;
    if(need<(1<<(d-1)))
    {
        return 1+dfs(need,d-1);
    }
    return dfs(need-(1<<(d-1)),d-1)+(1<<(d-1));
}

inline void print()
{
    _for(i,0,n)
    {
        cout<<cnt[i]<<" ";
    }
    cout<<endl;
}


inline LL solve(LL x,LL k)
{
    LL ans = 0;
    LL tmp = k;
    LL has = 0;
    int now;
    _for(i,0,n)
    {
        tmp-=cnt[i]*(1<<i);
    }
    if(tmp>0)return -1;
    tmp = k,ans = 0;
    _rep(i,0,x) tmp-=cnt[i];
    if(tmp<=0)return 0;
    tmp = k;
    _rep(i,0,x) k-=cnt[i];
    _rep(i,1,x) has+=((1<<i)-1)*cnt[i];
    for(now = x+1;now<n;++now)
    {
        LL tot = cnt[now]*(1<<(now-x));
        if(tot<=k)
        {
            ans+=cnt[now]*((1<<(now-x))-1);
            k-=tot;
            has+=cnt[now]*((1<<(now-x))*((1<<x)-1));
        }
        else
        {
            LL c = k/(1<<(now-x));
            ans+=c*((1<<(now-x))-1);
            k%=(1<<(now-x));
            has+=c*((1<<(now-x))*((1<<x)-1));
            LL cur = inf;
            for(;now>x&&k>0;--now)
            {
                if(has>=k)
                    cur = min(cur,ans+k);
                LL hf = (1<<(now-x-1));
                ans++;
                if(hf<=k)
                {
                    k-=hf;
                    ans+=(1<<(now-x-1))-1;
                    has+=hf*((1<<x)-1);
                }
            }
            return min(ans,cur);
        }
    }
    return ans+k;
}


int main(void)
{
    int q;
    scanf("%lld",&n);sci(q);
    _for(i,0,n) scl(cnt[i]);
    
    _rep(o,1,q)
    {
        LL x,k,op;
        scanf("%lld%lld%lld",&op,&x,&k);
        if(op==2)
        {
            LL ans = solve(x,k);
            printf("%lld\n",ans);
        }
        else cnt[x] = k;
    }
    return 0;
}