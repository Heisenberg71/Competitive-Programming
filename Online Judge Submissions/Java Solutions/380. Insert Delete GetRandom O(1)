class RandomizedSet {

    HashMap<Integer, Integer> position = new HashMap<Integer, Integer>();
    List<Integer> values = new ArrayList<>();
    Random rand;

    public RandomizedSet() {
        position.clear();
        values.clear();
        rand = new Random();
    }
    
    public boolean insert(int val) {
        if(position.containsKey(val)) return false;

        position.put(val, values.size());
        values.add(val);
        return true;
    }
    
    public boolean remove(int val) {
        if(!position.containsKey(val)) return false;

        int removedValueIndex = position.get(val);
        Collections.swap(values, values.size() - 1, removedValueIndex);
        values.remove(values.size() - 1);
        if(values.size() > removedValueIndex) {
            position.put(values.get(removedValueIndex), removedValueIndex);
        }
        position.remove(val);

        return true;
    }
    
    public int getRandom() {
        return values.get(rand.nextInt(values.size()));
    }
}

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * boolean param_1 = obj.insert(val);
 * boolean param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */
