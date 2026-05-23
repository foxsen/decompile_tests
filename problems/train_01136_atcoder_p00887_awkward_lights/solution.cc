#include <bits/stdc++.h>

using namespace std;

inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}
template<class T> inline T sqr(T x) {return x*x;}

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef pair<int, int> pii;
typedef long long ll;

#define all(a)  (a).begin(),(a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define pb push_back
#define mp make_pair
#define each(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define exist(s,e) ((s).find(e)!=(s).end())
#define range(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n)  range(i,0,n)
#define clr(a,b) memset((a), (b) ,sizeof(a))
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;

const double eps = 1e-10;
const double pi  = acos(-1.0);
const ll INF =1LL << 62;
const int inf =1 << 29;

typedef valarray<int> vec;
typedef valarray<vec> mat;

bool check(mat &a){
	int n=a.size(),m=a[0].size();
	int r=0,c=0;
	rep(i,n-1){
		int index=-1;

		while(c<m&&index==-1){
			range(j,i,n) if(a[j][c]) index=j;
			if(index==-1)
				c++;
			else if(i!=index)
				swap(a[i],a[index]);
		}
		if(index==-1) break;

		range(j,i+1,n){
			int d=a[j][c]/a[i][c];
			range(k,c,m){
				a[j][k]+=a[i][k]*d;
				a[j][k]%=2;
			}
		}
		c++;
	}
	int rank=0,add=0;
	r=0,c=0;
	while(r<n&&c<m-1){
		while(c<m-1&&a[r][c]==0) c++;
		if(c==m-1) break;
		rank++,r++;
		while(r<n&&a[r][c]!=0) r++;
		if(r==n) break;
	}

	if(r<n) range(i,r,n) if(a[i][m-1]!=0) add=1;
	return !add;
}


int main(void){
	int m,n,d;
	while(cin >> m >> n >> d){
		int num=m*n;
		if(num==0) break;
		mat state(vec(0,num+1),num);
		rep(i,n)rep(j,m){
			int row=i*m+j;
			rep(a,n)rep(b,m){
				int col=a*m+b;
				int dist=abs(i-a)+abs(j-b);
				if(dist==d) state[row][col]=1;
			}
			state[row][row]=1;
			cin >> state[row][num];
		}
		cout << check(state) << endl;
	}
	return 0;
}