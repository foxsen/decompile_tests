#include <cstdlib>
#include <iostream>
#include <memory>
#include <vector>
using namespace std;

struct node_t {
	shared_ptr<node_t> left, right;

	node_t():left(nullptr), right(nullptr) {}
};

shared_ptr<node_t> parse(string::const_iterator &it) {
	shared_ptr<node_t> p(new node_t());

	++it; // '('
	if(*it == '(') p->left = parse(it);
	++it; // ','
	if(*it == '(') p->right = parse(it);
	++it; // ')'

	return p;
}

inline shared_ptr<node_t> input_tree() {
	string s;
	cin >> s;

	auto it = s.cbegin();
	return parse(it);
}

inline bool intersection_ok(const shared_ptr<node_t> &a, const shared_ptr<node_t> &b) {
	return a != nullptr && b != nullptr;
}

inline bool union_ok(const shared_ptr<node_t> &a, const shared_ptr<node_t> &b) {
	return a != nullptr || b != nullptr;
}

template<class Predicate>
inline string dfs(const shared_ptr<node_t> &a, const shared_ptr<node_t> &b, const Predicate &ok) {
	if(!ok(a, b)) return "";

	string res = "(";
	res += dfs(a ? a->left : nullptr, b ? b->left : nullptr, ok);
	res += ",";
	res += dfs(a ? a->right : nullptr, b ? b->right : nullptr, ok);
	res += ")";

	return res;
}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	for(char c; cin >> c;) {
		const auto tree1 = input_tree();
		const auto tree2 = input_tree();

		const auto ok = (c == 'i' ? &intersection_ok : &union_ok);
		cout << dfs(tree1, tree2, ok) << endl;
	}

	return EXIT_SUCCESS;
}