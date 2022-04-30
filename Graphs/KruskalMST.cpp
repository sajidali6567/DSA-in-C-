#include<bits/stdc++.h>
using namespace std;

// Disjoint set implementation using the union by rank and path compression heuristic
// copid from GFG
class DSU {
	int* parent;
	int* rank;

public:
	DSU(int n)
	{
		parent = new int[n];
		rank = new int[n];

		for (int i = 0; i < n; i++) {
			parent[i] = -1;
			rank[i] = 1;
		}
	}

	// Find function
	int find(int i)
	{
		if (parent[i] == -1)
			return i;

		return parent[i] = find(parent[i]);
	}
	// union function
	void unite(int x, int y)
	{
		int s1 = find(x);
		int s2 = find(y);

		if (s1 != s2) {
			if (rank[s1] < rank[s2]) {
				parent[s1] = s2;
				rank[s2] += rank[s1];
			}
			else {
				parent[s2] = s1;
				rank[s1] += rank[s2];
			}
		}
	}
};


// Adds Edge u-v with weight w
void addEdge(vector<vector<int>>& edgelist, int u, int v, int w) {
	edgelist.push_back({ w, u, v });
}

bool compare(const pair<int, int>& a, const pair<int, int>& b) {
	return a.second > b.second;
}

void printEdgeList(vector<vector<int>> edgelist) {
	// Print adjacency list 
	for(int i=0;i<edgelist.size(); ++i) {
			cout << "weight = " << edgelist[i][0] << " " << edgelist[i][1] << "  " << edgelist[i][2] << endl;
	}
}

int Kruskal(vector<vector<int>> edgelist, int V) {
	// Sort the edges in non-descending order of their weight
	sort(edgelist.begin(), edgelist.end());
	
	DSU ds(V);

	// edgelist.size()-1 edges are required to find MST
	int ans = 0;
	for(auto edge:edgelist) {
		int w = edge[0];
		int u = edge[1];
		int v = edge[2];
		
		if(ds.find(u) != ds.find(v)) {
			ds.unite(u, v);
			ans += w;
		}
	}
	return ans;
}

int main() {
	// Adjaceny list contains all the nodes connected to a node and the weight value of the edge
	vector<vector<int>> adj;
	addEdge(adj, 0, 1, 2);
	addEdge(adj, 0, 3, 6);
	addEdge(adj, 1, 2, 3);
	addEdge(adj, 1, 3, 8);
	addEdge(adj, 1, 4, 5);
	addEdge(adj, 2, 4, 7);
	addEdge(adj, 3, 4, 9);
	cout << "Weight of MST is " << Kruskal(adj, 5);
}
