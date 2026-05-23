#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <algorithm>	// require sort next_permutation count __gcd reverse etc.
#include <cstdlib>	// require abs exit
#include <cstdio>	// require scanf printf
#include <functional>
#include <numeric>	// require accumulate
#include <cmath>
#include <climits>
#include <limits>
#include <cfloat>
#include <iomanip>	// require setw
#include <sstream>	// require stringstream 
#include <cstring>	// require memset
#include <cctype>	// require tolower, toupper
#include <fstream>	// require freopen
#include <ctime>
#define rep(i,n) for(int i=0;i<(n);i++)
#define ALL(A) A.begin(), A.end()
#define INF 1<<29
#define EPS 1e-9
#define each(i,c) for(auto i=(c).begin();i!=(c).end();++i)
#define exist(s,e) ((s).find(e)!=(s).end())
#define clr(a) memset((a),0,sizeof(a))
#define nclr(a) memset((a),-1,sizoef(a))
#define sz(s) (int)((s).size())
#define INRANGE(x,s,e) ((s)<=(x) && (x)<(e))
#define pb push_back
#define MP(x,y) make_pair((x),(y))
#define DEBUG 0

using namespace std;

typedef long long ll;
typedef pair<int, int> P;
string FILE_NAME = "testcase.B";
string NAME;
string itos (int n )
{
	stringstream ss;
	ss << n;

	return ss.str();
}

const int MAX_V = (int)1e5 + 5;
int V, E;
vector<int> G[MAX_V];
vector<char> v;
bool used[26];

int main()
{
//	cut here before submit 
#if DEBUG
	NAME = FILE_NAME;
	int CNT = 1;
	NAME += itos (CNT );
	while (freopen (NAME.c_str() , "r", stdin ) != NULL ) {
#endif
	v.clear();
	rep (i, MAX_V ) G[i].clear();
	ios_base::sync_with_stdio(0);
	cin >> V >> E;
 	v.resize (V, 0 );
	rep (i, V ) cin >> v[i];
	rep (i, E ){
		int s, t;
		cin >> s >> t;
		G[s].push_back (t );
		G[t].push_back (s );
	} // end rep

	rep (i, V ){
		if (v[i] == '?' ){
			memset (used, false, sizeof (used ) );
			rep (j, G[i].size() ){
				int u = G[i][j];
				if (v[u] != '?' ) used[(int)(v[u] - 'a')] |= true;
			} // end rep
			rep (j, 26 ){
				if (!used[j] ){
					v[i] = (char)(j+'a');
					break;
				} // end if
			} // end rep
		} // end if
	} // end rep

	rep (i, V ) cout << v[i];
	cout << endl;
#if DEBUG
	CNT++;	// cut here before submit
	NAME = FILE_NAME;
	NAME += itos (CNT );
	} // end loop; cut here before submit
#endif			
	return 0;
}
