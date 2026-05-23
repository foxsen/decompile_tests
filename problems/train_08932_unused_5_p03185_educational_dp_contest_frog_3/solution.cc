#include "bits/stdc++.h"
using namespace std;
using ll = long long;

struct line
{
	ll a, b;
	  line(ll m, ll c)
	{
		a = m;
		b = c;
	}
	ll operator[] (int x)
	{
		return a * x + b;
	}
	double operator*(line const &o)
	{
		return double(b - o.b) / (o.a - a);
	}
};

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);

	int n;
	ll c;
	cin >> n >> c;
	
	vector<ll> h(n);
	for(auto& x: h)
	  cin >> x;
	
	vector<ll> dp(n);
	
	deque<line> d;
	d.emplace_back(-2*h[0], dp[0] + h[0] * h[0]);
	for(int i = 1; i < n; ++i) {
	  auto x = h[i];
	  while(d.size() > 1 && d[0][x] >= d[1][x])
	    d.pop_front();
	  dp[i] = d.front()[x] + (x * x + c);
	  auto l = line(-2*x, dp[i] + x * x);
	  while(d.size() > 1 && (d.back() * d[d.size() - 2u]) >= (l * d[d.size() - 2u]))
	    d.pop_back();
	  if(d.back() * l <= h.back())
	    d.emplace_back(l);
	}
	
	cout << dp.back();
}