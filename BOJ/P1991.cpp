#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int node[26][2];
int node_size;
void Input() {
	cin >> node_size;
	for (int i = 0; i < node_size; i++) {
		char parent_node, left_node, right_node;
		cin >> parent_node >> left_node >> right_node;
		node[parent_node - 'A'][0] = left_node;
		node[parent_node - 'A'][1] = right_node;
	}
}

void Preorder(char parent_node) {
	if (parent_node == '.') {
		return;
	}
	else {
		cout << parent_node;
		Preorder(node[parent_node - 'A'][0]);
		Preorder(node[parent_node - 'A'][1]);
	}
}

void Inorder(char parent_node) {
	if (parent_node == '.') {
		return;
	}
	else {
		Inorder(node[parent_node - 'A'][0]);
		cout << parent_node;
		Inorder(node[parent_node - 'A'][1]);
	}
}

void Postorder(char parent_node) {
	if (parent_node == '.') {
		return;
	}
	else {
		Postorder(node[parent_node - 'A'][0]);
		Postorder(node[parent_node - 'A'][1]);
		cout << parent_node;
	}

}

void Solution(void) {
	Preorder('A');
	cout << endl;
	Inorder('A');
	cout << endl;
	Postorder('A');
}

int main(void) {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	Input();
	Solution();
	return 0;
}