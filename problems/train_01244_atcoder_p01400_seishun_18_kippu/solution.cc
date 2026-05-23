#include <iostream>
#include <map>
using namespace std;

int main(){
  int n,m;
  string s,p,g,a,b;

  while( cin>>n>>m && n && m ){
    cin >> s >> p >> g;
    int d[n][n];
    for( int i=0;i<n;i++ ){
      for( int j=0;j<n;j++ )
	d[i][j] = 10000000;
      d[i][i] = 0;
    }

    map<string,int> mp;
    int nn=0;
    for( int i=0;i<m;i++ ){
      int dd,t;
      cin >> a >> b >> dd >> t;
      if( mp.find(a) == mp.end() )
	mp[a] = nn++;
      if( mp.find(b) == mp.end() )
	mp[b] = nn++;
      int time = dd/40 + t;
      d[ mp[a] ][ mp[b] ] = d[ mp[b] ][ mp[a] ] = time;
    }

    for( int k=0;k<n;k++ )
      for( int i=0;i<n;i++ )
	for( int j=0;j<n;j++ )
	  d[i][j] = min( d[i][j], d[i][k] + d[k][j] );

    cout << d[ mp[s] ][ mp[p] ] + d[ mp[p] ][ mp[g] ] << endl;
  }

  return 0;
}