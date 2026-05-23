#include<deque>
#include<queue>
#include<vector>
#include<algorithm>
#include<iostream>
#include<set>
#include<cmath>
#include<tuple>
#include<string>
#include<chrono>
#include<functional>
#include<iterator>
#include<random>
#include<unordered_set>
#include<array>
#include<map>
#include<iomanip>
#include<assert.h>
#include<bitset>
#include<stack>
#include<memory>
using namespace std;
using namespace std::chrono;
typedef long long int llint;
typedef double lldo;
#define mp make_pair
#define mt make_tuple
#define pub push_back
#define puf push_front
#define pob pop_back
#define pof pop_front
#define fir first
#define sec second
#define res resize
#define ins insert
#define era erase
/*cout<<fixed<<setprecision(20);cin.tie(0);ios::sync_with_stdio(false);*/
const llint mod=998244353;
const llint big=2.19e15+1;
const long double pai=3.141592653589793238462643383279502884197;
const long double eps=1e-15;
template <class T,class U>bool mineq(T& a,U b){if(a>b){a=b;return true;}return false;}
template <class T,class U>bool maxeq(T& a,U b){if(a<b){a=b;return true;}return false;}
llint gcd(llint a,llint b){if(a%b==0){return b;}else return gcd(b,a%b);}
llint lcm(llint a,llint b){if(a==0){return b;}return a/gcd(a,b)*b;}
template<class T> void SO(T& ve){sort(ve.begin(),ve.end());}
template<class T> void REV(T& ve){reverse(ve.begin(),ve.end());}
template<class T>llint LBI(vector<T>&ar,T in){return lower_bound(ar.begin(),ar.end(),in)-ar.begin();}
template<class T>llint UBI(vector<T>&ar,T in){return upper_bound(ar.begin(),ar.end(),in)-ar.begin();}
//  10:00-
//A 10:05 AC
//B 10:15 AC
//C 10:21 AC
//F 10:49 AC
//D 10:59 RE
//D 11:04 TLE
//D 11:10 TLE
//D 11:13 AC
//E 11:34 RE
/*
3
2
1
*/
int solve(void){
	int n,m,i,j,ans=0;cin>>n>>m;
	if(n==0){return 0;}
	vector<string>mat(n+2);
	//どこの部屋を消しても連結ならいける
	for(i=1;i<=n;i++){cin>>mat[i];mat[i].insert(mat[i].begin(),'#');mat[i].pub('#');}
	mat[0]=string(m+2,'#');
	mat[n+1]=string(m+2,'#');
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			if(mat[i][j]=='#'){continue;}
			if(i==1&&j==1){continue;}
			mat[i][j]='#';
			queue<pair<int,int>>que;
			vector<vector<bool>>ren(n+2,vector<bool>(m+2));
			ren[1][1]=true;ren[i][j]=true;
			que.push(mp(1,1));
			while(que.size()){
				int y=que.front().fir;
				int x=que.front().sec;
				que.pop();
				if(mat[y+1][x]=='.'&&(!ren[y+1][x])){ren[y+1][x]=1;que.push(mp(y+1,x));}
				if(mat[y-1][x]=='.'&&(!ren[y-1][x])){ren[y-1][x]=1;que.push(mp(y-1,x));}
				if(mat[y][x+1]=='.'&&(!ren[y][x+1])){ren[y][x+1]=1;que.push(mp(y,x+1));}
				if(mat[y][x-1]=='.'&&(!ren[y][x-1])){ren[y][x-1]=1;que.push(mp(y,x-1));}
			}
			if(!ren[1][m]){cout<<"NO"<<endl;return 1;}
			if(!ren[n][1]){cout<<"NO"<<endl;return 1;}
			if(!ren[n][m]){cout<<"NO"<<endl;return 1;}
			mat[i][j]='.';
		}
	}
	cout<<"YES"<<endl;
	return 1;
}
int main(void){
	while(solve()){}
}

