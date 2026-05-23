#include <bits/stdc++.h>
using namespace std;

template<typename Monoid,typename OperatorMonoid>
struct LazySegmentTree{
    typedef function<Monoid(Monoid,Monoid)> F;
    typedef function<Monoid(Monoid,OperatorMonoid)> G;
    typedef function<OperatorMonoid(OperatorMonoid,OperatorMonoid)> H;
    int n,hi;
    F f;
    G g;
    H h;
    Monoid id0;
    OperatorMonoid id1;
    vector<Monoid> dat;
    vector<OperatorMonoid> laz;
    LazySegmentTree(int n_,F f,G g,H h,Monoid id0,OperatorMonoid id1):
                    f(f),g(g),h(h),id0(id0),id1(id1){init(n_);}
    void init(int n_){
        n=1,hi=0;
        while(n<n_) n<<=1,++hi;
        dat.assign(n<<1,id0);
        laz.assign(n<<1,id1);
    }
    void build(const vector<Monoid> &v){
        for (int i=0;i<v.size();++i) dat[i+n]=v[i];
        for (int i=n-1;i;--i) dat[i]=f(dat[i<<1|0],dat[i<<1|1]);
    }
    inline Monoid reflect(int k){
        return laz[k]==id1?dat[k]:g(dat[k],laz[k]);
    }
    inline void propagate(int k){
        if (laz[k]==id1) return;
        laz[k<<1|0]=h(laz[k<<1|0],laz[k]);
        laz[k<<1|1]=h(laz[k<<1|1],laz[k]);
        dat[k]=reflect(k);
        laz[k]=id1;
    }
    inline void thrust(int k){
        for (int i=hi;i;--i) propagate(k>>i);
    }
    inline void recalc(int k){
        while(k>>=1) dat[k]=f(reflect(k<<1|0),reflect(k<<1|1));
    }
    void update(int a,int b,OperatorMonoid x){
        if (a>=b) return;
        thrust(a+=n),thrust(b+=n-1);
        for (int l=a,r=b+1;l<r;l>>=1,r>>=1){
            if (l&1) laz[l]=h(laz[l],x),++l;
            if (r&1) --r,laz[r]=h(laz[r],x);
        }
        recalc(a),recalc(b);
    }
    void set_val(int k,Monoid x){
        thrust(k+=n);
        dat[k]=x,laz[k]=id1;
        recalc(k);
    }
    Monoid query(int a,int b){
        if (a>=b) return id0;
        thrust(a+=n),thrust(b+=n-1);
        Monoid vl=id0,vr=id0;
        for (int l=a,r=b+1;l<r;l>>=1,r>>=1){
            if (l&1) vl=f(vl,reflect(l++));
            if (r&1) vr=f(reflect(--r),vr);
        }
        return f(vl,vr);
    }
    // most left position p that f[a...p] meets conditin "check"
    template<typename C>
    int find_first(int a,const C &check,Monoid &M,int k,int l,int r){
        if (l+1==r){
            M=f(M,reflect(k));
            return check(M)?k-n:-1;
        }
        propagate(k);
        int m=(l+r)>>1;
        if (m<=a) return find_first(a,check,M,k<<1|1,m,r);
        if (a<=l&&!check(f(M,dat[k]))){
            M=f(M,dat[k]);
            return -1;
        }
        int vl=find_first(a,check,M,k<<1|0,l,m);
        if (~vl) return vl;
        return find_first(a,check,M,k<<1|1,m,r);
    }
    template<typename C>
    int find_first(int a,const C &check){
        Monoid M=id0;
        return find_first(a,check,M,1,0,n);
    }
    // most right position p that f[p...b) meets condition "check"
    template<typename C>
    int find_last(int b,const C &check,Monoid &M,int k,int l,int r){
        if (l+1==r){
            M=f(reflect(k),M);
            return check(M)?k-n:-1;
        }
        propagate(k);
        int m=(l+r)>>1;
        if (b<=m) return find_last(b,check,M,k<<1|0,l,m);
        if (r<=b&&!check(f(dat[k],M))){
            M=f(dat[k],M);
            return -1;
        }
        int vr=find_last(b,check,M,k<<1|1,m,r);
        if (~vr) return vr;
        return find_last(b,check,M,k<<1|0,l,m);
    }
    template<typename C>
    int find_last(int b,const C &check){
        Monoid M=id0;
        return find_last(b,check,M,1,0,n);
    }
    Monoid operator[](int i){return query(i,i+1);}
};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N,Q; cin >> N >> Q;
    vector<int> A(N);
    for (int i=0;i<N;++i) cin >> A[i];

    struct node{
        int a,b; long long c,d;
        node(int a,int b,long long c,long long d):a(a),b(b),c(c),d(d){}
    };
    auto f=[](node a,node b){return node(a.a+b.a,a.b+b.b,a.c+b.c+(long long)a.a*b.b,a.d+b.d+(long long)a.b*b.a);};
    auto g=[](node a,int x){
        if (!x) return a;
        return node(a.b,a.a,a.d,a.c);
    };
    auto h=[](int a,int b){return a^b;};
    LazySegmentTree<node,int> seg(N,f,g,h,node(0,0,0,0),0);
    vector<node> v;
    for (int i=0;i<N;++i){
        if (A[i]) v.emplace_back(0,1,0,0);
        else v.emplace_back(1,0,0,0);
    }
    seg.build(v);

    for (;Q--;){
        int T,L,R; cin >> T >> L >> R;
        if (T==1) seg.update(--L,R,1);
        else cout << seg.query(--L,R).d << '\n';
    }
}