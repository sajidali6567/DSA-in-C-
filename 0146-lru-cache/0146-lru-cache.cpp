class Node {
    public:
    int key;
    int value;
    Node* next;
    Node* prev;
    
    Node(int key, int value) {
        this->key   = key;
        this->value = value;
        this->next = NULL;
        this->prev = NULL;
    }
};

class DLL {
    public:
    Node* head; Node* tail;
    
    DLL() {
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
    }
    
    Node* Insert(int key, int value) {
        Node* newNode = new Node(key, value);
        Node* nextNode = head->next;
        
        head->next = newNode;
        newNode->prev = head;
        
        newNode->next = nextNode;
        nextNode->prev = newNode;
        
        return newNode;
    }
    
    void Remove(Node* delnode) {
        
        Node * delprev = delnode -> prev;
        Node * delnext = delnode -> next;
        delprev -> next = delnext;
        delnext -> prev = delprev;        
    }
};

class LRUCache {
public:
    int capacity;
    DLL* list;
    unordered_map<int, Node*> mp;
    
    LRUCache(int capacity) {
        this->capacity = capacity;
        list = new DLL();
    }
    
    int get(int key) {
        if(mp.find(key) == mp.end()) {
            return -1;
        }
        
        // Accessing the key makes it most recently used, so delete the node and insert new node
        int value = mp[key]->value;
        
        list->Remove(mp[key]);
        Node* addrOfInsertedNode = list->Insert(key, value);
        
        mp[key] = addrOfInsertedNode;

        
        return value;
    }
    
    void put(int key, int value) {
        // if key is already present in the cache
        if(mp.find(key) != mp.end()) {
            Node* nodeToBeDeleted = mp[key];
            mp.erase(key);
            
            list->Remove(nodeToBeDeleted);
        }
        
        // if capacity is full evict least recently used element
        if(mp.size() == capacity) {
            
            mp.erase(list->tail->prev->key);
            list->Remove(list->tail->prev);
            
        }
        
        Node* addrOfInsertedNode = list->Insert(key, value);    
        mp[key] = addrOfInsertedNode;
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */