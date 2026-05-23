#include <iostream>
#include <vector>
#include <string>

#define NIL -1

using namespace std;

class NODE {
public:
	int key, p = NIL, right = NIL, left = NIL;
	NODE(int key) {
		this->key = key;
	}
};

vector<NODE> T;
int root = NIL;

void insert(int z) {
	int y = NIL, x = root;
	while (x != NIL) {
		y = x;
		if (T[z].key < T[x].key) x = T[x].left;
		else x = T[x].right;
	}
	T[z].p = y;
	if (y == NIL) { root = z; }
	else if (T[z].key < T[y].key) { T[y].left = z; }
	else T[y].right = z;
}

void In(int a) {
	if (a != NIL) {
		In(T[a].left);
		cout << " " << T[a].key;
		In(T[a].right);
	}
}

void Pre(int a) {
	if (a != NIL) {
		cout << " " << T[a].key;
		Pre(T[a].left);
		Pre(T[a].right);
	}
}


int main() {
	string cmd;
	int m, cnt = 0, key;
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> cmd;
		if (cmd == "insert") {
			cin >> key;
			NODE z(key);
			T.push_back(z);
			insert(cnt);
			cnt++;
		}

		else if (cmd == "print") {
			In(root); cout << endl;
			Pre(root); cout << endl;
		}
	}

	return 0;
}
