#include<cstdio>
#include<algorithm>
#include<vector>
#include<deque>
#include<stack>
#include<queue>
#include<string>
#include<iostream>
//#include<tuple>
#include<utility>
#include<set>
#include<queue>
#include<iomanip>
#include<iterator>
//#include<chrono>
//cout<<setprecision(12)
//fixed
//#include<random>
using namespace std;
typedef long long int llint;
typedef long double lldo;
const llint big=1e15+100000;
const int mod=1e9+7;
const lldo eps=1e-9;
const long double pai=3.141592653589793238462643;
#define mt make_tuple
#define mp make_pair
#define fir first
#define sec second
#define pub push_back
#define puf push_front
#define pob pop_back
#define pof pop_front
#define res resize
#define ins insert
#define era erase
#define dme(in) cout<<in<<endl;return 0
template <class T,class U>void mineq(T& a,U b){if(a>b){a=b;}}
template <class T,class U>void maxeq(T& a,U b){if(a<b){a=b;}}
int main(void){
	int i,j,k,n,p;cin>>n>>p;
	static llint dp[1001][1001]={0};
	vector<int>dag;//0,3,1,2,5,4,6
	vector<int>zi(n);
	queue<int>kra;kra.push(n-1);
	vector<vector<pair<int,pair<int,int> > > > mti(n);//??\??????
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){dp[i][j]=big;}
	}
	dp[0][0]=0;
	for(i=0;i<p;i++){
		int s,e,t1,t2;cin>>s>>e>>t1>>t2;s--;e--;
		zi[s]++;
		mti[e].pub(mp(s,mp(t1,t1+t2)));
	}
	while(!kra.empty()){
		int ba=kra.front();kra.pop();
		dag.pub(ba);
		for(i=0;i<mti[ba].size();i++){
			zi[mti[ba][i].fir]--;
			if(zi[mti[ba][i].fir]==0){kra.push(mti[ba][i].fir);}
		}
	}
	reverse(dag.begin(),dag.end());
	for(i=1;i<dag.size();i++){
		int no=dag[i];
		for(j=0;j<mti[no].size();j++){
			int mae=mti[no][j].fir;
			mineq(dp[no][no],dp[mae][mae]+mti[no][j].sec.sec);//????????¨?????????2????????????
			int ti=mti[no][j].sec.fir;//?????£???????????????
			for(k=0;k<i;k++){
				mineq(dp[dag[k]][no],dp[dag[k]][mae]+ti);//1??????????????????
				mineq(dp[no][dag[k]],dp[dag[k]][mae]+ti);//1??????????????????
			}
			for(k=0;k<mti[no].size();k++){
				int mak=mti[no][k].fir;
				if(mae==mak){continue;}
				int tk=mti[no][k].sec.fir;//?????£???????????????
				mineq(dp[no][no],dp[mae][mak]+ti+tk);
			}
		}
	}
	cout<<dp[n-1][n-1]<<endl;
	return 0;
}