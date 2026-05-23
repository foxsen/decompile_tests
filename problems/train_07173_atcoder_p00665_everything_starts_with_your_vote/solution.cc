#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <list>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <queue>
#include <stack>
#include <string>
#include <sstream>
#include <cstring>
#include <cstdlib>

using namespace std;

#define ALL(c) c.begin(),c.end()
#define RALL(c) c.rbegin(),c.rend()
#define SORT(x) sort((x).begin(),(x).end())
#define REP(i,x,y) for(int i=(x);i<(y);++i)
#define MP(a,b) make_pair((a),(b))
#define debug(x) #x << "=" << (x)
 
#ifdef DEBUG
#define _GLIBCXX_DEBUG
#define dump(x) std::cerr << debug(x) << " (L:" << __LINE__ << ")" << std::endl
#else
#define dump(x)
#endif

typedef long long int ll;
typedef pair<int,int> pii;
//template<typename T> using vec=std::vector<T>;

const int INF=1<<30;
const long long int INF_=1LL<<58;
const double EPS=1e-9;
const int dx[]={1,0,-1,0},dy[]={0,1,0,-1};

template <typename T> ostream &operator<<(ostream &os, const vector<T> &vec){
	os << "[";
	for (const auto &v : vec) {
		os << v << ",";
	}
	os << "]";
	return os;
}

struct Chara{
	string name;
	ll vote;
	bool operator<(const Chara &c)const{
		if(vote!=c.vote) return vote>c.vote;
		return name<c.name;
	}
};

ll n,m,k,l;
vector<Chara> favs,unfavs;

bool Check(int x){
	if(x>k||x>m) return false;
	if(unfavs.size()<k-x+1) return true;

	ll cost=0;
	REP(i,0,x){
		cost+=max(0LL,unfavs[k-x].vote-favs[i].vote+(unfavs[k-x].name<favs[i].name));
		if(cost>l) return false;
	}
	
	return cost<=l;
}

void Solve(){
	while(true){
		cin >> n >> m >> k >> l;
		if(n+m+k+l==0) break;
		Chara charas[100010];
		REP(i,0,n) cin >> charas[i].name >> charas[i].vote;
		unordered_set<string> fav_names;
		REP(i,0,m){
			string name; cin >> name;
			fav_names.insert(name);
		}
		
		favs.clear(); unfavs.clear();
		REP(i,0,n){
			if(fav_names.find(charas[i].name)!=fav_names.end()) favs.push_back(charas[i]);
			else unfavs.push_back(charas[i]);
		}
		sort(favs.begin(),favs.end());
		sort(unfavs.begin(),unfavs.end());

		int lb=0,ub=min(m,k)+1;
		while(true){
			if(ub-lb<=1){
				if(Check(ub)) lb=ub;
				break;
			}
			int mid=(lb+ub)/2;
			if(Check(mid)) lb=mid;
			else ub=mid;
		}

		cout << lb << endl;
	}
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	Solve();
	return 0;
}