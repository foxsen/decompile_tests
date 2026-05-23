#include <bits/stdc++.h>

using namespace std;

#define int long long
#define x first
#define y second
#define PII pair<int,int>
#define LL long long
#define pb push_back
#define pqp priority_queue<PII,vector<PII>,greater<PII> >
#define pqi priority_queue<int,vector<int>,greater<int> >
#define PSS pair<string,string>
#define in insert
#define line inline
#define sort(s) sort(s.begin(),s.end());
#define reverse(s) reverse(s.begin(),s.end());
#define max_(s) *max_element(s.begin(), s.end())
#define V vector<int>
#define VV vector<V>
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int dx[]=  {0,-1,0,1,0,0},dy[]= {-1,0,1,0,0,0},dz[] = {0,0,0,0,-1,1};

void solve()
{
    int n,k; cin >> n >> k;
    string s; cin >> s;
    
    int star = -1,last,cnt = 0;
    for(int i = 0; i < s.size(); i ++){
        if(s[i] == '*'){
            if(star == -1) star = i;
            last = i;
        }
    }
    
    if(last == star){
        cout << 1 << endl;
        return ;
    }
    
    for(int i = star; i + k < last;){
        for(int j = i + k; j > i; j --){
            if(s[j] == '*'){
                i = j;
                cnt ++;
                break;
            }
        }
    }
    cout << cnt + 2 << endl;
    
}

signed main()
{
    // IOS
    // init();
    // get_primes(N - 1);
    int _; cin >> _;for(int i = 1; i <= _; i ++)
    solve();
}
