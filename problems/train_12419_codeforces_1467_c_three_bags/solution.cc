
// art by : Seoul_graffiti
// Last modified: 2021/01/08 22:44:15

#include <bits/stdc++.h>
using namespace std;

#define ERAGE(x) x.erase(unique(all(x)), x.end())
#define rall(x) x.rbegin(), x.rend()
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
#define show(x) cout << #x << " : " << x << "\n"

void no()
{
    printf("NO\n");
}
void yes() { printf("YES\n"); }

void files()
{
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    return;
}

const int N = 1e5 + 5;
const long long M = 1e9 + 7;

void sol()
{
    int n, n2, n3;
    cin >> n >> n2 >> n3;
    vector<int> a, b, c;
    long long sum = 0;
    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        a.push_back(x);
        sum += x;
    }
    for (int i = 0; i < n2; ++i)
    {
        int x;
        cin >> x;
        b.push_back(x);
        sum += x;
    }
    
    for (int i = 0; i < n3; ++i)
    {
        int x;
        cin >> x;
        c.push_back(x);
        sum += x;
    }
    sort(all(a));
    sort(all(b));
    sort(all(c));
    long long mn = 1e17;
    long long cnt = 0;
    for (int i : a)
        cnt += i;
    mn = min(cnt, mn);
    cnt = 0;
    for (int i : b)
        cnt += i;
    mn = min(cnt, mn);
    cnt = 0;
    for (int i : c)
        cnt += i;
    mn = min(cnt, mn);
    long long dif1 = abs(a[0] + b[0]);
    long long dif2 = abs(a[0] + c[0]);
    long long dif3 = abs(c[0] + b[0]);
    long long mx = 0;
    mx = max(sum - 2 * dif1, sum - 2 * mn);
    mx = max(sum - 2 * dif2, mx);
    mx = max(sum - 2 * dif3, mx);
    cout << mx << "\n";
}
int main()
{
    //files();
    int tcase = 1;
    //scanf("%d", &tcase);
    while (tcase--)
    {
        sol();
    }
}
