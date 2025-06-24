class Node {
    int key;
    int val;
    Node prev;
    Node next;
    public Node(int key, int val) {
        this.key = key;
        this.val = val;
        this.prev = null;
        this.next = null;
    }
}

class LRUCache {
    private int capacity;
    private Map<Integer, Node> keyNodeMap;
    private Node leftMostNode;
    private Node rightMostNode;

    public LRUCache(int capacity) {
        this.capacity = capacity;
        this.keyNodeMap = new HashMap<>();

        leftMostNode = new Node(0, 0);
        rightMostNode = new Node(0, 0);

        leftMostNode.next = rightMostNode;
        rightMostNode.prev = leftMostNode;
    }
    
    public int get(int key) {
        if(keyNodeMap.containsKey(key) == false) {
            return -1;
        }

        int value = keyNodeMap.get(key).val;
        Node currNode = keyNodeMap.get(key);
        evict(key);
        addFirst(key, currNode.val);

        return value;
    }
    
    public void put(int key, int value) {
        if(keyNodeMap.containsKey(key)) {
            evict(key);
        }
        if(!keyNodeMap.containsKey(key) && keyNodeMap.size() == capacity) {
            evictLast();
        }
        addFirst(key, value);
    }

    private void evict(int key) {
        Node currNode = keyNodeMap.get(key);
        Node prevNode = currNode.prev;
        Node nextNode = currNode.next;

        prevNode.next = nextNode;
        nextNode.prev = prevNode;
        
        keyNodeMap.remove(key);
    }

    private void addFirst(int key, int value) {
        Node currNode = new Node(key, value);
        
        Node nextNode = leftMostNode.next;
        currNode.next = nextNode;
        leftMostNode.next = currNode;

        currNode.prev = leftMostNode;
        nextNode.prev = currNode;
        keyNodeMap.put(key, currNode);
    }

    private void evictLast() {
        Node deletedNode = rightMostNode.prev;

        deletedNode.prev.next = rightMostNode;
        rightMostNode.prev = deletedNode.prev;
        keyNodeMap.remove(deletedNode.key);
    }
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
