#include <bits/stdc++.h>
#include <iostream>
#define ll           long long
#define vll          vector<ll>
#define vlp          vector<pair<ll,ll> >
#define test(t)      ll t;cin>>t;while(t--)
#define fr(i,a,n)    for(int i=a;i<n;i++)
#define al(a)        a.begin(),a.end()
#define alg(a)       a.begin(),a.end(),greater<ll>()
#define input(a,n)   for(int i=0;i<n;i++)cin>>a[i]
#define fastio       ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(0);
#define sll          set<long long>
#define msll         multiset<long long>
#define mll          map<ll,ll>
#define mmll         multimap<ll,ll>
#define uset         unordered_set<ll>
#define lb           lower_bound
#define ub           upper_bound
#define ff           first
#define ss           second
#define pb           push_back
#define mod          1000000007
/*--- bit-stuff ----*/
#define setbits(a)   ( __builtin_popcountll(a))
#define right(a)     (__builtin_ctzll(a))
#define left(a)      (__builtin_clzll(a))
#define parity(a)    (__builtin_parityll(a))
using namespace std;
/*
#define TRACE
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
    template <typename Arg1>
    void __f(const char* name, Arg1&& arg1){
        cout << name << " : " << arg1 << endl;
        //use cerr if u want to display at the bottom
    }
    template <typename Arg1, typename... Args>
    void __f(const char* names, Arg1&& arg1, Args&&... args){
        const char* comma = strchr(names + 1, ','); cout.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
    }
#else
#define trace(...)
#endif
*/

//---------------------------------------------------------------------------------------------



int main() {
//     #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// 	#endif

    fastio;
	
	

    test(t){
        
        
        
       
        ll a[4];
        ll w,x,y,z;
        cin >> w >> x >> y >> z;
        if(max(w,x)<min(y,z)){
            cout << "NO" << endl;
        }
        else if(max(y,z)<min(w,x)){
            cout << "NO" << endl;
        }
        else{
            cout << "YES" << endl;
        }
        
        
        
        
         
        
        
        
        
        
    }




#ifndef ONLINE_JUDGE
    cout << "\n\nTime lap: " << 1.0 * clock() / CLOCKS_PER_SEC << " sec\n";
#endif
    return 0;
} 
