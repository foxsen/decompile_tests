#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define lli long long int
#define MOD 1000000007
#define endl '\n'
#define inf 1e18
#define PQ priority_queue<int>
#define PQM priority_queue<int,vector<int>,greater<int>>
#define HashMap(x,y) unordered_map<x,y>
const int MAX = 1e9;
const int MIN = -1e9;







void solve()
{
  ll cntodd = 0, cnteven = 0, oddsum = 0, evensum = 0;
  ll n;
  cin >> n;
  ll c[n];
  ll minh = inf, minv = inf;
  for (ll i = 0; i < n; i++) {
    cin >> c[i];
  }
  ll ans, minans;
  minans = inf;

  for (ll i = 0; i < n; i++) {

    if (i % 2 == 0) {
      oddsum += c[i];
      minh = min(c[i], minh);
      cntodd++;
    }
    else {
      evensum += c[i];
      minv = min(c[i], minv);
      cnteven++;
    }
    if (i >= 1) {
      ans = oddsum + (minh * (n - cntodd)) + evensum + (minv * (n - cnteven));
      minans = min(ans, minans);
    }
  }
  cout << minans << endl;









}

void file_io()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

}

int main()
{
  file_io();

  int t;
  cin >> t;
  while (t--)
  {
    solve();
  }
  return 0;

}


