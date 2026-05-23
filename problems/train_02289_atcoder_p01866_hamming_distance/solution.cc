#include <bits/stdc++.h>

using namespace std;

#define FOR(i,s,e) for(int (i)=(s);(i)<(int)(e);(i)++)
#define REP(i,e) FOR(i,0,e)
#define RFOR(i,e,s) for(int (i)=(e)-1;(i)>=(int)(s);(i)--)
#define RREP(i,e) RFOR(i,e,0)

#define all(o) (o).begin(), (o).end()
#define psb(x) push_back(x)
#define mp(x,y) make_pair((x),(y))

typedef long long ll;
typedef pair<int, int> PII;
typedef priority_queue<int> PQI;
typedef priority_queue<PII> PQII;

const double EPS = 1e-10;
const int N = 1000;
int usd[N];

int main() {
  memset(usd, 0, sizeof(usd));
  int n, d;
  string x, res;
  scanf("%d ", &n);
  cin >> x;
  res = x;
  scanf("%d ", &d);
  int i=0, j=0;
  while (i<n && j<d) {
    if (x[i]=='0' && !usd[i]) {
      res[i] = '1'; 
      usd[i] = 1;
      j++;
    }
    i++;
  }

  i=n-1;
  while (i>=0 && j<d) {
    if (x[i]=='1' && !usd[i]) {
      res[i] = '0';
      usd[i] = 1;
      j++;
    }
    i--;
  }

  cout << res << endl;

  return 0;
}