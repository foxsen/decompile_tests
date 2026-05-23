#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
#include <cmath>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <sstream>
#include <string>
#define repd(i,a,b) for (int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repd(i,0,n)
#define all(x) (x).begin(),(x).end()
#define mod 1000000007
#define inf 2000000007
#define mp make_pair
#define pb push_back
typedef long long ll;
using namespace std;
template <typename T>
inline void output(T a, int p = 0) {
    if(p) cout << fixed << setprecision(p)  << a << "\n";
    else cout << a << "\n";
}
// end of template


// Trie tree (Prefix tree)
struct node{
    node *next[26] = {};
    int len[26] = {};
    bool ok = false;
    int exist = 0;
    int num = 0;
    node() {
        rep(i, 26) len[i] = 1;
    }
};

class Trie{
    
public:
    node *root;
    Trie(){
        root = new node();
    }
    
    void add(string &s){
        node *cur = root;
        for(char &c : s){
            if(!cur->next[c - 'a']){
                cur->next[c - 'a'] = new node();
                cur->exist++;
            }
            cur = cur->next[c - 'a'];
        }
        cur->ok = true;
        cur->num++;
    }
    
    // 縮約パート lenはその子のノードが何文字分縮約されているかを表す。numはcount(下参照)
    int dfs(node *n){
        if(!n) return 0;
        rep(i, 26){
            while(n->next[i] && n->next[i]->exist == 1 && !n->next[i]->ok){
                rep(j, 26){
                    if(n->next[i]->next[j]){
                        n->next[i] = n->next[i]->next[j];
                        n->len[i]++;
                        break;
                    }
                }
            }
            n->num += dfs(n->next[i]);
        }
        return n->num;
    }
    
    // ノードnの子に登録した文字列(のprefix)がいくつあるかを数える
    int count(node *n){
        return n ? n -> num : 0;
    }
    
    // 辞書順がlで定義された時のsの順番
    int ord(string &s, string &l){
        node *cur = root;
        int ret = 0;
        for(int i = 0; i < s.size();){
            char c = s[i];
            ret += cur->ok;
            rep(j, l.size()){
                if(c == l[j]){
                    i += cur->len[c - 'a'];
                    cur = cur->next[c - 'a'];
                    break;
                }
                else{
                    ret += count(cur->next[l[j] - 'a']);
                }
            }
        }
        return ret;
    }
    
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    // source code
    int N;
    cin >> N;
    vector<string> S(N);
    rep(i, N) cin >> S[i];
    Trie trie;
    rep(i, N) trie.add(S[i]);
    trie.dfs(trie.root);
    int Q;
    cin >> Q;
    rep(i, Q){
        int k;
        string s;
        cin >> k >> s;
        k--;
        output(trie.ord(S[k], s) + 1);
    }
    
    return 0;
}