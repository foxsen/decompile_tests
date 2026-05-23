#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
#include <utility>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <functional>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
 
using namespace std;
 
#define REP(i,s,e) for(int i=(s); i<(int)(e); i++)
#define rep(i,n) REP(i, 0, n)
#define pb push_back
#define mp make_pair
#define all(r) (r).begin(),(r).end()
#define rall(r) (r).rbegin(),(r).rend()
#define fi first
#define se second
 
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef vector<ll> vl;
typedef vector<vl> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
 

 
const int INF = 1000000;
const double EPS = 1e-8;
const int mod = 1e9 + 7;

int main(){
	string s;
	cin>>s;
	bool f, F, fn, fs;
	f = F = fn = false;
	fs = s.size() >= 6;
	rep(i, s.size()){
		if(s[i]>='a'&&s[i]<='z') f = true;
		else if(s[i] >= 'A' && s[i] <= 'Z') F = true;
		else if(s[i] >= '0' && s[i] <= '9') fn = true;
	}
	cout<<(f&F&fn&fs?"VALID":"INVALID")<<endl;
}