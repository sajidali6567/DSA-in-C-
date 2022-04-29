#include<bits/stdc++.h>
using namespace std;

// Disjoint set implementation using the union by rank and path compression heuristic

class DisjointSet {
	private:
		int n;
		vector<int> rank;
		vector<int> parent;
	public:
	DisjointSet(int n) {
		rank.resize(n);
		for(int i = 0; i< n; ++i) {
			cout << rank[i] << " ";
		}
		parent.resize(n);
		this->n = n;
		makeSet();
	}

	void makeSet() {
		for(int i = 0; i < n; i++) {
			parent[i] = i;
		}
	}	

	int find(int key) {
		// Path compression heuristic
		// While searching for key, we will attach all the intermediate keys to root node
		if(parent[key] != key) {
			parent[key] = find(parent[key]);
		}
		return parent[key];
	}

	void Union(int x, int y) {
		int x_root = find(x);
		int y_root = find(y);
		// if both lies in the same set do nothing
		if (x_root== y_root) return;

		if(rank[x_root] < rank[y_root]) {
			parent[x_root] = y_root;
		} else if(rank[x_root] > rank[y_root]) {
			parent[y_root] = x_root;
		}
		// When rank is equal, it does not matter, where you hang
		// hang inside y_root tree and increase the rank by 1
		parent[x_root] = y_root;
		rank[y_root]++;
	}
};

int main () {
	DisjointSet *dus = new DisjointSet(10);
}