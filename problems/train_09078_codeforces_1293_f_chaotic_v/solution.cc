#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 5000;
vector<int> primes;
vector<int> expansions[MAX_N + 1];
vector<int> factorials[MAX_N + 1];
vector<int> cnt_factorials(MAX_N + 1);
int index_of_prime[MAX_N + 1];
int n;
struct Node {
  int cnt = 0;
  long long sub_tree_sum = 0;
  long long sub_tree_cnt = 0;
  vector<pair<Node*, vector<pair<int, int>>>> edges;
};
void get_primes(int n) {
  vector<char> numbers(n + 1, 0);
  for (int i = 2; i <= n; i++)
    if (numbers[i] == false) {
      primes.push_back(i);
      index_of_prime[i] = primes.size() - 1;
      for (int j = i; j <= n; j += i) numbers[j] = true;
    }
}
void expansion(int n) {
  for (int number = 2; number <= n; number++) {
    expansions[number].assign(primes.size(), 0);
    int number_copy = number;
    for (int div = 2; div * div <= number; div++) {
      int cnt = 0;
      while (number_copy % div == 0) {
        cnt++;
        number_copy /= div;
      }
      expansions[number][index_of_prime[div]] += cnt;
    }
    if (number_copy != 1) expansions[number][index_of_prime[number_copy]] += 1;
  }
}
void factorials_expansion(int n) {
  factorials[1].assign(primes.size(), 0);
  for (int number = 2; number <= n; number++) {
    factorials[number] = factorials[number - 1];
    for (int i = 0; i < primes.size(); i++)
      factorials[number][i] += expansions[number][i];
  }
}
int roll(int factorial, int iPrime) {
  while (iPrime >= 0 && factorials[factorial][iPrime] == 0) iPrime--;
  return iPrime;
}
void add_factorial(Node* node, int factorial, int iPrime, int rest) {
  int cpy_iPrime = iPrime;
  if (rest == 0 && iPrime >= 0) iPrime--;
  iPrime = roll(factorial, iPrime);
  if (iPrime == -1) {
    node->cnt += cnt_factorials[factorial];
    return;
  }
  if (cpy_iPrime != iPrime) rest = factorials[factorial][iPrime];
  bool common = false;
  for (int i = 0; i < node->edges.size(); i++) {
    if (node->edges[i].second[0].first == iPrime) {
      int prefix_prime = 0, common_rest = 0;
      while (prefix_prime < node->edges[i].second.size() &&
             node->edges[i].second[prefix_prime].first == iPrime) {
        int rest_in_edge = node->edges[i].second[prefix_prime].second;
        if (rest == rest_in_edge) {
          iPrime = roll(factorial, iPrime - 1);
          if (iPrime == -1) break;
          rest = factorials[factorial][iPrime];
          prefix_prime++;
          continue;
        } else if (rest < rest_in_edge) {
          common_rest = rest;
          break;
        } else if (rest > rest_in_edge) {
          rest -= rest_in_edge;
          prefix_prime++;
        }
      }
      vector<pair<int, int>> left, right;
      left.assign(node->edges[i].second.begin(),
                  node->edges[i].second.begin() + prefix_prime);
      right.assign(node->edges[i].second.begin() + prefix_prime,
                   node->edges[i].second.end());
      if (common_rest != 0) {
        left.push_back({right[0].first, common_rest});
        right[0].second -= common_rest;
        rest = 0;
      }
      if (prefix_prime == node->edges[i].second.size()) {
        add_factorial(node->edges[i].first, factorial, iPrime, rest);
      } else {
        Node* new_node = new Node();
        Node* old_node = node->edges[i].first;
        new_node->edges.push_back({old_node, right});
        node->edges[i].first = new_node;
        node->edges[i].second = left;
        add_factorial(new_node, factorial, iPrime, rest);
      }
      common = true;
      break;
    }
  }
  if (!common) {
    Node* new_node = new Node();
    node->edges.push_back({new_node, vector<pair<int, int>>()});
    node->edges.back().second.push_back({iPrime, rest});
    iPrime--;
    while (iPrime >= 0) {
      if (factorials[factorial][iPrime] != 0)
        node->edges.back().second.push_back(
            {iPrime, factorials[factorial][iPrime]});
      iPrime--;
    }
    add_factorial(new_node, factorial, iPrime, 0);
  }
}
void dfs1(Node* node) {
  for (auto edge : node->edges) {
    dfs1(edge.first);
    int cnt = 0;
    for (auto pr : edge.second) cnt += pr.second;
    node->sub_tree_sum +=
        (long long)cnt * edge.first->sub_tree_cnt + edge.first->sub_tree_sum;
    node->sub_tree_cnt += edge.first->sub_tree_cnt;
  }
  node->sub_tree_cnt += node->cnt;
}
long long answer = 1e18;
void dfs2(Node* node, long long rest, int rest_cnt) {
  answer = min(answer, node->sub_tree_sum + rest);
  long long rest_sum_in_childs = 0;
  int rest_cnt_in_childs = 0;
  for (auto edge : node->edges) {
    rest_sum_in_childs += edge.first->sub_tree_sum;
    rest_cnt_in_childs += edge.first->sub_tree_cnt;
  }
  for (auto edge : node->edges) {
    long long current_cnt =
        rest_cnt + node->sub_tree_cnt - edge.first->sub_tree_cnt;
    int cnt = 0;
    for (auto pr : edge.second) cnt += pr.second;
    long long child_back =
        edge.first->sub_tree_sum + (long long)cnt * edge.first->sub_tree_cnt;
    dfs2(edge.first,
         (rest + node->sub_tree_sum - child_back) + cnt * (current_cnt),
         current_cnt);
  }
}
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    cnt_factorials[a]++;
  }
  get_primes(MAX_N);
  expansion(MAX_N);
  factorials_expansion(MAX_N);
  Node* root = new Node();
  for (int f = MAX_N; f >= 2; f--) {
    if (cnt_factorials[f] != 0) {
      add_factorial(root, f, primes.size() - 1, factorials[f].back());
    }
  }
  root->cnt = cnt_factorials[0] + cnt_factorials[1];
  dfs1(root);
  dfs2(root, 0, 0);
  cout << answer;
  return 0;
}
