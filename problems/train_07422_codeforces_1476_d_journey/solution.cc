
#include <bits/stdc++.h>
using namespace std;
typedef long long int       lli;
typedef unsigned long long int ulli;
typedef long double         ld;
#define vec                 vector
typedef vec<int>            veci;
typedef vec<lli>            veclli;
typedef vec<char>           vecc;
typedef vec<ulli>           veculli;
typedef pair<int,int>       pii;
typedef pair<string,int>    psi;
typedef map<int,int>        mapii;
typedef map<lli,lli>        maplii;
typedef map<string,int>     mapsi;
#define co                  cout<<
#define ci                  cin>>
#define fo(i,a,b,p)         for(int i=a;i<b;i += p)
#define pack                push_back
#define foi(n)              fo(i,0,n,1)
#define fi                  foi(n)
#define foj(n)              fo(j,0,n,1)
#define fj                  foj(n)
#define ex                  exit(0)
#define lde(a)              lli a; ci a
#define ide(a)              int a; ci a
#define ss                  second
#define ff                  first

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    ide(t);
    while(t--)
    {
        ide(n);
        string s;ci s;int count;int l=0,r=0;
        for(int i=0;i<=n;i++)
        {
            count=1;
            if(l<=i){l=i;
            for(int j=i;j<n;j++)
            {
                if(s[j]=='R') count++; else break;
                j++; l++;
                if(s[j]=='L'&&j<n) count++; else break;
                l++;
            }}
            else if(s[i]=='R')
                count += l-i;
            
            if(s[i-1]==s[i-2]&&i>1)
                r = i-1;
            if(s[i-1]=='L'&&i>0)
                count += i-r;
            co count<<" ";
        }
        co endl;
    }
    
    return 0;
}






