// https://leetcode.com/problems/lru-cache/description/?envType=study-plan-v2&envId=top-interview-150

// Runtime Beats: 72.42%        Memory Beats: 58.02%

class LRUCache {
    class Node {
      public:
        int key, value;
        Node *prev, *next;

        Node(int key, int value) {
            this->key = key;
            this->value = value;
            prev = nullptr;
            next = nullptr;
        }
    };

    int cap;
    unordered_map<int, Node*> m;

    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);

  public:
    LRUCache(int capacity) : cap(capacity) {
        head->next = tail;
        tail->prev = head;
    }

    void addNode(Node* newNode) {
        Node* temp = head->next;

        newNode->next = temp;
        newNode->prev = head;

        head->next = newNode;
        temp->prev = newNode;
    }

    void deleteNode(Node* delNode) {
        Node* prevNode = delNode->prev;
        Node* nextNode = delNode->next;

        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

    int get(int key) {
        if (m.find(key) == m.end())
            return -1;

        Node* node = m[key];

        deleteNode(node);
        addNode(node);

        return node->value;
    }

    void put(int key, int value) {
        if (m.find(key) != m.end()) {
            Node* existingNode = m[key];

            deleteNode(existingNode);
            delete existingNode;
            m.erase(key);
        }

        if (m.size() == cap) {
            Node* lru = tail->prev;

            m.erase(lru->key);
            deleteNode(lru);
            delete lru;
        }

        Node* newNode = new Node(key, value);
        addNode(newNode);
        m[key] = newNode;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */