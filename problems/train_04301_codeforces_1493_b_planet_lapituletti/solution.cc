#include <bits/stdc++.h>
#define F first
#define S second
#define ll long long
#define pi acos(-1.0)
#define pb push_back
#define mp make_pair
#define lb printf("\n");
#define INF 1000000000000000000
#define LES -1000000000000000000

using namespace std;
//---------------All Solution Functions Start Here--------------//
int t, h, m, hh, mm;
int a[10] = {0, 1, 5, -1, -1, 2, -1, -1, 8, -1};
bool check(int nh, int nm)
{
    if (a[nh / 10] == -1 || a[nh % 10] == -1 || a[nm / 10] == -1 || a[nm % 10] == -1){
        return false;
    }
    int ih = a[nm % 10] * 10 + a[nm / 10], im = a[nh % 10] * 10 + a[nh / 10];
    
    return ih < h && im < m;
}
void solve()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d", &h, &m);
        scanf("%d:%d", &hh, &mm);
        int nh = hh, nm = mm;
        while (nh != 0 || nm != 0)
        {
            if (check(nh, nm)){
                break;
            }
            if (nm == m - 1){
                nh = (nh + 1) % h;
            }
            nm = (nm + 1) % m;
        }
        printf("%d%d:%d%d\n", nh / 10, nh % 10, nm / 10, nm % 10);
    }
}
//---------------All Solution Functions End Here---------------//
void file()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
int main()
{
    file();
    solve();

    return 0;
}
