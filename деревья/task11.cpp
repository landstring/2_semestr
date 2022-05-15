#include <iostream>

using namespace std;

struct tree {
	int inf;
	tree* right;
	tree* left;
};

tree* node(int x) {
	tree* p = new tree;
	p->inf = x;
	p->right = p->left = NULL;
	return p;
}

void create(tree*& tr, int n) {
	int x;
	if (n > 0) {
		cin >> x;
		tr = node(x);
		int nl = n / 2;
		int nr = n - nl - 1;
		create(tr->left, nl);
		create(tr->right, nr);

	}
}

void preorder(tree* tr) {
	if (tr) {
		cout << tr->inf << " ";
		preorder(tr->left);
		preorder(tr->right);
	}
}

int task(tree* tr) {
	if (!tr->right && !tr->left) {
		return tr->inf;
	}
	else {
		if (tr->right && tr->left) {
			return task(tr->left) + task(tr->right);
		}
		else if (tr->right) {
			return task(tr->right);
		}
		else {
			return task(tr->left);
		}
	}
}

int main() {
	int n; 
	cout << "n = "; cin >> n;

	tree* tr = NULL;
	create(tr, n);

	cout << "S = " << task(tr) << endl;


}
