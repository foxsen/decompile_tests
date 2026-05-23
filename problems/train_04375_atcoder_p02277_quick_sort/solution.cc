#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int Partition(vector<pair<char, int> >& A, int p, int r)
{
    int x = A[r - 1].second;
    int i = p - 1;
    
    for(int j = p; j < r - 1; ++j){
        if(A[j].second <= x){
            ++i;
            swap(A[i], A[j]);
        }
    }
    swap(A[i + 1], A[r - 1]);
    return i + 1;
}

void QuickSort(vector<pair<char, int> >& A, int p, int r)
{
    if(p < r){
        int q = Partition(A,p,r);
        QuickSort(A,p,q);
        QuickSort(A,q + 1,r);
    }
}

bool comp(const pair<char, int>& p1, const pair<char, int>& p2)
{
    return p1.second < p2.second;
}

int main()
{
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<pair<char, int> > A(n);
    
    for(int i = 0; i < n; ++i){
        cin >> A[i].first >> A[i].second;
    }
    
    vector<pair<char, int> > B(A);
    
    stable_sort(B.begin(),B.end(),comp);
    QuickSort(A,0,n);
    
    cout << (A == B ? "Stable" : "Not stable") << endl;
    for(int i = 0; i < n; ++i){
        cout << A[i].first << ' ' << A[i].second << endl;
    }
}