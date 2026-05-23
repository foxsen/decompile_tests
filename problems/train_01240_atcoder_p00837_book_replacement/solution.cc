#include <vector>
#include <list>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <algorithm>
#include <utility>
#include <functional>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <climits>
#include <cassert>
using namespace std;
inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef pair<int, int> pii;
typedef long long ll;
#define ALL(a) (a).begin(),(a).end()
#define RALL(a) (a).rbegin(),(a).rend()
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
#define EACH(t,i,c) for(t::iterator i=(c).begin(); i!=(c).end(); ++i)
const double EPS = 1e-10;
const double PI  = acos(-1.0);


int main(){
	int m,c,n;
	while(cin>>m>>c>>n,m){
		vi k(n);
		vvi b(n,vi());
		queue<vi> q;
		REP(i,n){
			cin>>k[i];
			REP(j,k[i]){
				int bb;
				cin>>bb;
				b[i].push_back(bb);
			}
			q.push(b[i]);
		}
		vvi d(m,vi());

		int cost=0;

		while(!q.empty()){
			vi p=q.front();q.pop();
			int req=p.front();p.erase(p.begin(),p.begin()+1);
			//If a student requests a book, the librarian enters the storeroom and looks for it on D1, ... , Dm in this order,
			//and then on the shelf. After finding the book, the librarian takes it and gives a copy of a page to the student. 
			int founddesk=-1,foundloc=-1;
			REP(i,m){
				vi::iterator it= find(ALL(d[i]),req);
				if(it!=d[i].end()){
					founddesk=i;
					foundloc=it-d[i].begin();
					break;
				}
			}
			if(founddesk==-1){
				cost+=m+1;
			}else{
				d[founddesk].erase(d[founddesk].begin()+foundloc,d[founddesk].begin()+foundloc+1);
				cost+=founddesk+1;
			}

			//If D1 is not full (in other words, the number of books on D1 < c), the librarian puts the requested book there.
			if(d[0].size()<c){
				d[0].push_back(req);
				cost+=1;
			}

			//If D1 is full, the librarian
			else{
				bool put=false;
				int tempdesk=-1,temploc=-1;
				REP(i,m){
			//    temporarily puts the requested book on the non-full desk closest to the entrance or,
					if(d[i].size()<c){
						d[i].push_back(req);
						put=true;
						tempdesk=i;
						temploc=d[i].size()-1;
						cost+=i+1;
						break;
					}
				}
			//in case all the desks are full,on the shelf,
				if(!put){
					tempdesk=-1;
					cost+=m+1;
				}
			//    finds the book on D1 that has not been requested for the longest time (i.e. the least recently used book) and takes it,
				int lru=d[0].front();
				d[0].erase(d[0].begin(),d[0].begin()+1);
				cost+=1;
			//    puts it on the non-full desk (except D1 ) closest to the entrance or,
				bool putlru=false;
				FOR(j,1,m){
					if(d[j].size()<c){
						d[j].push_back(lru);
						putlru=true;
						cost+=j+1;
						break;
					}
				}
				//in case all the desks except D1 are full, on the shelf,
				if(!putlru){
					cost+=m+1;
				}
			//    takes the requested book from the temporary place,
				if(tempdesk!=-1){
					d[tempdesk].erase(d[tempdesk].begin()+temploc,d[tempdesk].begin()+temploc+1);
					cost+=tempdesk+1;
				}else{
					cost+=m+1;
				}
			//    and finally puts it on D1 .
				d[0].push_back(req);
				cost+=1;
			}

			if(!p.empty()){
				q.push(p);
			}
		}

		cout<<cost<<endl;
	}
}