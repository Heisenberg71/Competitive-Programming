class LFUCache {
private:
    int NOT_FOUND = -1;
    int MAX_CAPACITY;

    int minFrequency;
    unordered_map<int, int> key_value, key_frequency;
    unordered_map<int, list<int>::iterator> addressOf;
    unordered_map<int, list<int>> lfuCache;

    void evict() {
        addressOf.erase(lfuCache[ minFrequency ].back());
        key_frequency.erase(lfuCache[ minFrequency ].back());
        key_value.erase(lfuCache[ minFrequency ].back());
        lfuCache[ minFrequency ].erase(--lfuCache[ minFrequency ].end());
        minFrequency = 1;
    }

    void updateCache(int key) {
        if(key_value.count(key)){
            if(key_value.size() == MAX_CAPACITY && key_frequency[key] == minFrequency && lfuCache[ key_frequency[key] ].size() == 1) {
                minFrequency++;
            }
            lfuCache[ key_frequency[key] ].erase(addressOf[key]);
        }
        key_frequency[key]++;
        lfuCache[ key_frequency[key] ].push_front(key);
        addressOf[key] = lfuCache[ key_frequency[key] ].begin();
    }

public:
    LFUCache(int capacity) {
        MAX_CAPACITY = capacity;
        minFrequency = 1;
        key_value.clear();
        key_frequency.clear();
        addressOf.clear();
        lfuCache.clear();
    }
    
    int get(int key) {
        if(!key_value.count(key)) return NOT_FOUND;
        updateCache(key);
        return key_value[key];
    }
    
    void put(int key, int value) {
        if(!key_value.count(key) && key_value.size() == MAX_CAPACITY) evict();
        updateCache(key);
        key_value[key] = value;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
