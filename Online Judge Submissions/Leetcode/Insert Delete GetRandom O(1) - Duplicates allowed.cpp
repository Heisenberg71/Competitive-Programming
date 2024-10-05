class RandomizedCollection {
private:
    srand(time(0));
    vector<pair<int, int>> value_mapIdx;
    unordered_map<int, vector<int>> value_index;
public:
    RandomizedCollection() {
        value_mapIdx.clear();
        value_index.clear();
    }
    
    bool insert(int val) {
        value_index[val].push_back(value_mapIdx.size());
        value_mapIdx.push_back({val, value_index[val].size() - 1});

        return (value_index[val].size() == 1);
    }
    
    bool remove(int val) {

        if(value_index[val].size() == 0) return false;

        int position = value_index[val].back();
        value_index[ value_mapIdx.back().first  ][ value_mapIdx.back().second ] = position;
        swap(value_mapIdx[position], value_mapIdx.back());

        value_index[val].pop_back();
        value_mapIdx.pop_back();

        return true;
    }
    
    int getRandom() {
        
        int randomIndex = rand() %value_mapIdx.size();
        return value_mapIdx[randomIndex].first;
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
