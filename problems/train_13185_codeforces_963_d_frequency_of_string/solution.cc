#include <bits/stdc++.h>
using namespace std;
const int MAXCHAR = 26;
struct STATE {
  int next[MAXCHAR];
  int suf_state;
  int out_state;
  int id_of_pattern;
  int isLeaf;
  STATE() {
    for (int i = 0; i < MAXCHAR; i++) {
      next[i] = -1;
    }
    suf_state = out_state = id_of_pattern = isLeaf = -1;
  }
};
void add_string(vector<struct STATE>& states, const string& s, const int& id) {
  int curr_state = 0, c;
  for (auto ch : s) {
    c = ch - 'a';
    if (states[curr_state].next[c] == -1) {
      states[curr_state].next[c] = (int)states.size();
      states.emplace_back();
    }
    curr_state = states[curr_state].next[c];
  }
  states[curr_state].isLeaf = 1;
  states[curr_state].id_of_pattern = id;
}
void construct_trie(vector<struct STATE>& states, const vector<string>& query) {
  for (int i = 0; i < (int)query.size(); i++) {
    add_string(states, query[i], i);
  }
}
void build_automaton(vector<struct STATE>& states) {
  queue<pair<int, pair<int, int> > > q;
  for (int i = 0; i < MAXCHAR; i++) {
    if (states[0].next[i] != -1) {
      states[states[0].next[i]].suf_state = 0;
      q.push({i, {0, states[0].next[i]}});
    }
  }
  while (!q.empty()) {
    pair<int, pair<int, int> > pt = q.front();
    q.pop();
    int c = pt.first;
    int prev_state = pt.second.first;
    int curr_state = pt.second.second;
    if (states[curr_state].suf_state == -1) {
      int state_x = states[prev_state].suf_state;
      while (state_x != -1 && states[state_x].next[c] == -1) {
        state_x = states[state_x].suf_state;
      }
      states[curr_state].suf_state =
          (state_x == -1) ? 0 : states[state_x].next[c];
    }
    if (states[curr_state].out_state == -1) {
      if (states[states[curr_state].suf_state].isLeaf == 1) {
        states[curr_state].out_state = states[curr_state].suf_state;
      } else {
        states[curr_state].out_state =
            states[states[curr_state].suf_state].out_state;
      }
    }
    for (int i = 0; i < MAXCHAR; i++) {
      if (states[curr_state].next[i] != -1) {
        q.push({i, {curr_state, states[curr_state].next[i]}});
      }
    }
  }
}
void search_(const vector<struct STATE>& states, const string& s,
             vector<vector<int> >& index) {
  int curr_state = 0;
  for (int i = 0; i < (int)s.size(); i++) {
    int c = s[i] - 'a';
    while (curr_state != 0 && states[curr_state].next[c] == -1) {
      curr_state = states[curr_state].suf_state;
    }
    if (states[curr_state].next[c] != -1) {
      curr_state = states[curr_state].next[c];
      if (states[curr_state].isLeaf == 1) {
        index[states[curr_state].id_of_pattern].push_back(i);
      }
      int out_s = states[curr_state].out_state;
      while (out_s != -1) {
        index[states[out_s].id_of_pattern].push_back(i);
        out_s = states[out_s].out_state;
      }
    }
  }
}
int solve(int k, vector<int>& id, int len) {
  int mn = INT_MAX;
  for (int i = 0; k + i - 1 < (int)id.size(); i++) {
    mn = min(id[k + i - 1] - id[i] + 1, mn);
  }
  if (mn == INT_MAX) return -1;
  mn += (len - 1);
  return mn;
}
int main() {
  string s;
  cin >> s;
  int m;
  cin >> m;
  vector<string> query(m);
  vector<int> k(m);
  for (int i = 0; i < m; i++) {
    cin >> k[i] >> query[i];
  }
  vector<struct STATE> states(1);
  construct_trie(states, query);
  build_automaton(states);
  vector<vector<int> > index(m);
  search_(states, s, index);
  for (int i = 0; i < m; i++) {
    cout << solve(k[i], index[i], (int)query[i].size()) << '\n';
  }
  return 0;
}
