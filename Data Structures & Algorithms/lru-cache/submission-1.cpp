class Node {
public:
    int key;
    int value;
    Node* prev, *next;
    Node(int key, int value) {
        this->key = key;
        this->value = value;
        this->prev = nullptr;
        this->next = nullptr;
    }
};

class LRUCache {
private:
    void remove(Node* node) {
        Node* prevNode = node->prev;
        Node* nextNode = node->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode; 
    }

    void insert(Node* node) {
        Node* prev = right->prev;
        prev->next = node;
        right->prev = node;

        node->next = right;
        node->prev = prev;
    }
public:
    unordered_map<int, Node*> cache;
    int capacity = 0;
    Node* left;
    Node* right;

    LRUCache(int capacity) {
        this->capacity = capacity;
        cache.clear();
        left = new Node(-1, 0);
        right = new Node(-1, 0);

        left->next = right;
        right->prev = left;

    }
    
    int get(int key) {
        if (cache.find(key) != cache.end()) {
            Node* node = cache[key];
            remove(node);
            insert(node);
            return node->value;
        }

        return -1;
    }
    
    void put(int key, int value) {
        // If the cache has key, then removing from the list to update it to LRU
        if (cache.find(key) != cache.end()) {
            remove(cache[key]);
        }

        Node* newNode = new Node(key, value);
        cache[key] = newNode;
        insert(newNode);

        if (cache.size() > capacity) {
            Node* lu = left->next;
            cache.erase(lu->key);
            remove(lu);
            delete lu;
        }
    }
};
