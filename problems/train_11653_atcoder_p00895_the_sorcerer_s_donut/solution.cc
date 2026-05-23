#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>
#include <set>
#include <map>
#include <deque>
#include <queue>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <stdio.h>

using namespace std;

#define fo(i,n) for(int i=0; i<(int)n; i++)
#define rep(it,s) for(__typeof((s).begin()) it=(s).begin();it!=(s).end();it++)
#define mp(a,b) make_pair(a,b)
#define pb(x) push_back(x)
#define pii pair<int,int>

int n,m;
string buf[35];
set<string> all;
bool vis[35][35];
int dx[] = {-1,0,1,-1,1,-1,0,1};
int dy[] = {-1,-1,-1,0,0,1,1,1};

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

	while (scanf("%d%d",&n,&m) && n!=0) {
		for (int i=0; i<n; i++) cin>>buf[i];

		all.clear();
		int best = 0;
		string str;
		for (int k=0; k<8; k++) {;
			for (int i=0; i<n; i++) {
				for (int j=0; j<m; j++) {
					for (int x=0; x<n; x++) for (int y=0; y<m; y++) vis[x][y] = 0;
					int x = i;
					int y = j;
					string s;
					while (!vis[x][y]) {
						vis[x][y] = 1;
						s = s + buf[x][y];
						x = (x + dx[k] + n)%n;
						y = (y + dy[k] + m)%m;
						if (s.length()>=2) {
							if (all.find(s)==all.end()) all.insert(s);
							else {
								if (best<=(int)s.length()) {
									if (best<(int)s.length()) {
										best = s.length();
										str = s;
									}
									else if (str>s) {
										str = s;
									}
								}
							}
						}
					}
				}
			}
		}
		
		if (best==0) cout<<"0"<<endl;
		else cout<<str<<endl;
	}
	
    return 0;

}