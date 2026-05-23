#include<bits/stdc++.h>
using namespace std;
template<typename T>
struct BIT{
    private:
    vector<T> array;
    const int n;

    public:
    BIT(int _n):array(_n+1,0),n(_n) {}

    T sum(int i){
        T s=0;
        while(i>0){
            s+=array[i];
            i-=i&-i;
        }
        return s;
    }
    
    T sum(int i,int j){
        return sum(j)-sum(i-1);
    }

    void add(int i,T x){
        while(i<=n){
            array[i]+=x;
            i+=i&-i;
        }
    }
    void pr(int i){
        cout << array[i] << endl;
    }
};
int main(){
    int n,q;cin >> n >> q;
    int c,x,y;
    BIT<int> bit(n);
    while(q--){
        cin >> c >> x >> y;
        if(!c){
            bit.add(x,y);
        }
        else{
            cout << bit.sum(x,y) << endl;
        }
    }
}
