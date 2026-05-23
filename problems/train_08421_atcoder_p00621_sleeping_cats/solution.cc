#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<cassert>
#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<utility>
#include<numeric>
#include<algorithm>
#include<bitset>
#include<complex>

using namespace std;

typedef long long Int;
typedef vector<int> vint;
typedef pair<int,int> pint;
#define mp make_pair

template<class T> void pv(T a, T b) { for (T i = a; i != b; ++i) cout << *i << " "; cout << endl; }
template<class T> void chmin(T &t, T f) { if (t > f) t = f; }
template<class T> void chmax(T &t, T f) { if (t < f) t = f; }
int in() { int x; scanf("%d", &x); return x; }

int hei[110];

int main() {
	int W,Q;
	while(cin>>W>>Q){
		if(W==0&&Q==0)break;
		memset(hei,-1,sizeof(hei));
		string str;
		int id,w;
		int i;
		for(i=0;i<Q;i++){
			cin>>str;
			if(str=="s"){
				cin>>id>>w;
				int j;
				int k;
				bool ok;
				for(j=0;j<W;j++){
					ok=true;
					for(k=0;k<w;k++){
						if(j+k>=W||hei[j+k]!=-1){
							ok=false;
							break;
						}
					}
					if(ok){
						for(k=0;k<w;k++){
							hei[j+k]=id;
						}
						cout<<j<<endl;
						break;
					}
				}
				if(j==W)cout<<"impossible\n";
			}else{
				cin>>id;
				int j;
				for(j=0;j<W;j++){
					if(hei[j]==id){
						hei[j]=-1;
					}
				}
			}
		}
		cout<<"END\n";
	}
	return 0;
}