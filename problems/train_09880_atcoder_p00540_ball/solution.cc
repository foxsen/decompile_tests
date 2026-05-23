#include<bits/stdc++.h>
using namespace std;
typedef long long int64;
const int64 INF = 1LL << 55;
 
int toChild[1000000][3];
int Buffer[99999];
vector< int > Dwill;
int N, M;
 
int MakeTree(){
  queue< int > que;
  for(int i = 0; i < N; i++){
    que.push(i);
    toChild[i][0] = -1;
    toChild[i][1] = -1;
    toChild[i][2] = -1;
  }
  int nextIndex = N;
  while(que.size() > 1){
    toChild[nextIndex][0] = que.front(); que.pop();
    toChild[nextIndex][1] = que.front(); que.pop();
    toChild[nextIndex][2] = que.front(); que.pop();
    que.push(nextIndex);
    ++nextIndex;
  }
  return(que.front());
}
 
int64 getDP(const int64& Value, int index) {
  if(toChild[index][0] == -1){
    if(Buffer[index] == 0) return(1);
    else if(Buffer[index] >= Value) return(0);
    else return(INF);
  } else {
    int64 array[] = { getDP(Value, toChild[index][0]), getDP(Value, toChild[index][1]), getDP(Value, toChild[index][2])};
    sort( array, array + 3);
    return(min(INF - 1, array[0] + array[1]));
  }
}
 
bool Calclation(int64 Value, const int& root){
  int High = Dwill.end() - lower_bound( Dwill.begin(), Dwill.end(), Value);
  return(getDP(Value, root) <= High);
}
 
int main() {
  cin >> N >> M;
  for(int i = 0; i < M; i++){
    int D, P;
    cin >> D >> P;
    --P;
    Buffer[P] = D;
  }
  Dwill.resize(N - M);
  for(int i = 0; i < N - M; i++){
    cin >> Dwill[i];
  }
  sort( Dwill.begin(), Dwill.end());
  int root = MakeTree();
  int64 low = 0, high = INF;
  while(high - low > 0){
    int64 mid = (low + high + 1) / 2;
    if(Calclation(mid, root)) low = mid;
    else high = mid - 1;
  }
  cout << low << endl;
}