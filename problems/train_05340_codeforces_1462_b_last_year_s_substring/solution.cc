#include<bits/stdc++.h>
#define pb push_back
#define ll long long
#define endl '\n'
#define mp make_pair
#define f first
#define s second
#define eb emplace_back
#define pii pair<int, int>
#define pll pair<ll, ll>
#define INF INT_MAX
#define LINF LLONG_MAX
#define all(vec) vec.begin(), vec.end()
#define testIN 0
#define testOUT 0
#define FILEINPUT freopen("inputCNB.txt", "r", stdin);
#define FILEOUTPUT freopen("ouputCNB.txt", "w", stdout);
#define FOR(i, m, n) for(int i=m; i<n; i++)
#define FORD(i, m, n) for(int i=m; i>=n; i--)
#define FastIO cin.tie(0); ios_base::sync_with_stdio(false); cout.tie(0);
#define pq_max priority_queue<int>
#define pq_min priority_queue<int, vector<int>, greater<int>>
#define reset(A) memset(A, 0, sizeof(A))
using namespace std;
/******* LIBRARY and DEFINE *******/
template<typename A, typename B> 
ostream& operator << (ostream &os, const pair<A, B> &p){return os << "(" << p.f << " " << p.s << ")";};
template<typename T>
ostream& operator << (ostream &os, const vector<T> &vec){os << "VECTOR: "; for(auto ele: vec) os << ele << " "; return os;};
/********** TEMPLATES *********/
const int MAXN = 305;
const int mod = 1e9 + 7;
/********** CONSTANT *********/
void resetGlobalVar(){
	
}

void solution(){
	resetGlobalVar();
	// reset global variable
	int n; cin >> n;
	string s;
	cin >> s;
	bool check = false;
	vector<pii> v = {{0, 4}, {4, 0}, {1, 3}, {3, 1}, {2, 2}};
	FOR(i, 0, v.size()){
		string res1, res2;
		res1 = s.substr(0, v[i].f);
		FORD(j, n-1, n - v[i].s) res2 = s[j] + res2;
		if(res1 + res2 == "2020") check = true;
	}
	cout << (check? "YES" : "NO") << endl;
	
	
}

/*******************************/
		
/******** MAIN FUNCTION *********/
int main(){
	#if testIN
		FILEINPUT;
	#endif
	#if testOUT 
		FILEOUTPUT;
	#endif
	
	FastIO;

	int test = 1;
	cin >> test; cin.ignore();
	while(test--) solution();
	
	return 0;
}
/********** I'mAlone ***********/
/******** CAN NGOC BINH **********/