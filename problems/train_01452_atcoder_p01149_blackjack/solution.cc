#include<cstdio>
#include<vector>

#define	pb			push_back
#define	rep(i,n)	for(int i=0;i<(n);i++)

using namespace std;

int f[128];

bool isAce11(const vector<char> &hand){
	int sc=0,acecnt=0;
	rep(i,hand.size()){
		sc+=f[hand[i]];
		if(hand[i]=='A')	acecnt++;
	}
	return (acecnt>0 && sc<=11);
}

int score(const vector<char> &hand){
	int sc=0,acecnt=0;
	rep(i,hand.size()){
		sc+=f[hand[i]];
		if(hand[i]=='A')	acecnt++;
	}
	if(acecnt>0 && sc<=11)	sc+=10;
	return sc;
}

int main(){
	f['A']=1;	f['2']=2;	f['3']=3;	f['4']=4;	f['5']=5;	f['6']=6;
	f['7']=7;	f['8']=8;	f['9']=9;	f['T']=10;	f['J']=10;	f['Q']=10;
	f['K']=10;

	int T;	scanf("%d",&T);
	while(T--){
		vector<char> hand(2);	scanf(" %c %c",&hand[0],&hand[1]);
		char card[8];
		rep(i,8)	scanf(" %c",card+i);
		int sc=score(hand);
		if(sc==21){ puts("blackjack"); continue; }
		for(int i=0;;i++){
			sc=score(hand);
			if(sc>21){ puts("bust"); break; }
			if(sc>17 || (!isAce11(hand) && sc==17)){ printf("%d\n",sc); break; }
			hand.pb(card[i]);
		}
	}

	return 0;
}