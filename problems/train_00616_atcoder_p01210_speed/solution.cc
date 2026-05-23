#include<iostream>
#include<stack>
#include<queue>
#include<cassert>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
#define REP(i,b,n) for(int i=b;i<n;i++)
#define rep(i,n)   REP(i,0,n)
#define pb         push_back
typedef long long ll;

const ll inf =(1LL)<<50;

enum{IDLE=-1,PUTR=0,PUTL=1,DRAW=2,BACK=3};

bool isend(int *a){
  rep(i,4)if (a[i]!=-1)return false;
  return true;
}

//0123456789012
bool canput(int a,int b){
  int vala=a/4,valb=b/4;
  return (vala+1)%13 == valb||(valb+1)%13==vala;
}

bool isgreater(int a,int b){//a>b?
  if (a/4 != b/4)return a/4 > b/4;
  else return a%4 > b%4;
}

bool solve(queue<int> *deck){
  ll now=0,time[2];
  int have[2][4];
  int table[2];
  int state[2];
  int hand[2],place[2];
  int lastput[2];

  rep(i,2){
    rep(j,4)have[i][j]=-1;
    rep(j,4 && deck[i].size()){
      have[i][j]=deck[i].front();
      deck[i].pop();
    }
  }

  state[0]=IDLE;
  state[1]=IDLE;

  while(true){
    ll next=inf;
    //take min time
    if (state[0]==IDLE&&state[1]==IDLE){
      rep(i,2){
	if (deck[i].size()){
	  table[i]=deck[i].front();
	  deck[i].pop();
	}else {
	  //	  for(int j=3;j>=0;j--){
	  rep(j,4){
	    if (have[i][j] != -1){
	      lastput[i]=have[i][j];
	      table[i]=have[i][j];
	      have[i][j]=-1;
	      break;
	    }
	  }
	}
      }
      next=500;
      time[0]=time[1]=0;
      state[0]=state[1]=IDLE;
    }else if(state[0]==IDLE){
      next=time[1];
    }else if(state[1]==IDLE){
      next=time[0];
    }else next=min(time[0],time[1]);

    if (next == inf);
    else now+=next;
    //     cout << "current time " << now << endl;
    //     cout << "state " << state[0] <<" " << state[1] << endl;
    //     cout << "table " << table[0] <<" " << table[1] << endl;

    //pass time
    rep(i,2)if (state[i] != IDLE)time[i]-=next;

    //interrupt
    rep(i,2){
      if ((state[i]==PUTR && state[1-i]==PUTL && time[i]==0 &&time[1-i]!=0) ||
	  (state[i]==PUTL && state[1-i]==PUTR && time[i]==0)){
	have[1-i][place[1-i]]=hand[1-i];
	time[1-i]=500;
	state[1-i]=BACK;
      }
    }
		
    //    cout << table[0]<<" " << table[1]4 << endl;
    //    cout <<"state "<< state[0] <<" " << state[1] << endl;
    
    //done this action and choose next action(no dependencies)
    rep(i,2){
      if (time[i]!=0)continue;
      if (state[i]==IDLE){
      }else if (state[i] == PUTR || state[i]==PUTL){
	//DRAW or choose nexthand
	//	cout <<"hand " << i <<" " <<  hand[i] << endl;
	if (state[i]==PUTR)table[i]=hand[i];
	else if (state[i]==PUTL)table[1-i]=hand[i];
	lastput[i]=hand[i];
	if (deck[i].size()){
	  hand[i]=deck[i].front();
	  deck[i].pop();
	  time[i]=300;
	  state[i]=DRAW;
	}else have[i][place[i]]=-1;
      }else if (state[i] == DRAW){
	//choose next hand
	have[i][place[i]]=hand[i];
      }else if(state[i] == BACK){
	//choose next hand
      }
    }

    //choose next action(depend on other)
    rep(i,2){
      if (time[i] != 0)continue;
      state[i]=IDLE;
      hand[i]=-1;
      //right
      rep(j,4){
	if (have[i][j]!=-1&&
	    canput(have[i][j],table[i])&&
	    (hand[i]==-1||isgreater(hand[i],have[i][j]))){
	  hand[i]=have[i][j];
	  place[i]=j;
	  state[i]=PUTR;
	  time[i]=500;
	}
      }
      if (state[i]==IDLE){
	rep(j,4){
	  if (have[i][j]!=-1&&
	      canput(have[i][j],table[1-i])&&
	      (hand[i]==-1||isgreater(hand[i],have[i][j]))){
	    hand[i]=have[i][j];
	    place[i]=j;
	    state[i]=PUTL;
	    time[i]=700;
	  }
	}
      }
      //if (state[i] != IDLE)have[i][place[i]]=-1;
    }

//      cout << state[0] <<" " << state[1] << 
//        " table: " << table[0] <<" " << table[1] << endl;
//      cout << "next " << time[0] <<" " << time[1] << endl;
//      cout <<"hand " << hand[0] <<" " << hand[1] << endl;
//      rep(i,2){
//       rep(j,4)cout << have[i][j]<<" ";
//        cout << endl;
//      }

    if (isend(have[0])&&isend(have[1]))return lastput[0]>lastput[1];
    else if (isend(have[0]))return true;
    else if (isend(have[1]))return false;
  }
  assert(false);
}

//23456789HJQKA
int main(){
  string suit="CDHS";
  string tmp="23456789XJQKA";
  map<string,int> M;
  rep(j,tmp.size()){
    rep(i,suit.size()){
      string ins=string(1,suit[i]);
      ins+=tmp[j];
      M[ins]=i+j*4;
    }
  }
  
  int n;
  while(cin>>n && n){
    queue<int> S[2];
    rep(i,n){
      string in;
      cin>>in;
      //      cout << in <<" " << M[in] << endl;
      S[0].push(M[in]);
    }
    cin>>n;
    rep(i,n){
      string in;
      cin>>in;
      //      cout << in <<" " << M[in] << endl;
      S[1].push(M[in]);
    }

    if (solve(S))cout <<"A wins."<<endl;
    else cout << "B wins."<<endl;
  }
  return false;
}