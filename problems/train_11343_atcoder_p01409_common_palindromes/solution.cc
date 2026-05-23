#include <cstdio>
#include <iostream>
#include <queue>
#include <set>

using namespace std;

template<typename C, typename C::value_type low, typename C::value_type high>
class PalindromeTree{
  const static int m = high - low + 1;
  typedef typename C::value_type T;

  struct node{
    int next[m];
    int len;
    int sufflink;
  };

  const C s;
  int len;
  int num;

  void initTree(){
    num = 2; suff = 2;
    tree[1].len = -1; tree[1].sufflink = 1;
    tree[2].len = 0; tree[2].sufflink = 1;
  }

public:
  vector<node> tree;
  int suff;

  bool addLetter(int pos){
    int cur = suff;
    int curLen = 0;
    const int let = s[pos] - low;

    while(true){
      curLen = tree[cur].len;
      if(pos - 1 - curLen >= 0 && s[pos - 1 - curLen] == s[pos]) break;
      cur = tree[cur].sufflink;
    }

    if(tree[cur].next[let]){
      suff = tree[cur].next[let];
      return false;
    }

    num++;
    suff = num;
    tree[num].len = tree[cur].len + 2;
    tree[cur].next[let] = num;

    if(tree[num].len == 1){
      tree[num].sufflink = 2;
      return true;
    }

    while(true){
      cur = tree[cur].sufflink;
      curLen = tree[cur].len;
      if(pos - 1 - curLen >= 0 && s[pos - 1 - curLen] == s[pos]){
	tree[num].sufflink = tree[cur].next[let];
	break;
      }
    }

    return true;
  }

  PalindromeTree(const C &s)
    : s(s), len(s.size()), tree(s.size() + 3){
    initTree();
  }

  void build(){
    for(int i = 0; i < len; i++){
      addLetter(i);
    }
  }

  static long long countSamePalindrome(const C &s, const C &t, const C &sp){
    long long ans = 0;
    const C sum = s + sp + t;
    PalindromeTree tree(sum);
    vector<long long> scnt(sum.size() + 3);
    vector<long long> tcnt(sum.size() + 3);

    for(int i = 0; i < (int)sum.size(); i++){
      tree.addLetter(i);

      int pos = tree.suff;
      const node &nd = tree.tree[pos];
      if(i - nd.len + 1 < (int)s.size()){
	scnt[pos]++;
      }else if(i - nd.len + 1 >= (int)(s.size() + sp.size())){
	tcnt[pos]++;
      }
    }

    for(int i = 0; i < 2; i++){
      vector<long long> &v = i == 0 ? scnt : tcnt;

      vector<int> ref(v.size());
      for(int j = 3; j < (int)v.size(); j++){
	if(v[j] > 0 && tree.tree[j].sufflink >= 3){
	  ref[tree.tree[j].sufflink]++;
	}
      }

      queue<int> q;
      for(int j = 3; j < (int)v.size(); j++){
	if(v[j] > 0 && ref[j] == 0) q.push(j);
      }

      while(q.size()){
	const int pos = q.front(); q.pop();
	const int suff = tree.tree[pos].sufflink;
	if(suff >= 3){
	  v[suff] += v[pos];
	  ref[suff]--;
	  if(ref[suff] == 0) q.push(suff);
	}
      }
    }

    for(int i = 3; i < (int)scnt.size(); i++){
      ans += scnt[i] * tcnt[i];
    }

    return ans;
  }
};

typedef PalindromeTree<string, 'a', 'z'> SPalindromeTree;

char buff[50000 + 10];
string getStr(){
  scanf("%s", buff);
  return buff;
}

int main(){
  const string s = getStr();
  const string t = getStr();

  typedef PalindromeTree<string, 'A' - 2, 'Z'> SPalindromeTree;
  printf("%lld\n", SPalindromeTree::countSamePalindrome(s, t, "@?"));
  return 0;
}