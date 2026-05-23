#include<iostream>
#include<vector>
#include<cassert>
#include<string>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<stack>
#include<queue>
#include<set>
#include<map>
#include<tuple>
#include<numeric>
using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
typedef ll int__;
#define rep(i,j) for(int__ i=0;i<(int__)(j);i++)
#define repeat(i,j,k) for(int__ i=(j);i<(int__)(k);i++)
#define all(v) v.begin(),v.end()

const ll INF = 1LL << 60;

template<typename T>
ostream& operator << (ostream &os , const vector<T> &v){
    rep(i,v.size()) os << v[i] << (i!=v.size()-1 ? " " : "\n"); return os;
}

template<typename T>
istream& operator >> (istream &is , vector<T> &v){
    rep(i,v.size()) is >> v[i]; return is;
}

#ifdef DEBUG
void debug(){ cerr << endl; }
#endif
template<class F,class...R>
void debug(const F &car,const R&... cdr){
#ifdef DEBUG
    cerr << car << " "; debug(cdr...);
#endif
}


#include<functional>
using Index = int;

template<typename Data>
class SegmentTree{
  public:
    int N;
    vector<Data> data;
    vector<Data> sum;
    function< Data(Data,Data) > selector;
    Data default_val;

    
    SegmentTree(int n, function< Data(Data,Data) > selector,Data default_val)
            :selector(selector),default_val(default_val){
        N = n;
        n = 1;
        while(n < N) n *= 2;
        //data.resize(2 * n - 1, default_val);
        data.resize(2 * n - 1, 0);
        sum.resize(2 * n - 1, 0);
    }

    // ??????[a,b) ??? add val
    void add(Index a, Index b, Data val){
        debug("[", a, b, ") += ", val);
        add(a, b, val, 0, 0, N);
    }
    
    // [a,b) ????????¨???
    Data query(Index a, Index b){
        assert( a < b );
        assert( 0 <= a and b <= N );
        //debug("query [", a, b, ") is", search(a, b, 0, 0, N));
        return search(a, b, 0, 0, N);
    }
  private:
    //[a,b)???????°????,k???????????´???,[l,r)????????????????????????
    Data search(Index a, Index b, Index k, Index l, Index r){
        if( r <= a or b <= l ) return default_val; // ?????????
        if( a <= l and r <= b ) return data[k];    // ?????????
        else { // ????????????
            Index m = (l + r) / 2;
            Data vl = search(a, b, k * 2 + 1, l, m);
            Data vr = search(a, b, k * 2 + 2, m, r);
            debug("search [", a, b, ") is", selector(vl, vr));
            return selector(vl, vr) + sum[k];
        }
    }

    //??????[a, b)??????????????????????????????????°?????????????
    // k  : ???????????????(??¨???)index
    // [l, r): k?????????????????????
    void add(Index a, Index b, Data x, Index k, Index l, Index r){
        if( a <= l and r <= b){
            data[k] += x;
            sum[k] += x;
        } else if(l < b and a < r){ //???????????£???????????????
            Index m = (l + r) / 2;
            Index lc = k * 2 + 1;
            Index rc = k * 2 + 2;
            add(a, b, x, lc, l, m);
            add(a, b, x, rc, m, r);
            data[k] = selector( data[lc], data[rc]) + sum[k];
        }
    }

};


void debug_out(SegmentTree<ll> &st){
    rep(i, st.N){
        debug("ST[",i,"] = ", st.query(i,i+1));
    }
}

bool solve(){
    int N; cin >> N;
    N /= 2;
    SegmentTree<ll> lminq(N, [](ll a, ll b){ return min(a, b); },  INF);
    SegmentTree<ll> lmaxq(N, [](ll a, ll b){ return max(a, b); }, -INF);

    rep(i, N*2){
        int s; cin >> s;
        if(i >= N) s *= -1;
        int idx = i < N ? i : N - i%N -1;
        lminq.add(idx, idx + 1, s);
        lmaxq.add(idx, idx + 1, s);
    }

    int Q; cin >> Q;
    rep(i, Q){
        int l, r, x; cin >> l >> r >> x;
        l--; r--;

        int ll = l < N ? l : N - l%N -1;
        int rr = r < N ? r : N - r%N -1;
        if(ll > rr){
            swap(ll, rr);
            x *= -1;
        } else if(l == r and l >= N){
            x *= -1;
        }
        if(l == r or ll != rr){
            if( l < N and N <= r) rr--;
            lminq.add(ll, rr + 1, x);
            lmaxq.add(ll, rr + 1, x);
        }
        cout << ( lminq.query(0, N) == 0 and lmaxq.query(0, N) == 0 ) << endl;
    }
    
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    while(solve());
    return 0;
}