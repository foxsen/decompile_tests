/****Bismillahir rahmanir rahim****/

#include<bits/stdc++.h>

using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vl;

template <typename T>
void get_vector(T &a)
{
    for(auto &e: a) cin >> e;
}

template <typename T>
void put_vector(T a)
{
    for(auto e :a)cout << e << " ";
    cout << endl;
}
int n;
bool is_sorted(vi a)
{
    for(int i = 0;i<2*n;i++)
    {
        if(a[i]!=i+1)return false;
    }
    return true;
}
#define SWAP(a,b){\
    a^=b;\
    b^=a;\
    a^=b;\
}


int main()
{
    cin >> n;
    vi a(2*n);
    get_vector(a);
    vi b = a;
    bool op = true;
    int ans1 = -1;
    int ans2 = -1;
    for(int i = 0; i<2*n+2;i++)
    {
        if(is_sorted(a))
        {
            ans1 = i;
            break;
        }
        if(op)
        {
            for(int i = 0; i<2*n; i+=2)
            {
                SWAP(a[i],a[i+1]);
            }
        }
        else{
            for(int i = 0; i<n; i++)
            {
                SWAP(a[i],a[i+n]);
            }
        }
        //put_vector(a);
        op = !op;
    }
    op = false;
    for(int i = 0; i<2*n+2;i++)
    {
        if(is_sorted(b))
        {
            ans2 = i;
            break;
        }
        if(op)
        {
            for(int i = 0; i<2*n; i+=2)
            {
                SWAP(b[i],b[i+1]);
            }
        }
        else{
            for(int i = 0; i<n; i++)
            {
                SWAP(b[i],b[i+n]);
            }
        }
        op = !op;
    }
    if(ans1 == -1&&ans2 ==-1)
    {
        cout << -1 << endl;
        return 0;
    }
    cout << min(ans1,ans2) << endl;
    return 0;
    
}
 
