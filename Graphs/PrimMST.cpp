#include<bits/stdc++.h>
using namespace std;

// Adds Edge u-v with weight w
void addEdge(vector<pair<int, int>> adj[], int u, int v, int w) {
	adj[u].push_back({v, w});
	adj[v].push_back({u, w});
}

int indexOfMinWeightNode(vector<int>& nodeWeight, vector<bool>& setMST) {
	int minNodeIdx = -1;
	int min = INT_MAX;
	for(int i=0;i<nodeWeight.size();++i) {
		if(!setMST[i] &&  nodeWeight[i] < min) {
			min = nodeWeight[i];
			minNodeIdx = i;
		}
	}
	return minNodeIdx;
}

void printMST(vector<int> parent) {
	cout << " parent array is\n";
	for(int i=0;i<parent.size();++i) {
		cout << i << " " << parent[i] << endl;
	}
}

void primMST(vector<pair<int, int>> adj[], int V) {
	// SetMST array to keep track to nodes included in MST
	vector<bool> setMST(V, false);
	// nodeWeight keeps track of nodeValue for all the nodes
	vector<int> nodeWeight(V, INT_MAX);
	// parent will store parent of node to keep track of edges of MST
	vector<int> parent(V);
	// Initialise node weight zero for a node, so that it gets picked first and parent as -1
	nodeWeight[0] = 0;
	parent[0] = -1;

	// we are inclduing nodes one by one, so when all nodes are included in setMst we are done
	for(int i=1;i<=V;i++) {
		// pick the node with min Node Weight
		int u = indexOfMinWeightNode(nodeWeight, setMST);
		// include in SetMST
		setMST[u] = true;
		// Relax all the adjacent Edges
		for(auto x:adj[u]) {
			if(!setMST[x.first] && x.second < nodeWeight[x.first]) {
				nodeWeight[x.first] = x.second;
				parent[x.first]= u;
			}
		}
	}
	printMST(parent);
}

int main() {
	// Adjaceny list contains all the nodes connected to a node and the weight value of the edge
	vector<pair<int, int>> adj[5];
	addEdge(adj, 0, 1, 2);
	addEdge(adj, 0, 3, 6);
	addEdge(adj, 1, 2, 3);
	addEdge(adj, 1, 3, 8);
	addEdge(adj, 1, 4, 5);
	addEdge(adj, 2, 4, 7);
	addEdge(adj, 3, 4, 9);
	primMST(adj, 5);
}
