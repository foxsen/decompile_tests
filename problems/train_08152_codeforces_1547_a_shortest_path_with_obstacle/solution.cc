#include <bits/stdc++.h>

using namespace std;

#define ar array
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;



string solve(string m) {
    
    string c = m;
    int r,l;
    l = 0; 
    r = m.length() - 1;
    
    for(int t = m.length() - 1; t >= 0; t--)
    {
        if(c[l] - 'a' == t)
        {
            l++;
        }
        else if(c[r] - 'a' == t)
        {
            r--;
        }
        else
        {
            return "NO";
        }
        
        
    }
    
     return "YES";
    
    
    

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        int ax, ay;;
        cin>>ax>>ay;
        int bx, by;
        cin>>bx>>by;
        int fx, fy;
        cin>>fx>>fy;
        
        int ans = abs(ax -  bx) + abs(ay - by);
        
        if((ax == bx) && (ax == fx) && ((fy - ay)*(fy - by) < 0) || (ay == by) && (ay == fy) &&((fx - ax)*(fx - bx) < 0))
        {
            ans += 2;
        }
        cout<<ans<<endl;
    }
}