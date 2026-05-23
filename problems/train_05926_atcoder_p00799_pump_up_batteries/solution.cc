#include<bits/stdc++.h>

#define REP(i,s,n) for(int i=s;i<n;i++)
#define rep(i,n) REP(i,0,n)

using namespace std;

typedef pair<int,int> ii;

struct Data{
  int id,stamp;
  bool operator < ( const Data& data ) const {
    if( stamp != data.stamp ) return stamp > data.stamp;
    return id > data.id;
  }
};

vector<ii> cycle[110];
int n,m,run_time[110],indices[110],charger,charge_id;
bool inQueue[110];

int simulate(){

  rep(i,n) run_time[i] = cycle[i][0].first, indices[i] = 0, inQueue[i] = false;
  charger = 0, charge_id = -1;
  priority_queue<Data> Q;
  int ret = 0;
  rep(_,m){

    rep(i,n) {
      if( run_time[i] <= 0 && !inQueue[i] ) {
        Q.push((Data){i,_});
        inQueue[i] = true;
      }
      run_time[i]--;
    }

    if( charger == 0 && !Q.empty() ) {
      charge_id = Q.top().id; Q.pop();
      charger = cycle[charge_id][indices[charge_id]].second;
    } 

   if( charger ) {
      --charger;
      if( charger <= 0 ) {
        inQueue[charge_id] = false;
        ( indices[charge_id] += 1 ) %= (int)cycle[charge_id].size();
        run_time[charge_id] = cycle[charge_id][indices[charge_id]].first;
      }
    } 

    ret += (int)Q.size();

  }

  return ret;
}

int main(){
  while( cin >> n >> m, n | m ){
    rep(i,n) {
      int a,b;
      cycle[i].clear();
      while( cin >> a , a ){
        cin >> b;
        cycle[i].push_back(ii(a,b));
      }
    }

    cout << simulate() << endl;

  }
  return 0;
}