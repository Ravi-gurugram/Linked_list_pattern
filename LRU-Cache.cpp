class LRUCache {
    int capacity;
    list<pair<int, int>> dll; // Doubly linked list: {key, value}
    unordered_map<int, list<pair<int, int>>::iterator> mp; // key -> node iterator

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }

    int get(int key) {
        if (mp.find(key) == mp.end()) return -1;

        // Move accessed node to front
        auto it = mp[key];
        int val = it->second;

        dll.erase(it);
        dll.push_front({key, val});
        mp[key] = dll.begin();

        return val;
    }

    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            // Remove old node
            dll.erase(mp[key]);
        } else if (dll.size() == capacity) {
            // Remove LRU from back
            auto lru = dll.back();
            mp.erase(lru.first);
            dll.pop_back();
        }

        // Insert at front
        dll.push_front({key, value});
        mp[key] = dll.begin();
    }
};


/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */