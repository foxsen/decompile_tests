                  /**Bismillahir Rahmanir Rahim.**/
#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long int   ull;
typedef long long int            ll;
typedef long double              ld;
#define Faster  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pi                 acos(-1)
#define test        int t; cin>>t; while(t--)
#define dot(x)      fixed<<setprecision(x)
#define eps 0.000000001
int chessx[]={-1,-1,1, 1,-2,-2, 2,2}; //knight
int chessy[]={ 2,-2,2,-2, 1,-1,-1,1}; //knight
int xx[]={ 0,0,1,-1};
int yy[]={-1,1,0, 0};
const double EPS = 1e-12;
bool isEqual(ld a, ld b) {
    return abs(a - b) <= EPS;
}
bool isGreater(ld a, ld b) {
    return a > b + EPS;
}
bool isSmaller(ld a, ld b) {
    return a + EPS < b;
}
// cin.ignore();
//sort(s,s+n,greater<int>());
//cin.getline(array,size);
//s.erase(s.begin()+s.size()-1,s.end()); last index
int main()
{
    #ifdef RANA_HOSSAIN
        clock_t tStart = clock();
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    Faster
    test
    {
        int n,i,j,s=1,ans=1,p=3;
        cin>>n;
        if(n==1)
        {
            cout<<"1"<<endl;
            continue;
        }
        while(1)
        {
            if(s+p<=n)
            {
                s+=p;
                p+=2;
                if(s==n)
                    break;
            }
            else
                break;
            //cout<<s<<endl;
            ans++;
        }
        
        cout<<ans+1<<endl;
    }



    #ifdef RANA_HOSSAIN
        fprintf(stderr, "\n>> Runtime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
    #endif
}