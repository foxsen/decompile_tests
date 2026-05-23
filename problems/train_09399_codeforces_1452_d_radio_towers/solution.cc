#include <bits/stdc++.h>
#define fastIO  std::ios::sync_with_stdio(false);cin.tie(NULL)
using namespace std;
#define int long long int
#define vi vector<int>
#define vvi vector<vector<int>>
#define pii pair<int,int>
#define ff first
#define ss second
#define mod 1000000007
#define MMOD  998244353
#define pb push_back
#define PI  3.1415926535897


using namespace std;

int gcdExtended(int a, int b, int *x, int *y);

// Function to find modulo inverse of b. It returns
// -1 when inverse doesn't
int modInverse(int b, int m)
{
  int x, y; // used in extended GCD algorithm
  int g = gcdExtended(b, m, &x, &y);

  // Return -1 if b and m are not co-prime
  if (g != 1)
    return -1;

  // m is added to handle negative x
  return (x % m + m) % m;
}

// Function to compute a/b under modlo m
int modDivide(int a, int b, int m)
{
  a = a % m;
  int inv = modInverse(b, m);
  return (inv * a) % m;
}

// C function for extended Euclidean Algorithm (used to
// find modular inverse.
int gcdExtended(int a, int b, int *x, int *y)
{
  // Base Case
  if (a == 0)
  {
    *x = 0, *y = 1;
    return b;
  }

  int x1, y1; // To store results of recursive call
  int gcd = gcdExtended(b % a, a, &x1, &y1);

  // Update x and y using results of recursive
  // call
  *x = y1 - (b / a) * x1;
  *y = x1;

  return gcd;
}

// Driver Program


signed main(void)
{
  int t = 1;
  fastIO;
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  //cin >> t;
  //int e = 1;
  while (t--)
  {
    int n;
    cin >> n;
    vi dp(n + 1);
    dp[0] = 1;
    int h = 2;
    for (int i = 1; i < n; i++)
    {
      h = (h * 2) % MMOD;
      dp[i] = dp[i - 1];
      if (i - 2 >= 0)
        dp[i] = (dp[i] + dp[i - 2]) % MMOD;
    }
    int k = dp[n - 1];
    // cout << k << endl;
    cout << modDivide(k, h, MMOD) << endl;
  }
}



