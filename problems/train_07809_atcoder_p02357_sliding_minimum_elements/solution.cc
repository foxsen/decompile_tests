#include<bits/stdc++.h>
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }

using Lint=long long;

template<typename T> class SlidingBestElement
{
 private:
    vector<T> a,best;
    int N,L;
    deque<int> deq;
    function<bool(T,T)> good;
 public:
    SlidingBestElement(vector<T> a,int L,function<bool(T,T)> good):a(a),N(a.size()),L(L),good(good)
    {
        for(int i=0;i<L;i++) insert(i);
        best.resize(N-L+1);
        for(int i=0;i+L<=N;i++){
            best[i]=a[deq[0]];
            if(deq[0]==i) deq.pop_front();
            if(i+L<N) insert(i+L);
        }
    }
    void insert(int i){
        while(!deq.empty() and !good(a[deq.back()],a[i])) deq.pop_back();
        deq.push_back(i);
    }
    T operator[](int i){ return best[i]; }
};

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N,L; cin>>N>>L;
    vector<int> a(N);
    for(int i=0;i<N;i++) cin>>a[i];

    SlidingBestElement<int> best(a,L,[](int a,int b){return a<b;});
    for(int i=0;i+L<=N;i++){
        cout<<best[i]<<(i+L==N? '\n':' ');
    }  
    return 0;
}
