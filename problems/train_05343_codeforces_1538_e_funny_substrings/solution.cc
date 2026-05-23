// {{{ by unolight
#include <bits/stdc++.h>
#include <unistd.h>
#pragma GCC diagnostic ignored "-Wunused-result"
#pragma GCC diagnostic ignored "-Wunused-function"
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x),end(x)
#define RALL(x) rbegin(x),rend(x)
#define REP(i,n) for ( int i=0; i<int(n); i++ )
#define REP1(i,a,b) for ( int i=(a); i<=int(b); i++ )
#define MP make_pair
#define PB push_back
using namespace std;
typedef int64_t LL;
typedef pair<int,int> PII;
typedef vector<int> VI;

namespace { namespace unolight {
// Read Input
template<class T> void _R( T &x ) { cin>>x; }
void _R( int &x ) { scanf("%d",&x); }
void _R( int64_t &x ) { scanf("%" PRId64,&x); }
void _R( double &x ) { scanf("%lf",&x); }
void _R( char &x ) { scanf(" %c",&x); }
void _R( char *x ) { scanf("%s",x); }
void R() {}
template<class T, class... U> void R( T& head, U&... tail ) { _R(head); R(tail...); }
// Write Output
template<class T> void _W( const T &x ) { cout<<x; }
void _W( const int &x ) { printf("%d",x); }
void _W( const int64_t &x ) { printf("%" PRId64,x); }
void _W( const double &x ) { printf("%.16f",x); }
void _W( const char &x ) { putchar(x); }
void _W( const char *x ) { printf("%s",x); }
template<class T> void _W( const vector<T> &x ) { for (auto i = x.begin(); i != x.end(); _W(*i++)) if (i != x.cbegin()) putchar(' '); }
void W() {}
template<class T, class... U> void W( const T& head, const U&... tail ) { _W(head); putchar(sizeof...(tail)?' ':'\n'); W(tail...); }

#ifdef UNOLIGHT
#include "dump.hpp"
#else
#define dump(...)
#endif

template<class T> inline bool chmax( T &a, const T &b ) { return b>a ? a=b,true : false; }
template<class T> inline bool chmin( T &a, const T &b ) { return b<a ? a=b,true : false; }
template<class T> using MaxHeap = priority_queue<T>;
template<class T> using MinHeap = priority_queue<T, vector<T>, greater<T>>;
template<class T, class F=less<T>> void sort_uniq( vector<T> &v, F f=F() ) {
    sort(begin(v),end(v),f);
    v.resize(unique(begin(v),end(v))-begin(v));
}
// }}}

struct Data {
    LL cnt;
    string pref,s,suff;
    Data() {}
    Data( string t ) {
        cnt=0;
        s=pref=suff="";
        for ( int i=0; i+4<=t.size(); i++ ) {
            if ( t.substr(i,4)=="haha" ) cnt++;
        }
        if ( t.size()<3 ) {
            s=t;
        } else {
            pref=t.substr(0,3);
            suff=t.substr((int)t.size()-3);
        }
    }
    Data operator+( const Data& other ) const {
        if ( s!="" && other.s!="" ) {
            return Data(s+other.s);
        }
        Data res;
        // pref
        if ( s!="" )  {
            Data tmp(s+other.pref);
            res.pref=tmp.pref;
            res.suff=other.suff;
            res.cnt=tmp.cnt+other.cnt;
        }
        // suff
        else if ( other.s!="" ) {
            Data tmp(suff+other.s);
            res.pref=pref;
            res.suff=tmp.suff;
            res.cnt=cnt+tmp.cnt;
        }
        else {
            Data tmp(suff+other.pref);
            res.pref=pref;
            res.suff=other.suff;
            res.cnt=cnt+other.cnt+tmp.cnt;
        }
        return res;
    }
};

void main() {
    int tt;
    R(tt);
    while ( tt-- ) {
        int n;
        R(n);
        map<string,Data> mp;
        REP(i,n) {
            string var,op;
            R(var,op);
            if ( op==":=" ) {
                string s;
                R(s);
                mp[var]=Data(s);
            } else {
                string v1,add,v2;
                R(v1,add,v2);
                mp[var]=mp[v1]+mp[v2];
            }
            if ( i==n-1 ) W(mp[var].cnt);
        }
    }
}

 // {{{ main
}}
int main() { unolight::main(); return 0; }
// }}}
