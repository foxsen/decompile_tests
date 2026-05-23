#include <bits/stdc++.h>
using namespace std;

int N,M;
int q[100005];
int p[100005];

const int MAX = (1<<17);
struct seg {
  int d[2*MAX];
  int n = 0;
  void init(int _n){
    memset( d,0,sizeof(d) );
    n = 1;
    while( n < _n ) n*=2;
  }
  void set(int k,int x){
    k += n-1;
    d[k] = x;
    while( k ){
      k = (k-1)/2;
      d[k] = max( d[2*k+1], d[2*k+2] );
    }
  }
  int query(int a,int b,int k,int l,int r){
    if( r <= a || b <= l ) return 0;
    else if( a <= l && r <= b ) {
      return d[k];
    } else {
      int vl = query( a, b, 2*k+1, l, (l+r)/2 );
      int vr = query( a, b, 2*k+2, (l+r)/2, r );
      return max( vl, vr );
    }
  }
  int query(int a,int b){
    return query( a, b, 0, 0, n );
  }

};

seg S;
void rev(){
  for(int i = 0; i < N; i++ )
    q[i] = N-q[i];
}
int check(int id,int k,int f){
  if( id >= N ) return N;
  if( f == -1 ) rev();
  S.init(N);
  for(int i=id;i<N;i++){
    int x = S.query( 0, q[i] );
//    cout << i << " " <<q[i] << " "<<  x << endl;
    x++;
    S.set( q[i], x );
  //  cout << i << ": " << x << endl;
    if(x == k) {
      if( f == -1 ) rev();
      return i;
    }
  }
  if( f == -1 ) rev();
  return N;
}

int main(){
  cin >> N;
  for(int i=0;i<N;i++){
    cin >> q[i];
  }
  cin >> M;
  for(int i=0;i<M;i++)
    cin >> p[i];

  if( N == 1 && M ==1  ){
    cout << "Yes" << endl;
    return 0;
  }

  int id = 0;
  int k = 2;
  int f = (p[1]-p[0])<0?-1:1;
  for(int i=1;i<M-1;i++){
    int nf = (p[i+1]-p[i])<0?-1:1;
    if( nf != f ){
  //    cout << id << " " <<k << " "<< f << endl;
      id = check( id, k, f );
      k = 2; f = nf;
    } else {
      k++;
    }
  }
//  cout << id << " "<< k <<" " << f << endl;
  id = check( id, k, f );
  if( id >= N ) cout << "No" << endl;
  else cout << "Yes" << endl;


}