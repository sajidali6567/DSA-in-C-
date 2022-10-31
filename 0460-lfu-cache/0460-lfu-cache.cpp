class Node {
    public:
    int key;
    int value;
    int cnt;
    Node* next;
    Node* prev;
    Node(int key, int value) {
        this->key = key;
        this->value = value;
        this->cnt = 1;
        this->next = this->prev = NULL;
    }
};

class List {
    public:
    Node* head; Node* tail;
    int size;
    List() {
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
        size = 0;
    }
    
    void addFront(Node* newNode) {
        Node* nextNode = head->next;
        
        newNode->next = nextNode;
        nextNode->prev = newNode;
        
        head->next = newNode;
        newNode->prev = head;

        size++;
    }
    
    void removeNode(Node* delnode) {
        Node* delprev = delnode->prev;
        Node* delnext = delnode->next;
        delprev->next = delnext;
        delnext->prev = delprev;
        size--; 
    }
    void popNode() {
        Node* lastNode = tail->prev;
        tail->prev = lastNode->prev;
        lastNode->prev->next = tail;
        --size;
    }
};

class LFUCache {
    map<int, Node*> keyNode; 
    map<int, List*> freqListMap; 
    int maxSizeCache;
    int minFreq; 
    int curSize; 
public:
    LFUCache(int capacity) {
        maxSizeCache = capacity; 
        minFreq = 0;
        curSize = 0; 
    }

    // this function remove the node from frequency n and add it to the n+1
    void updateFreqListMap(Node *node) {
        int cnt = node->cnt;
        freqListMap[cnt]->removeNode(node);
        keyNode.erase(node->key);
        if(cnt == minFreq && freqListMap[cnt]->size == 0) {
            minFreq++;
        }

        cnt += 1;
        List* list = new  List;
        if(freqListMap.find(cnt) == freqListMap.end()) {
            freqListMap[cnt] = list;
        }
        node->cnt = cnt;
        freqListMap[cnt]->addFront(node);
        keyNode[node->key] = node;
    }
    
    int get(int key) {
        if(keyNode.find(key) != keyNode.end()) {
            Node* node = keyNode[key];
            int value = node->value;
            updateFreqListMap(node);
            return value;
        }
        return -1;
    }    
    
    void put(int key, int value) {
        if(maxSizeCache == 0) return;
    
        if(keyNode.find(key) != keyNode.end()) {     // key is already present in the cache
            Node* node = keyNode[key];
            node->value = value;
            updateFreqListMap(node);
        } else {
            if(curSize == maxSizeCache) {
                List* list = freqListMap[minFreq];
                keyNode.erase(list->tail->prev->key);
                list->removeNode(list->tail->prev);
                curSize--;
            }
            curSize++;
            minFreq = 1;
            List* list = new List();
            if(freqListMap.find(minFreq) == freqListMap.end()) {     // if list is already present then fine, otherwise Initialise a new list
                freqListMap[minFreq] = list;
            }
            Node* node = new Node(key, value);
            freqListMap[minFreq]->addFront(node);
            keyNode[key] = node;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */