class LRUCache {
private:
    int capacity;
    list<pair<int, int>> dll;

    unordered_map<int, list<pair<int, int>>::iterator> mp;

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }

    int get(int key) {
        if (mp.find(key) == mp.end())
            return -1;

        auto it = mp[key];

        int value = it->second;

        dll.splice(dll.begin(), dll, it);

        return value;
    }

    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            auto it = mp[key];

            it->second = value;

            dll.splice(dll.begin(), dll, it);
        }

        else {
            if (dll.size() == capacity) {
                int lruKey = dll.back().first;

                mp.erase(lruKey);

                dll.pop_back();
            }

            dll.push_front({key, value});

            mp[key] = dll.begin();
        }
    }
};
