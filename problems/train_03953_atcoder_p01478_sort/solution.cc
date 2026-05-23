#include<iostream>
#include<map>
#include<queue>
#include<vector>
#include<sstream>
#include<functional>
#include<stdio.h>
#include<string>
#include<string.h>
#define INF 2147483647
#define MP make_pair
using namespace std;

string start(int N){
	string st[9];
	st[0]="0";st[1]="1";st[2]="12";st[3]="123";st[4]="1234";
	st[5]="12345";st[6]="123456";st[7]="1234567";st[8]="12345678";
	return st[N];
}
int fact(int N){
	return (N==0)?1:N*fact(N-1);
}
string swapnumber(const string input,int a,int b){
	char str[9];
	char *pa,*pb;
	string before(input);
	strcpy(str,before.c_str());
	pa=strchr(str,'0'+a);pb=strchr(str,'0'+b);
	*pa='0'+b;*pb='0'+a;
	return str;
	//p=before.find(sa,0);pb=before.find(sb,0);
	
}
int main(void){
  int N;
  int c[8][8];
  map<string,int> node;//数列、コスト
  map<string,int>::iterator itr;
	priority_queue<pair<int,string>,vector<pair<int,string> >,greater<pair<int,string> > > edge;//コスト,数列
  int ans=0;
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
    	scanf("%d",&c[i][j]);
    }
  }

  string startstr=start(N);
  node.insert(MP(start(N),0));
  for(int i=0;i<N;i++){
    for(int j=i+1;j<N;j++){
    	edge.push( MP(c[i][j],swapnumber(startstr,i+1,j+1)) );
    }
  }
  while(1){
	  pair<int,string> buf;
	  if(node.size()==fact(N)){
	  	break;
	  }
 	  while(1){
  		buf=edge.top();
	  	edge.pop();
	  	
  		if(node.count(buf.second)){//既に確定してたら
  			continue;
	  	}else{//初めてだったら
	  		break;
	  	}
	  }
	  node.insert(map<string,int>::value_type(buf.second,buf.first));
	  for(int i=0;i<N;i++){
    	for(int j=i+1;j<N;j++){
   			edge.push( MP( buf.first+c[i][j],swapnumber(buf.second,i+1,j+1) ) );
   		}
 	 	}
  }
	for (itr = node.begin(); itr != node.end(); itr++){
		// キーを出力
	//	cout << itr->first << " " << itr->second << endl;
		if((itr->second)>ans){
			ans=itr->second;
		}
	}
	printf("%d\n",ans);
	
  return 0;
}