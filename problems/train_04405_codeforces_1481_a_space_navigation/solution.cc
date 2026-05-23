#include<iostream>
#include<stack>
#include<string>
#include<set>
#include<map>
#include<vector>
#include<math.h>
#include<functional>
#include<limits.h>
#include<utility>
#include<queue>
#include<algorithm>
#include<cstring>
#include<iomanip>
#define lowbit(x) ((x)&(-x))
#define mid ((l+r)>>1)
typedef long long ll;
//
const int maxn = 2e5 + 10;
const int maxm = 2e4 + 10;
const double inf = 1e7;
const ll mod = 1e9+7;
const double eps = 1e-7;
using namespace std;
typedef pair<int, ll> pii;
/*ll gcd(ll a, ll b)//最大公约数
{
return b == 0 ? a : gcd(b, a%b);
}
ll lcm(ll a, ll b)
{
return a / gcd(a, b)*b;
}
ll fast_pow(ll a, ll k)//快速幂
{
ll ans = 1;
a = a%mod;
while (k != 0)
{
if (k & 1) ans = (ans*a) % mod;
k >>= 1;
a = (a*a) % mod;
}
return ans;
}
ll C(ll n, ll m)
{
return ((fac[n] * fast_pow(fac[m], mod - 2))%mod*fast_pow(fac[n - m], mod - 2)%mod);
}

bool is_prime(ll x)//素数判断
{
if (x == 2 || x == 3) return true;
if (x % 6 != 1 && x % 6 != 5) return false;
ll temp = sqrt(1.0*x);
for (ll i = 5;i <= temp;i += 6)
if (x%i == 0 || x % (i + 2) == 0) return false;
return true;
}
int prime[maxm], pnum = 0;//素数表，pnum是索引
bool p[maxm] = { 0 };//如果被筛掉，就为true
void Find_Prime()//更快的筛选法，遇到一个素数，就把它的倍数全部筛掉
{
for (int i = 2;i < maxm;i++)
{
if (p[i] == false)//不用一个数一个数的判断素数了
{
prime[pnum++] = i;
for (int j = i + i;j < maxm;j += i)//筛掉素数的倍数
p[j] = true;
}
}
}

void Exgcd(ll a, ll b, ll &x, ll &y) {
if (!b) x = 1, y = 0;
else Exgcd(b, a % b, y, x), y -= a / b * x;
}//x是a在mod b下的逆元
ll CRT(int a[],int m[],int n)
{
ll M=1,ans=0,t,x,y;
for(int i=0; i<n; i++)
{
M*=m[i];///M为除数乘积
}
for(int i=0; i<n; i++)
{
t=M/m[i];///除了mi以外的n-1个整数乘积
Exgcd(t,m[i],x,y);///求逆元，由扩展欧几里得转换成t*ti+m[i]*y=1来求ti
ans=(ans+a[i]*x*t)%M;
}
return (ans+M)%M;
}
struct Edge
{
int to, next;
}edge[maxn<<1];
int cnt, head[maxn];
void add_edge(int u, int v)
{
edge[++cnt].next = head[u];
edge[cnt].to = v;
head[u] = cnt;
}*/

string s;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T;
	cin >> T;
	while (T--)
	{
		int x, y;
		cin >> x >> y >> s;
		int a[4] = { 0,0,0,0 };
		for (int i = 0;i < s.size();i++)
		{
			if (s[i] == 'U') a[0]++;
			else if (s[i] == 'D') a[1]++;
			else if (s[i] == 'L') a[2]++;
			else a[3]++;
		}
		bool ok = true;
		if (x < 0 && a[2] < abs(x)) ok = false;
		if (x > 0 && a[3] < x) ok = false;
		if (y < 0 && a[1] < abs(y)) ok = false;
		if (y > 0 && a[0] < y) ok = false;
		if (ok) cout << "YES";
		else cout << "NO";
		cout << endl;
	}
	return ~~(0 - 0);
}