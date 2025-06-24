class LRUCache {

    private LinkedHashMap<Integer, Integer> keyValueLinkedMap = new LinkedHashMap<>();;
    private int capacity;
    
    public LRUCache(int capacity) {
        this.capacity = capacity;
    }

    public int get(int key) {
        if(!keyValueLinkedMap.containsKey(key)) return -1;
            
        int value = keyValueLinkedMap.get(key);
        keyValueLinkedMap.remove(key);
        keyValueLinkedMap.put(key, value);
        return value;
    }

    public void put(int key, int value) {
        if (keyValueLinkedMap.containsKey(key)) keyValueLinkedMap.remove(key);

        if (keyValueLinkedMap.size() == capacity) {
            Integer firstKey = keyValueLinkedMap.keySet().iterator().next();
            keyValueLinkedMap.remove(firstKey);
        }
        keyValueLinkedMap.put(key, value);
    }
}
