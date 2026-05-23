#include<bits/stdc++.h>

using namespace std;

struct Node {
  int nxt[28];

  int exist; // 子ども以下に存在する文字列の数の合計
  vector< int > accept; // その文字列id

  Node() : exist(0) {
    memset(nxt, -1, sizeof(nxt));
  }
};

struct Trie {

  vector< Node > nodes;
  int root;

  Trie() : root(0) {
    nodes.push_back(Node());
  }

  virtual void direct_action(int node, int id) {}

  virtual void child_action(int node, int child, int id) {}

  void update_direct(int node, int id) {
    nodes[node].accept.push_back(id);
    direct_action(node, id);
  }

  void update_child(int node, int child, int id) {
    ++nodes[node].exist;
    child_action(node, child, id);
  }

  void add(const string &str, int str_index, int node_index, int id) {
    if(str_index == str.size()) {
      update_direct(node_index, id);
    } else {
      const int c = str[str_index] - 'a';
      if(nodes[node_index].nxt[c] == -1) {
        nodes[node_index].nxt[c] = (int) nodes.size();
        nodes.push_back(Node());
      }
      add(str, str_index + 1, nodes[node_index].nxt[c], id);
      update_child(node_index, nodes[node_index].nxt[c], id);
    }
  }

  void add(const string &str, int id) {
    add(str, 0, 0, id);
  }

  void add(const string &str) {
    add(str, nodes[0].exist);
  }

  void query(const string &str, const function< void(int) > &f, int str_index, int node_index) {
    for(auto &idx : nodes[node_index].accept) f(idx);
    if(str_index == str.size()) {
      return;
    } else {
      const int c = str[str_index] - 'a';
      if(nodes[node_index].nxt[c] == -1) return;
      query(str, f, str_index + 1, nodes[node_index].nxt[c]);
    }
  }

  void query(const string &str, const function< void(int) > &f) {
    query(str, f, 0, 0);
  }

  int size() const {
    return (nodes[0].exist);
  }

  int nodesize() const {
    return ((int) nodes.size());
  }
};

struct Aho_Corasick : Trie {
  static const int FAIL = 27;
  vector< int > correct;


  void build(bool heavy = true) {
    correct.resize(nodes.size());
    for(int i = 0; i < nodes.size(); i++) {
      correct[i] = (int) nodes[i].accept.size();
    }

    queue< int > que;
    for(int i = 0; i <= 27; i++) {
      if(~nodes[0].nxt[i]) {
        nodes[nodes[0].nxt[i]].nxt[FAIL] = 0;
        que.emplace(nodes[0].nxt[i]);
      } else {
        nodes[0].nxt[i] = 0;
      }
    }
    while(!que.empty()) {
      Node &now = nodes[que.front()];
      correct[que.front()] += correct[now.nxt[FAIL]];
      que.pop();
      for(int i = 0; i < 27; i++) {
        if(now.nxt[i] == -1) continue;
        int fail = now.nxt[FAIL];
        while(nodes[fail].nxt[i] == -1) fail = nodes[fail].nxt[FAIL];
        nodes[now.nxt[i]].nxt[FAIL] = nodes[fail].nxt[i];
        if(heavy) {
          auto &u = nodes[now.nxt[i]].accept;
          auto &v = nodes[nodes[fail].nxt[i]].accept;
          vector< int > accept;
          set_union(begin(u), end(u), begin(v), end(v), back_inserter(accept));
          u = accept;
        }
        que.emplace(now.nxt[i]);
      }

    }
  }

  int match(const string &str, vector< int > &result, int now = 0) {
    result.assign(size(), 0);
    int count = 0;
    for(auto &c : str) {
      while(nodes[now].nxt[c - 'a'] == -1) now = nodes[now].nxt[FAIL];
      now = nodes[now].nxt[c - 'a'];
      count += correct[now];
      for(auto &v : nodes[now].accept) ++result[v];
    }
    return (count);
  }

  int move(const char &c, int &now) {
    int count = 0;
    while(nodes[now].nxt[c - 'a'] == -1) now = nodes[now].nxt[FAIL];
    now = nodes[now].nxt[c - 'a'];
    count += correct[now];
    return (count);
  }
};

int main() {
  string S;
  cin >> S;
  int K;
  cin >> K;
  Aho_Corasick aho;
  for(int i = 0; i < K; i++) {
    string x;
    cin >> x;
    aho.add(x);
  }
  aho.build(true);
  int cur = 0;
  int ret = 0;
  for(int i = 0; i < S.size(); i++) {
    int buff = cur;
    if(aho.move(S[i], buff) > 0) {
      S[i] = 'z' + 1;
      aho.move(S[i], cur);
      ++ret;
    } else {
      aho.move(S[i], cur);
    }
  }
  cout << ret << endl;
}
