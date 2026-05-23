///Astalavista Code........~CodeSlayer007
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define Br cout<<endl
#define int long long
#define fe first
#define se second
#define double long double
#define all(v) v.begin(),v.end()
#define allr(v) v.rbegin(),v.rend()
#define PT(x) cout << (x) << endl
#define last(x)  prev(x.end())
#define PP(x) cout << (x) << " "
#define PS(x) for(auto it: x)cout << it <<" "; cout << endl;
#define PTT(x) cout << (#x) << " is " << (x) << endl
#define lets_go ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
void PV(vi v) { for (int i = 0 ; i < v.size() ; i++) cout << v[i] << " " ; cout << endl;}
void PVV(vii v) {for (int i = 0 ; i < v.size() ; i++) cout << v[i].first << " " << v[i].second << endl;}
void PA(int v[], int n, int x = 0) { for (int i = x ; i < n + x; i++)cout << v[i] << ' ' ; cout << endl;}
void IN(int a[], int n, int x = 0) {for (int i = x; i < n + x; i++)cin >> a[i];}
inline void op() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
// <=================================================================================================================================
// <=================================================================================================================================
const int M = 1e9 + 7;
const int IM = 1e18 + 37;
const int N = 300 + 10;


signed  main() {
    lets_go
    op();

    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        // PT(s);
        int x = 0, y = 0;
        int n = s.size();
        ii p = {0, 0};
        for (int i = 0; i < n; i++) {
            char cc = s[i];
            if (cc == 'L')
                x--;
            if (cc == 'R')
                x++;
            if (cc == 'U')
                y++;
            if (cc == 'D')
                y--;
            if(x == 0 && y == 0)
                continue ;
            int px = 0, py = 0;
            int id = 0;
            for ( ; id < n; id++) {
                char c = s[id];
                if (c == 'L')
                    px--;
                if (c == 'R')
                    px++;
                if (c == 'U')
                    py++;
                if (c == 'D')
                    py--;
                if (px == x && py == y) { // vapis jao 
                    if (c == 'L')
                        px++;
                    if (c == 'R')
                        px--;
                    if (c == 'U')
                        py--;
                    if (c == 'D')
                        py++;
                }
            }
            if (px == 0 && py == 0) {
                p = {x, y};
            }
        }
        cout << p.fe << " " << p.se << endl;

    }

    return 0;
}