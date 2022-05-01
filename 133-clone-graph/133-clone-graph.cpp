/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        // start BFS
        if (node == NULL) return NULL;
        map<Node*, Node*> mp;
        
        Node* copyNode = new Node();
        copyNode->val = node->val;
        // starting point of graph is node
        queue<Node*> q;
        q.push(node);
        mp[node] = copyNode;
        while(!q.empty()) {
            Node* temp = q.front();q.pop();
            vector<Node*> nbrs = temp->neighbors;
            // traverse all the neighbours
            for(auto x:nbrs) {
                // check if node is created or not
                if(mp.find(x) == mp.end()) {
                    // create a node and put in map
                    Node* newNode = new Node();
                    newNode->val = x->val;
                    mp[x] = newNode;
                    q.push(x);
                }
                // push neighbours of temp into clone node similar to temp
                mp[temp]->neighbors.push_back(mp[x]);
            }
        }
        
        return mp[node];
    }
};