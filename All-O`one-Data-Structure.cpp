class AllOne {
    struct Bucket {
        int count;
        unordered_set<string> keys;
    };

    list<Bucket> buckets;
    unordered_map<string, list<Bucket>::iterator> keyToBucket;

public:
    AllOne() {}

    void inc(string key) {
        if (keyToBucket.find(key) == keyToBucket.end()) {
            if (buckets.empty() || buckets.front().count > 1) {
                buckets.push_front({1, {key}});
                keyToBucket[key] = buckets.begin();
            } else {
                buckets.front().keys.insert(key);
                keyToBucket[key] = buckets.begin();
            }
        } else {
            auto curr = keyToBucket[key];
            auto nxt = std::next(curr);
            int newCount = curr->count + 1;

            if (nxt == buckets.end() || nxt->count > newCount) {
                nxt = buckets.insert(nxt, {newCount, {}});
            }

            nxt->keys.insert(key);
            keyToBucket[key] = nxt;

            curr->keys.erase(key);
            if (curr->keys.empty()) buckets.erase(curr);
        }
    }

    void dec(string key) {
        auto curr = keyToBucket[key];
        int newCount = curr->count - 1;

        if (newCount == 0) {
            keyToBucket.erase(key);
        } else {
            auto prev = (curr == buckets.begin()) ? buckets.end() : std::prev(curr);
            if (curr == buckets.begin() || prev->count < newCount) {
                prev = buckets.insert(curr, {newCount, {}});
            }

            prev->keys.insert(key);
            keyToBucket[key] = prev;
        }

        curr->keys.erase(key);
        if (curr->keys.empty()) buckets.erase(curr);
    }

    string getMaxKey() {
        return buckets.empty() ? "" : *(buckets.back().keys.begin());
    }

    string getMinKey() {
        return buckets.empty() ? "" : *(buckets.front().keys.begin());
    }
};


/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */