class Node{
    public:
        int key;
        int value;
        Node* prev;
        Node* next;

        Node(int k, int v)
        {
            key = k;
            value = v;
            prev = NULL;
            next = NULL;
        }
};

class LRUCache {
    Node* head;
    Node* tail;
    map<int, Node*> map;
    int capacity;
public:
    LRUCache(int capacity) {
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
        this->capacity = capacity;
    }
    
    int get(int key) {
        if(map.count(key) == 0)
            return -1;
        moveToTail(map[key]);
        return map[key]->value;
    }
    
    void put(int key, int value) {
        if(map.count(key) == 0)
        {
            Node* node = new Node(key, value);
            if(map.size() == capacity)
            {
                Node* nodeTodelete = head->next;
                map.erase(nodeTodelete->key);
                deleteNode(nodeTodelete);
                addToTail(node);
            }
            else
            {
                addToTail(node);
            }
             map[key] = node;
        }
        else
        {
            moveToTail(map[key]);
            map[key]->value = value;
        }
    }

    void addToTail(Node* node)
    {
        node->prev = tail->prev;
        tail->prev->next = node;
        node->next = tail;
        tail->prev = node;
    }

    void deleteNode(Node* node)
    {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void moveToTail(Node* node)
    {
        deleteNode(node);
        addToTail(node);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */