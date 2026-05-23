#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>

using namespace std;

#define foreach(i,c) for(__typeof__((c).begin()) i=(c).begin();i!=(c).end();++i)

int main()
{
	for(int n;cin>>n,n;){
		cin.ignore();
		vector<string> words;
		while(n--){
			string line; getline(cin,line);
			istringstream iss(line);
			for(string w;iss>>w;)
				words.push_back(w);
		}
		char c; cin>>c;
		
		map<string,int> m;
		for(int i=0;i<words.size();i++)
			m[words[i]]++;
		
		set<pair<int,string> > s;
		foreach(i,m)
			if(i->first[0]==c)
				s.insert(make_pair(-i->second,i->first));
		
		if(s.empty())
			cout<<"NA"<<endl;
		else{
			int cnt=0;
			foreach(i,s){
				cout<<(i==s.begin()?"":" ")<<i->second;
				if(++cnt==5)
					break;
			}
			cout<<endl;
		}
	}
	return 0;
}