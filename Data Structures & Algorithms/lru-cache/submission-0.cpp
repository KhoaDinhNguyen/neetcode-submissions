class Node {
public:
    int key;
    int value;
    Node* left, *right;
    Node(int key, int value) {
        this->key = key;
        this->value = value;
        this->left = nullptr;
        this->right = nullptr;
    }
};

class LRUCache {
private:
    void remove(Node* node) {
        Node* prevNode = node->left;
        Node* nextNode = node->right;
        prevNode->right = nextNode;
        nextNode->left = prevNode; 
    }

    void insert(Node* node) {
        Node* prev = right->left;
        prev->right = node;
        right->left = node;

        node->right = right;
        node->left = prev;
    }
public:
    unordered_map<int, Node*> mp;
    int capacity = 0;
    Node* left;
    Node* right;

    LRUCache(int capacity) {
        this->capacity = capacity;
        mp.clear();
        left = new Node(-1, 0);
        right = new Node(-1, 0);

        left->right = right;
        right->left = left;

    }
    
    int get(int key) {
        if (mp.find(key) != mp.end()) {
            Node* node = mp[key];
            remove(node);
            insert(node);
            return node->value;
        }

        return -1;
    }
    
    void put(int key, int value) {
        // If the mp has key, then removing from the list to update it to LRU
        if (mp.find(key) != mp.end()) {
            remove(mp[key]);
        }

        Node* newNode = new Node(key, value);
        mp[key] = newNode;
        insert(newNode);

        if (mp.size() > capacity) {
            Node* lu = left->right;
            mp.erase(lu->key);
            remove(lu);
            delete lu;
        }
    }
};
