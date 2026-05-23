#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Team{
public:
  int id, pr, pe;
  Team(){}
  Team(int id, int pr, int pe): id(id), pr(pr), pe(pe){}
  bool operator < (const Team &t) const {
    if(pr != t.pr) return pr > t.pr;
    if(pe != t.pe) return pe < t.pe;
    return id > t.id;
  }
  bool operator == (const Team &t) const {
    return pr == t.pr && pe == t.pe;
  }
};

const int N = 50;

int M, T, P, R;
bool sc[N][10];
int cnt[N][10];
Team team[N];

int main(){
  while(cin >> M >> T >> P >> R && (M|T|P|R)){
    for(int i=0;i<T;i++) team[i] = Team(i, 0, 0);
    fill(sc[0], sc[N], false);
    fill(cnt[0], cnt[N], 0);
    for(int i=0;i<R;i++){
      int m, t, p, j;
      cin >> m >> t >> p >> j;
      t--; p--;
      if(j) cnt[t][p]++;
      else if(!sc[t][p]){
        sc[t][p] = true;
        team[t].pr++;
        team[t].pe += m + 20 * cnt[t][p];
      }
    }
    sort(team, team+T);
    cout << team[0].id+1;
    for(int i=1;i<T;i++) cout << (team[i-1] == team[i] ? '=' : ',') << team[i].id+1;
    cout << endl;
  }
}