#include<bits/stdc++.h>
using namespace std;

class DisjointSet {
	int *parent, *rank, n;
	public:
		DisjointSet(int size);
		void MakeSet();
		int Find(int value);
		void Union(int x, int y);	
};

DisjointSet::DisjointSet(int size) {
	n = size;
	parent = new int[size];
	rank = new int[size];
	MakeSet();
}

void DisjointSet::MakeSet(){
	for (int i=0;i<n;++i) {
		parent[i] = i;
	}
}
int DisjointSet::Find(int value){
	if (value != parent[value]) {
		// Since value is not the representative of the set
		// Make it child of the root node
		// Path Compression
		parent[value] = Find(parent[value]);
	}
	return parent[value];
}
void DisjointSet::Union(int x, int y){
	int x_id = Find(x);
	int y_id = Find(y);
	if (x_id == y_id) return;
	if (rank[x_id] > rank[y_id]) {
		parent[y_id] = x_id;
	}
	else {
		parent[x_id] = y_id;
		if (rank[x_id] == rank[y_id]) {
			rank[y_id] = rank[y_id] + 1;
		}
	}
}	

int main() {
	DisjointSet obj(10);
	obj.Union(0, 2);
    obj.Union(4, 2);
    obj.Union(3, 1);
    if (obj.Find(4) == obj.Find(0))
        cout << "Yes\n";
    else
        cout << "No\n";
    if (obj.Find(1) == obj.Find(0))
        cout << "Yes\n";
    else
        cout << "No\n";
  
    return 0;
}
