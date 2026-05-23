#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef vector<int> vi;

int main(){
  int l; cin >> l;
  while(l--){
    vi seq;
    int n=0;
    {
      int tmp;
      while(cin >> tmp, tmp){
	seq.pb(tmp);
	if(tmp>0)n++;
      }
    }
    
    vi d(n,0), s;
    vector<vi> a(n);
    int id = 0;
    s.pb(0); d[0] = seq[0];

    for(int i=1;i<(int)seq.size();i++){
      if(seq[i]>0){
	id++;

	a[s.back()].pb(id);
	a[id].pb(s.back());
	d[id] = seq[i]-1;
	d[s.back()]--;

	s.pb(id);
      }else{
	int u = s[s.size()-1+seq[i]];

	a[s.back()].pb(u);
	a[u].pb(s.back());
	d[u]--;
	d[s.back()]--;
      }
      while(s.size() && d[s.back()]==0)s.pop_back();
    }

    for(int i=0;i<n;i++){
      cout << i+1;
      sort(a[i].begin(), a[i].end());
      for(int u : a[i])cout << " " << u+1;
      cout << endl;
    }
  }
}