class LRUCache {
private:
    unordered_map<int, list< pair<int, int> >::iterator> map;
    list< pair<int, int> > cache;
    int capacity;
public:
    LRUCache(int c) : capacity(c) {}

    int get(int key) {
        const auto it = map.find(key);
        if (it == map.end()) {
            return -1;
        }
        cache.splice(cache.begin(), cache, it -> second);
        return it -> second -> second;
    }

    void put(int key, int value) {
        const auto it = map.find(key);
        if (it != map.end()) {
            it -> second -> second = value;
            cache.splice(cache.begin(), cache, it -> second);
            return;
        }

        if (cache.size() == capacity) {
            const auto& p = cache.back();
            map.erase(p.first);
            cache.pop_back();
        }
        cache.emplace_front(key, value);
        map[key] = cache.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
