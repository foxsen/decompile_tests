#include<iostream>
#include<sstream>
#include<map>
#include<string>
using namespace std;

#define INF 100000000

int main()
{	
	int n;
	string temp;
	int a;
	int cost[201][201],minicost[201];
	while(cin>>n && n!=0){

		for(int i=0;i<=200;i++){
			for(int j=0;j<=200;j++){
				cost[i][j]=INF;
			}
			minicost[i]=INF;
		}


		map<string,int> Idx;
		int num=0;
		for(int i=0;i<n;i++){
			cin>>a;//1
			string s,t,p; cin>>s>>temp>>p>>t;
			if(!Idx.count(s)){Idx[s]=num++;}
			if(!Idx.count(t)){Idx[t]=num++;}
			std::istringstream is(p);
			int k;
			char taa;
			is>>a>>taa>>k;
			cost[Idx[s]][Idx[t]]=k;
			cost[Idx[t]][Idx[s]]=-k;
		}

		int count=0;
		while(true){
			bool update=false;
			for(int i=0;i<num;i++){
				for(int j=0;j<num;j++){
					if(cost[i][j]<INF){
						if(minicost[j]>minicost[i]+cost[i][j]){
							update=true;
							minicost[j]=minicost[i]+cost[i][j];
						}
					}
				}
			}
			if(!update){cout<<"Yes"<<endl;break;}
			count++;
			if(count>n+1){cout<<"No"<<endl;break;}
		}
	}
	return 0;
}