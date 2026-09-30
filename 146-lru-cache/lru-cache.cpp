class LRUCache {
public:
    struct Node{
        int key;
        int value;
        Node* prev;
        Node* next;

        Node(int k, int v){
            key= k;
            value= v;
            prev= nullptr;
            next= nullptr;
        }
    };

    int capacity;
    unordered_map<int, Node*> mp;

    Node* head;
    Node* tail;

    LRUCache(int capacity) {
        this-> capacity= capacity;
        head= new Node(-1, -1);
        tail= new Node(-1, -1);

        head-> next= tail;
        tail-> prev= head;
    }

    void remove(Node* node){
        Node* prevNode= node-> prev;
        Node* nextNode= node-> next;

        prevNode-> next= nextNode;
        nextNode-> prev= prevNode;
    }

    void insert(Node* node){
        Node* nextNode= head-> next;
        head-> next= node;
        node-> prev= head;

        node-> next= nextNode;
        nextNode-> prev= node;
    }
    
    int get(int key) {
        if(mp.find(key)== mp.end())
            return -1;
        Node* node= mp[key];
        remove(node);
        insert(node);

        return node-> value;
    }
    
    void put(int key, int value) {
        if(mp.find(key)!= mp.end()){
            Node* node= mp[key];
            node-> value= value;

            remove(node);
            insert(node);

            return;
        }
        Node* node= new Node(key, value);
        mp[key]= node;

        insert(node);

        if(mp.size()> capacity){
            Node* lru= tail-> prev;

            remove(lru);

            mp.erase(lru-> key);
            delete lru;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */