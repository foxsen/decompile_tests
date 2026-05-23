#include <bits/stdc++.h>

using namespace std;

#define int long long
#define all(v) (v).begin(), (v).end()
#define rez(v, n) (v).clear(), (v).resize(n)
#define reps(i, m, n) for(int i = (int)(m); i < (int)(n); i++)
#define rep(i, n) reps(i, 0, n)

template<class T1, class T2> void chmin(T1 &a, T2 b){if(a>b)a=b;}
template<class T1, class T2> void chmax(T1 &a, T2 b){if(a<b)a=b;}

typedef pair<int, int> Pi;
typedef tuple<int, int, int> Ti;
typedef vector<int> vint;

const int inf = 1LL << 55;
const int mod = 1e9 + 7;

template<class T> struct Min {
  T nil;
  Min(){}
  Min(T nil):nil(nil){}
  T operator()(T a, T b) {
    return a < b ? a : b;
  }
};
template<class T> struct Max {
  T nil;
  Max(){}
  Max(T nil):nil(nil){}
  T operator()(T a, T b) {
    return a > b ? a : b;
  }
};

template<class T, class F>
struct SegmentTree {
  vector<T> data;
  F func;
  int sz;
  SegmentTree(int n, F f) {
    func = f;
    sz = 1; while(sz < n) sz <<= 1;
    data.resize(2*sz+1, func.nil);
  }
  void update(int k, T x) {
    k += sz-1;
    data[k] = x;
    while(k > 0) {
      k = (k-1)/2;
      data[k] = func(data[2*k+1], data[2*k+2]);
    }
  }
  T query(int a, int b, int k, int l, int r) {
    if(r <= a || b <= l) return func.nil;
    if(a <= l && r <= b) return data[k];
    return func(query(a, b, 2*k+1, l, (l+r)/2),
	       query(a, b, 2*k+2, (l+r)/2, r));
  }
  T query(int a, int b) {
    return query(a, b, 0, 0, sz);
  }
};

int N, L;
vint A, B, C, D;
vint sumC, sumD;
vint idx;

bool cmp(int i, int j) {
  return D[i] > D[j];
}

signed main()
{
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(12);

  cin >> N >> L;
  rez(A, N), rez(B, N), rez(C, N), rez(D, N);
  rep(i, N) {
    cin >> A[i] >> B[i];
    D[i] = A[i]-B[i];
  }
  rep(i, N) {
    cin >> C[i];
  }

  rez(idx, N);
  rep(i, N) idx[i] = i;
  sort(all(idx), cmp);
  rez(sumC, N+1), rez(sumD, N+1);
  rep(i, N) {
    sumD[i+1] = sumD[i] + D[idx[i]];
    sumC[i+1] = sumC[i] + C[i];
  }

  SegmentTree< int, Max<int> > segA(N, Max<int>(-inf)), segB(N, Max<int>(-inf));
  rep(i, N) {
    int k = idx[i];
    segA.update(i, A[k]);
    segB.update(i, B[k]);
  }

  SegmentTree< int, Min<int> > segX(N, Min<int>(inf));
  rep(i, N) {
    segX.update(i, sumD[i+1]-sumC[i+1]);
  }

  int ans = inf;
  rep(i, N) {
    int a = segA.query(i, N);
    if(sumD[i]+a >= L) {
      //cout<<sumD[i]+a<<" "<<L<<endl;
      chmin(ans, i);
      break;
    }

    //cout<<"BIN_SEARCH"<<endl;
    int lb = -1, ub = i;
    while(lb+1 < ub) {
      int mb = (lb+ub)/2;
      //cout<<idx[mb]<<" "<<idx[i]<<endl;
      //cout<<segX.query(mb, i) << " "<< D[idx[mb]]-D[idx[i]]<<endl;
      if(segX.query(mb, i) > D[idx[mb]]-D[idx[i]]) ub = mb;
      else lb = mb;
    }
    int b = segB.query(ub, i);
    if(b != -inf) {
      //cout<<"OK"<<endl;
      //cout << ub << " " << b << endl;
      //cout<<sumD[i+1]<<" " << b << endl;
      if(sumD[i+1]+b >= L) {
	chmin(ans, i);
	break;
      }
    }
    if(sumD[i+1] <= sumC[i+1]) break;
  }

  cout << (ans == inf ? -1 : ans+1) << endl;

  return 0;
}