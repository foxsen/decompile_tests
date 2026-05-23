#include <cstdio>
#include <map>
#include <algorithm>
#include <vector>
#include <functional>
#define pb push_back
#define fi first
#define sec second
using namespace std;
typedef pair<int,int> P;
typedef pair<int,P> PP;

int main(){
	int n, m, a;
	while(scanf("%d%d%d", &n, &m, &a),n||m||a){
		vector<PP> v;
		for(int i = 0; i < m; i++){
			int h,p,q;
			scanf("%d%d%d", &h, &p, &q);
			v.pb(PP(h,P(p,q)));
		}
		sort(v.begin(),v.end(),greater<PP>());
		for(int i = 0; i < m; i++){
			if(a == v[i].sec.fi) a = v[i].sec.sec;
			else if(a == v[i].sec.sec) a = v[i].sec.fi;
		}
		printf("%d\n", a);
	}
}